#ifndef OBJECT_H
#define OBJECT_H
#include <string>
using namespace std;

class Object{
public:
  static std::string message;
  virtual std::string whoAmI() = 0;
  virtual bool exist() = 0;
  virtual char getChar() = 0;
  virtual ~Object(){};
};

#endif
