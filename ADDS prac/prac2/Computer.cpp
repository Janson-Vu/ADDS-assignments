#include "Computer.h"

Computer::Computer(): Player("Computer"){}
Computer::~Computer(){}

Move* Computer::makeMove(){
    _latest_move = new Rock();
    return _latest_move;
}