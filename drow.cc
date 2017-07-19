#include "drow.h"

void Drow::attack(Enemy &e){ e.attacked(*this); }
void Drow::attacked(Enemy &e){ e.attack(*this); }
void Drow::use(Item &i){ i.used(*this); }

Drow::~Drow(){}
