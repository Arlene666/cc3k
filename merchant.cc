#include "merchant.h"

Merchant::~Merchant(){}

void defaultAttacked(Player &p) {
  this->getHP() -= ceiling((100/100+this->getDef()))*p.getAtk());
  if (isDead()) {
    int &g = p.getGold();
    g += 4;
  }
}

friend std::ostream &operator<<(std::ostream &out, Merchant &e){
  out << 'M';
  return out;
}
