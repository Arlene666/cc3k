#include "dwarf.h"

void Dwarf::attackedImpl(Vampire &p){
  defaultAttacked(p);
  p.getHp() = max(p.getHp()-5, 0);
}

Dwarf::~Dwarf(){}

char Dwarf::getChar(){ return 'W'; }
