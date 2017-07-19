#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"

class Dragon : public Enemy {
public:
  Dragon(): Enemy{150, 20, 20} {}
  ~Dragon();
  friend std::ostream &operator<<(std::ostream &out, Dragon &e);
};

#endif
