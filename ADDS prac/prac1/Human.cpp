#include "Human.h"

Human::Human(std::string name): Player(name){}
Human::Human(): Human("Human"){}
Human::~Human(){}

char Human::makeMove(){
    // asking user to input move (R,P,S)
    char move;
    std::cout << "Enter move: ";
    std::cin >> move;

    _latest_move = move;
    return _latest_move;
}



