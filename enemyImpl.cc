#include "enemyImpl.h"

void EnemyImpl::defaultAttack(Player &p){
  if(rand()%2 == 0){
    int newHp = p.getHp() - damage(this->getAtk(), p.getDef());
    p.getHp() = (newHp >= 0)? newHp : 0;
  }
}

void EnemyImpl::attack(Shade &p){
  defaultAttack(p);
}

void EnemyImpl::attack(Drow &p){
  defaultAttack(p);
}

void EnemyImpl::attack(Vampire &p){
  defaultAttack(p);
}

void EnemyImpl::attack(Troll &p){
  defaultAttack(p);
}

void EnemyImpl::attack(Goblin &p){
  defaultAttack(p);
}

void EnemyImpl::defaultAttacked(Player &p){
  int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
  this->getHp() = (newHp >= 0)? newHp : 0;
  if(this->getHp() <= 0) p.getGold() += this->getDrop();
}

void EnemyImpl::attacked(Shade &p){
  defaultAttacked(p);
}

void EnemyImpl::attacked(Drow &p){
  defaultAttacked(p);
}

void EnemyImpl::attacked(Vampire &p){
  defaultAttacked(p);
  p.getHp() += 5;
}

void EnemyImpl::attacked(Troll &p){
  defaultAttacked(p);
  p.getHp() = (p.getHp() + 5 > p.getDfHp())? p.getDfHp() : p.getHp() + 5;
}

void EnemyImpl::attacked(Goblin &p){
  defaultAttacked(p);
  if(this->getHp() <= 0) p.getGold() += 5;
}
