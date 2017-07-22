#include "zombie.h"

void Zombie::attack(Enemy &e){ e.attacked(*this); }
void Zombie::attacked(Enemy &e){
  e.attack(*this);
  getAtk() = getDfAtk + getDfHp() - getHp();
}
void Zombie::use(Item &i){ i.used(*this); }

Zombie::~Zombie(){}
