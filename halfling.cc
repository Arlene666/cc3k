#include "halfling.h"

void Halfling::attackedImpl(Shade &p){
  if(rand()%2 == 0){
    defaultAttacked(p);
  }
}

void Halfling::attackedImpl(Drow &p){
  if(rand()%2 == 0){
    defaultAttacked(p);
  }
}

void Halfling::attackedImpl(Vampire &p){
  if(rand()%2 == 0){
    defaultAttacked(p);
    p.getHp += 5;
  }
}

void Halfling::attackedImpl(Troll &p){
  if(rand()%2 == 0){
    defaultAttacked(p);
  }
  p.getHp = (p.getHp + 5 > 120)? 120 : p.getHp + 5;
}

void Halfling::attackedImpl(Goblin &p){
  if(rand()%2 == 0){
    defaultAttacked(p);
  }
  if(this->isDead()) p.getGold() += 5;
}

Halfling::~Halfling(){}

friend std::ostream &operator<<(std::stream &out, Halfling &e){
  out << 'L';
  return out;
}
