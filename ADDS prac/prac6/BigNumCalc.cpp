#include "BigNumCalc.h"
#include <iostream>
using namespace std;

BigNumCalc::BigNumCalc(){}

BigNumCalc::~BigNumCalc(){}

list<int> BigNumCalc::buildBigNum(string numString){
    list<int> seq;
    for (unsigned int i=0; i<numString.length(); i++){
        if (i == 0 && numString[i] == '0'){
            continue;
        }
        int num = numString[i] - '0';
        seq.push_back(num);
    }
    return seq;
}

list<int> BigNumCalc::add(list<int> num1, list<int> num2){

    list<int> result;
    int remain = 0;

    while(!num1.empty() || !num2.empty() || remain != 0){

        int res = remain;

        if (!num1.empty()){
            int digit1 = num1.back();
            num1.pop_back();
            res += digit1;
        }   
        if (!num2.empty()){
            int digit2 = num2.back();
            num2.pop_back();
            res += digit2;
        }    
        result.push_front(res % 10);
        remain = res / 10;

    }    

    return result;
}

list<int> BigNumCalc::sub(list<int> num1, list<int> num2){

    list<int> result;
    int getmore = 0;

    while (!num1.empty() || !num2.empty() || getmore != 0){

        int diff = getmore;
        int digit1 = 0, digit2 = 0;

        if (!num1.empty()){
            digit1 = num1.back();
            num1.pop_back();
        }

        if (!num2.empty()){
            digit2 = num2.back();
            num2.pop_back();
        }

        diff += digit1 - digit2;
  
        if (diff < 0){
            diff += 10;
            getmore = -1;
        }else{
            getmore = 0;
        }

        result.push_front(diff);
    }

    while(!result.empty() && result.front() == 0){
            result.pop_front();
    }
        if (result.empty()){
            result.push_back(0);
    }
    return result;
}

list<int> BigNumCalc::mul(list<int> num1, list<int> num2){
    list<int> result;

    if (num2.back() ==  0){
        result.push_back(0);
        return result;
    }

    int remain = 0;

    int digit2 = num2.back();
    num2.pop_back();

    while (!num1.empty() || remain != 0){
        int res = remain;
        int digit1 = 0;

        if (!num1.empty()){
            digit1 = num1.back();
            num1.pop_back();
        }

        res += digit2 * digit1;

        result.push_front(res % 10);
        remain = res / 10;

    }
    return result;
}

