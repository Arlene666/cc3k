#ifndef ITEMIMPL_H
#define ITEMIMPL_H
#include "item.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "phantom.h"
#include "zombie.h"

class ItemImpl : public Item{
  protected:
    virtual void defaultUsed(Player &p) = 0;
    virtual void usedImpl(Shade &p);
    virtual void usedImpl(Drow &p);
    virtual void usedImpl(Vampire &p);
    virtual void usedImpl(Troll &p);
    virtual void usedImpl(Goblin &p);
    virtual void usedImpl(Phantom &p);
    virtual void usedImpl(Zombie &p);

  public:
    ItemImpl(bool isUsable): Item{isUsable}{}
    virtual ~ItemImpl() = 0;
};

#endif
