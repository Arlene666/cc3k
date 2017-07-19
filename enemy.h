#ifndef ENEMY_H
#define ENEMY_H
#include <cstdlib>
#include "object.h"
#include "player.h"

class Player;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Enemy : public Object{
  int hp, atk, def; // status

protected:

  virtual void defaultAttack(Player &p);
  //Visitor Pattern: visitor
  virtual void attackImpl(Shade &p);
  virtual void attackImpl(Drow &p);
  virtual void attackImpl(Vampire &p);
  virtual void attackImpl(Troll &p);
  virtual void attackImpl(Goblin &p);

  virtual void defaultAttacked(Player &p);
  //Visitor Pattern: visitor
  virtual void attackedImpl(Shade &p);
  virtual void attackedImpl(Drow &p);
  virtual void attackedImpl(Vampire &p);
  virtual void attackedImpl(Troll &p);
  virtual void attackedImpl(Goblin &p);

public:

  //ctor
  Enemy(int hp, int atk, int def): hp{hp}, atk{atk}, def{def}{}

  //Visitor Pattern: visitor
  //  (Identification of type of Player happens in attackImpl)
  void attack(Player &p);
  //Visitor Pattern: visitor
  //  (Identification of type of Player happens in attackedImpl)
  void attacked(Player &p);

  //Accessor
  int &getHp(){ return hp; }
  int &getAtk(){ return atk; }
  int &getDef(){ return def; }

  bool isDead();

  //dtor
  virtual ~Enemy() = 0;

};

#endif
