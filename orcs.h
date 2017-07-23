#ifndef ORCS_H
#define ORCS_H
#include "enemyImpl.h"

class Orcs : public EnemyImpl {
protected:
  void attackImpl(Goblin &p) override;
public:
  Orcs(): EnemyImpl{180, 30, 25, rand()%2+1} {}
  char getChar() override;
  ~Orcs();
};

#endif
