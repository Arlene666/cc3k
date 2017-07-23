#ifndef _PH_H_
#define _PH_H_
#include "potion.h"

class PH : public Potion {
protected:
  void defaultUsed(Player &p) override;
  void usedImpl(Drow &p) override;
  std::string whoAmIImpl(){ return "PH"; }
public:
  PH();
  ~PH() override{}
};


#endif
