#include "Human.h"
using namespace std;

Human::Human(std::string name): Player(name){}
Human::Human(): Human("Human"){}
Human::~Human(){}

Move* Human::makeMove(){
    // asking user to input move (R,P,S)
    string move;
    cout << "Enter move: ";
    cin >> move;

    WhatMove decideMove;
    _latest_move = decideMove.returnMove(move);
    return _latest_move;
}



