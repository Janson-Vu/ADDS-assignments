#include "LinkedList.h"
#include <iostream>
#include <limits>
using namespace std;

LinkedList::LinkedList(){
    head = nullptr;
    length = 0;
}

LinkedList::~LinkedList(){
    if (head == nullptr){
        return;
    }

    Node * curr = head;
    Node * new_node = curr->link;
    head = new_node;
    length--;
    delete curr;

    while (curr != nullptr && length > 1){
        curr = head;
        new_node = curr->link;
        head = new_node;
        length--;

        delete curr;
    }
    if (length == 1){
        delete head;
        length--;
    }
}

void LinkedList::insertPosition(int pos, int newNum){
    // create new node
    Node* new_node = new Node;
    new_node->data = newNum;

    // if list is empty (insert at head same as insert at tail)
    if (head == nullptr){
        head = new_node;
        length++;
        return;
    }

    // if list has at least 1 node (not empty)

    // if insert at head
    if (pos <= 1){
        new_node -> link = head;
        head = new_node;
        length++;
        return;
    }

    // if insert at  1 < pos < length
    if (pos > 1 && pos <= length){
        int index = 1;
        Node* prev = head;

        // get the previous node before pos (aka pos-1 node)
        while(prev != nullptr && index < pos-1){
            prev = prev->link;
            index++;
        }
        
        Node* pos_node = prev->link;
        prev->link = new_node;
        new_node->link = pos_node;
        length++;
        return;
    }

    // if insert at tail
    if (pos > length){
        Node* curr = head;

        // traverse to tail node
        while (curr -> link != nullptr){
            curr = curr->link;
        }

        // update tail node to point to new_node
        curr -> link = new_node;
        length++;
        return;
    }
}

bool LinkedList::deletePosition(int pos){

    // if pos is over bound
    if (pos > length || pos < 1){
        return false;
    }

    // delete head node case
    if (pos == 1){
        Node* curr = head;
        head = curr -> link;
        delete curr;
        length--;
        return true;
    }

    // delete middle node and last node case
    if (pos > 1 && pos <= length){
        int index = 1;
        Node* prev = head;

        // get the previous node before pos (aka pos-1 node)
        while(prev != nullptr && index < pos-1){
            prev = prev->link;
            index++;
        }
        
        Node* pos_node = prev->link;
        prev->link = pos_node->link;
        delete pos_node;
        length--;
        return true;    
    }

    return false; 
}

int LinkedList::get(int pos){

    if (pos > length || pos < 1){
        return std::numeric_limits < int >::max();
    }

    int index = 1;
    Node* curr = head;

    // get the node at pos 
    while(curr != nullptr && index < pos){
        curr = curr->link;
        index++;
    }

    // cout << curr -> data<<endl;
    return curr->data;
}

int LinkedList::search(int target){
    Node* curr = head;
    int index = 1;

    while (curr != nullptr){
        if (curr -> data == target){
            return index;
        }
        curr = curr->link;
        index++;
    }
    return -1;
}


LinkedList::LinkedList(int* array, int len){
    head = nullptr;
    length = 0;
    for (int i=0; i<len; i++){
        insertPosition(len+1, array[i]);
    }
}

void LinkedList::printList(){
    if (head == nullptr){
        return;
    }

    Node* curr = head;

    cout << "[";
    while(curr != nullptr){
        cout << curr -> data <<" ";
        curr = curr -> link;
    }
    cout<<"]"<<endl;
}

