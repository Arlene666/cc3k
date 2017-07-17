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

    virtual void usedDefault(Player &p) = 0;
    virtual void usedImpl(Shade &s);
    virtual void usedImpl(Drow &d);
    virtual void usedImpl(Vampire &v);
    virtual void usedImpl(Troll &t);
    virtual void usedImpl(Goblin &g);

  public:
    void used(Player &p);
    bool exist();
};

#endif
