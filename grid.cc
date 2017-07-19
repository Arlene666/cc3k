#include "grid.h"

//*************private methods******************************

void Grid::setPlayer(){
  if(race == 's'){
    p = std::make_shared<Shade>();
  }else if(race == 'd'){
    p = std::make_shared<Drow>();
  }else if(race == 'v'){
    p = std::make_shared<Vampire>();
  }else if(race == 'g'){
    p = std::make_shared<Goblin>();
  }else if(race == 't'){
    p = std::make_shared<Troll>();
  }
}

shared_ptr<Object> Grid::setObject(char c){
  shared_ptr<Object> o;
  switch(c){
    case '0': o = std::make_shared<RH>(); break;
    case '1': o = std::make_shared<BA>(); break;
    case '2': o = std::make_shared<BD>(); break;
    case '3': o = std::make_shared<PH>(); break;
    case '4': o = std::make_shared<WA>(); break;
    case '5': o = std::make_shared<WD>(); break;
    case '6': o = std::make_shared<Gold>(2, true); break;
    case '7': o = std::make_shared<Gold>(1, true); break;
    case '8': o = std::make_shared<Gold>(4, true); break;
    case '9': o = std::make_shared<Gold>(6, false); break;
    case 'H': o = std::make_shared<Human>(); break;
    case 'w': o = std::make_shared<Dwarf>(); break;
    case 'E': o = std::make_shared<Elf>(); break;
    case 'O': o = std::make_shared<Orcs>(); break;
    case 'M': o = std::make_shared<Merchant>(); break;
    case 'D': o = std::make_shared<Dragon>(); break;
    case 'L': o = std::make_shared<Halfling>(); break;
    default: o = nullptr;
  }
  return o;
}

Cell *Grid::getCell(std::string command, int x, int y){
  // Command: "no", "so". "ea". "we", "ne", "nw", "se", "sw"
  if (command == "no" && x > 0) return &cells[x-1][y];
  else if(command == "so" && x < height-1) return &cells[x+1][y];
  else if(command == "ea" && y < width -1) return &cells[x][y+1];
  else if(command == "we" && y > 0) return &cells[x][y-1];
  else if(command == "ne" && x > 0 && y < width -1) return &cells[x-1][y+1];
  else if(command == "nw" && x > 0 && y > 0) return &cells[x-1][y-1];
  else if(command == "se" && x < height-1 && y < width -1) return &cells[x+1][y+1];
  else if(command == "sw" && x < height-1 && y > 0) return &cells[x+1][y-1];
  else return nullptr;
}


//****************public methods******************************

void Grid::loadStage(){
  floor++;
  for(int x = 0; x < height; x++){
    vector<Cell> row;
    for(int y = 0; y < width; y++){
      char c;
      *in >> std::noskipws >> c;
      if(c == '|' || c == '-' || c == ' ' || c == '+' || c == '#' || c == '.'){
        row.push_back(Cell(x, y, c));
      }else if(c == '@'){
        setPlayer();
        pX = x;
        pY = y;
        row.push_back(Cell(x, y, c));
      }else{
        row.push_back(Cell(x, y, '.', setObject(c)));
      }
    }
    cells.push_back(row);
  }
}

void Grid::movePlayer(std::string command){
  Cell *c = this->getCell(command, pX, pY);
  if(c != nullptr && c->getTile() != '|' && c->getTile() != ' ' && c->getTile() != '-'){
    if(c->getObject() == nullptr){
      std::swap(this->cells[pX][pY].getObject(), c->getObject());
      pX = c->getX();
      pY = c->getY();
    }else if(c->getObject()->whoAmI() == "Gold"){
      p->use(*dynamic_pointer_cast<Gold>(c->getObject()));
      if(!c->getObject()->exist()) c->getObject() = nullptr;
      pX = c->getX();
      pY = c->getY();
    }else if(c->getObject()->whoAmI() == "Potion"){
      pX = c->getX();
      pY = c->getY();
    }
  }
}

void Grid::attackEnemy(std::string command){
  Cell *c = this->getCell(command, pX, pY);
  if(c != nullptr && c->getObject() != nullptr && c->getObject()->whoAmI() == "Enemy"){
    p->attack(*dynamic_pointer_cast<Enemy>(c->getObject()));
    if(!c->getObject()->exist()) c->getObject() = nullptr;
  }
}

void Grid::useItem(std::string command){
  Cell *c = this->getCell(command, pX, pY);
  if(c != nullptr && c->getObject() != nullptr && c->getObject()->whoAmI() == "Potion"){
    p->use(*dynamic_pointer_cast<Potion>(c->getObject()));
    if(!c->getObject()->exist()) c->getObject() = nullptr;
  }
}

void Grid::moveEnemy(){
  if(enemyCanMove){
    for(int x = 0; x < height; x++){
      for(int y = 0; y < width; y++){

      }
    }
  }
}

void Grid::stopEnemy(){
  enemyCanMove = (enemyCanMove)? false : true;
}

bool Grid::isPlaying(){
  return p->isDead();
}

std::ostream &operator<<(std::ostream &out, Grid &g){
  for(int x = 0; x < g.height; x++){
    for(int y = 0; y < g.width; y++){
      if(x == g.pX && y == g.pY) out << '@';
      else out << g.cells[x][y];
    }
    out << endl;
  }
  out << "Race: ";
  switch(g.race){
    case 's': out << "Shade"; break;
    case 'd': out << "Drow"; break;
    case 'v': out << "Vampire"; break;
    case 'g': out << "Goblin"; break;
    case 't': out << "Troll"; break;
  }
  out << " Gold: " << g.p->getGold();
  out << "\t\tFloor " << g.floor << endl;
  out << "HP: " << g.p->getHp() << endl;
  out << "Atk: " << g.p->getAtk() << endl;
  out << "Def: " << g.p->getDef() << endl;
  out << "Action: " << endl;
  return out;
}
