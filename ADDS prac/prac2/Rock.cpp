#include "Rock.h"
using namespace std;

Rock::Rock() {
    _name = "Rock";
    _beat.push_back("Scissors");
}
Rock::~Rock(){}

bool Rock::canBeat(Move* anotherMove){
    for (size_t i=0; i<_beat.size(); i++){
        if (anotherMove->getName() == _beat.at(i)){
            return true;
        }
    }
    return false;
}