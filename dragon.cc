#include "dragon.h"

Dragon::~Dragon(){}

std::ostream &operator<<(std::ostream &out, Dragon &e){
  out << 'D';
  return out;
}
