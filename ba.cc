#include "ba.h"

BA::BA(): Potion{} {}

void BA::used(Shade &p){
  p.getAtk() += 5;
  isUsed = true;
  Object::message += "PC uses BA";
}
void BA::used(Drow &p){
  p.getAtk() += 7;
  isUsed = true;
  Object::message += "PC uses BA";
}
void BA::used(Vampire &p){
  p.getAtk() += 5;
  isUsed = true;
  Object::message += "PC uses BA";
}
void BA::used(Troll &p){
  p.getAtk() += 5;
  isUsed = true;
  Object::message += "PC uses BA";
}
void BA::used(Goblin &p){
  p.getAtk() += 5;
  isUsed = true;
  Object::message += "PC uses BA";
}
