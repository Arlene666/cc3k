#include "wd.h"

WD::WD(): Potion{} {}

void WD::used(Shade &p){
  int &def = p.getDef();
  def = std::max(def-5, 0);
  isUsed = true;
}
void WD::used(Drow &p){
  int &def = p.getDef();
  def = std::max(def-7, 0);
  isUsed = true;
}
void WD::used(Vampire &p){
  int &def = p.getDef();
  def = std::max(def-5, 0);
  isUsed = true;
}
void WD::used(Troll &p){
  int &def = p.getDef();
  def = std::max(def-5, 0);
  isUsed = true;
}
void WD::used(Goblin &p){
  int &def = p.getDef();
  def = std::max(def-5, 0);
  isUsed = true;
}
