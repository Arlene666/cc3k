#include "dwarf.h"

Dwarf::~Dwarf(){}

void Dwarf::attacked(Vampire &p){
  defaultAttacked(p);
  p.getHp() = max(p.getHp()-5, 0);
}

char Dwarf::getChar(){ return 'W'; }
