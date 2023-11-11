#pragma once
#include "Sort.h"

class QuickSort: public Sort{
private:
    void sort_helper(std::vector<int>& list, int start, int end);
public:
    std::vector<int> sort(std::vector<int> list);
};