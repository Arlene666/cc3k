#ifndef PLAYER_H
#define PLAYER_H
#include "object.h"

class Enemy;
class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Player : public Object {
  //status
  int hp, initHp, atk, initAtk, def, initDef, gold;

public:

  //ctor
  Player(int hp, int atk, int def):
  hp{hp}, initHp{hp}, atk{atk}, initAtk{atk}, def{def}, initDef{def}, gold{0}{}

  //Visitor Pattern: acceptor
  void attack(Enemy &e);
  //Visitor Pattern: acceptor
  void attacked(Enemy &e);
  //Visitor Pattern: acceptor
  void use(Item &i);

  void initAtkDef();
  bool isDead();

  //accessor
  int &getHp() const;
  int &getAtk() const;
  int &getDef() const;
  int &getGold() const;
  int getDfHp() const;

  //dtor
  virtual ~Player() = 0;

  friend std::ostream &operator<<(std::ostream &out, Player &p);
};

#endif
