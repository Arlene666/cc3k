#include "gold.h"

void Gold::defaultUsed(Player &p){
  if(isUsable){
    p.getGold() += pile;
    isUsed = true;
  }
}

Gold::Gold(int n, bool isUsable): ItemImpl{isUsable}, pile{n} {}

char Gold::getCharImpl(){ return 'G'; }
