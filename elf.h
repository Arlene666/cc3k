#ifndef ELF_H
#define ELF_H
#include "enemyImpl.h"

class Elf : public EnemyImpl {
public:
  Elf(): EnemyImpl{140, 30, 10, rand()%2+1} {}
  void attack(Shade &p) override;
  void attack(Vampire &p) override;
  void attack(Troll &p) override;
  void attack(Goblin &p) override;
  char getChar() override;
  ~Elf();
};

#endif
