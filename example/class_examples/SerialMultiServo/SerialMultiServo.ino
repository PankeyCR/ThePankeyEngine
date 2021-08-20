
#include "SimpleServo.h"
#include "SerialController.h"

using namespace ame;

SimpleServo *servos;
SerialController *serial;
String buff;  

void setup() {
  Serial.begin(9600);    
  serial = new SerialController();
  serial->setPort(&Serial);
  
  servos = new SimpleServo();
  servos->setup(5);

  servos->attach(0,24);        
  servos->attach(1,26);
  servos->attach(2,28);
  servos->attach(3,30);
  servos->attach(4,31);
        
  servos->MoveServo(0,45);
  servos->MoveServo(1,45);
  servos->MoveServo(2,45);
  servos->MoveServo(3,45);
  servos->MoveServo(4,45);
}

void loop() {
  serial->update(0.1f);
  buff = serial->safeReceive('{','}');        
  String buff_0 = "";

  if(buff != ""){
    buff_0 = serial->Split(buff,0,' ');
  }
      
  if(buff_0 == "angulo"){
    int buff_angulo = serial->Split(buff,1,' ').toInt();
    servos->MoveServo(0,buff_angulo);
    }
  if(buff_0 == "comando1"){
    int buff_angulo1 = serial->Split(buff,1,' ').toInt();
    int buff_angulo2 = serial->Split(buff,2,' ').toInt();
    servos->MoveServo(0,buff_angulo1);
    servos->MoveServo(1,buff_angulo2);
  }

}
