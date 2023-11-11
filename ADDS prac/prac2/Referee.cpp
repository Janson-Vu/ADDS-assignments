#include "Referee.h"

Referee::Referee(){}
Referee::~Referee(){}

Player* Referee::refGame(Player * player1, Player * player2){

    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    Move* winMove = nullptr;
    WinnerMove decideMove;
    winMove = decideMove.decideWinMove(move1, move2);

    if (winMove == move1){
        return player1;
    }else if (winMove == move2){
        return player2;
    }
    return nullptr;
    
}