#include "rh.h"
#include <utility>


RH::RH():isUsable{true}, isUsed{false} {}

void RH::usedDefault(Player &p) {
    int &hp = p.getHP();
    int &dfhp = p.getDfHP();
    hp = max(hp+10, dfhp);
    isUsed = true;
}


void RH:usedImpl(Drow &d) {
    int &hp = p.getHP();
    int &dfhp = p.getDfHP();
    hp = max(hp+10*1.5, dfhp);
    isUsed = true;
}



