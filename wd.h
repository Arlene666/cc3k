#ifndef _WD_H_
#define _WD_H_
#include "potion.h"

class WD : public Potion {
    public:
    WD();
    std::string whoAmI(){ return "WD"; }
    void used(Shade &p) override;
    void used(Drow &p) override;
    void used(Vampire &p) override;
    void used(Troll &p) override;
    void used(Goblin &p) override;
};

#endif
