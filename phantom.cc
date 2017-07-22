#include "phantom.h"

void Phantom::attack(Enemy &e){ e.attacked(*this); }
void Phantom::attacked(Enemy &e){ e.attack(*this); }
void Phantom::use(Item &i){ i.used(*this); }

Phantom::~Phantom(){}
