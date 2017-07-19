#include "wa.h"

WA::WA(): Potion{} {}

void WA::used(Shade &p){
  int &atk = p.getAtk();
  atk = std::max(atk-5, 0);
  isUsed = true;
}
void WA::used(Drow &p){
  int &atk = p.getAtk();
  atk = std::max(atk-7, 0);
  isUsed = true;
}
void WA::used(Vampire &p){
  int &atk = p.getAtk();
  atk = std::max(atk-5, 0);
  isUsed = true;
}
void WA::used(Troll &p){
  int &atk = p.getAtk();
  atk = std::max(atk-5, 0);
  isUsed = true;
}
void WA::used(Goblin &p){
  int &atk = p.getAtk();
  atk = std::max(atk-5, 0);
  isUsed = true;
}
