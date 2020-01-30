
#include "SerialController.h"

SerialController *serial;
String buff;  

void setup() {
  Serial.begin(9600);
  serial = new SerialController();
  serial->setPort(&Serial);
}

void loop() {
  serial->update(0.1f);
  buff = serial->safeReceive('{','}');        
  String buff_0 = "";

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
