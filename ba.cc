#include "ba.h"

BA::BA(): Potion{} {}

void BA::defaultUsed(Player &p){
  p.getAtk() += 5;
  isUsed = true;
  Object::message += "PC uses BA.";
}

void BA::used(Drow &p){
  p.getAtk() += 7;
  isUsed = true;
  Object::message += "PC uses BA.";
}
