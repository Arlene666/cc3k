#ifndef _GOLD_H_
#define _GOLD_H_
#include "item.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

class Gold : public ItemImpl {
    int pile;
  protected:
    void defaultUsed(Player &p) override;

  public:
    Gold(int n, bool isUsable);
    std::string whoAmI(){ return "Gold"; }
    char getChar() override;
    virtual ~Gold() override{}
};

#endif
