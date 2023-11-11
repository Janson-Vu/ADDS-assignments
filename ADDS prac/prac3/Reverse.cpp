#include "Reverse.h"
using namespace std;

Reverse::Reverse() {}

Reverse::~Reverse() {}

int Reverse::reverseDigit(int value){
    if (value < 0){
        return -1;
    }
    if (value == 0){
        return 0;
    }
    int temp = value % 10;
    string digits = to_string(value);
    return (temp * pow(10,digits.length()-1)) + reverseDigit(value/10);

}

std::string Reverse::reverseString(std::string characters){

    if (characters == ""){
        return "ERROR";
    }

    if (characters.length()==1){
        return characters;
    }
    char last_char = characters[characters.length()-1];
    string remains = characters.substr(0,characters.length()-1);
    return last_char + reverseString(remains);

}
