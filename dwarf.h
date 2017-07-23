#ifndef DWARF_H
#define DWARF_H
#include "enemyImpl.h"

class Dwarf : public EnemyImpl {
protected:
  void attackedImpl(Vampire &p) override;
  char getCharImpl() override;
public:
  Dwarf(): EnemyImpl{100, 20, 30, rand()%2+1} {}
  ~Dwarf();
};

#endif
