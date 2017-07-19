#include "grid.h"
#include <fstream>
#include <iostream>
#include <memory>
#include "grid.h"

using namespace std;

int main(int argc, char *argv[]){
  shared_ptr<Grid> g;
  shared_ptr<ifstream> in;
  string fname;

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

  char c;
  string s;
  bool gameOver = false;

  while(!gameOver){
    // set the player race
    while(1){
      cin >> c;
      if(c == 's' || c == 'd' || c == 'v' || c == 'g' || c == 't') {
        g = make_shared<Grid>(in, c);
        break;
      }
    }
    // take in commands
    while(g->isPlaying() && getline(cin, s)){
      if(s[0] == 'u'){
        g->useItem(s.substr(1));
        cout << *g;
      }else if(s[0] == 'a'){
        g->attackEnemy(s.substr(1));
        cout << *g;
      }else if(s[0] == 'f'){
        g->stopEnemy();
        cout << *g;
      }else if(s[0] == 'r'){
        gameOver = false;
        break;
      }else if(s[0] == 'q'){
        gameOver = true;
        break;
      }else{
        g->movePlayer(s);
        cout << *g;
      }
    }
    if(!g->isPlaying()){
      cout << "Would you like to play again?[y/n]";
      cin >> c;
      if(c == 'n') gameOver = true;
    }
  }

}
