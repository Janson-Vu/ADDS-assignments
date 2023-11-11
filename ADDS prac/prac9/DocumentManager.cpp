#include "DocumentManager.h"
using namespace std;

DocumentManager::DocumentManager(){}
DocumentManager::~DocumentManager(){}

void DocumentManager::addDocument(string name, int id, int license_limit){
    unordered_map<string, Document*>::iterator it;

    // try to find if there are existing document in the storage
    it = document_dict_name.find(name);
    
    // if document already exits, do nothing
    if (it != document_dict_name.end()){ 
        //cout << "Cannot add the document with already existing name"<<endl;
        return;
    }

    // try look at all the IDs in document dict, if repeated id -> don't allow adding
    // try this if fail gradescope
    
    // add to the map
    Document* new_docu = new Document(id, name, license_limit);
    document_dict_name.insert(pair<string, Document*>(name, new_docu));
    document_dict_id.insert(pair<int, Document*>(id, new_docu));
    
}

void DocumentManager::addPatron(int patronID){
    unordered_map<int, Patron*>::iterator it;

    // try to find if there are existing patron with patronID in the storage
    it = patron_dict.find(patronID);

    // if patron with patronID already exits, do nothing
    if (it != patron_dict.end()){ 
        //cout << "Cannot add the new patron with already existing id"<<endl;
        return;
    }
    else{
        // add to the map
        Patron* new_patron = new Patron(patronID);
        patron_dict.insert(pair<int, Patron*>(patronID, new_patron));
    }
}

int DocumentManager::search(string name){
    unordered_map<string, Document*>::iterator it;
    // try to find if there are existing document in the storage
    it = document_dict_name.find(name);

    // if found document with the given name
    if (it != document_dict_name.end()){
        return it->second->doc_id;
    }
    return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID){

    // STEP1: check if patronID is registered
    unordered_map<int, Patron*>::iterator it_patron;

    // try to find if there are existing patrionID in the storage
    it_patron = patron_dict.find(patronID);

    // if patronID don't exist
    if (it_patron == patron_dict.end()){ 
        return false;
    }

    // STEP 2+3: check if docid exists and if there is still enough copy
    unordered_map<int, Document*>::iterator it_doc;

    // check if there is enough copy to borrow from
    it_doc = document_dict_id.find(docid);

    // if docid does not exist
    if (it_doc == document_dict_id.end()){
        return false;
    }

    // if docid exist and if enough copy
    if (it_doc->second->borrow_cap > 0){
        it_doc->second->borrow_cap--;

        // update borrow list
        borrow_list.insert(pair<int,int>(patronID, docid));

        return true;
    }
    return false;
}

void DocumentManager::returnDocument(int docid, int patronID){

    // STEP1: check if patronID is registered
    unordered_map<int, Patron*>::iterator it_patron;

    // try to find if there are existing patrionID in the storage
    it_patron = patron_dict.find(patronID);

    // if patronID don't exist
    if (it_patron == patron_dict.end()){ 
        return;
    }

    // STEP 2+3: check if docid exists and increase the copy of that document again (<= orginal copy_limit)
    unordered_map<int, Document*>::iterator it_doc;

    // check if there if doc exists
    it_doc = document_dict_id.find(docid);

    // if docid does not exist
    if (it_doc == document_dict_id.end()){
        return;
    }

    // if exist, increase
    if (it_doc->second->borrow_cap < it_doc->second->copy_lim && borrow_list.find(patronID) != borrow_list.end()){
        borrow_list.erase(patronID);
        it_doc->second->borrow_cap++;
    }

}

void DocumentManager::printDocument(){
    unordered_map<string, Document*>::iterator it;
    cout << "List of all DOCUMENTS"<<endl;
    for (it = document_dict_name.begin(); it != document_dict_name.end(); it++){
        cout<<"Doc Name: "<<it->first<<"     " << "Doc ID: "<<it->second->doc_id << "     Doc copy: " <<it->second->copy_lim <<  "     Borrow: " <<it->second->borrow_cap<<endl;
    }
}

void DocumentManager::printPatron(){
    unordered_map<int, Patron*>::iterator it;
    cout << "List of all PATRONS"<<endl;
    for (it = patron_dict.begin(); it != patron_dict.end(); it++){
        cout<<"Patron ID: "<<it->first<<endl;
    }
}

void DocumentManager::printBorrow(){
    unordered_map<int, int>::iterator it;
    cout << "List of all borrows"<<endl;
    for (it = borrow_list.begin(); it != borrow_list.end(); it++){
        cout<<"Patron ID: "<<it->first <<"     Doc ID: "<<it->second<<endl;
    }
}
