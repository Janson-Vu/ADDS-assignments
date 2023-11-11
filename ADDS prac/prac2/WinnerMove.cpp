#include "WinnerMove.h"

WinnerMove::WinnerMove() {}

WinnerMove::~WinnerMove() {}

Move* WinnerMove::decideWinMove(Move* move1, Move* move2){
    if (move1->canBeat(move2)){
        return move1;
    }else if (move2->canBeat(move1)){
        return move2;
    }
    return nullptr;
    
}
