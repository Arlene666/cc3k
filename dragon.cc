#include "dragon.h"

Dragon::~Dragon(){ if(g != nullptr) g->usable() = true; }

char Dragon::getCharImpl(){ return 'D'; }

void Dragon::setGold(std::shared_ptr<Gold> g, int x, int y){
  this->g = g;
  this->hX = x;
  this->hY = y;
}

void Dragon::defaultAttacked(Player &p){
  int damage = EnemyImpl::damage(p.getAtk(), this->getDef());
  this->getHp() = max(this->getHp()-damage, 0);
  if(this->getHp() <= 0) p.getGold() += this->getDrop();
  Object::message += "PC deals " + std::to_string(damage) + " damage to " +
  getChar() + " (" + std::to_string(getHp()) + " HP).";
  if(this->getHp() <= 0){
    string ws = " ";
    Object::message += ws + getChar() + " dropped the key of the Dragon hoard.";
  }
}
