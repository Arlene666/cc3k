#include "halfling.h"

void Halfling::attacked(Shade &p){
  if(rand()%2 == 0){
    EnemyImpl::attack(p);
  }
}

void Halfling::attacked(Drow &p){
  if(rand()%2 == 0){
    EnemyImpl::attack(p);
  }
}

void Halfling::attacked(Vampire &p){
  if(rand()%2 == 0){
    EnemyImpl::attack(p);
  }
}

void Halfling::attacked(Troll &p){
  if(rand()%2 == 0){
    defaultAttacked(p);
  }
  p.getHp() = (p.getHp() + 5 > p.getDfHp())? p.getDfHp() : p.getHp() + 5;
}

void Halfling::attacked(Goblin &p){
  if(rand()%2 == 0){
    EnemyImpl::attack(p);;
  }
}

Halfling::~Halfling(){}

char Halfling::getChar(){ return 'L'; }
