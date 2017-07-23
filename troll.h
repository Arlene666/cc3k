#ifndef TROLL_H
#define TROLL_H
#include "player.h"

class Troll : public Player{
protected:
  void attackImpl(Enemy &e);
  void attackedImpl(Enemy &e);
  void useImpl(Item &i);
public:
  Troll(): Player{120, 25, 15} {}
  ~Troll();
};

#endif
