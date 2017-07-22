#ifndef ITEMIMPL_H
#define ITEMIMPL_H
#include "item.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "zombie.h"

class ItemImpl : public Item{
  protected:
    virtual void defaultUsed(Player &p) = 0;

  public:
    ItemImpl(bool isUsable): Item{isUsable}{}
    virtual void used(Shade &p);
    virtual void used(Drow &p);
    virtual void used(Vampire &p);
    virtual void used(Troll &p);
    virtual void used(Goblin &p);
    virtual void used(Zombie &p);
    virtual ~ItemImpl() override {}
};

#endif
