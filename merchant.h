#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy.h"

class Merchant : public Enemy {
public:
  Merchant(): Enemy{30, 70, 5} {}
  ~Merchant();
  void attacked(Shade &p) override;
  void attacked(Drow &p) override;
  void attacked(Vampire &p) override;
  void attacked(Troll &p) override;
  void attacked(Goblin &p) override;
  friend std::ostream &operator<<(std::ostream &out, Merchant &e);
};

#endif
