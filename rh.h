#ifndef _RH_H_
#define _RH_H_
#include "potion.h"

class RH : public Potion {
    public:
    RH();
    protected:
    void usedDefault(Player &p) override;
    void usedImpl(Drow &d) override;
};

#endif

