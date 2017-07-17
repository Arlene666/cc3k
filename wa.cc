#include "wa.h"

WA::WA():isUsable{true}, isUsed{false} {}

void WA::usedDefault(Player &p) {
    int &atk = p.getAtk();
    if (atk - 5 < 0) {
        atk = 0;
    } else {
        atk -= 5;
    }
    isUsed = true;
}


void WA::usedImpl(Drow &d) {
    int &atk = d.getAtk();
    if (atk - 7 < 0) {
        atk = 0;
    } else {
        atk -= 7;
    }
    isUsed = true;
}
