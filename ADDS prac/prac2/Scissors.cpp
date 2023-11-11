#include "Scissors.h"

Scissors::Scissors() {
    _name = "Scissors";
    _beat.push_back("Paper");
}

Scissors::~Scissors() {}

bool Scissors::canBeat(Move* anotherMove){
    for (size_t i=0; i<_beat.size(); i++){
        if (anotherMove->getName() == _beat.at(i)){
            return true;
        }
    }
    return false;
}
