#include "player.h"

void Player::initAtkDefImpl(){
  atk = initAtk;
  def = initDef;
}

//*****public methods*************

void Player::attack(Enemy &e){
  attackImpl(e);
}

void Player::attacked(Enemy &e){
  attackedImpl(e);
}

void Player::use(Item &i){
  useImpl(i);
}

void Player::initAtkDef(){ initAtkDefImpl(); }
bool Player::isDead(){ return hp <= 0; }

int &Player::getHp() { return hp; }
int &Player::getAtk() { return atk; }
int &Player::getDef() { return def; }
int &Player::getGold() { return gold; }
int Player::getDfHp() const { return initHp; }
int Player::getDfAtk() const { return initAtk; }
int Player::getDfDef() const { return initDef; }

Player::~Player(){}
