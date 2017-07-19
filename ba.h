#ifndef _BA_H_
#define _BA_H_
#include "potion.h"

class BA : public Potion {
    public:
    BA();
    void used(Shade &p) override;
    void used(Drow &p) override;
    void used(Vampire &p) override;
    void used(Troll &p) override;
    void used(Goblin &p) override;
};


#endif
