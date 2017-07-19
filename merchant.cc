#include "merchant.h"

Merchant::~Merchant(){}

std::ostream &operator<<(std::ostream &out, Merchant &e){
  out << 'M';
  return out;
}
