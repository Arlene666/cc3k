#include "troll.h"

void Troll::attackImpl(Enemy &e){ e.attacked(*this); }
void Troll::attackedImpl(Enemy &e){ e.attack(*this); }
void Troll::useImpl(Item &i){ i.used(*this); }

Troll::~Troll(){}
