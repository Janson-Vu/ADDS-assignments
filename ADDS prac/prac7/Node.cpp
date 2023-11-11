#include "Node.h"

Node::Node(){
    c = '\0';
    is_word_end = false;
}

Node::Node(char letter){
    c = letter;
    is_word_end = false;
}

Node::~Node(){}

