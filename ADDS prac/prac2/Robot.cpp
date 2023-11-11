#include "Robot.h"

Robot::Robot() {
    _name = "Robot";
    _beat.push_back("Ninja");
    _beat.push_back("Zombie");    
}

Robot::~Robot() {}

bool Robot::canBeat(Move* anotherMove){
    for (size_t i=0; i<_beat.size(); i++){
        if (anotherMove->getName() == _beat.at(i)){
            return true;
        }
    }
    return false;
}
