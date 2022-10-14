
#include "SerialConnection.hpp"
#include "Note.hpp"

using namespace ame;

SerialConnection *serial;
Note buff;  

void setup() {
  Serial.begin(9600);
  serial = new SerialConnection();
  serial->setPort(&Serial);
}

void loop() {
  buff = serial->safeReceive('{','}');        
  Note buff_0 = "";

  if(buff != ""){
    buff_0 = serial->Split(buff,0,' ');
  }
      
  if(buff_0 == "angulo"){
    serial->println("angulo entregado");
  }
  
  if(buff_0 == "comando1"){
    serial->println("commando1 entregado");
  }
  if(buff_0 == "comando2"){
    serial->println("commando2 entregado");
  }

}
