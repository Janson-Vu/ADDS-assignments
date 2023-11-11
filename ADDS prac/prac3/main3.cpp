#include <iostream>
#include "EfficientTruckloads.h"
using namespace std;

int main(){

    EfficientTruckloads et;
    int n = et.numTrucks(100000000,3);
    cout << n << endl;
    
    // Truckloads t;
    // int n2 = t.numTrucks(1000000,3);
    // cout << n2 << endl;
    

    return 0;
}