#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"

class Vampire : public Player{
public:
  Vampire(): Player{50, 25, 25} {}
  void attack(Enemy &e);
  void attacked(Enemy &e);
  void use(Item &i);
  ~Vampire();
};

#endif
