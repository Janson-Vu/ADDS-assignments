#include "EfficientTruckloads.h"
using namespace std;

map<vector<int>, int> EfficientTruckloads::calcs{};

EfficientTruckloads::EfficientTruckloads() {}

EfficientTruckloads::~EfficientTruckloads() {}

int EfficientTruckloads::numTrucks(int numCrates, int loadSize){

    // create a vector to be added to map (if needed)
    vector<int> params;
    params.push_back(numCrates);
    params.push_back(loadSize);

    // create a map
    map<vector<int>, int>::iterator it;

    // lookup values
    it = calcs.find(params);
    // if found
    if (it != calcs.end()){
        return it->second;
    }
    // base case & haven't found existing parameters
    if (numCrates <= loadSize){
        calcs.insert({params,1});
        return 1;
    }
    
    int temp1 = numCrates/2;
    int temp2 = numCrates % 2? (numCrates/2 + 1): numCrates/2;
    int num = numTrucks(temp1, loadSize) + numTrucks(temp2, loadSize);

    calcs.insert({params,num});

    return num;
}
