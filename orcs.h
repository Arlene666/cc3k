#ifndef ORCS_H
#define ORCS_H
#include "enemy.h"

class Orcs : public Enemy {
protected:
  void attackImpl(Goblin &p) override;
public:
  Orcs(): Player{180, 30, 25} {}
  ~Orcs();
  friend std::ostream &operator<<(std::ostream &out, Orcs &e);
};

#endif
