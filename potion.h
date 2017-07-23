#ifndef _POTION_H_
#define _POTION_H_
#include <algorithm>
#include "itemImpl.h"

class Potion : public ItemImpl {
protected:
  char getCharImpl() override;
public:
  Potion(): ItemImpl{true}{}
  virtual ~Potion() = 0;
};

#endif
