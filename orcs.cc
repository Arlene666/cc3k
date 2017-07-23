#include "orcs.h"

Orcs::~Orcs(){}

void Orcs::attackImpl(Goblin &p) {
  if(rand()%2 == 0){
    int damage = EnemyImpl::damage(this->getAtk(), p.getDef()) * 3 / 2;
    p.getHp() = max(p.getHp()-damage, 0);
    string ws = " ";
    Object::message += ws + getChar() + " deals " + std::to_string(damage) + " damage to PC.";
  }else{
    string ws = " ";
    Object::message += ws + getChar() + " missed.";
  }
}

char Orcs::getChar(){ return 'O'; }
