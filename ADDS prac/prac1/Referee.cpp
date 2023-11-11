#include "Referee.h"

Referee::Referee(){}
Referee::~Referee(){}

Player* Referee::refGame(Player * player1, Player * player2){

    // Make the move
    char player1_move = player1->makeMove();
    char player2_move = player2->makeMove();
    
    // Human vs Computer ends in draw
    if (player1_move == player2_move){
        return nullptr;
    }

    // One wins, one loses

    // Paper vs Rock, Scissors
    if (player1_move == 'P' && player2_move == 'S' ){
        return player2;
    }else if (player1_move == 'P' && player2_move == 'R'){
        return player1;
    }else if (player2_move == 'P' && player1_move == 'R'){
        return player2;
    }else if (player2_move == 'P' && player1_move == 'S'){
        return player1;
    }

    // Rock vs Scissors
    Player *  winner = player1_move < player2_move? player1 : player2;
    return winner;
}