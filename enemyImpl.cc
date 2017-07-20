#include "enemyImpl.h"

void EnemyImpl::defaultAttack(Player &p){
  if(rand()%2 == 0){
    int damage = Enemy::damage(this->getAtk(), p.getDef());
    int newHp = p.getHp() - damage;
    p.getHp() = (newHp >= 0)? newHp : 0;
    Object::message += getChar() + " deals " + std::to_string(damage) + " damage to PC. ";
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
  int damage = Enemy::damage(p.getAtk(), this->getDef());
  int newHp = this->getHp() - damage;
  this->getHp() = (newHp >= 0)? newHp : 0;
  if(this->getHp() <= 0) p.getGold() += this->getDrop();
  Object::message += "PC deals " + std::to_string(damage) + " damage to " +
  getChar() + " (" + std::to_string(getHp()) + " HP). ";
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
