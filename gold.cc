#include "gold.h"

void Gold::usedDefault(Player &p){
  if(isUsable){
    p.getGold() += pile;
    isUsed = true;
  }
}

Gold::Gold(int n, bool isUsable): Item{isUsable}, pile{n} {}

char Gold::getChar(){ return 'G'; }
