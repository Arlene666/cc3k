#include "elf.h"

Elf::~Elf(){}

void Elf::defaultAttack(Player &p){
  defaultAttackImpl(p);
  defaultAttackImpl(p);
}

void Elf::attackImpl(Drow &p){
  defaultAttackImpl(p);
}

char Elf::getChar(){ return 'E'; }
