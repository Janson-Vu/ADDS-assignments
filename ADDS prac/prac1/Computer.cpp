#include "Computer.h"

Computer::Computer(): Player("Computer"){}
Computer::~Computer(){}

char Computer::makeMove(){
    _latest_move = 'R';
    return _latest_move;
}