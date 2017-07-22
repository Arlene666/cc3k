#include "phantom.h"

void Phantom::attack(Enemy &e){ e.attacked(*this); }
void Phantom::attacked(Enemy &e){}
void Phantom::use(Item &i){}

Phantom::~Phantom(){}
