#ifndef ENEMYIMPL_H
#define ENEMYIMPL_H
#include <cstdlib>
#include <string>
#include "enemy.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "phantom.h"
#include "zombie.h"

class EnemyImpl : public Enemy{
protected:
  int damage(float atk, float def);
  void defaultAttackImpl(Player &p);
  void defaultAttackedImpl(Player &p);
  virtual void defaultAttack(Player &p);
  virtual void defaultAttacked(Player &p);

public:
  EnemyImpl(int hp, int atk, int def, int drop): Enemy(hp, atk, def, drop){}
  virtual void attack(Shade &p);
  virtual void attack(Drow &p);
  virtual void attack(Vampire &p);
  virtual void attack(Troll &p);
  virtual void attack(Goblin &p);
  virtual void attack(Phantom &p);
  virtual void attack(Zombie &p);
  virtual void attacked(Shade &p);
  virtual void attacked(Drow &p);
  virtual void attacked(Vampire &p);
  virtual void attacked(Troll &p);
  virtual void attacked(Goblin &p);
  virtual void attacked(Phantom &p);
  virtual void attacked(Zombie &p);
  virtual ~EnemyImpl() = 0;
};

#endif
