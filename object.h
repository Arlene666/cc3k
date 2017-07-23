#ifndef OBJECT_H
#define OBJECT_H
#include <string>
using namespace std;

class Object{
private:
  int count = 0;
  virtual std::string whoAmIImpl() = 0;
  virtual bool existImpl() = 0;
  virtual char getCharImpl() = 0;
public:
  static std::string message;
  static int global_count;
  int &getCount(){ return count; }
  std::string whoAmI();
  bool exist();
  char getChar();
  virtual ~Object() = 0;
};

#endif
