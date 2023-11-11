#pragma once
#include <string>
#include "Move.h"

class Player {
 protected:
  std::string _name;
  Move* _latest_move;

 public:
  Player(std::string name);
  Player();
  virtual Move* makeMove() = 0;
  Move* getMove();
  std::string getName();
  ~Player();
};