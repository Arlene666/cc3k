#include "vampire.h"

void Vampire::attack(Enemy &e){ e.attacked(*this); }
void Vampire::attacked(Enemy &e){ e.attack(*this); }
void Vampire::use(Item &i){ i.used(*this); }

Vampire::~Vampire(){}
