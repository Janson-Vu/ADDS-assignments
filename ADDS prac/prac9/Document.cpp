#include "Document.h"
using namespace std;

// int Document::count = 0;

Document::Document(){
    doc_id = 0;
    doc_name = "No name";
    copy_lim = 0;
    borrow_cap = copy_lim;
}

Document::Document(int id, string name, int license_lim){
    doc_id = id;
    doc_name = name;
    copy_lim = license_lim;
    borrow_cap = copy_lim;
}

Document::~Document(){}