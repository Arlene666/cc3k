#ifndef DWARF_H
#define DWARF_H
#include "enemyImpl.h"

class Dwarf : public EnemyImpl {
public:
  Dwarf(): EnemyImpl{100, 20, 30, rand()%2+1} {}
  void attacked(Vampire &p) override;
  ~Dwarf();
  friend std::ostream &operator<<(std::ostream &out, Dwarf &e);
};

#endif
