#ifndef GOBLIN_H
#define GOBLIN_H
#include "player.h"

class Goblin : public Player{
public:
  Goblin(): Player{110, 15, 20} {}
  void attack(Enemy &e);
  void attacked(Enemy &e);
  void use(Item &i);
  ~Goblin();
};

#endif
