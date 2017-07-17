#ifndef DROW_H
#define DROW_H
#include "player.h"

class Drow : public Player{
public:
  Drow(): Player{150, 25, 25} {}
  ~Drow();
};

#endif
