#ifndef HUMAN_H
#define HUMAN_H
#include "enemy.h"

class Human : public Enemy {
public:
  Human(): Player{140, 20, 20} {}
  ~Human();
  void attackedImpl(Shade &p) override;
  void attackedImpl(Drow &p) override;
  void attackedImpl(Vampire &p) override;
  void attackedImpl(Troll &p) override;
  void attackedImpl(Goblin &p) override;
  friend std::ostream &operator<<(std::ostream &out, Human &e);
};

#endif
