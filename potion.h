#ifndef _POTION_H_
#define _POTION_H_
#include "item.h"

class Potion : public Item {
  std::string whoAmI(){ return "Potion"; }
  friend std::ostream &operator<<(std::ostream &out, Potion &i);
};

#endif
