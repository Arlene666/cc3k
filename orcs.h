#ifndef ORCS_H
#define ORCS_H
#include "enemy.h"

class Orcs : public Enemy {
public:
  Orcs(): Enemy{180, 30, 25} {}
  void attack(Goblin &p) override;
  ~Orcs();
  friend std::ostream &operator<<(std::ostream &out, Orcs &e);
};

#endif
