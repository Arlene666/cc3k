#ifndef CELL_H
#define CELL_H
#include <memory>
#include <iostream>

class Object;

class Cell{
  char tile;
  std::shared_ptr<Object> o;
public:
  Cell(char tile): tile{tile}{}
  Cell(char tile, std::shared_ptr<Object> o): tile{tile}, o{o}{}

  std::shared_ptr<Object> getObject() { return o; }

  ~Cell();

  friend std::ostream &operator<<(std::ostream &out, Cell &c);
};

#endif
