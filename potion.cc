#include "potion.h"


Potion::Potion(): isUsable{true}, isUsed{false} {}

friend std::ostream &operator<<(std::ostream &out, Potion &i){
  out << 'P';
  return out;
}
