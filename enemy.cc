#include "enemy.h"

void Enemy::attack(Shade &p){ attackImpl(p); }
void Enemy::attack(Drow &p){ attackImpl(p); }
void Enemy::attack(Vampire &p){ attackImpl(p); }
void Enemy::attack(Troll &p){ attackImpl(p); }
void Enemy::attack(Goblin &p){ attackImpl(p); }
void Enemy::attack(Phantom &p){ attackImpl(p); }
void Enemy::attack(Zombie &p){ attackImpl(p); }
void Enemy::attacked(Shade &p){ attackedImpl(p); }
void Enemy::attacked(Drow &p){ attackedImpl(p); }
void Enemy::attacked(Vampire &p){ attackedImpl(p); }
void Enemy::attacked(Troll &p){ attackedImpl(p); }
void Enemy::attacked(Goblin &p){ attackedImpl(p); }
void Enemy::attacked(Phantom &p){ attackedImpl(p); }
void Enemy::attacked(Zombie &p){ attackedImpl(p); }

bool Enemy::existImpl(){
  return hp > 0;
}

Enemy::~Enemy(){}
