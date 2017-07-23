#ifndef _RH_H_
#define _RH_H_
#include "potion.h"

class RH : public Potion {
protected:
  void defaultUsed(Player &p) override;
  void usedImpl(Drow &p) override;
public:
  RH();
  std::string whoAmI(){ return "RH"; }
  ~RH(){}
};

#endif
