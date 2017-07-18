#include "human.h"

Human::~Human(){}

friend std::ostream &operator<<(std::ostream &out, Human &e){
  out << 'H';
  return out;
}
