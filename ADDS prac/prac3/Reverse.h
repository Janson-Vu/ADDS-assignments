#pragma once
#include <string>
#include <iostream>
#include <math.h>

class Reverse{
public:
    Reverse();
    ~Reverse();
    int reverseDigit(int value);
    std::string reverseString(std::string characters);
};