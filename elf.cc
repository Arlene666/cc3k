#include "elf.h"

void Elf::defaultAttack(Player &p){
  defaultAttackImpl(p);
  defaultAttackImpl(p);
}

void Elf::attackImpl(Drow &p){
  defaultAttackImpl(p);
}

char Elf::getCharImpl(){ return 'E'; }

Elf::~Elf(){}
