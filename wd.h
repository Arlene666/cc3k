#ifndef _WD_H_
#define _WD_H_
#include "potion.h"

class WD : public Potion {
    public:
    WD();
    protected:
    void usedDefault(Player &p) override;
    void usedImpl(Drow &d) override;
};

#endif

