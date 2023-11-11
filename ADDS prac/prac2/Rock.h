#pragma once
#include "Move.h"

class Rock: public Move{
    public:
    Rock();
    ~Rock();
    bool canBeat(Move* anotherMove);
};