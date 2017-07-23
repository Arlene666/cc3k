#include "item.h"

bool Item::exist() {
    return (!isUsed);
}

void Item::used(Shade &p){ usedImpl(p); }
void Item::used(Drow &p){ usedImpl(p); }
void Item::used(Vampire &p){ usedImpl(p); }
void Item::used(Troll &p){ usedImpl(p); }
void Item::used(Goblin &p){ usedImpl(p); }
void Item::used(Phantom &p){ usedImpl(p); }
void Item::used(Zombie &p){ usedImpl(p); }

Item::~Item(){}
