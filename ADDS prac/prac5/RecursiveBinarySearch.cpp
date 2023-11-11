#include "RecursiveBinarySearch.h"
#include <iostream>
using namespace std;


int RecursiveBinarySearch::search_helper(std::vector<int>& array, int target, int start, int end){

    // base case: only 1 element left
    if (start == end){
        if (array.at(start) == target){
            return start;
        }
        return -1;
    }

    // find middle element
    int mid_index = start + (end-start)/2;
    int mid = array.at(mid_index);

    // storing the found index that has the value "target"
    int res = -1;

    // recursive cases
    if (target < mid){
        res = search_helper(array, target, start, mid_index-1);
    }else if (target > mid){
        res = search_helper(array, target, mid_index+1, end);
    }else{
        res = mid_index;
    }
    return res;
}

bool RecursiveBinarySearch::search(std::vector<int> array, int target){
    int res = RecursiveBinarySearch::search_helper(array, target, 0, array.size()-1);
    cout << res <<endl;
    if (res > -1) {
        return true;
    }
    return false;
}