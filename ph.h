#ifndef _PH_H_
#define _PH_H_
#include "potion.h"


class PH : public Potion {
    public:
    PH();
    protected:
    void usedDefault(Player &p) override;
    void usedImpl(Drow &d) override;
};


#endif

