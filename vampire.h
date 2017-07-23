#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"

class Vampire : public Player{
protected:
  void attackImpl(Enemy &e);
  void attackedImpl(Enemy &e);
  void useImpl(Item &i);
public:
  Vampire(): Player{50, 25, 25} {}
  ~Vampire();
};

#endif
