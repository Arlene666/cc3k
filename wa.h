#ifndef _WA_H_
#define _WA_H_
#include "potion.h"

class WA : public Potion {
protected:
  void defaultUsed(Player &p) override;
public:
  WA();
  std::string whoAmI(){ return "WA"; }
  void used(Drow &p) override;
  ~WA() override{}
};

#endif
