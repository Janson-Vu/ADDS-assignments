#include <string>
#include "Move.h"
#include "Rock.h"
#include "Scissors.h"
#include "Paper.h"
#include "Monkey.h"
#include "Robot.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"

class WhatMove{
    public:
    WhatMove();
    ~WhatMove();
    Move* returnMove(std::string move);
};