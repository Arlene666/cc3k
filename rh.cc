#include "rh.h"

RH::RH(): Potion{} {}

void RH::used(Shade &p){
  int &hp = p.getHp();
  hp = std::max(hp+10, p.getDfHp());
  isUsed = true;
  Object::message += "PC uses RH";
}
void RH::used(Drow &p){
  int &hp = p.getHp();
  hp = std::max(hp+15, p.getDfHp());
  isUsed = true;
  Object::message += "PC uses RH";
}
void RH::used(Vampire &p){
  int &hp = p.getHp();
  hp = std::max(hp+10, p.getDfHp());
  isUsed = true;
  Object::message += "PC uses RH";
}
void RH::used(Troll &p){
  int &hp = p.getHp();
  hp = std::max(hp+10, p.getDfHp());
  isUsed = true;
  Object::message += "PC uses RH";
}
void RH::used(Goblin &p){
  int &hp = p.getHp();
  hp = std::max(hp+10, p.getDfHp());
  isUsed = true;
  Object::message += "PC uses RH";
}
