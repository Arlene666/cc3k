#include "object.h"

std::string Object::whoAmI(){ return whoAmIImpl(); }
bool Object::exist(){ return existImpl(); }
char Object::getChar(){ return getCharImpl(); }

Object::~Object(){}
