#include "halfling.h"

void Halfling::attacked(Shade &p) override{
  if(rand()%2 == 0){
    Enemy::attack(p);
  }
}

void Halfling::attacked(Drow &p) override{
  if(rand()%2 == 0){
    Enemy::attack(p);
  }
}

void Halfling::attacked(Vampire &p) override{
  if(rand()%2 == 0){
    Enemy::attack(p);
  }
}

void Halfling::attacked(Troll &p) override{
  if(rand()%2 == 0){
    int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
    this->getHp() = (newHp >= 0) newHp : 0;
  }
  p.getHp() = (p.getHp() + 5 > p.getDfHp())? p.getDfHp() : p.getHp() + 5;
  if(this->getHp() <= 0) p.getGold() += rand()%2 + 1;
}

void Halfling::attacked(Goblin &p) override{
  if(rand()%2 == 0){
    Enemy::attack(p);;
  }
}

Halfling::~Halfling(){}

friend std::ostream &operator<<(std::ostream &out, Halfling &e){
  out << 'L';
  return out;
}
