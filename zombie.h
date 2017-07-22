#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "player.h"

class Zombie : public Player{
public:
  Zombie(): Player{100, 10, 10} {}
  void attack(Enemy &e);
  void attacked(Enemy &e);
  void use(Item &i);
  void initAtkDef() override;
  ~Zombie();
};

#endif
