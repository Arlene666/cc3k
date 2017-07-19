#include "orcs.h"

Orcs::~Orcs(){}

void Orcs::attack(Goblin &p) {
  if(rand()%2 == 0){
    int newHp = p.getHp() - damage(this->getAtk(), p.getDef()) * 3 / 2;
    p.getHp() = (newHp >= 0)? newHp : 0;
  }
}

std::ostream &operator<<(std::ostream &out, Orcs &e){
  out << 'O';
  return out;
}
