#include "goblin.h"

void Goblin::attack(Enemy &e){ e.attacked(*this); }
void Goblin::attacked(Enemy &e){ e.attack(*this); }
void Goblin::use(Item &i){ i.used(*this); }

Goblin::~Goblin(){}
