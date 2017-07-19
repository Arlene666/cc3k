#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemyImpl.h"

class Merchant : public EnemyImpl {
public:
  Merchant(): EnemyImpl{30, 70, 5, 4} {}
  char getChar() override;
  ~Merchant();
};

#endif
