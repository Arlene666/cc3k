#include "player.h"

void Player::initAtkDef(){
  atk = initAtk;
  def = initDef;
}
bool Player::isDead(){ return hp <= 0; }

int &Player::getHp() { return hp; }
int &Player::getAtk() { return atk; }
int &Player::getDef() { return def; }
int &Player::getGold() { return gold; }
int Player::getDfHp() const { return initHp; }
