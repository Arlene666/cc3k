#include "grid.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//*************private methods******************************

void Grid::setPlayer(){
  if(race == 's'){
    p = std::make_unique<Shade>();
  }else if(race == 'd'){
    p = std::make_unique<Drow>();
  }else if(race == 'v'){
    p = std::make_unique<Vampire>();
  }else if(race == 'g'){
    p = std::make_unique<Goblin>();
  }else if(race == 't'){
    p = std::make_unique<Troll>();
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
  if(o != nullptr) o->getCount() = 0;
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

std::string getDirection(std::string command){
  if (command == "no") return "North";
  else if(command == "so") return "South";
  else if(command == "ea") return "East";
  else if(command == "we") return "West";
  else if(command == "ne") return "North East";
  else if(command == "nw") return "North West";
  else if(command == "se") return "South East";
  else if(command == "sw") return "South West";
  else return "";
}

void Grid::checkObject(std::shared_ptr<Object> o){
  if(o != nullptr && o->whoAmI() != "Enemy" && o->whoAmI() != "Gold"){
    if(o->whoAmI() == "RH" && rh){ Object::message += " and sees an RH"; }
    else if(o->whoAmI() == "BA" && ba){ Object::message += " and sees an BA"; }
    else if(o->whoAmI() == "BD" && bd){ Object::message += " and sees an BD"; }
    else if(o->whoAmI() == "PH" && ph){ Object::message += " and sees an PH"; }
    else if(o->whoAmI() == "WA" && wa){ Object::message += " and sees an WA"; }
    else if(o->whoAmI() == "WD" && wd){ Object::message += " and sees an WD"; }
    else { Object::message += " and sees an unknown potion"; }
  }else if(o != nullptr && o->whoAmI() == "Gold"){
    Object::message += " and sees Gold";
  }
}

void Grid::updatePotion(std::string name){
  if(name == "RH") rh = true;
  else if(name == "BA") ba = true;
  else if(name == "BD") bd = true;
  else if(name == "PH") ph = true;
  else if(name == "WA") wa = true;
  else if(name == "WD") wd = true;
}

bool Grid::playerWalkable(Cell *c){
  return (c!=nullptr && c->getTile()!='|' && c->getTile()!=' ' && c->getTile()!='-');
}

bool Grid::enemyWalkable(Cell *c){
  return (playerWalkable(c) && c->getTile() != '+' && c->getTile() != '#' && c->getObject() == nullptr);
}

void Grid::setDragonHoard(Dragon &d, int x, int y){
  for(int i = -1; i <= 1; i++){
    for(int j = -1; j <= 1; j++){
      if((x != 0 || y != 0) && cells[x+i][y+j].getObject() != nullptr &&
      cells[x+i][y+j].getObject()->getChar() == 'G'){
        shared_ptr<Gold> g = dynamic_pointer_cast<Gold>(cells[x+i][y+j].getObject());
        if(!g->usable()) { d.setGold(g, x+i, y+j); break;}
      }
    }
  }
}

bool Grid::setDragon(Cell *temp){
  int x = temp->getX();
  int y = temp->getY();
  for(int i = -1; i <= 1; i++){
    for(int j = -1; j <= 1; j++){
      if(0 <= x+i && x+i < height && 0 <= y+j && y+j < width){
        Cell *c = &cells[x+i][y+j];
        if(enemyWalkable(c) && c->getObject() == nullptr){
          c->getObject() = make_shared<Dragon>();
          Dragon &d = *dynamic_pointer_cast<Dragon>(c->getObject());
          shared_ptr<Gold> g = dynamic_pointer_cast<Gold>(temp->getObject());
          d.setGold(g, x+i, y+j);
          return true;
        }
      }
    }
  }
  return false;
}

//****************public methods******************************

Grid::Grid(shared_ptr<ifstream> in, char race): in{in}, race{race}, floor{0},
lv{1}, enemyCanMove{true}, merchantHostile{false}, rh{false}, ba{false}, bd{false},
ph{false}, wa{false}, wd{false}{
  setPlayer();
  Object::message = "";
  loadStage();
}

void Grid::loadStage(){
  //init floor
  if(floor == 0) Object::message = "Player character has spawned.";
  p->initAtkDef();
  Object::global_count = 0;
  floor++;
  srand(time(NULL));
  cells.clear();
  if(in == nullptr){
    // set default stage file
    ifstream in{"defaultfloor.txt"};
    if (in.fail()){
      cerr << "Default stage file does not exist" << endl;
      exit(1);
    }
    // set stage
    for(int x = 0; x < height; x++){
      std::vector<Cell> row;
      char c;
      for(int y = 0; y < width; y++){
        in >> std::noskipws >> c;
        row.push_back(Cell(x, y, c));
      }
      in >> std::noskipws >> c;
      cells.push_back(row);
    }
    std::vector<std::vector<Cell*>> chamber;
    for(int x = 0; x < 5; x++){
      std::vector<Cell*> temp;
      chamber.push_back(temp);
    }
    for(int x = 0; x < height; x++){
      for(int y = 0; y < width; y++){
        Cell *c = &cells[x][y];
        if('0' <= c->getTile() && c->getTile() <= '4'){
          chamber[c->getTile()-'0'].push_back(c);
          c->getTile() = '.';
        }
      }
    }
    // set objects
    // generate PC
    int pRoom = rand()%5;
    Cell *temp = chamber[pRoom][rand()%chamber[pRoom].size()];
    pX = temp->getX();
    pY = temp->getY();
    // generate stair
    int room;
    do{ room = rand()%5; }while(room == pRoom);
    chamber[room][rand()%chamber[room].size()]->getTile() = '\\';
    // generate potion
    for(int x = 0; x < 10; x++){
      room = rand()%5;
      do{
        temp = chamber[room][rand()%chamber[room].size()];
      }while(temp->getObject()!=nullptr || temp->getTile()!='.' ||
      (temp->getX() == pX && temp->getY() == pY));
      switch(rand()%6){
        case 0: temp->getObject() = make_shared<RH>(); break;
        case 1: temp->getObject() = make_shared<BA>(); break;
        case 2: temp->getObject() = make_shared<BD>(); break;
        case 3: temp->getObject() = make_shared<PH>(); break;
        case 4: temp->getObject() = make_shared<WA>(); break;
        case 5: temp->getObject() = make_shared<WD>(); break;
      }
    }
    // generate Gold
    for(int x = 0; x < 10; x++){
      room = rand()%5;
      do{
        temp = chamber[room][rand()%chamber[room].size()];
      }while(temp->getObject()!=nullptr || temp->getTile()!='.' ||
      (temp->getX() == pX && temp->getY() == pY));
      switch(rand()%8){
        case 0: case 1: case 2: case 3: case 4:
        temp->getObject() = make_shared<Gold>(2, true); break;
        case 5: case 6:
        temp->getObject() = make_shared<Gold>(1, true); break;
        case 7:
        temp->getObject() = make_shared<Gold>(6, false);
        if(!setDragon(temp)) x--; break;
      }
    }
    // set Enemies
    for(int x = 0; x < 20; x++){
      room = rand()%5;
      do{
        temp = chamber[room][rand()%chamber[room].size()];
      }while(temp->getObject()!=nullptr || temp->getTile()!='.' ||
      (temp->getX() == pX && temp->getY() == pY));
      switch(rand()%18){
        case 0: case 1: case 3: case 4:
        temp->getObject() = make_shared<Human>(); break;
        case 5: case 6: case 7:
        temp->getObject() = make_shared<Dwarf>(); break;
        case 8: case 9: case 10: case 11: case 12:
        temp->getObject() = make_shared<Halfling>(); break;
        case 13: case 14:
        temp->getObject() = make_shared<Elf>(); break;
        case 15: case 16:
        temp->getObject() = make_shared<Orcs>(); break;
        case 17: case 18:
        temp->getObject() = make_shared<Merchant>(); break;
      }
    }
  }else{
    //read from in and generate map
    for(int x = 0; x < height; x++){
      vector<Cell> row;
      char c;
      for(int y = 0; y < width; y++){
        *in >> std::noskipws >> c;
        if(c == '|' || c == '-' || c == ' ' || c == '+' || c == '#' || c == '.' || c == '\\'){
          row.push_back(Cell(x, y, c));
        }else if(c == '@'){
          pX = x;
          pY = y;
          row.push_back(Cell(x, y, '.'));
        }else{
          row.push_back(Cell(x, y, '.', setObject(c)));
        }
      }
      *in >> std::noskipws >> c;
      cells.push_back(row);
    }
    //find dragon and set dragon hoard to it
    for(int x = 0; x < height; x++){
      for(int y = 0; y < width; y++){
        std::shared_ptr<Object> o = cells[x][y].getObject();
        if(o != nullptr && o->getChar() == 'D') setDragonHoard(*dynamic_pointer_cast<Dragon>(o), x, y);
      }
    }
  }
}

void Grid::movePlayer(std::string command){
  Object::message = "";
  Cell *c = getCell(command, pX, pY);
  if(playerWalkable(c) && (c->getObject() == nullptr || c->getObject()->whoAmI() != "Enemy")){
    Object::message += "PC moves " + getDirection(command);
    if(c->getTile() == '\\'){
      // PC walk on the stair
      Object::message += " and walked down the stair";
      if(floor < 5) {
        loadStage();
        Object::message += " and arrived to the next floor";
      }else{
        p->getHp() = 0;
        Object::message += " and conquered the dangeon. Congratulation! Your score is " + std::to_string(getScore()) + ".";
      }
    }else if(c->getObject() == nullptr || c->getObject()->whoAmI() != "Gold"){
      // PC walk on nothing or potion
      pX = c->getX();
      pY = c->getY();
    }else{
      // PC walk on the gold
      std::shared_ptr<Gold> g = dynamic_pointer_cast<Gold>(c->getObject());
      p->use(*g);
      if(!g->exist()){
        Object::message += " and picked up a gold";
        c->getObject() = nullptr;
      }
      pX = c->getX();
      pY = c->getY();
    }
    // check object around the new location
    for(int x = -1; x <= 1; x++){
      for(int y = -1; y <= 1; y++){
        if(x != 0 || y != 0) checkObject(cells[pX+x][pY+y].getObject());
      }
    }
    Object::message += ".";
  }
  moveEnemy();
}

void Grid::attackEnemy(std::string command){
  Object::message = "";
  Cell *c = getCell(command, pX, pY);
  if(playerWalkable(c) && c->getObject() != nullptr && c->getObject()->whoAmI() == "Enemy"){
    p->attack(*dynamic_pointer_cast<Enemy>(c->getObject()));
    // if enemy is a merchant, turn all merchant hostile
    if(c->getObject()->getChar() == 'M') merchantHostile = true;
    // check whether enemy died
    if(!c->getObject()->exist()){
      c->getObject() = nullptr;
      // if PC is on dragon hoard when killed the dragon, pick up it
      if(cells[pX][pY].getObject() != nullptr && cells[pX][pY].getObject()->getChar() == 'G'){
        std::shared_ptr<Gold> g = dynamic_pointer_cast<Gold>(cells[pX][pY].getObject());
        p->use(*g);
        if(!g->exist()){
          Object::message += " PC picked up a gold.";
          c->getObject() = nullptr;
        }
      }
    }
  }else{
    Object::message = "PC missed.";
  }
  moveEnemy();
}

void Grid::useItem(std::string command){
  // use potion
  Object::message = "";
  Cell *c = getCell(command, pX, pY);
  if(playerWalkable(c) && c->getObject() != nullptr &&
  c->getObject()->whoAmI() != "Enemy" && c->getObject()->whoAmI() != "Gold"){
    p->use(*dynamic_pointer_cast<Potion>(c->getObject()));
    Object::message += ".";
    updatePotion(c->getObject()->whoAmI());
    if(!c->getObject()->exist()) c->getObject() = nullptr;
  }
  moveEnemy();
}

void Grid::moveEnemy(){
  // regains hp if the PC is troll
  if(race == 't') p->getHp() = (p->getHp() + 5 > p->getDfHp())? p->getDfHp() : p->getHp() + 5;
  // Dragon does not move. Only attack enemy when PC is within 1 grid of
  //   Dragon it self or the Dragon hoard
  // Merchant moves randomly and does not attack the PC when not hostile
  // Other enemies and hostile merchant walks towards PC and attack PC when they sees PC(lv cells)
  Object::global_count++;
  for(int x = 0; x < height; x++){
    for(int y = 0; y < width; y++){
      shared_ptr<Object> &o = cells[x][y].getObject();
      if(o != nullptr && o->whoAmI() == "Enemy" && o->getCount() != Object::global_count){
        // calculate the distance from the player
        int dx = pX - x;
        int dy = pY - y;
        if(-1 <= dx && dx <= 1 && -1 <= dy && dy <= 1 && (o->getChar() != 'M' || merchantHostile)){
          // attack player when player is within 1 cell
          p->attacked(*dynamic_pointer_cast<Enemy>(o));
          o->getCount()++;
        }else{
          if(o->getChar() != 'D'){
            if(enemyCanMove){
              // AI for enemy
              if(-lv <= dx && dx <= lv && -lv <= dy && dy <= lv && (o->getChar() != 'M' || merchantHostile)){
                // walks towards the player when player is within lv cells
                int ndx = (dx == 0)? 0 : ((dx < 0)? -1 : 1);
                int ndy = (dy == 0)? 0 : ((dy < 0)? -1 : 1);
                while((ndx == 0 && ndy == 0) || x+ndx < 0 || y + ndy < 0 || x+ndx >= height ||
                y+ndy >= width || (pX == x+ndx && pY == y+ndy) || !enemyWalkable(&cells[x+ndx][y+ndy])){
                  if(dy != 0){
                    if(dx == 0 && ndx == 0) ndx = 1;
                    else if(dx == 0 && ndx == 1) ndx = -1;
                    else if(dx > 0 && ndx == 1) ndx = 0;
                    else if(dx > 0 && ndx == 0) ndx = -1;
                    else if(dx < 0 && ndx == -1) ndx = 0;
                    else if(dx < 0 && ndx == 0) ndx = 1;
                    else { ndx = 0; ndy = 0; break; }
                  }else if(dx != 0){
                    if(dy == 0 && ndy == 0) ndy = 1;
                    else if(dy == 0 && ndy == 1) ndy = -1;
                    else if(dy > 0 && ndy == 1) ndy = 0;
                    else if(dy > 0 && ndy == 0) ndy = -1;
                    else if(dy < 0 && ndy == -1) ndy = 0;
                    else if(dy < 0 && ndy == 0) ndy = 1;
                    else { ndx = 0; ndy = 0; break; }
                  }
                }
                dx = ndx;
                dy = ndy;
              }else{
                // moves randomly
                do{
                  dx = rand()%3-1;
                  dy = rand()%3-1;
                }while((dx == 0 && dy == 0) || x+dx < 0 || y + dy < 0 || x+dx >= height ||
                y+dy >= width || (pX == x+dx && pY == y+dy) || !enemyWalkable(&cells[x+dx][y+dy]));
              }
              o->getCount()++;
              std::swap(cells[x+dx][y+dy].getObject(), o);
            }else{
              o->getCount()++;
            }
          }else{
            // attack PC when PC is next to Dragon or Dragon hoard
            Dragon &d = *dynamic_pointer_cast<Dragon>(o);
            if(d.hasHoard()){
              dx = pX - d.getHX();
              dy = pY - d.getHY();
              if(-1 <= dx && dx <= 1 && -1 <= dy && dy <= 1){
                p->attacked(d);
              }
            }
            o->getCount()++;
          }
        }
      }
    }
  }
  if(p->getHp() <= 0) Object::message += " PC died. Your score is " + std::to_string(getScore()) + ".";
}

void Grid::stopEnemy(){
  enemyCanMove = (enemyCanMove)? false : true;
}

int &Grid::getEnemyLevel(){
  return lv;
}

bool Grid::isPlaying(){
  return !p->isDead();
}

int Grid::getScore(){
  if(race == 's') return p->getGold() * 3 / 2;
  return p->getGold();
}

bool Grid::enemyMovable(){
  return enemyCanMove;
}

Grid::~Grid(){
  cells.clear();
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
  out << "\t\t\t\t\t\tFloor " << g.floor << endl;
  out << "HP: " << g.p->getHp() << endl;
  out << "Atk: " << g.p->getAtk() << endl;
  out << "Def: " << g.p->getDef() << endl;
  out << "Action: " << Object::message << endl;
  return out;
}
