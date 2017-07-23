#ifndef ALIEN_H
#define ALIEN_H
#include "enemyImpl.h"

class Alien : public EnemyImpl {
protected:
  void defaultAttack(Player &p) override;
  char getCharImpl() override;
public:
  Alien(): EnemyImpl{100, 15, 40, rand()%2+1} {}
  ~Alien();
};

#endif
