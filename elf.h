#ifndef ELF_H
#define ELF_H
#include "enemy.h"

class Elf : public Enemy {
public:
  Elf(): Enemy{140, 30, 10} {}
  void attack(Shade &p) override;
  void attack(Vampire &p) override;
  void attack(Troll &p) override;
  void attack(Goblin &p) override;
  ~Elf();
  friend std::ostream &operator<<(std::ostream &out, Elf &e);
};

#endif
