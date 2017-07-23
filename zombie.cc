#include "zombie.h"

void Zombie::attackImpl(Enemy &e){
  e.attacked(*this);
  getAtk() = getDfAtk() + getDfHp() - getHp();
}

void Zombie::attackedImpl(Enemy &e){
  e.attack(*this);
  getAtk() = getDfAtk() + getDfHp() - getHp();
}

void Zombie::useImpl(Item &i){
  i.used(*this);
  getAtk() = getDfAtk() + getDfHp() - getHp();
}

void Zombie::initAtkDefImpl(){
  getAtk() = getDfAtk() + getDfHp() - getHp();
  getDef() = getDfDef();
}

Zombie::~Zombie(){}
