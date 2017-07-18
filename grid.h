#ifndef GRID_H
#define GRID_H
#include "cell.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Object;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Human;
class Merchant;
class Dragon;
class Dwarf;
class Orcs;
class Halfling;
class Elf;
class Gold;
class RH;
class BA;
class BD;
class PH;
class WA;
class WD;

class Grid{
  std::vector<std::vector<Cell>> cells;
  ifstream in;
  char race;
  int playerPosX, playerPosY, floor;
  const int width = 79, height = 25;
  bool enemyCanMove;

  Cell &getCell(std::string command, int x, int y);

  std::string getType(Enemy &e);
  std::string getType(Potion &i);
  std::string getType(Gold &i);

public:
  //ctor
  Grid(ifstream &in, char race): in{in}, race{race}, floor{0}, enemyCanMove{true} {}
  //Grid(char race): in{NULL}, race{race}, floor{0}, enemyCanMove{true}{}

  void loadStage();
  //void reset();

  // Command: "no", "so". "ea". "we", "ne", "nw", "se", "sw"
  void movePlayer(std::string command);
  // Command: "a<direction>"
  void attackEnemy(std::string command);
  // Command: "u<direction>"
  void useItem(std::string command);
  // move all enemies
  void moveEnemy();
  // stop enemy and start enemy
  void stopEnemy();
  bool isPlaying();

  friend std::ostream &operator<<(std::ostream &out, Grid &g);

  ~Grid();
};

#endif
