#include "dwarf.h"

Dwarf::~Dwarf(){}

void Dwarf::attacked(Vampire &p){
  defaultAttacked(p);
  p.getHp() -= 5;
}

char Dwarf::getChar(){ return 'W'; }
