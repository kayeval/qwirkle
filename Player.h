
#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>
#include "LinkedList.h"

class Player {
  LinkedList* tiles;
  std::string name;
  int points;

 public:
  Player(std::string name, int points);
  ~Player();
  std::string getName();
  void setPoints(int points);
  int getPoints();
  LinkedList* getTiles();
};

#endif  // ASSIGN2_PLAYER_H
