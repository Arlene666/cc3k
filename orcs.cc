#include "orcs.h"

void Orcs::attackImpl(Goblin &p) override {
  int newHp = p.getHp() - ceiling((100/(100+p.getDef()))*this->getAtk())*3/2;
  p.getHp() = (newHp >= 0) newHp : 0;
}

Orcs::~Orcs(){}

friend std::ostream &operator<<(std::ostream &out, Orcs &e){
  out << 'O';
  return out;
}
