#ifndef _PH_H_
#define _PH_H_
#include "potion.h"

class PH : public Potion {
protected:
  void defaultUsed(Player &p) override;
public:
  PH();
  std::string whoAmI(){ return "PH"; }
  void used(Drow &p) override;
  ~PH() override{}
};


#endif
