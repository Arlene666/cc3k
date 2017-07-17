#include "bd.h"



BD::BD(): isUsable{true}, isUsed{false} {}

void BD::usedDefault(Player &p) {
    p.getDef() += 5;
    isUsed = true;
}

void BD::usedImpl(Drow &d) {
    d.getDef() += 7;
    isUsed = true;
}
