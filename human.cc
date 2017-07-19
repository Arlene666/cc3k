#include "human.h"

Human::~Human(){}

std::ostream &operator<<(std::ostream &out, Human &e){
  out << 'H';
  return out;
}
