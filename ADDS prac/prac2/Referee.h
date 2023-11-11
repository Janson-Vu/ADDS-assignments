#pragma once
#include "Player.h"
#include "WinnerMove.h"

class Referee{
public:
    Referee();
    ~Referee();
    Player * refGame(Player * player1, Player * player2);
};