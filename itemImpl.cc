#include "itemImpl.h"

void ItemImpl::usedImpl(Shade &p){
  defaultUsed(p);
}

void ItemImpl::usedImpl(Drow &p){
  defaultUsed(p);
}

void ItemImpl::usedImpl(Vampire &p){
  defaultUsed(p);
}

void ItemImpl::usedImpl(Troll &p){
  defaultUsed(p);
}

void ItemImpl::usedImpl(Goblin &p){
  defaultUsed(p);
}

void ItemImpl::usedImpl(Phantom &p){
}

void ItemImpl::usedImpl(Zombie &p){
  defaultUsed(p);
}

ItemImpl::~ItemImpl(){}
