#ifndef _GOLD_H_
#define _GOLD_H_
#include "itemImpl.h"

class Gold : public ItemImpl {
    int pile;
  protected:
    void defaultUsed(Player &p) override;

  public:
    Gold(int n, bool isUsable);
    std::string whoAmI(){ return "Gold"; }
    char getChar() override;
    virtual ~Gold() override{}
};

#endif
