#include "Finder.h"
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int main(){

    Finder find;
    vector<int> result = find.findSubstrings("4634554567","45689");

    for (size_t i=0; i<result.size(); i++){
        cout <<result[i]<<endl;
    }

    // string s2 = "1234";
    // cout << s2.substr(0,2)<<endl;


    return 0;
}