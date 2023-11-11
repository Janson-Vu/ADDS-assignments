#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
using namespace std;

void print2(vector<int>& array){
    for (size_t i=0; i< array.size(); i++){
        cout << array.at(i) <<" ";
    }
    cout<<endl;
}


int main(){

    // vector<int> array = {1,2,3,4,5,6,7};
    // vector<int> array2 = {-10,1, 3, 5, 4,100, -5, 100, 7777, 2014,0};
    //BubbleSort s;
    QuickSort s2;
    RecursiveBinarySearch r;
    
    // get the input into the vector
    vector<int> array;
    string line;
    getline(cin, line);  // Read in the entire line
    stringstream ss(line);  // Create a stringstream to read from the line
    int num;
    while (ss >> num) {  // Read in integers one by one until a non-integer is encountered
        array.push_back(num);
    }

    // sort the array
    // ex: 1 3 5 4 -5 100 7777 2014
    vector<int> res = s2.sort(array);
    // print2(res);

    
    bool isFound = r.search(res, 1);
    if (isFound){
        cout<< "true ";
    }else{
        cout<< "false ";
    }
    print2(res);


    return 0;
}