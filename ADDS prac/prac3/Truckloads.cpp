#include "Truckloads.h"
using namespace std;

Truckloads::Truckloads() {}

Truckloads::~Truckloads() {}

int Truckloads::numTrucks(int numCrates, int loadSize){
    if (numCrates <= loadSize){
        return 1;
    }
    int temp1 = numCrates/2;
    int temp2 = numCrates % 2? (numCrates/2 + 1): numCrates/2;
    return numTrucks(temp1, loadSize) + numTrucks(temp2, loadSize);
}
