#pragma once
#include "Move.h"

class Zombie: public Move{
    public:
    Zombie();
    ~Zombie();
    bool canBeat(Move* anotherMove);
};