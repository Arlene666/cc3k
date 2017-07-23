#ifndef _GOLD_H_
#define _GOLD_H_
#include "itemImpl.h"

class Gold : public ItemImpl {
    int pile;
  protected:
    void defaultUsed(Player &p) override;
    std::string whoAmIImpl(){ return "Gold"; }
    char getCharImpl() override;
  public:
    Gold(int n, bool isUsable);
    virtual ~Gold() override{}
};

#endif
