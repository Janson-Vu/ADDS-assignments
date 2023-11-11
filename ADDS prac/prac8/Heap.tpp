#ifndef HEAP_H
#define HEAP_H

#include <cmath>  // for floor()
#include <iostream>
#include <vector>

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();  // constructs an empty heap

  // constructs a heap with the values from the given vector
  // the type T MUST provide comparison operators <, >, ==
  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
};

/*******************************/
// default constructor
/*******************************/

template <typename T>
Heap<T>::Heap() {}

/*******************************/
// constructs a heap with the values in the given vector
// the type T MUST provide comparison operators <, >, ==
/*******************************/

template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
  // copy the values into our heap vector
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }

  // starting from last non-leaf node (last parent), heapify each
  // of the parents
  int initial_parent_index = floor(values.size() / 2) - 1;
  for (int parent_index = initial_parent_index; parent_index >= 0;
       parent_index--) {
    heapify(parent_index);
  }
}

/*******************************/
// add values to the heap
/*******************************/

template <typename T>
void Heap<T>::insert(T value) {
  // TO BE IMPLEMENTED
  values.push_back(value);


  int curr_index = values.size()-1;
  int parent_index = (curr_index - 1) / 2;

  // while not curr_index has not reached root & heap[i] < heap[parent]
  while (curr_index != 0 && values.at(curr_index) < values.at(parent_index)) {
    T temp = values.at(curr_index);
    values.at(curr_index) = values.at(parent_index);
    values.at(parent_index) = temp;

    curr_index = parent_index;
    parent_index = (parent_index - 1) / 2;
  }
}

/*******************************/
/* delete values from the heap */
/*******************************/

template <typename T>
void Heap<T>::remove(T value) {
  // TO BE IMPLEMENTED

  // search for the target value to be removed 
  int removed_index = -1;
  for (size_t i=0; i < values.size(); i++){
    if (values.at(i) == value){
      removed_index = i;
      //std::cout<<"removed index: "<<removed_index<<std::endl;
      break;
    }
  }

  // if cannot find any item to delete
  if (removed_index == -1){
    return;
  }

  // swap the value at removed_index with value at last_index
  int last_index = values.size()-1; 

  T temp = values.at(removed_index);
  values.at(removed_index) = values.at(last_index);
  values.at(last_index) = temp;

  // delete the back element
  values.pop_back();

  //std::cout<<"item at last index: "<<values.at(last_index)<<std::endl;
  //std::cout<<"item at removed index: (after swap) "<<values.at(removed_index)<<std::endl;

  // heapify to fix the heap
  heapify(removed_index);

}

/*******************************/
// find the smallest value in the heap
/*******************************/

template <typename T>
T Heap<T>::getMin() {
  // TO BE IMPLEMENTED
  if (values.empty()){
    return INT16_MAX;
  }
  return values.at(0); 
}

// template <typename T>
// void Heap<T>::print() {
//   for (size_t i = 0; i < values.size(); i++) {
//     std::cout << values.at(i) << std::endl;
//   }
// }

/*******************************/
// private function to heapify a given 'node'
/*******************************/

template <typename T>
void Heap<T>::heapify(int parent_index) {
  // if we're outside the index range, return
  if (parent_index < 0 || parent_index >= values.size()) {
    // std::cout <<"parent index: "<< parent_index<<std::endl;
    return;
  }

  // find children indexes
  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;

  // if parent is larger than child, swap with smallest child
  int index_of_smallest = parent_index;

  // check if left child exists and if exists, is smallest value there
  if (left_child_index < values.size() &&
      values.at(left_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = left_child_index;
  }

  // check if left child exists and if exists, is smallest value there
  if (right_child_index < values.size() &&
      values.at(right_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = right_child_index;
  }

  // if parent is not smallest, swap with smallest child
  if (index_of_smallest != parent_index) {
    T temp = values.at(parent_index);
    values.at(parent_index) = values.at(index_of_smallest);
    values.at(index_of_smallest) = temp;

    // heapify the swapped index - it may need to move
    // further down the 'tree'
    heapify(index_of_smallest);
    // std::cout<<"run"<<std::endl;
  }
}

#endif
