#include "merchant.h"

Merchant::~Merchant(){}

friend std::ostream &operator<<(std::stream &out, Merchant &e){
  out << 'M';
  return out;
}
