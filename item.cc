#include "item.h"

bool Item::exist() {
    return (!isUsed);
}

Item::~Item(){}
