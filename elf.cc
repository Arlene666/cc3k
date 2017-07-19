#include "elf.h"

Elf::~Elf(){}

void Elf::attack(Shade &p) override{
  Enemy::attack(p);
  Enemy::attack(p);
}

void Elf::attack(Vampire &p) override{
  Enemy::attack(p);
  Enemy::attack(p);
}

void Elf::attack(Troll &p) override{
  Enemy::attack(p);
  Enemy::attack(p);
}

void Elf::attack(Goblin &p) override{
  Enemy::attack(p);
  Enemy::attack(p);
}

friend std::ostream &operator<<(std::ostream &out, Elf &e){
  out << 'E';
  return out;
}
