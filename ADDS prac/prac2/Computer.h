#pragma once
#include "Player.h"
#include "Rock.h"

class Computer: public Player{
public: 
    Computer();
    ~Computer();

    Move* makeMove();
    
};