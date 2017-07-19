#ifndef HUMAN_H
#define HUMAN_H
#include "enemy.h"

class Human : public Enemy {
public:
  Human(): Enemy{140, 20, 20} {}
  ~Human();
  void attacked(Shade &p) override;
  void attacked(Drow &p) override;
  void attacked(Vampire &p) override;
  void attacked(Troll &p) override;
  void attacked(Goblin &p) override;
  friend std::ostream &operator<<(std::ostream &out, Human &e);
};

#endif
