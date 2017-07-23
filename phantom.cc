#include "phantom.h"

void Phantom::attackImpl(Enemy &e){ e.attacked(*this); }
void Phantom::attackedImpl(Enemy &e){ e.attack(*this); }
void Phantom::useImpl(Item &i){ i.used(*this); }

Phantom::~Phantom(){}
