#ifndef DWARF_H
#define DWARF_H
#include "enemy.h"

class Dwarf : public Enemy {
protected:
  void attackImpl(Vampire &p) override;
public:
  Dwarf(): Player{100, 20, 30} {}
  ~Dwarf();
  friend std::ostream &operator<<(std::ostream &out, Dwarf &e);
};

#endif
