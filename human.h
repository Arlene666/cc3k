#ifndef HUMAN_H
#define HUMAN_H
#include "enemyImpl.h"

class Human : public EnemyImpl {
public:
  Human(): EnemyImpl{140, 20, 20, 4} {}
  ~Human();
  friend std::ostream &operator<<(std::ostream &out, Human &e);
};

#endif
