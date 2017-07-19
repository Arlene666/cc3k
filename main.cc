#include "grid.h"
#include <fstream>
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char *argv[]){
  shared_ptr<Grid> g;
  shared_ptr<ifstream> in;

  if(argc - 1 == 1){
    //load stage file
    string fname = argv[1];
    in = make_shared<ifstream>(fname);
    if (in->fail()){
      cerr << "Stage file does not exist" << endl;
      exit(1);
    }
  }else{
    in = make_shared<ifstream>("cc3kfloor.txt");
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
        cout << g;
      }else if(s[0] == 'a'){
        g->attackEnemy(s.substr(1));
        cout << g;
      }else if(s[0] == 'f'){

      }else if(s[0] == 'r'){
        gameOver = false;
        break;
      }else if(s[0] == 'q'){
        gameOver = true;
        break;
      }else{
        g->movePlayer(s);
        cout << g;
      }
    }
    if(!g->isPlaying()){
      cout << "Would you like to play again?[y/n]";
      cin >> c;
      if(c == 'n') gameOver = true;
    }
  }

}
