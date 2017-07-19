#include "shade.h"

void Shade::attack(Enemy &e){ e.attacked(*this); }
void Shade::attacked(Enemy &e){ e.attack(*this); }
void Shade::use(Item &i){ i.used(*this); }

Shade::~Shade(){}
