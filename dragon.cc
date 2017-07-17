#include "merchant.h"

Dragon::~Dragon(){}

friend std::ostream &operator<<(std::stream &out, Dragon &e){
  out << 'D';
  return out;
}
