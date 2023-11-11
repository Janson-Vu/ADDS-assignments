#pragma once
#include "Move.h"

class Pirate: public Move{
    public:
    Pirate();
    ~Pirate();
    bool canBeat(Move* anotherMove);
};