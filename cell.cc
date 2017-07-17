#include "cell.h"

Cell::~Cell(){}

friend std::ostream &operator<<(std::stream &out, Cell &c){
  if(o){
    out << o;
  }else{
    out << tile;
  }
  return out;
}
