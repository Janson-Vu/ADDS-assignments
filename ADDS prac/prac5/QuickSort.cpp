#include "QuickSort.h"
using namespace std;


void QuickSort::sort_helper(vector<int>& array, int start, int end) {

    // Base case, nothing to sort
    if(start >= end) {
        return;
    }

    // Swap the value of the only 2 elements 
    // if array has more then 2 elements
    if (start + 1 == end){ 
        if (array.at(start) > array.at(end)){
            swap(array.at(start), array.at(end));
        }
    }
    // Swap the value 3rd element and the value of last element
    // if array has MORE THAN 2 elements
    else{           
        swap(array.at(start+2), array.at(end));
    }

    // Select the last element as pivot (originally the 3rd element)
    int pivot = array.at(end);

    // pivot index is from the beginning of each sub-array
    int pivot_index = start;

    for(int i = start; i < end; i++) {
        if (array.at(i) < pivot) {
            // swap ith element and element at pivot_index
            swap(array.at(i), array.at(pivot_index));

            pivot_index++;
        }
    }
    
    // swap the pivot_index element and pivot
    swap(array.at(pivot_index), array.at(end));
    
    // call sort for subarrays
    sort_helper(array, start, pivot_index - 1);
    sort_helper(array, pivot_index + 1, end);
}


std::vector<int> QuickSort::sort(std::vector<int> list){
    vector<int> sorted_list = list;
    QuickSort::sort_helper(sorted_list, 0, sorted_list.size() - 1);
    
    return sorted_list;
}

