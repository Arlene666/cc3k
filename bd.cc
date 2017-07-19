#include "bd.h"

BD::BD(): Potion{} {}

void BD::used(Shade &p){
  p.getDef() += 5;
  isUsed = true;
}
void BD::used(Drow &p){
  p.getDef() += 7;
  isUsed = true;
}
void BD::used(Vampire &p){
  p.getDef() += 5;
  isUsed = true;
}
void BD::used(Troll &p){
  p.getDef() += 5;
  isUsed = true;
}
void BD::used(Goblin &p){
  p.getDef() += 5;
  isUsed = true;
}
