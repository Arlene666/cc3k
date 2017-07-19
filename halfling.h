#ifndef HALFLING_H
#define HALFLING_H
#include "enemy.h"

class Halfling : public Enemy {
public:
  Halfling(): Enemy{100, 15, 20} {}
  void attacked(Shade &p) override;
  void attacked(Drow &p) override;
  void attacked(Vampire &p) override;
  void attacked(Troll &p) override;
  void attacked(Goblin &p) override;
  ~Halfling();
  friend std::ostream &operator<<(std::ostream &out, Halfling &e);
};

#endif
