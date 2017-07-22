#include "enemyImpl.h"

int EnemyImpl::damage(float atk, float def){
  return ceil((100/(100+def))*atk);
}

void EnemyImpl::defaultAttackImpl(Player &p){
  if(rand()%2 == 0){
    int damage = EnemyImpl::damage(this->getAtk(), p.getDef());
    p.getHp() = max(p.getHp()-damage, 0);
    string ws = " ";
    Object::message += ws + getChar() + " deals " + std::to_string(damage) + " damage to PC.";
  }else{
    string ws = " ";
    Object::message += ws + getChar() + " missed.";
  }
}

void EnemyImpl::defaultAttackedImpl(Player &p){
  int damage = EnemyImpl::damage(p.getAtk(), this->getDef());
  this->getHp() = max(this->getHp()-damage, 0);
  if(this->getHp() <= 0) p.getGold() += this->getDrop();
  Object::message += "PC deals " + std::to_string(damage) + " damage to " +
  getChar() + " (" + std::to_string(getHp()) + " HP).";
  if(this->getHp() <= 0){
    string ws = " ";
    Object::message += ws + getChar() + " dropped " +
    std::to_string(this->getDrop()) + " gold.";
  }
}

void EnemyImpl::defaultAttack(Player &p){
  defaultAttackImpl(p);
}

void EnemyImpl::defaultAttacked(Player &p){
  defaultAttackedImpl(p);
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

void EnemyImpl::attacked(Phantom &p){
  defaultAttacked(p);
}

void EnemyImpl::attacked(Zombie &p){
  defaultAttacked(p);
}
