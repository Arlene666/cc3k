#include "merchant.h"

Dragon::~Dragon(){}

friend std::ostream &operator<<(std::ostream &out, Dragon &e){
  out << 'D';
  return out;
}
