#include <iostream>
#include "Truckloads.h"
using namespace std;

int main(){

    Truckloads t;
    int n = t.numTrucks(100000000,3);
    cout << n << endl;

    return 0;
}