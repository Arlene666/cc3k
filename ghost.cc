#include "ghost.h"

void Ghost::attack(Enemy &e){ e.attacked(*this); }
void Ghost::attacked(Enemy &e){}
void Ghost::use(Item &i){}

Ghost::~Ghost(){}
