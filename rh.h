#ifndef _RH_H_
#define _RH_H_
#include "potion.h"

class RH : public Potion {
    public:
    RH();
    std::string whoAmI(){ return "RH"; }
    void used(Shade &p) override;
    void used(Drow &p) override;
    void used(Vampire &p) override;
    void used(Troll &p) override;
    void used(Goblin &p) override;
    ~RH(){}
};

#endif
