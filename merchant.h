#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy.h"

class Merchant : public Enemy {
public:
  Merchant(): Player{30, 70, 5} {}
  ~Merchant();
  void defaultAttacked(Player &p) override;
  friend std::ostream &operator<<(std::ostream &out, Merchant &e);
};

#endif
