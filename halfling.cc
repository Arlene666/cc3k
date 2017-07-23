#include "halfling.h"

void Halfling::defaultAttacked(Player &p){
  if(rand()%2 == 0){
    defaultAttackedImpl(p);
  }else{
    Object::message += "PC missed.";
  }
}

void Halfling::attackedImpl(Vampire &p){
  if(rand()%2 == 0){
    defaultAttackedImpl(p);
    p.getHp() += 5;
  }else{
    Object::message += "PC missed.";
  }
}

char Halfling::getCharImpl(){ return 'L'; }

Halfling::~Halfling(){}
