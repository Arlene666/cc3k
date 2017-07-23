#ifndef HALFLING_H
#define HALFLING_H
#include "enemyImpl.h"

class Halfling : public EnemyImpl {
protected:
  void defaultAttacked(Player &p) override;
  void attackedImpl(Vampire &p) override;
  char getCharImpl() override;
public:
  Halfling(): EnemyImpl{100, 15, 20, rand()%2+1} {}
  ~Halfling();
};

#endif
