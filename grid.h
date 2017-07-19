#ifndef GRID_H
#define GRID_H
#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include "cell.h"
#include "player.h"
#include "item.h"
#include "enemy.h"
#include "potion.h"
#include "gold.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "human.h"
#include "merchant.h"
#include "dragon.h"
#include "dwarf.h"
#include "orcs.h"
#include "halfling.h"
#include "elf.h"
#include "rh.h"
#include "ba.h"
#include "bd.h"
#include "ph.h"
#include "wa.h"
#include "wd.h"

using namespace std;

class Grid{
  const int width = 79, height = 25;
  std::vector<std::vector<Cell>> cells;
  shared_ptr<Player> p;
  shared_ptr<ifstream> in;
  char race;
  int pX, pY, floor;
  bool enemyCanMove;

  void setPlayer();
  shared_ptr<Object> setObject(char c);
  Cell *getCell(std::string command, int x, int y);

public:
  //ctor
  Grid(shared_ptr<ifstream> in, char race): in{in}, race{race}, floor{0}, enemyCanMove{true} {}
  //Grid(char race): in{NULL}, race{race}, floor{0}, enemyCanMove{true}{}

  void loadStage();
  //void reset();

  // Command: "no", "so". "ea". "we", "ne", "nw", "se", "sw"
  void movePlayer(std::string command);
  void attackEnemy(std::string command);
  void useItem(std::string command);
  // move all enemies
  void moveEnemy();
  // stop enemy and start enemy
  void stopEnemy();
  // determine whether player is alive
  bool isPlaying();

  friend std::ostream &operator<<(std::ostream &out, Grid &g);

  ~Grid();
};

#endif
