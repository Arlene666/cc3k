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

void EnemyImpl::attackImpl(Shade &p){
  defaultAttack(p);
}

void EnemyImpl::attackImpl(Drow &p){
  defaultAttack(p);
}

void EnemyImpl::attackImpl(Vampire &p){
  defaultAttack(p);
}

void EnemyImpl::attackImpl(Troll &p){
  defaultAttack(p);
}

void EnemyImpl::attackImpl(Goblin &p){
  defaultAttack(p);
}

void EnemyImpl::attackImpl(Phantom &p){
  string ws = " ";
  Object::message += ws + getChar() + " missed.";
}


void EnemyImpl::attackImpl(Zombie &p){
  defaultAttack(p);
}


void EnemyImpl::attackedImpl(Shade &p){
  defaultAttacked(p);
}

void EnemyImpl::attackedImpl(Drow &p){
  defaultAttacked(p);
}

void EnemyImpl::attackedImpl(Vampire &p){
  defaultAttacked(p);
  p.getHp() += 5;
}

void EnemyImpl::attackedImpl(Troll &p){
  defaultAttacked(p);
}

void EnemyImpl::attackedImpl(Goblin &p){
  defaultAttacked(p);
  if(this->getHp() <= 0) p.getGold() += 5;
}

void EnemyImpl::attackedImpl(Phantom &p){
  defaultAttacked(p);
}

void EnemyImpl::attackedImpl(Zombie &p){
  defaultAttacked(p);
}

EnemyImpl::~EnemyImpl(){}
