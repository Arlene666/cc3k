#include "ph.h"
#include <utility>

PH::PH():isUsable{true}, isUsed{false} {}

void PH::used(Shade &p) override{
  int &hp = p.getHP();
  hp = max(hp-10, 0);
  isUsed = true;
}

void PH::used(Drow &p) override{
  int &hp = p.getHP();
  hp = max(hp-15, 0);
  isUsed = true;
}

void PH::used(Vampire &p) override{
  int &hp = p.getHP();
  hp = max(hp-10, 0);
  isUsed = true;
}

void PH::used(Troll &p) override{
  int &hp = p.getHP();
  hp = max(hp-10, 0);
  isUsed = true;
}

void PH::used(Goblin &p) override{
  int &hp = p.getHP();
  hp = max(hp-10, 0);
  isUsed = true;
}
