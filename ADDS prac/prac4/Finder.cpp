#include "Finder.h"

#include <iostream>
using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
  vector<int> result;

  // take care of the first character and other characters onwward
  // Iterate over s2 with length of m takes: O(m) (length of s2)
  string curr;
  for (size_t i = 0; i <= s2.size()-1; i++) {
    // appending the result to the result array takes O(1)
    if ( result.size() > 0 && result.back() == -1) {
      result.push_back(-1);
      continue;
    }

    // appending each new characrer to the current string is now O(1)
    curr += s2.at(i);
    // cout << curr << endl;

    // looking up for subtring now takes log(n) 
    // since we just start looking at the index that has the pattern instead of the whole string
    size_t found;
    if (result.size() > 0){
        found = s1.find(curr, result.back());
    }else{
        found = s1.find(curr);
    }


    // appending the result to the result array takes O(1)
    if (found != string::npos) {
      result.push_back(found);
    } else {
      result.push_back(-1);
    }
  }
  return result;
}

/*
    Time complexity of algorightm is O(m*n)
*/
