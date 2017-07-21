#ifndef DRAGON_H
#define DRAGON_H
#include "enemyImpl.h"
#include <memory>
#include "gold.h"

class Dragon : public EnemyImpl {
private:
  std::shared_ptr<Gold> g;
  int hX, hY;
protected:
  void defaultAttacked(Player &p) override;

public:
  Dragon(): EnemyImpl{150, 20, 20, 0} {}
  void setGold(std::shared_ptr<Gold> g, int x, int y);
  char getChar() override;
  int getHX(){ return hX; }
  int getHY(){ return hY; }
  bool hasHoard(){ return g != nullptr; }
  ~Dragon();
};

#endif
