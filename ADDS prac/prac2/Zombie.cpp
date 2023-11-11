#include "Zombie.h"

Zombie::Zombie() {
    _name = "Zombie";
    _beat.push_back("Pirate");
    _beat.push_back("Monkey");
}

Zombie::~Zombie() {}

bool Zombie::canBeat(Move* anotherMove){
    for (size_t i=0; i<_beat.size(); i++){
        if (anotherMove->getName() == _beat.at(i)){
            return true;
        }
    }
    return false;
}
