#include "ba.h"



BA::BA():isUsable{true}, isUsed{false} {}
}

void BA::usedDefault(Player &p) {
    p.getAtk() += 5;
    isUsed = true;
}


void BA::usedImpl(Drow &d) {
    d.getAtk() += 7;
    isUsed = true;
}
