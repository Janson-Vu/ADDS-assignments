#include "Paper.h"

Paper::Paper() {
    _name = "Paper";
    _beat.push_back("Rock");
}
Paper::~Paper() {}

bool Paper::canBeat(Move* anotherMove){
    for (size_t i=0; i<_beat.size(); i++){
        if (anotherMove->getName() == _beat.at(i)){
            return true;
        }
    }
    return false;
}
