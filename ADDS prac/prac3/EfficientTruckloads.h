#pragma once
#include <iostream>
#include <map>
#include <vector>

class EfficientTruckloads{
private:
    static std::map<std::vector<int>, int> calcs;
public:
    EfficientTruckloads();
    ~EfficientTruckloads();
    int numTrucks(int numCrates, int loadSize);
};