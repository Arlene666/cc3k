#include "vampire.h"

void Vampire::attackImpl(Enemy &e){ e.attacked(*this); }
void Vampire::attackedImpl(Enemy &e){ e.attack(*this); }
void Vampire::useImpl(Item &i){ i.used(*this); }

Vampire::~Vampire(){}
