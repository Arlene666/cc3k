#include "elf.h"


void Elf::attackImpl(Shade &p) override{
  if(rand()%2 == 0){
    defaultAttack(p);
  }if(rand()%2 == 0){
    defaultAttack(p);
  }
}

void Elf::attackImpl(Vampire &p) override{
  if(rand()%2 == 0){
    defaultAttack(p);
  }if(rand()%2 == 0){
    defaultAttack(p);
  }
}

void Elf::attackImpl(Troll &p) override{
  if(rand()%2 == 0){
    defaultAttack(p);
  }if(rand()%2 == 0){
    defaultAttack(p);
  }
}

void Elf::attackImpl(Goblin &p) override{
  if(rand()%2 == 0){
    defaultAttack(p);
  }if(rand()%2 == 0){
    defaultAttack(p);
  }
}

Elf::~Elf(){}

friend std::ostream &operator<<(std::ostream &out, Elf &e){
  out << 'E';
  return out;
}
