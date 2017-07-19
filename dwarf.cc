#include "dwarf.h"

Dwarf::~Dwarf(){}

void Dwarf::attacked(Vampire &p){
  defaultAttacked(p);
  p.getHp() -= 5;
}

std::ostream &operator<<(std::ostream &out, Dwarf &e){
  out << 'D';
  return out;
}
