#include "cell.h"

Cell::~Cell(){}

std::ostream &operator<<(std::ostream &out, Cell &c){
  if(c.o != nullptr){
    out << c.o;
  }else{
    out << c.tile;
  }
  return out;
}
