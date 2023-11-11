#include "PrefixMatcher.h"
#include <string.h>
#include <iostream>
using namespace std;

PrefixMatcher::PrefixMatcher(){
    root = nullptr;
}

PrefixMatcher::~PrefixMatcher(){}

void PrefixMatcher::insert(string address, int routerNumber){

    // if trie is empty
    if (root == nullptr){
        root = new Node();
    }

    Node* curr = root;
    for (size_t i=0; i < address.length(); i++){
        char c = address.at(i);
        if (curr->children.find(c) == curr->children.end()){
            curr->children[c] = new Node(c);
        }
        curr = curr->children[c];
    }
    curr->router = routerNumber;
}

int PrefixMatcher::selectRouter(string networkAddress){
    // if trie is empty
    if (root == nullptr){
        return -1;
    }

    Node* curr = root;
    int router = -1;
    for (size_t i=0; i < networkAddress.length(); i++){
        char c = networkAddress.at(i);
        if (curr->children.count(c) == 0){
            break;
        }
        curr = curr->children[c];
        if (curr->router != -1){
            router = curr->router;
        } 
    }

    // networkAddress shorter than the longest path of try, keep exploring until find the next closest route 
    if (!curr->children.empty()){
        router = findRemain(curr, networkAddress);
    }
    return router;
}

int PrefixMatcher::findRemain(Node* curr, string curr_prefix){

    int router = -1;
    // if (curr->router != -1 && curr->children.empty()) -> get further result than router 1
    if (curr->router != -1){
        router = curr->router;
        return router;
    }

    // go thru all children of curr node
    for (auto child: curr->children){
        Node* next_node = child.second;
        char next_letter = child.first;
        router = findRemain(next_node, curr_prefix + next_letter);
    }

    return router;
    
}