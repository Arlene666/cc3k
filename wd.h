#ifndef _WD_H_
#define _WD_H_
#include "potion.h"

class WD : public Potion {
protected:
  void defaultUsed(Player &p) override;
  void usedImpl(Drow &p) override;
  std::string whoAmIImpl(){ return "WD"; }
public:
  WD();
  ~WD() override{}
};

#endif
