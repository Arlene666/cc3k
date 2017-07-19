#ifndef HUMAN_H
#define HUMAN_H
#include "enemy.h"

class Human : public Enemy {
public:
  Human(): Enemy{140, 20, 20} {}
  ~Human();
  void defaultAttacked(Player &p) override;
  friend std::ostream &operator<<(std::ostream &out, Human &e);
};

#endif
