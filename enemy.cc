#include "enemy.h"
#include <cstdlib>
#include <cmath>

//*********protected methods**********************************

int Enemy::damage(float atk, float def){
  return ceil((100/(100+def))*atk);
}

//********public methods***********************************

bool Enemy::exist(){
  return hp > 0;
}
