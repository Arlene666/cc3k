#ifndef HALFLING_H
#define HALFLING_H
#include "enemy.h"

class Halfling : public Enemy {
protected:
  void attackedImpl(Shade &p);
  void attackedImpl(Drow &p);
  void attackedImpl(Vampire &p);
  void attackedImpl(Troll &p);
  void attackedImpl(Goblin &p);
public:
  Halfling(): Player{100, 15, 20} {}
  ~Halfling();
  friend std::ostream &operator<<(std::ostream &out, Halfling &e);
};

#endif
