#pragma once
#include <string>
#include <string.h>
#include <unordered_map>
#include <vector>

class PrefixMatcher{ // using Trie
public:
    struct Node{
        char data;
        std::unordered_map<char, Node*> children;
        int router;

        Node(){
            router = -1;
        }
        Node(char c){
            data = c;
            router = -1;
        }
        ~Node(){}
    };
    Node* root;
    std::vector<std::string> suggests;
    
    
public:
    PrefixMatcher();
    ~PrefixMatcher();
    int selectRouter(std::string networkAddress);  // return the router with the longest matching prefix
    void insert(std::string address, int routerNumber); // add a router address
    int findRemain(Node* curr, std::string prefix);
};