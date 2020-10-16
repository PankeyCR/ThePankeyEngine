
#ifndef CommandControl_h
#define CommandControl_h

#include "Ethernet2SerialPortServer.h"
#include "Ethernet2SerialPortClient.h"

class CommandControl{
public:
CommandControl(){
}
virtual ~CommandControl(){}

bool invokeGlobal(String method){
  Serial.println(method);
  return true;
}
bool invokeGlobal(String method, String parameter1){
  return false;
}
bool invokeGlobal(String method, String parameter1, String parameter2){
  return false;
}
bool invoke(String method){
  Serial.println(method);
  return true;
}
bool invoke(String method, String parameter1){
  return false;
}
bool invoke(String method, String parameter1, String parameter2){
  return false;
}

void operator=(CommandControl b){}
bool operator==(CommandControl b){return false;}
bool operator!=(CommandControl b){return false;}


protected:
};

#endif 
