#include "elf.h"

Elf::~Elf(){}

void Elf::attack(Shade &p){
  EnemyImpl::attack(p);
  EnemyImpl::attack(p);
}

void Elf::attack(Vampire &p){
  EnemyImpl::attack(p);
  EnemyImpl::attack(p);
}

void Elf::attack(Troll &p){
  EnemyImpl::attack(p);
  EnemyImpl::attack(p);
}

void Elf::attack(Goblin &p){
  EnemyImpl::attack(p);
  EnemyImpl::attack(p);
}

char Elf::getChar(){ return 'E'; }
