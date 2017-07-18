#include "grid.h"

void Grid::loadstage(){
  floor++;
  if(in != NULL){
    for(int x = 0; x < height; x++){
      vector<Cell> row;
      for(int y = 0; y < width; y++){
        char c;
        in >> std::noskipws >> c;
        if(c == '|' || c == '-' || c == ' ' || c == '+' || c == '#' || c == '.'){
          row.push_back(Cell(x, y, c));
        }else{
          std::shared_ptr<Object> o;
          if(c == '@'){
            if(race == 's'){
              o = std::make_shared<Shade>();
            }else if(race == 'd'){
              o = std::make_shared<Drow>();
            }else if(race == 'v'){
              o = std::make_shared<Vampire>();
            }else if(race == 'g'){
              o = std::make_shared<Goblin>();
            }else if(race == 't'){
              o = std::make_shared<Troll>();
            }
            playerPosX = x;
            playerPosY = y;
          }else if(c == '0'){
            o = std::make_shared<RH>();
          }else if(c == '1'){
            o = std::make_shared<BA>();
          }else if(c == '2'){
            o = std::make_shared<BD>();
          }else if(c == '3'){
            o = std::make_shared<PH>();
          }else if(c == '4'){
            o = std::make_shared<WA>();
          }else if(c == '5'){
            o = std::make_shared<WD>();
          }else if(c == '6'){
            o = std::make_shared<Gold>(2);
          }else if(c == '7'){
            o = std::make_shared<Gold>(1);
          }else if(c == '8'){
            o = std::make_shared<Gold>(4);
          }else if(c == '9'){
            o = std::make_shared<Gold>(6);
          }else if(c == 'H'){
            o = std::make_shared<Human>();
          }else if(c == 'w'){
            o = std::make_shared<Dwarf>();
          }else if(c == 'E'){
            o = std::make_shared<Elf>();
          }else if(c == 'O'){
            o = std::make_shared<Orc>();
          }else if(c == 'M'){
            o = std::make_shared<Merchant>();
          }else if(c == 'D'){
            o = std::make_shared<Dragon>();
          }else if(c == 'L'){
            o = std::make_shared<Halfling>();
          }
          row.push_back(Cell(x, y, '.', o));
        }
      }
      cells.push_back(row);
    }
  }else{

  }
}

std::string Grid::getType(Enemy &e){ return "Enemy"; }
std::string Grid::getType(Potion &i){ return "Potion"; }
std::string Grid::getType(Gold &i){ return "Gold"; }

Cell &Grid::getCell(std::string command, int x, int y){
  // Command: "no", "so". "ea". "we", "ne", "nw", "se", "sw"
  if (command == "no" && x > 0) return cells[x-1][y];
  else if(command == "so" && x < height-1) return cells[x+1][y];
  else if(command == "ea" && y < width -1) return cells[x][y+1];
  else if(command == "we" && y > 0) return cells[x][y-1];
  else if(command == "ne" && x > 0 && y < width -1) return cells[x-1][y+1];
  else if(command == "nw" && x > 0 && y > 0) return cells[x-1][y-1];
  else if(command == "se" && x < height-1 && y < width -1) return cells[x+1][y+1];
  else if(command == "sw" && x < height-1 && y > 0) return cells[x+1][y-1];
  else return NULL;
}

void Grid::movePlayer(std::string command){
  Cell &c = this->getCell(command, playerPosX, playerPosY);
  if(c != NULL && c.getTile() != '|' && c.getTile() != ' ' && c.getTile() != '-'){
    if(c.getObject() == nullptr){
      std::swap(this->cells[playerPosX][playerPosY].getObject(), c.getObject());
      playerPosX = c.getX();
      playerPosY = c.getY();
    }else if(getType(*c.getObject()) == "Gold"){
      this->cells[playerPosX][playerPosY].getObject()->use(*c.getObject());
      c.getObject() = nullptr;
      std::swap(this->cells[playerPosX][playerPosY].getObject(), c.getObject());
      playerPosX = c.getX();
      playerPosY = c.getY();
    }else if(getType(*c.getObject()) == "Potion"){

    }
  }
}

void Grid::attackEnemy(std::string command){
  Cell &c = this->getCell(command.substr(1), playerPosX, playerPosY);
  if(c != NULL && c.getTile() != '|' && c.getTile() != ' ' && c.getTile() != '-'){
    if(getType(*c.getObject()) == "Enemy"){

    }
  }
}

void Grid::useItem(std::string command){

}

void Grid::moveEnemy(){
  if(enemyCanMove){

  }
}

void Grid::stopEnemy(){
  enemyCanMove = (enemyCanMove)? false : true;
}

bool Grid::isPlaying(){
  return !cells[playerPosX][playerPosY]->getObject()->isDead();
}

friend std::ostream &operator<<(std::ostream &out, Grid &g){
  for(int x = 0; x < height; x++){
    for(int y = 0; y < width; y++){
      out << cells[x][y];
    }
    out << endl;
  }
  out << "Race: ";
  switch(race){
    case 's': out << "Shade"; break;
    case 'd': out << "Drow"; break;
    case 'v': out << "Vampire"; break;
    case 'g': out << "Goblin"; break;
    case 't': out << "Troll"; break;
  }
  out << " Gold: " << cells[playerPosX][playerPosY]->getObject()->getGold();
  out << "\t\tFloor " << floor << endl;
  out << "HP: " << cells[playerPosX][playerPosY]->getObject()->getHp() << endl;
  out << "Atk: " << cells[playerPosX][playerPosY]->getObject()->getAtk() << endl;
  out << "Def: " << cells[playerPosX][playerPosY]->getObject()->getDef() << endl;
  out << "Action: " << endl;
  return out;
}
