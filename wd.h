#ifndef _WD_H_
#define _WD_H_
#include "potion.h"

class WD : public Potion {
protected:
  void defaultUsed(Player &p) override;
public:
  WD();
  std::string whoAmI(){ return "WD"; }
  void used(Drow &p) override;
  ~WD() override{}
};

#endif
