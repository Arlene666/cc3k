#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>

class Object{
public:
  virtual std::string whoAmI() = 0;
  virtual bool exist() = 0;
  virtual char getChar() = 0;
  virtual ~Object(){};
};

#endif
