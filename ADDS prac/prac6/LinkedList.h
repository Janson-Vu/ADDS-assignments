#pragma once
#include "Node.h"

class LinkedList{
private:   // ****************Remember to change to private later********************
    Node* head;
    int length;

public:
    LinkedList(); // A default constructor that creates an empty list
    LinkedList(int* array, int len); // A constructor that creates a list of from a C-array of length len
    ~LinkedList(); // A destructor that deletes all nodes from the list.

    void insertPosition(int pos, int newNum); // method to insert a new node containing the number newNum into the pos position
    // A pos of 1 (or less) places a new node at the front of the list.
    // A pos that exceeds the size of the list should add the node to the end of the list.

    bool deletePosition(int pos); // method to remove the node at position pos from the list and delete it

    int get(int pos); // method that returns the pos Node's data member variable. If pos is out-of-bounds, it should return std::numeric_limits < int >::max()

    int search(int target); // searches the list for the first occurrence of target in the list and returns the index of where target is. If target does not exist in the list, return -1.

    void printList(); // method that prints the data of all the nodes in the list, separated by spaces and encapsulated by '[' and ']'. In the case of an empty list, it prints nothing.
};