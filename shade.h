#ifndef SHADE_H
#define SHADE_H
#include "player.h"

class Shade: public Player {
protected:
  void attackImpl(Enemy &e);
  void attackedImpl(Enemy &e);
  void useImpl(Item &i);
public:
  Shade(): Player{125, 25, 25} {}
  ~Shade();
};

#endif
