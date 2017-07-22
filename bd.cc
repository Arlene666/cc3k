#include "bd.h"

BD::BD(): Potion{} {}

void BD::defaultUsed(Player &p){
  p.getDef() += 5;
  isUsed = true;
  Object::message += "PC uses BD";
}
void BD::used(Drow &p){
  p.getDef() += 7;
  isUsed = true;
  Object::message += "PC uses BD";
}
