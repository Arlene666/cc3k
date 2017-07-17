#include "wd.h"

WD::WD():isUsable{true}, isUsed{false} {}

void WD::usedDefault(Player &p) {
    int &def = p.getDef();
    if (def - 5 < 0) {
        def = 0;
    } else {
        def -= 5;
    }
    isUsed = true;
}


void WD::usedImpl(Drow &d) {
    int &def = d.getDef();
    if (def - 7 < 0) {
        def = 0;
    } else {
        def -= 7;
    }
    isUsed = true;
}
