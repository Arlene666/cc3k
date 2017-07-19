#ifndef TROLL_H
#define TROLL_H
#include "player.h"

class Troll : public Player{
public:
  Troll(): Player{120, 25, 15} {}
  void attack(Enemy &e);
  void attacked(Enemy &e);
  void use(Item &i);
  ~Troll();
};

#endif
