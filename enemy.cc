#include "enemy.h"


// public methods

void Enemy::attack(Player &p){
  attackImpl(p);
}

void Enemy::attacked(Player &p){
  attackImpl(p);
}

bool Enemy::isDead(){
  return hp <= 0;
}


// protected methods

void Enemy::defaultAttack(Player &p){
  int newHp = p.getHp() - ceiling((100/(100+p.getDef()))*this->getAtk());
  p.getHp() = (newHp >= 0) newHp : 0;
}

virtual void Enemy::attackImpl(Shade &p){
  if(rand()%2 == 0){
    defaultAttack(p);
  }
}

virtual void Enemy::attackImpl(Drow &p){
  if(rand()%2 == 0){
    defaultAttack(p);
  }
}

virtual void Enemy::attackImpl(Vampire &p){
  if(rand()%2 == 0){
    defaultAttack(p);
  }
}

virtual void Enemy::attackImpl(Troll &p){
  if(rand()%2 == 0){
    defaultAttack(p);
  }
}

virtual void Enemy::attackImpl(Goblin &p){
  if(rand()%2 == 0){
    defaultAttack(p);
  }
}


void Enemy::defaultAttacked(Player &p){
  this->getHp() -= ceiling((100/(100+this->getDef()))*p.getAtk());
}

virtual void Enemy::attackedImpl(Shade &p){
  defaultAttacked(p);
}

virtual void Enemy::attackedImpl(Drow &p){
  defaultAttacked(p);
}

virtual void Enemy::attackedImpl(Vampire &p){
  defaultAttacked(p);
  p.getHp += 5;
}

virtual void Enemy::attackedImpl(Troll &p){
  defaultAttacked(p);
  p.getHp = (p.getHp + 5 > 120)? 120 : p.getHp + 5;
}

virtual void Enemy::attackedImpl(Goblin &p){
  defaultAttacked(p);
  if(this->isDead()) p.getGold() += 5;
}
