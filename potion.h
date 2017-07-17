#ifndef _POTION_H_
#define _POTION_H_
#include "item.h"

class Potion : public Item {
  friend std::ostream &operator<<(std::stream &out, Potion &i);
};

#endif
