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
          row.push_back(Cell(c));
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
          row.push_back(Cell(c, o));
        }
      }
      cells.push_back(row);
    }
  }else{

  }
}

void Grid::movePlayer(std::string command){
  if()
}

void Grid::attackEnemy(std::string command){

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

friend std::ostream &operator<<(std::stream &out, Grid &g){
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
