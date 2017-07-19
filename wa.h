#ifndef _WA_H_
#define _WA_H_
#include "potion.h"

class WA : public Potion {
    public:
    WA();
    void used(Shade &p) override;
    void used(Drow &p) override;
    void used(Vampire &p) override;
    void used(Troll &p) override;
    void used(Goblin &p) override;
};


#endif
