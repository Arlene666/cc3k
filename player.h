#ifndef PLAYER_H
#define PLAYER_H
#include "object.h"
#include "enemy.h"
#include "item.h"

class Player{
  //status
  int hp, initHp, atk, initAtk, def, initDef, gold;

public:

  //ctor
  Player(int hp, int atk, int def):
  hp{hp}, initHp{hp}, atk{atk}, initAtk{atk}, def{def}, initDef{def}, gold{0}{}

  //Visitor Pattern: acceptor
  virtual void attack(Enemy &e) = 0;
  //Visitor Pattern: acceptor
  virtual void attacked(Enemy &e) = 0;
  //Visitor Pattern: acceptor
  virtual void use(Item &i) = 0;

  virtual void initAtkDef();
  bool isDead();

  //accessor
  int &getHp();
  int &getAtk();
  int &getDef();
  int &getGold();
  int getDfHp() const;
  int getDfAtk() const;
  int getDfDef() const;

  //dtor
  virtual ~Player() = 0;
};

#endif
