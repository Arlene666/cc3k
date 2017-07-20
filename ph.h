#ifndef _PH_H_
#define _PH_H_
#include "potion.h"


class PH : public Potion {
    public:
    PH();
    std::string whoAmI(){ return "PH"; }
    void used(Shade &p) override;
    void used(Drow &p) override;
    void used(Vampire &p) override;
    void used(Troll &p) override;
    void used(Goblin &p) override;
};


#endif
