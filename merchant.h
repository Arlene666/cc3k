#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy.h"

class Merchant : public Enemy {
public:
  Merchant(): Player{30, 70, 5} {}
  ~Merchant();
  friend std::ostream &operator<<(std::stream &out, Merchant &e);
};

#endif
