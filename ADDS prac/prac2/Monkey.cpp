#include "Monkey.h"

Monkey::Monkey() {
    _name = "Monkey";
    _beat.push_back("Ninja");
    _beat.push_back("Robot");
}

Monkey::~Monkey() {}

bool Monkey::canBeat(Move* anotherMove){
    for (size_t i=0; i<_beat.size(); i++){
        if (anotherMove->getName() == _beat.at(i)){
            return true;
        }
    }
    return false;
}
