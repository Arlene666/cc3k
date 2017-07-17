#include "grid.h"
#include "ifstream"
#include "iostream"

using namespace std;

int main(int argc, char *argv[]){
  Grid g;

  if(argc - 1 == 1){
    //load stage file
    string fname = argv[1];
    ifstream in{fname.c_str()};
    if (in->fail()){
      cerr << "Stage file does not exist" << endl;
      exit(1);
    }
  }

  char c;
  string s;
  bool gameOver = false;
  while(!gameOver){
    // set the player race
    while(1){
      cin >> c;
      if(c == 's' || c == 'd' || c == 'v' || c == 'g' || c == 't') {
        if(argc - 1 == 1) g{in, c};
        else g{c};
        break;
      }
    }
    // take in commands
    while(g.isPlaying() && getline(cin, s)){
      if(s[0] == 'u'){
        g.useItem(s);
        cout << g;
      }else if(s[0] == a){
        g.attackEnemy(s);
        cout << g;
      }else if(s[0] == 'f'){

      }else if(s[0] == 'r'){
        gameOver = false;
        break;
      }else if(s[0] == 'q'){
        gameOver = true;
        break;
      }else{
        g.movePlayer(s);
        cout << g;
      }
    }
    if(!g.isPlaying()){
      cout << "Would you like to play again?[y/n]"
      cin >> c;
      if(c == 'n') gameOver = true;
    }
  }

}
