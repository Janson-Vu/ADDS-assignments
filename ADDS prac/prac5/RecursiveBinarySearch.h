#pragma once
#include <vector>

class RecursiveBinarySearch{
private:
    int search_helper(std::vector<int>& array, int target, int start, int end);
public:
    bool search(std::vector<int>, int);
};