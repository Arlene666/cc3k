#ifndef GHOST_H
#define GHOST_H
#include "player.h"

class Ghost : public Player{
public:
  Ghost(): Player{1, 25, 25} {}
  void attack(Enemy &e);
  void attacked(Enemy &e);
  void use(Item &i);
  ~Ghost();
};

#endif
