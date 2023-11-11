#include "Pirate.h"

Pirate::Pirate() {
    _name = "Pirate";
    _beat.push_back("Robot");
    _beat.push_back("Monkey");
}

Pirate::~Pirate() {}

bool Pirate::canBeat(Move* anotherMove){
    for (size_t i=0; i<_beat.size(); i++){
        if (anotherMove->getName() == _beat.at(i)){
            return true;
        }
    }
    return false;
}
