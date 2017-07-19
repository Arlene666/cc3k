#include "rh.h"
#include <utility>

RH::RH():isUsable{true}, isUsed{false} {}

void RH::used(Shade &p) override{
  int &hp = p.getHp();
  hp = max(hp+10, p.getDfHp());
  isUsed = true;
}
void RH::used(Drow &p) override{
  int &hp = p.getHp();
  hp = max(hp+15, p.getDfHp());
  isUsed = true;
}
void RH::used(Vampire &p) override{
  int &hp = p.getHp();
  hp = max(hp+10, p.getDfHp());
  isUsed = true;
}
void RH::used(Troll &p) override{
  int &hp = p.getHp();
  hp = max(hp+10, p.getDfHp());
  isUsed = true;
}
void RH::used(Goblin &p) override{
  int &hp = p.getHp();
  hp = max(hp+10, p.getDfHp());
  isUsed = true;
}
