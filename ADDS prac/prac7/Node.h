#pragma once
#include <unordered_map>

class Node{
private:
    friend class Autocomplete;
    char c;
    std::unordered_map<char, Node*> children;
    bool is_word_end;
public:

    Node();
    Node(char letter);
    ~Node();
};