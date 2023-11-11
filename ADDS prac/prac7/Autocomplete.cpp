#include "Autocomplete.h"
#include <iostream>
using namespace std;

Autocomplete::Autocomplete(){
    root = nullptr;
}

Autocomplete::~Autocomplete(){}

void Autocomplete::insert(string word){
    if (root == nullptr){
        root = new Node();
    }

    Node* curr = root;
    // loop thru the each letter of word
    for (size_t i = 0; i < word.length(); i++){

        char c = word.at(i);

        // if cannot find char 'c' in the map of children -> add it
        if (curr->children.find(c) == curr->children.end()){
            curr->children[c] = new Node(c);
        }

        // go to the child subtree starting with 'c' char
        curr = curr->children[c];
    }
    curr->is_word_end = true;
}



vector<string> Autocomplete::getSuggestions(string partialWord){

    // if tree is empty -> return empty vector
    if (root == nullptr){
        return suggests;
    }

    // Traverse to the ending letter of 'partialWord' in trie.
    // In other words, we are jumping from a node (whose map contains the corresponding letter in 'partialWord' sequence) 
    // to another node (whose map contains the next corresponding letter in 'partialWord' sequence) 
    // until we find a letter that ends with the letter ending 'partialWord'.
    // But if we cannot find any letter of 'partialWord' in trie -> return empty vector suggestion
    Node * curr = root;
    for (size_t i = 0; i < partialWord.length(); i++){
        char c = partialWord.at(i);

        // if cannot find any letters of partialWord in trie -> return empty vectors
        if (curr->children.find(c) == curr->children.end()){
            return suggests;
        }

        // go to child node that corresponds with char c of partialWord
        curr = curr->children[c];
    }

    traverse(curr, partialWord);
    return suggests;
}

// traverse from the last letter of partialWord to the node that is end of word
void Autocomplete::traverse(Node* curr, string curr_prefix){

    if (curr->is_word_end){
        suggests.push_back(curr_prefix);
    }

    // go thru all children of curr node
    for (auto child: curr->children){
        Node* next_node = child.second;
        char next_letter = child.first;

        traverse(next_node, curr_prefix + next_letter);
    }

}