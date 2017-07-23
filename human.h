#ifndef HUMAN_H
#define HUMAN_H
#include "enemyImpl.h"

class Human : public EnemyImpl {
protected:
  char getCharImpl() override;
public:
  Human(): EnemyImpl{140, 20, 20, 4} {}
  ~Human();
};

#endif
