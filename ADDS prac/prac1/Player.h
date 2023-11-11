#pragma once
#include <string>

class Player {
 protected:
  std::string _name;
  char _latest_move;

 public:
  Player(std::string name);
  Player();
  virtual char makeMove() = 0;
  char getMove();
  std::string getName();
  ~Player();
};