#ifndef _GOLD_H_
#define _GOLD_H_
#include "item.h"


class Gold : public Item {
    int pile;
  protected:
    void usedDefault(Player &p) override;
  public:
    Gold(int n);
    friend std::ostream &operator<<(std::stream &out, Gold &i);
};
