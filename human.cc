#include "human.h"

Human::~Human(){}

friend std::ostream &operator<<(std::stream &out, Human &e){
  out << 'H';
  return out;
}
