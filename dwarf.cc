#include "dwarf.h"

Dwarf::~Dwarf(){}

void attacked(Vampire &p) override{
  int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
  this->getHp() = (newHp >= 0) newHp : 0;
  p.getHp() -= 5;
  if(this->getHp() <= 0) p.getGold() += rand()%2 + 1;
}

friend std::ostream &operator<<(std::ostream &out, Dwarf &e){
  out << 'D';
  return out;
}
