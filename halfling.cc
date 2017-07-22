#include "halfling.h"

void Halfling::defaultAttacked(Player &p){
  if(rand()%2 == 0){
    defaultAttackedImpl(p);
  }else{
    Object::message += "PC missed.";
  }
}

void Halfling::attacked(Vampire &p){
  if(rand()%2 == 0){
    defaultAttackedImpl(p);
    p.getHp() += 5;
  }else{
    Object::message += "PC missed.";
  }
}

Halfling::~Halfling(){}

char Halfling::getChar(){ return 'L'; }
