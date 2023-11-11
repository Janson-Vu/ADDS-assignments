#pragma once
#include <string>
#include <vector>

class Move{
protected:
    std::string _name;
    std::vector<std::string> _beat;
public:
    Move();
    ~Move();
    std::string getName();
    virtual bool canBeat(Move* anotherMove);
};