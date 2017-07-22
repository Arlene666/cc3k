#include "wd.h"

WD::WD(): Potion{} {}

void WD::defaultUsed(Player &p){
  int &def = p.getDef();
  def = std::max(def-5, 0);
  isUsed = true;
  Object::message += "PC uses WD";
}
void WD::used(Drow &p){
  int &def = p.getDef();
  def = std::max(def-7, 0);
  isUsed = true;
  Object::message += "PC uses WD";
}
