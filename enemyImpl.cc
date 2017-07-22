#include "enemyImpl.h"

int EnemyImpl::damage(float atk, float def){
  return ceil((100/(100+def))*atk);
}

void EnemyImpl::defaultAttack(Player &p){
  if(rand()%2 == 0){
    int damage = damage(this->getAtk(), p.getDef());
    int newHp = p.getHp() - damage;
    p.getHp() = (newHp >= 0)? newHp : 0;
    string ws = " ";
    Object::message += ws + getChar() + " deals " + std::to_string(damage) + " damage to PC.";
  }else{
    string ws = " ";
    Object::message += ws + getChar() + " missed.";
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

void EnemyImpl::attack(Zombie &p){
  defaultAttack(p);
}

void EnemyImpl::defaultAttacked(Player &p){
  int damage = damage(p.getAtk(), this->getDef());
  int newHp = this->getHp() - damage;
  this->getHp() = (newHp >= 0)? newHp : 0;
  if(this->getHp() <= 0) p.getGold() += this->getDrop();
  Object::message += "PC deals " + std::to_string(damage) + " damage to " +
  getChar() + " (" + std::to_string(getHp()) + " HP).";
  if(this->getHp() <= 0){
    string ws = " ";
    Object::message += ws + getChar() + " dropped " +
    std::to_string(this->getDrop()) + " gold.";
  }
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
}

void EnemyImpl::attacked(Goblin &p){
  defaultAttacked(p);
  if(this->getHp() <= 0) p.getGold() += 5;
}

void EnemyImpl::attacked(Ghost &p){
  defaultAttacked(p);
}

void EnemyImpl::attacked(Zombie &p){
  defaultAttacked(p);
}
