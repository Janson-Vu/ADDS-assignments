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
    Player* winner = r1.refGame(&c1, &h1);
    cout << "Winner is: "<< winner -> getName()<<endl;

    bool r_s = 'R' < 'S';
    bool s_p = 'S' > 'P';
    bool p_r = 'P' < 'R';

    cout << r_s <<" "<<s_p<< " "<<p_r<<endl;
 

    return 0;
}

