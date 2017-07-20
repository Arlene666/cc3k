#include "grid.h"
#include <fstream>
#include <iostream>
#include <memory>
#include "grid.h"
using namespace std;

std::string Object::message;

int main(int argc, char *argv[]){
  std::shared_ptr<Grid> g;
  std::shared_ptr<std::ifstream> in;
  std::string fname;

  if(argc - 1 == 1){
    fname = argv[1];
  }else{
    fname = "cc3kfloor.txt";
  }
  // load stage file
  in = make_shared<ifstream>(fname);
  if (in->fail()){
    cerr << "Stage file does not exist" << endl;
    exit(1);
  }

  string s;
  bool gameOver = false;

  while(!gameOver){
    // set the player race
    while(1){
      getline(cin, s);
      if(s.at(0) == 's' || s.at(0) == 'd' || s.at(0) == 'v' || s.at(0) == 'g' || s.at(0) == 't') {
        g = make_shared<Grid>(in, s.at(0));
        cout << *g;
        break;
      }
    }
    // take in commands
    while(g->isPlaying() && getline(cin, s)){
      if(s.at(0) == 'u'){
        g->useItem(s.substr(1));
        cout << *g;
      }else if(s.at(0) == 'a'){
        g->attackEnemy(s.substr(1));
        cout << *g;
      }else if(s.at(0) == 'f'){
        g->stopEnemy();
        cout << *g;
      }else if(s.at(0) == 'r'){
        gameOver = false;
        break;
      }else if(s.at(0) == 'q'){
        gameOver = true;
        break;
      }else{
        g->movePlayer(s);
        cout << *g;
      }
    }
    if(!g->isPlaying()){
      cout << "Would you like to play again?[y/n]";
      getline(cin, s);
      if(s.at(0) == 'n') gameOver = true;
    }
  }

}
