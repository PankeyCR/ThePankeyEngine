
#ifndef FlyMonkey_h
#define FlyMonkey_h

#include "Method.h"
#include "cppObject.h"

class FlyMonkey{
public:

FlyMonkey(){
}
virtual ~FlyMonkey(){}

bool invoke(String method){
  if(method == "println"){
    Serial.println(method);
    return true;
  }
  return false;
}

protected:
};

#endif 
