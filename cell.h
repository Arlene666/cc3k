#ifndef CELL_H
#define CELL_H
#include <memory>
#include <iostream>
#include "object.h"

class Cell{
  int x, y;
  char tile;
  std::shared_ptr<Object> o;
public:
  Cell(int x, int y, char tile): x{x}, y{y}, tile{tile}{}
  Cell(int x, int y, char tile, std::shared_ptr<Object> o):
  x{x}, y{y}, tile{tile}, o{o}{}

  std::shared_ptr<Object> &getObject() { return o; }
  int getX() { return x; }
  int getY() { return y; }
  char &getTile() { return tile; }

  ~Cell();

  friend std::ostream &operator<<(std::ostream &out, Cell &c);
};

#endif
