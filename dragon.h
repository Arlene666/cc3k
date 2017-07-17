#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"

class Dragon : public Enemy {
public:
  Dragon(): Player{150, 20, 20} {}
  ~Dragon();
  friend std::ostream &operator<<(std::stream &out, Dragon &e);
};

#endif
