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

char Gold::getChar(){ return 'G'; }
