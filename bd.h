#ifndef _BD_H_
#define _BD_H_
#include "potion.h"

class BD : public Potion {
protected:
  void defaultUsed(Player &p) override;
public:
  BD();
  std::string whoAmI(){ return "BD"; }
  void used(Drow &p) override;
  ~BD() override{}
};


#endif
