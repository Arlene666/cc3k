#ifndef _BD_H_
#define _BD_H_
#include "potion.h"

class BD : public Potion {
protected:
  void defaultUsed(Player &p) override;
  void usedImpl(Drow &p) override;
public:
  BD();
  std::string whoAmI(){ return "BD"; }
  ~BD() override{}
};


#endif
