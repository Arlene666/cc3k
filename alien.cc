#include "alien.h"

Alien::~Alien(){}

void Alien::defaultAttack(Player &p){
  if(rand()%2 == 0){
    int damage = EnemyImpl::damage(this->getAtk(), p.getDef());
    p.getHp() = max(p.getHp()-damage, 0);
    p.getDef() = max(p.getDef()-1, 0);
    string ws = " ";
    Object::message += ws + getChar() + " deals " + std::to_string(damage) + " damage to PC.";
  }else{
    string ws = " ";
    Object::message += ws + getChar() + " missed.";
  }
}

char Alien::getChar(){ return 'A'; }
