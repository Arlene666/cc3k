#ifndef _GOLD_H_
#define _GOLD_H_
#include "item.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

class Gold : public Item {
    int pile;
  public:
    Gold(int n, bool isUsable);
    std::string whoAmI(){ return "Gold"; }
    void used(Shade &p) override;
    void used(Drow &p) override;
    void used(Vampire &p) override;
    void used(Troll &p) override;
    void used(Goblin &p) override;
    friend std::ostream &operator<<(std::ostream &out, Gold &i);
};

#endif
