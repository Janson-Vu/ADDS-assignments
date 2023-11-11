#include "Player.h"

Player::Player(std::string name){
    _name = name;
    _latest_move = new Move();
}

Move* Player::getMove(){
    return _latest_move;
}

std::string Player::getName(){
    return _name;
}

Player::Player(){}
Player::~Player(){}