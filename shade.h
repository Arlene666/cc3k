#ifndef SHADE_H
#define SHADE_H
#include "player.h"

class Shade: public Player {
public:
  Shade(): Player{125, 25, 25} {}
  void attack(Enemy &e);
  void attacked(Enemy &e);
  void use(Item &i);
  ~Shade();
};

#endif
