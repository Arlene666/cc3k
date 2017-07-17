#include "gold.h"


Gold::Gold(int n): isUsable{false}, isUsed{false}, pile{n} {}



void Gold::usedDefault(Player &p) {
    if (isUsable) {
        p.getGold() += pile;
        isUsed = true;
    }
}

friend std::ostream &operator<<(std::stream &out, Gold &i){
  out << 'G';
  return out;
}
