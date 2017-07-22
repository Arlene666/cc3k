#include "ph.h"

PH::PH(): Potion{} {}

void PH::defaultUsed(Player &p){
  int &Hp = p.getHp();
  Hp = std::max(Hp-10, 0);
  isUsed = true;
  Object::message += "PC uses PH.";
}

void PH::used(Drow &p){
  int &Hp = p.getHp();
  Hp = std::max(Hp-15, 0);
  isUsed = true;
  Object::message += "PC uses PH.";
}
