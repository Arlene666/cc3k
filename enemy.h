#ifndef ENEMY_H
#define ENEMY_H
#include <cstdlib>
#include "object.h"

class Player;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Enemy : public Object{
  int hp, atk, def; // status

  int damage(int atk, int def);

public:

  //ctor
  Enemy(int hp, int atk, int def): hp{hp}, atk{atk}, def{def}{}

  //Visitor Pattern: visitor
  virtual void attack(Shade &p) = 0;
  virtual void attack(Drow &p) = 0;
  virtual void attack(Vampire &p) = 0;
  virtual void attack(Troll &p) = 0;
  virtual void attack(Goblin &p) = 0;
  virtual void attacked(Shade &p) = 0;
  virtual void attacked(Drow &p) = 0;
  virtual void attacked(Vampire &p) = 0;
  virtual void attacked(Troll &p) = 0;
  virtual void attacked(Goblin &p) = 0;

  //Accessor
  int &getHp(){ return hp; }
  int &getAtk(){ return atk; }
  int &getDef(){ return def; }

  std::string whoAmI(){ return "Enemy"; }

  bool exist();

  //dtor
  virtual ~Enemy() = 0;

};

#endif
