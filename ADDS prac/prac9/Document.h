#pragma once
#include <string>

class Document{
public:
    // static int count;
    int doc_id;
    std::string doc_name;
    int copy_lim;
    int borrow_cap;

    Document();
    Document(int id, std::string name, int license_lim);
    ~Document();
};