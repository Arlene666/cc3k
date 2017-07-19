#ifndef ORCS_H
#define ORCS_H
#include "enemyImpl.h"

class Orcs : public EnemyImpl {
public:
  Orcs(): EnemyImpl{180, 30, 25, rand()%2+1} {}
  void attack(Goblin &p) override;
  ~Orcs();
  friend std::ostream &operator<<(std::ostream &out, Orcs &e);
};

#endif
