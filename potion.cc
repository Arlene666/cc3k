#include "potion.h"

std::ostream &operator<<(std::ostream &out, Potion &i){
  if (i.exist()) {
    out << 'P';
  }
  return out;
}
