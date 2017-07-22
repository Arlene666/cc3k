#include "zombie.h"

void Zombie::attack(Enemy &e){
  e.attacked(*this);
  getAtk() = getDfAtk() + getDfHp() - getHp();
}

void Zombie::attacked(Enemy &e){
  e.attack(*this);
  getAtk() = getDfAtk() + getDfHp() - getHp();
}

void Zombie::use(Item &i){
  i.used(*this);
  getAtk() = getDfAtk() + getDfHp() - getHp();
}

void Zombie::initAtkDef(){
  getAtk() = getDfAtk() + getDfHp() - getHp();
  getDef() = getDfDef();
}

Zombie::~Zombie(){}
