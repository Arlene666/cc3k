#ifndef _POTION_H_
#define _POTION_H_
#include <algorithm>
#include "itemImpl.h"

class Potion : public ItemImpl {
public:
  Potion(): ItemImpl{true}{}
  char getChar() override;
  virtual ~Potion() override{}
};

#endif
