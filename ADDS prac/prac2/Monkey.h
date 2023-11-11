#pragma once
#include "Move.h"

class Monkey: public Move{
    public:
    Monkey();
    ~Monkey();
    bool canBeat(Move* anotherMove);
};
