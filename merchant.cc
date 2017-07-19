#include "merchant.h"

Merchant::~Merchant(){}

void Merchant::attacked(Shade &p) override{
  int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
  this->getHp() = (newHp >= 0) newHp : 0;
  if(this->getHp() <= 0) p.getGold() += 4;
}

void Merchant::attacked(Drow &p) override{
  int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
  this->getHp() = (newHp >= 0) newHp : 0;
  if(this->getHp() <= 0) p.getGold() += 4;
}

void Merchant::attacked(Vampire &p) override{
    int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
    this->getHp() = (newHp >= 0) newHp : 0;
    p.getHp() += 5;
    if(this->getHp() <= 0) p.getGold() += 4;
}

void Merchant::attacked(Troll &p) override{
  int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
  this->getHp() = (newHp >= 0) newHp : 0;
  p.getHp() = (p.getHp() + 5 > p.getDfHp())? p.getDfHp() : p.getHp() + 5;
  if(this->getHp() <= 0) p.getGold() += 4;
}

void Merchant::attacked(Goblin &p) override{
  int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
  this->getHp() = (newHp >= 0) newHp : 0;
  if(this->getHp() <= 0) p.getGold() += 5;
  if(this->getHp() <= 0) p.getGold() += 4;
}

friend std::ostream &operator<<(std::ostream &out, Merchant &e){
  out << 'M';
  return out;
}
