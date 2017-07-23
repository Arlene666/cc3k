#ifndef DROW_H
#define DROW_H
#include "player.h"

class Drow : public Player{
protected:
  void attackImpl(Enemy &e);
  void attackedImpl(Enemy &e);
  void useImpl(Item &i);
public:
  Drow(): Player{150, 25, 25} {}
  ~Drow();
};

#endif
