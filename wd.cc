#include "wd.h"
#include <utility>

WD::WD():isUsable{true}, isUsed{false} {}

void WD::used(Shade &p) override{
  int &def = p.getDef();
  def = max(def-5, 0);
  isUsed = true;
}
void WD::used(Drow &p) override{
  int &def = p.getDef();
  def = max(def-7, 0);
  isUsed = true;
}
void WD::used(Vampire &p) override{
  int &def = p.getDef();
  def = max(def-5, 0);
  isUsed = true;
}
void WD::used(Troll &p) override{
  int &def = p.getDef();
  def = max(def-5, 0);
  isUsed = true;
}
void WD::used(Goblin &p) override{
  int &def = p.getDef();
  def = max(def-5, 0);
  isUsed = true;
}
