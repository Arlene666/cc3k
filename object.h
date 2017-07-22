#ifndef OBJECT_H
#define OBJECT_H
#include <string>
using namespace std;

class Object{
private:
  int count = 0;
public:
  static std::string message;
  static int global_count;
  int &getCount(){ return count; }
  virtual std::string whoAmI() = 0;
  virtual bool exist() = 0;
  virtual char getChar() = 0;
  virtual ~Object() = 0;
};

#endif
