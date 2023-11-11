#pragma once
#include "Move.h"

class Paper: public Move{
    public:
    Paper();
    ~Paper();
    bool canBeat(Move* anotherMove);
};