#ifndef _BA_H_
#define _BA_H_
#include "potion.h"

class BA : public Potion {
protected:
  void defaultUsed(Player &p) override;
public:
  BA();
  std::string whoAmI(){ return "BA"; }
  void used(Drow &p) override;
  ~BA() override{}
};


#endif
