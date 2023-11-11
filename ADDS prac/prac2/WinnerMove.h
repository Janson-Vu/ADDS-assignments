#include "Player.h"
#include "Move.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"

class WinnerMove{
public:
    WinnerMove();
    ~WinnerMove();
    Move* decideWinMove(Move* move1, Move* move2);
};