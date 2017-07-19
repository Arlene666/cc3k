#include "cell.h"

Cell::~Cell(){}

std::ostream &operator<<(std::stream &out, Cell &c){
  if(o != nullptr){
    out << o;
  }else{
    out << tile;
  }
  return out;
}
