#include "troll.h"

void Troll::attack(Enemy &e){ e.attacked(*this); }
void Troll::attacked(Enemy &e){ e.attack(*this); }
void Troll::use(Item &i){ i.used(*this); }

Troll::~Troll(){}
