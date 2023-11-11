#include "Ninja.h"

Ninja::Ninja() {
    _name = "Ninja";
    _beat.push_back("Pirate");
    _beat.push_back("Zombie");
}

Ninja::~Ninja() {}

bool Ninja::canBeat(Move* anotherMove){
    for (size_t i=0; i<_beat.size(); i++){
        if (anotherMove->getName() == _beat.at(i)){
            return true;
        }
    }
    return false;
}

