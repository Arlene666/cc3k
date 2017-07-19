#ifndef DRAGON_H
#define DRAGON_H
#include "enemyImpl.h"

class Dragon : public EnemyImpl {
public:
  Dragon(): EnemyImpl{150, 20, 20, 0} {}
  char getChar() override;
  ~Dragon();
};

#endif
