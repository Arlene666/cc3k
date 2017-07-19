#ifndef DWARF_H
#define DWARF_H
#include "enemy.h"

class Dwarf : public Enemy {
public:
  Dwarf(): Enemy{100, 20, 30} {}
  void attacked(Vampire &p) override;
  ~Dwarf();
  friend std::ostream &operator<<(std::ostream &out, Dwarf &e);
};

#endif
