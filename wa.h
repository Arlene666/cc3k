#ifndef _WA_H_
#define _WA_H_
#include "potion.h"

class WA : public Potion {
protected:
  void defaultUsed(Player &p) override;
  void usedImpl(Drow &p) override;
  std::string whoAmIImpl(){ return "WA"; }
public:
  WA();
  ~WA() override{}
};

#endif
