#include "gold.h"


Gold::Gold(int n): isUsable{false}, isUsed{false}, pile{n} {}

void Gold::used(Shade &p) override{
  if(isUsable){
    p.getGold() += pile;
    isUsed = true;
  }
}
void Gold::used(Drow &p) override{
  if(isUsable){
    p.getGold() += pile;
    isUsed = true;
  }
}
void Gold::used(Vampire &p) override{
  if(isUsable){
    p.getGold() += pile;
    isUsed = true;
  }
}
void Gold::used(Troll &p) override{
  if(isUsable){
    p.getGold() += pile;
    isUsed = true;
  }
}
void Gold::used(Goblin &p) override{
  if(isUsable){
    p.getGold() += pile;
    isUsed = true;
  }
}

std::ostream &operator<<(std::stream &out, Gold &i){
  if (i.exist()) { out << 'G'; }
  return out;
}
