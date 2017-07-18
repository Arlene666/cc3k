#ifndef HUMAN_H
#define HUMAN_H
#include "enemy.h"

class Human : public Enemy {
public:
  Human(): Player{140, 20, 20} {}
  ~Human();
  friend std::ostream &operator<<(std::ostream &out, Human &e);
};

#endif
