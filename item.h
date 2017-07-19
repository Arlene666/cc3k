#ifndef _ITEM_H_
#define _ITEM_H_
#include "object.h"

class Player;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Item : public Object{
  protected:
    bool isUsable;
    bool isUsed = false;

  public:
    // visitor pattern: visitor
    virtual void used(Shade &p) = 0;
    virtual void used(Drow &p) = 0;
    virtual void used(Vampire &p) = 0;
    virtual void used(Troll &p) = 0;
    virtual void used(Goblin &p) = 0;
    bool exist();
};

#endif
