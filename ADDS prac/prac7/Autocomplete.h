#pragma once
#include <string>
#include <vector>
#include "Node.h"

class Autocomplete{
private:
    Node* root;
    std::vector<std::string> suggests;

public:
    Autocomplete();
    ~Autocomplete();

    void insert(std::string word); // add a word to the known words
    std::vector<std::string> getSuggestions(std::string partialWord);  // return the known words that start with partialWord
    void traverse(Node* curr, std::string prefix);
};