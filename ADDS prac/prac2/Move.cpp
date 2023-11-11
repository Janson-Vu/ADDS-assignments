#include "Move.h"
using namespace std;


Move::Move() {}

Move::~Move(){}

string Move::getName(){
    return _name;
}

bool Move::canBeat(Move* anotherMove){
    return true;
}