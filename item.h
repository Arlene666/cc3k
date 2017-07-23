#ifndef _ITEM_H_
#define _ITEM_H_
#include "object.h"

class Player;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Phantom;
class Zombie;

class Item : public Object{
  protected:
    bool isUsable;
    bool isUsed;

    virtual void usedImpl(Shade &p) = 0;
    virtual void usedImpl(Drow &p) = 0;
    virtual void usedImpl(Vampire &p) = 0;
    virtual void usedImpl(Troll &p) = 0;
    virtual void usedImpl(Goblin &p) = 0;
    virtual void usedImpl(Phantom &p) = 0;
    virtual void usedImpl(Zombie &p) = 0;

  public:
    Item(bool isUsable): isUsable{isUsable}, isUsed{false}{}

    // visitor pattern: visitor
    void used(Shade &p);
    void used(Drow &p);
    void used(Vampire &p);
    void used(Troll &p);
    void used(Goblin &p);
    void used(Phantom &p);
    void used(Zombie &p);

    bool exist();
    //Accessor
    bool &usable() { return isUsable; }

    virtual ~Item() = 0;
};

#endif
