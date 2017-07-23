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

  virtual void attackImpl(Shade &p);
  virtual void attackImpl(Drow &p);
  virtual void attackImpl(Vampire &p);
  virtual void attackImpl(Troll &p);
  virtual void attackImpl(Goblin &p);
  virtual void attackImpl(Phantom &p);
  virtual void attackImpl(Zombie &p);
  virtual void attackedImpl(Shade &p);
  virtual void attackedImpl(Drow &p);
  virtual void attackedImpl(Vampire &p);
  virtual void attackedImpl(Troll &p);
  virtual void attackedImpl(Goblin &p);
  virtual void attackedImpl(Phantom &p);
  virtual void attackedImpl(Zombie &p);

public:
  EnemyImpl(int hp, int atk, int def, int drop): Enemy(hp, atk, def, drop){}
  virtual ~EnemyImpl() = 0;
};

#endif
