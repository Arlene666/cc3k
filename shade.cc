#include "shade.h"

void Shade::attackImpl(Enemy &e){ e.attacked(*this); }
void Shade::attackedImpl(Enemy &e){ e.attack(*this); }
void Shade::useImpl(Item &i){ i.used(*this); }

Shade::~Shade(){}
