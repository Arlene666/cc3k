#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemyImpl.h"

class Merchant : public EnemyImpl {
protected:
  char getCharImpl() override;
public:
  Merchant(): EnemyImpl{30, 70, 5, 4} {}
  ~Merchant();
};

#endif
