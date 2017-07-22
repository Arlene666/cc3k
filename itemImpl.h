#ifndef ITEMIMPL_H
#define ITEMIMPL_H
#include "item.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

class ItemImpl : public Item{
  protected:
    virtual void defaultUsed(Player &p) = 0;

  public:
    Item(bool isUsable): isUsable{isUsable}, isUsed{false}{}
    virtual void used(Shade &p) override;
    virtual void used(Drow &p) override;
    virtual void used(Vampire &p) override;
    virtual void used(Troll &p) override;
    virtual void used(Goblin &p) override;
    virtual void used(Zombie &p) override;
    virtual ~ItemImpl() override {}
};

#endif
