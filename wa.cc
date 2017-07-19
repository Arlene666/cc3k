#include "wa.h"
#include <utility>

WA::WA():isUsable{true}, isUsed{false} {}

void WA::used(Shade &p) override{
  int &atk = p.getAtk();
  atk = max(atk-5, 0);
  isUsed = true;
}
void WA::used(Drow &p) override{
  int &atk = p.getAtk();
  atk = max(atk-7, 0);
  isUsed = true;
}
void WA::used(Vampire &p) override{
  int &atk = p.getAtk();
  atk = max(atk-5, 0);
  isUsed = true;
}
void WA::used(Troll &p) override{
  int &atk = p.getAtk();
  atk = max(atk-5, 0);
  isUsed = true;
}
void WA::used(Goblin &p) override{
  int &atk = p.getAtk();
  atk = max(atk-5, 0);
  isUsed = true;
}
