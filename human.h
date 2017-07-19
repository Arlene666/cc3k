#ifndef HUMAN_H
#define HUMAN_H
#include "enemyImpl.h"

class Human : public EnemyImpl {
public:
  Human(): EnemyImpl{140, 20, 20, 4} {}
  char getChar() override;
  ~Human();
};

#endif
