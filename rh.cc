#include "rh.h"

RH::RH(): Potion{} {}

void RH::defaultUsed(Player &p){
  int &hp = p.getHp();
  hp = std::max(hp+10, p.getDfHp());
  isUsed = true;
  Object::message += "PC uses RH.";
}

void RH::usedImpl(Drow &p){
  int &hp = p.getHp();
  hp = std::max(hp+15, p.getDfHp());
  isUsed = true;
  Object::message += "PC uses RH.";
}
