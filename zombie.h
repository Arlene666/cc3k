#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "player.h"

class Zombie : public Player{
protected:
  void attackImpl(Enemy &e);
  void attackedImpl(Enemy &e);
  void useImpl(Item &i);
  void initAtkDefImpl() override;
public:
  Zombie(): Player{100, 10, 10} {}
  ~Zombie();
};

#endif
