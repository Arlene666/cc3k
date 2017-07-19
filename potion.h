#ifndef _POTION_H_
#define _POTION_H_
#include <algorithm>
#include "item.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

class Potion : public Item {
public:
  Potion(): Item{true}{}
  std::string whoAmI(){ return "Potion"; }
  char getChar() override;
  virtual ~Potion() override{}
};

#endif
