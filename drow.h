#ifndef DROW_H
#define DROW_H
#include "player.h"

class Drow : public Player{
public:
  Drow(): Player{150, 25, 25} {}
  void attack(Enemy &e);
  void attacked(Enemy &e);
  void use(Item &i);
  ~Drow();
};

#endif
