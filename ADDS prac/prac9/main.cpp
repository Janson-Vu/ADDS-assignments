#include "DocumentManager.h"
#include <iostream>
using namespace std;

int main(){
    
    DocumentManager m;
    m.addDocument("Doc1", 1, 3);
    m.addDocument("Doc2", 2, 3);
    // m.addDocument("Doc2", 2, 3);

    m.addPatron(1);
    // m.addPatron(1);
    m.addPatron(2);
    m.addPatron(3);

    m.printDocument();
    //m.printPatron();

    cout << "try to borrow Doc1 result: "<<m.borrowDocument(1,1) <<endl;
    cout << "try to borrow Doc1 result: "<<m.borrowDocument(1,2) <<endl;
    cout << "try to borrow Doc1 result: "<<m.borrowDocument(1,3) <<endl;

    m.printDocument();
    cout << "try to borrow Doc1 result: "<<m.borrowDocument(1,3) <<endl;

    m.returnDocument(1,1);
    m.returnDocument(1,1);
    m.returnDocument(1,2);
    m.returnDocument(1,3);

    m.printDocument();

    m.printBorrow();


    return 0;
}