#include <iostream>
#include "Reverse.h"
using namespace std;

int main(){

    Reverse r;
    int res = r.reverseDigit(-4321);
    int res2 = r.reverseDigit(12345);
    cout << res <<" " << res2<< endl;

    string s = r.reverseString("");
    string s2 = r.reverseString(" glo");
    cout << s <<" "<<s2<< endl;
    
    

    return 0;
}