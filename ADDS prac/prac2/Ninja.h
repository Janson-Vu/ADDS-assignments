#pragma once
#include "Move.h"

class Ninja: public Move{
    public:
    Ninja();
    ~Ninja();
    bool canBeat(Move* anotherMove);
};