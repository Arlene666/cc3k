#include "bd.h"

BD::BD(): isUsable{true}, isUsed{false} {}

void BD::used(Shade &p) override{
  p.getDef() += 5;
  isUsed = true;
}
void BD::used(Drow &p) override{
  d.getDef() += 7;
  isUsed = true;
}
void BD::used(Vampire &p) override{
  p.getDef() += 5;
  isUsed = true;
}
void BD::used(Troll &p) override{
  p.getDef() += 5;
  isUsed = true;
}
void BD::used(Goblin &p) override{
  p.getDef() += 5;
  isUsed = true;
}
