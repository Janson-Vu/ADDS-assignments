#pragma once
#include "Move.h"

class Scissors: public Move{
    public:
    Scissors();
    ~Scissors();
    bool canBeat(Move* anotherMove);
};