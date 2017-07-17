#include "item.h"

void Item::usedImpl(Shade &s) {
    Item::usedDefault(s);
}

void Item::usedImpl(Drow &d) {
    Item::usedDefault(d);
}

void Item::usedImpl(Vampire &v) {
    Item::usedDefault(v);
}

void Item::usedImpl(Troll &t) {
    Item::usedDefault(t);
}

void Item::usedImpl(Goblin &g) {
    Item::usedDefault(t);
}

void Item::used(Player &p) {
    Item::usedImpl(p):
}

bool Item::exist() {
    return (!isUsed);
}



