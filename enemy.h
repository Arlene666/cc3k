#ifndef ENEMY_H
#define ENEMY_H
#include <cstdlib>
#include <cmath>
#include "object.h"

class Player;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Phantom;
class Zombie;

class Enemy : public Object{
  int hp, atk, def, drop; // status

protected:
  virtual void attackImpl(Shade &p) = 0;
  virtual void attackImpl(Drow &p) = 0;
  virtual void attackImpl(Vampire &p) = 0;
  virtual void attackImpl(Troll &p) = 0;
  virtual void attackImpl(Goblin &p) = 0;
  virtual void attackImpl(Phantom &p) = 0;
  virtual void attackImpl(Zombie &p) = 0;
  virtual void attackedImpl(Shade &p) = 0;
  virtual void attackedImpl(Drow &p) = 0;
  virtual void attackedImpl(Vampire &p) = 0;
  virtual void attackedImpl(Troll &p) = 0;
  virtual void attackedImpl(Goblin &p) = 0;
  virtual void attackedImpl(Phantom &p) = 0;
  virtual void attackedImpl(Zombie &p) = 0;

public:
  //ctor
  Enemy(int hp, int atk, int def, int drop): hp{hp}, atk{atk}, def{def}, drop{drop}{}

  //Visitor Pattern: visitor
  void attack(Shade &p);
  void attack(Drow &p);
  void attack(Vampire &p);
  void attack(Troll &p);
  void attack(Goblin &p);
  void attack(Phantom &p);
  void attack(Zombie &p);
  void attacked(Shade &p);
  void attacked(Drow &p);
  void attacked(Vampire &p);
  void attacked(Troll &p);
  void attacked(Goblin &p);
  void attacked(Phantom &p);
  void attacked(Zombie &p);

  //Accessor
  int &getHp(){ return hp; }
  int &getAtk(){ return atk; }
  int &getDef(){ return def; }
  int &getDrop(){ return drop; }

  std::string whoAmI(){ return "Enemy"; }

  bool exist();

  //dtor
  ~Enemy();

};

#endif
