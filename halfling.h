#ifndef HALFLING_H
#define HALFLING_H
#include "enemyImpl.h"

class Halfling : public EnemyImpl {
public:
  Halfling(): EnemyImpl{100, 15, 20, rand()%2+1} {}
  void attacked(Shade &p) override;
  void attacked(Drow &p) override;
  void attacked(Vampire &p) override;
  void attacked(Troll &p) override;
  void attacked(Goblin &p) override;
  char getChar() override;
  ~Halfling();
};

#endif
