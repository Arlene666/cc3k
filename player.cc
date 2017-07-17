#include "player.h"


void Player::attack(Enemy &e){ e.attacked(*this); }
void Player::attacked(Enemy &e){ e.attack(*this); }
void Player::use(Item &i){ i.used(*this); }

void initAtkDef(){
  atk = initAtk;
  def = initDef;
}
bool isDead(){ return hp <= 0; }

int &Player::getHp() const { return hp; }
int &Player::getAtk() const { return atk; }
int &Player::getDef() const { return def; }
int &Player::getGold() const { return gold; }
int Player::getDfHP() const { return initHp; }

friend std::ostream &operator<<(std::stream &out, Player &p){
  out << '@';
  return out;
}
