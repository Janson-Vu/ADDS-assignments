#include "WhatMove.h"
using namespace std;

WhatMove::WhatMove() {}

WhatMove::~WhatMove() {}

Move* WhatMove::returnMove(string move){
    if (move == "Rock"){
        return new Rock();
    }else if (move == "Paper"){
        return new Paper();
    }else if (move == "Scissors"){
        return new Scissors();
    }else if (move == "Monkey"){
        return new Monkey();
    }else if (move == "Robot"){
        return new Robot();
    }else if (move == "Ninja"){
        return new Ninja();
    }else if (move == "Pirate"){
        return new Pirate();
    }
    return new Zombie();
}