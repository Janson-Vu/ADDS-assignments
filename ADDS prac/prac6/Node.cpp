#include "Node.h"
#include <stddef.h>
#include <iostream>
using namespace std;

Node::Node(){
    link = nullptr;
}

Node::~Node(){
    cout <<"Node deleted: "<< data<<endl;
}