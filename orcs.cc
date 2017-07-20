#include "orcs.h"

Orcs::~Orcs(){}

void Orcs::attack(Goblin &p) {
  if(rand()%2 == 0){
    int damage = Enemy::damage(this->getAtk(), p.getDef()) * 3 / 2;
    int newHp = p.getHp() - damage;
    p.getHp() = (newHp >= 0)? newHp : 0;
    Object::message += getChar() + " deals " + std::to_string(damage) + " damage to PC. ";
  }
}

char Orcs::getChar(){ return 'O'; }
