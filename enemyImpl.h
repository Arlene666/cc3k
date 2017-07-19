#ifndef ENEMYIMPL_H
#define ENEMYIMPL_H
#include <cstdlib>
#include "enemy.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

class EnemyImpl : public Enemy{
protected:
  void defaultAttack(Player &p);
  void defaultAttacked(Player &p);

public:
  EnemyImpl(int hp, int atk, int def, int drop): Enemy(hp, atk, def, drop){}
  virtual void attack(Shade &p);
  virtual void attack(Drow &p);
  virtual void attack(Vampire &p);
  virtual void attack(Troll &p);
  virtual void attack(Goblin &p);
  virtual void attacked(Shade &p);
  virtual void attacked(Drow &p);
  virtual void attacked(Vampire &p);
  virtual void attacked(Troll &p);
  virtual void attacked(Goblin &p);
  virtual ~EnemyImpl(){}
};

#endif
