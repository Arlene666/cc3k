#ifndef GOBLIN_H
#define GOBLIN_H
#include "player.h"

class Goblin : public Player{
protected:
  void attackImpl(Enemy &e);
  void attackedImpl(Enemy &e);
  void useImpl(Item &i);
public:
  Goblin(): Player{110, 15, 20} {}
  ~Goblin();
};

#endif
