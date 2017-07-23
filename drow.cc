#include "drow.h"

void Drow::attackImpl(Enemy &e){ e.attacked(*this); }
void Drow::attackedImpl(Enemy &e){ e.attack(*this); }
void Drow::useImpl(Item &i){ i.used(*this); }

Drow::~Drow(){}
