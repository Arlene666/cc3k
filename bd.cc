#include "bd.h"

BD::BD(): Potion{} {}

void BD::used(Shade &p){
  p.getDef() += 5;
  isUsed = true;
  Object::message += "PC uses BD";
}
void BD::used(Drow &p){
  p.getDef() += 7;
  isUsed = true;
  Object::message += "PC uses BD";
}
void BD::used(Vampire &p){
  p.getDef() += 5;
  isUsed = true;
  Object::message += "PC uses BD";
}
void BD::used(Troll &p){
  p.getDef() += 5;
  isUsed = true;
  Object::message += "PC uses BD";
}
void BD::used(Goblin &p){
  p.getDef() += 5;
  isUsed = true;
  Object::message += "PC uses BD";
}
