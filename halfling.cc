#include "halfling.h"

void Halfling::attacked(Shade &p){
  if(rand()%2 == 0){
    EnemyImpl::attacked(p);
  }else{
    Object::message += "PC missed. ";
  }
}

void Halfling::attacked(Drow &p){
  if(rand()%2 == 0){
    EnemyImpl::attacked(p);
  }else{
    Object::message += "PC missed. ";
  }
}

void Halfling::attacked(Vampire &p){
  if(rand()%2 == 0){
    EnemyImpl::attacked(p);
  }else{
    Object::message += "PC missed. ";
  }
}

void Halfling::attacked(Troll &p){
  if(rand()%2 == 0){
    defaultAttacked(p);
  }else{
    Object::message += "PC missed. ";
  }
  p.getHp() = (p.getHp() + 5 > p.getDfHp())? p.getDfHp() : p.getHp() + 5;
}

void Halfling::attacked(Goblin &p){
  if(rand()%2 == 0){
    EnemyImpl::attacked(p);;
  }else{
    Object::message += "PC missed. ";
  }
}

Halfling::~Halfling(){}

char Halfling::getChar(){ return 'L'; }
