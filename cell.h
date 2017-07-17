#ifndef CELL_H
#define CELL_H

class Object;

class Cell{
  std::shared_ptr<Object> o;
  char tile;
public:
  Cell(char tile): tile{tile}{}
  Cell(char tile, std::shared_ptr<Object> o): tile{tile}, o{o}{}

  std::shared_ptr<Object> getObject() { return o; }

  ~Cell();
  
  friend std::ostream &operator<<(std::stream &out, Cell &c);
};

#endif
