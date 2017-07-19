#include "enemy.h"
#include <cstdlib>
#include <cmath>

//*********private methods**********************************

int Enemy::damage(int atk, int def){
  return ceil((100/(100+def))*atk);
}

//********public methods***********************************

void Enemy::attack(Shade &p){
  if(rand()%2 == 0){
    int newHp = p.getHp() - damage(this->getAtk(), p.getDef());
    p.getHp() = (newHp >= 0) newHp : 0;
  }
}

void Enemy::attack(Drow &p){
  if(rand()%2 == 0){
    int newHp = p.getHp() - damage(this->getAtk(), p.getDef());
    p.getHp() = (newHp >= 0) newHp : 0;
  }
}

void Enemy::attack(Vampire &p){
  if(rand()%2 == 0){
    int newHp = p.getHp() - damage(this->getAtk(), p.getDef());
    p.getHp() = (newHp >= 0) newHp : 0;
  }
}

void Enemy::attack(Troll &p){
  if(rand()%2 == 0){
    int newHp = p.getHp() - damage(this->getAtk(), p.getDef());
    p.getHp() = (newHp >= 0) newHp : 0;
  }
}

void Enemy::attack(Goblin &p){
  if(rand()%2 == 0){
    int newHp = p.getHp() - damage(this->getAtk(), p.getDef()));
    p.getHp() = (newHp >= 0) newHp : 0;
  }
}


void Enemy::attacked(Shade &p){
  int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
  this->getHp() = (newHp >= 0) newHp : 0;
  if(this->getHp() <= 0) p.getGold() += rand()%2 + 1;
}

void Enemy::attacked(Drow &p){
  int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
  this->getHp() = (newHp >= 0) newHp : 0;
  if(this->getHp() <= 0) p.getGold() += rand()%2 + 1;
}

void Enemy::attacked(Vampire &p){
  int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
  this->getHp() = (newHp >= 0) newHp : 0;
  p.getHp() += 5;
  if(this->getHp() <= 0) p.getGold() += rand()%2 + 1;
}

void Enemy::attacked(Troll &p){
  int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
  this->getHp() = (newHp >= 0) newHp : 0;
  p.getHp() = (p.getHp() + 5 > p.getDfHp())? p.getDfHp() : p.getHp() + 5;
  if(this->getHp() <= 0) p.getGold() += rand()%2 + 1;
}

void Enemy::attacked(Goblin &p){
  int newHp = this->getHp() - damage(p.getAtk(), this->getDef());
  this->getHp() = (newHp >= 0) newHp : 0;
  if(this->getHp() <= 0) p.getGold() += rand()%2 + 1;
  if(this->getHp() <= 0) p.getGold() += 5;
}


bool Enemy::exist(){
  return hp > 0;
}
