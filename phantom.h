#ifndef PHANTOM_H
#define PHANTOM_H
#include "player.h"

class Phantom : public Player{
protected:
  void attackImpl(Enemy &e);
  void attackedImpl(Enemy &e);
  void useImpl(Item &i);
public:
  Phantom(): Player{1, 25, 25} {}
  ~Phantom();
};

#endif
