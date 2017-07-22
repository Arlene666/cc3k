#ifndef PHANTOM_H
#define PHANTOM_H
#include "player.h"

class Phantom : public Player{
public:
  Phantom(): Player{1, 25, 25} {}
  void attack(Enemy &e);
  void attacked(Enemy &e);
  void use(Item &i);
  ~Phantom();
};

#endif
