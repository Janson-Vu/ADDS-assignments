#include <iostream>
#include <vector>
#include <string>
#include "Autocomplete.h"
#include "PrefixMatcher.h"
using namespace std;


int main(){

    Autocomplete a;
    a.insert("word");
    a.insert("world");
    a.insert("worship");
    a.insert("worry");
    a.insert("wow");

    vector<string> res = a.getSuggestions("wo");
    for (auto word: res){
        cout << word <<endl;
    }

    PrefixMatcher p;

    
    p.insert("110011011",2);
    p.insert("11001101",3);
    p.insert("1100110111911",1);
    p.insert("11001101119111",4);


    int route = p.selectRouter("11001101119");

    cout << route <<endl;

    // for (string str: p.suggests){
    //     cout << str <<endl;
    // }

    return 0;
}