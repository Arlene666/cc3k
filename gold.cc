#include "gold.h"

Gold::Gold(int n, bool isUsable): Item{isUsable}, pile{n} {}

void Gold::used(Shade &p){
  if(isUsable){
    p.getGold() += pile;
    isUsed = true;
  }
}
void Gold::used(Drow &p){
  if(isUsable){
    p.getGold() += pile;
    isUsed = true;
  }
}
void Gold::used(Vampire &p){
  if(isUsable){
    p.getGold() += pile;
    isUsed = true;
  }
}
void Gold::used(Troll &p){
  if(isUsable){
    p.getGold() += pile;
    isUsed = true;
  }
}
void Gold::used(Goblin &p){
  if(isUsable){
    p.getGold() += pile;
    isUsed = true;
  }
}

std::ostream &operator<<(std::ostream &out, Gold &i){
  if (i.exist()) { out << 'G'; }
  return out;
}
