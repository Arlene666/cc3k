#ifndef _BA_H_
#define _BA_H_
#include "potion.h"

class BA : public Potion {
    public:
    BA();
    protected:
    void usedDefault(Player &p) override;
    void usedImpl(Drow &d) override;
};


#endif

