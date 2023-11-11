#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

#include "Document.h"
#include "Patron.h"

class DocumentManager {
 public:
  std::unordered_map<std::string, Document*> document_dict_name;
  std::unordered_map<int, Document*> document_dict_id;
  std::unordered_map<int, int> borrow_list; // key: patronID, value: docid 
  std::unordered_map<int, Patron*> patron_dict;

 public:
  DocumentManager();
  ~DocumentManager();
  void addDocument(std::string name, int id, int license_limit);

  void addPatron(int patronID);

  int search(std::string name); // returns docid if name is in the document collection or 0
                                // if the name is not in the collection

  bool borrowDocument(int docid, int patronID); // returns true if document is borrowed, false if it can
                                                // not be borrowed (invalid patronid or the number of
                                                // copies current borrowed has reached the license limit)

  void returnDocument(int docid, int patronID);

  void printDocument();
  void printPatron();
  void printBorrow();
};