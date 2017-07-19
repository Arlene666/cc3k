#include "ba.h"

BA::BA():isUsable{true}, isUsed{false} {}

void BA::used(Shade &p) override{
  p.getAtk() += 5;
  isUsed = true;
}
void BA::used(Drow &p) override{
  d.getAtk() += 7;
  isUsed = true;
}
void BA::used(Vampire &p) override{
  p.getAtk() += 5;
  isUsed = true;
}
void BA::used(Troll &p) override{
  p.getAtk() += 5;
  isUsed = true;
}
void BA::used(Goblin &p) override{
  p.getAtk() += 5;
  isUsed = true;
}
