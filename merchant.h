#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemyImpl.h"

class Merchant : public EnemyImpl {
public:
  Merchant(): EnemyImpl{30, 70, 5, 4} {}
  ~Merchant();
  friend std::ostream &operator<<(std::ostream &out, Merchant &e);
};

#endif
