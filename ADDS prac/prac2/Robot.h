#pragma once
#include "Move.h"

class Robot: public Move{
    public:
    Robot();
    ~Robot();
    bool canBeat(Move* anotherMove);
};