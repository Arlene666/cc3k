#include "goblin.h"

void Goblin::attackImpl(Enemy &e){ e.attacked(*this); }
void Goblin::attackedImpl(Enemy &e){ e.attack(*this); }
void Goblin::useImpl(Item &i){ i.used(*this); }

Goblin::~Goblin(){}
