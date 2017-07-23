#ifndef ELF_H
#define ELF_H
#include "enemyImpl.h"

class Elf : public EnemyImpl {
protected:
  void defaultAttack(Player &p) override;
  void attackImpl(Drow &p) override;
public:
  Elf(): EnemyImpl{140, 30, 10, rand()%2+1} {}
  char getChar() override;
  ~Elf();
};

#endif
