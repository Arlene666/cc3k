#include "ph.h"

PH::PH():isUsable{true}, isUsed{false} {}

void PH::usedDefault(Player &p) {
    int &hp = p.getHP();
    if (hp - 10 < 0) {
        hp = 0;
    } else {
        hp -= 10;
    }
    isUsed = true;
}


void PH::usedImpl(Drow &d) {
    int &hp = d.getHP();
    if (hp - 15 < 0) {
        hp = 0;
    } else {
        hp -= 15;
    }
    isUsed = true;
}
