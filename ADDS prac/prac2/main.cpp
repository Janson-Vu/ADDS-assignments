#include <iostream>
#include <string>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"
using namespace std;

int main(){

    Human h1("sam"), h2("fred");
    Computer c1;
    Referee r1;

    // game of: h1,c1,r1
    Player* winner = r1.refGame(&h1, &c1);
    cout << "Winner is: "<< winner -> getName()<<endl;
    cout << h1.getMove()->getName() <<endl;
    cout << c1.getMove()->getName() <<endl;

    return 0;
}

