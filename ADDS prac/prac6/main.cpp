#include <iostream>
#include "LinkedList.h"
#include "BigNumCalc.h"
#include <string>
using namespace std;

int main(){

    BigNumCalc b;
    list<int> num1 = b.buildBigNum("1234");
    list<int> num2 = b.buildBigNum("0");
   
    // list<int> num = b.add(num1, num2);
    // list<int> num = b.sub(num1, num2);
    list<int> num = b.mul(num1, num2);

    list<int>::iterator it;
    for (it = num.begin(); it != num.end(); ++it){
        cout << *it<< "";
    }
    cout<<endl;


    // int array[] = {1,2,3,4,5,6};
    // LinkedList l(array, 6);
    // LinkedList l;

    // l.insertPosition(0,1);
    // l.insertPosition(0,2);
    // l.insertPosition(0,3);
    // l.insertPosition(4,4);
    // l.insertPosition(5,5);
    // l.insertPosition(6,6);
    // l.insertPosition(7,7);
    
    // l.printList();

    // l.deletePosition(7);
    // l.deletePosition(6);
    // l.deletePosition(1);
    // l.deletePosition(1);
    
    // l.insertPosition(7,7);
    // l.insertPosition(6,6);
    // l.insertPosition(2,100);
    // l.insertPosition(1,101);
    // l.insertPosition(9,102);


    // int res = l.get(9);
    // cout << res <<endl;
    // l.deletePosition(2);

    // int target = l.search(0);
    // cout <<"target: "<<target<<endl;

    // l.printList();

    //cout << "Length of list: "<<l.length <<endl;

    return 0;
}