#include "dwarf.h"

void Dwarf::attackImpl(Player &p) override{
  defaultAttacked(p);
  p.getHp -= 5;
}

Dwarf::~Dwarf(){}

friend std::ostream &operator<<(std::stream &out, Dwarf &e){
  out << 'D';
  return out;
}
