
#include "Computer.hpp"

using namespace ame;

void Move(Computer<MonkeyHardware>* computer, const typename MonkeyHardware::Instruction& intruction){

}

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Computer<MonkeyHardware> computer;
  computer.add(Move);
  computer.compute(MonkeyInstruction::move_value_to_reg);
  computer.compute(0b00000000);//register
  computer.compute(0b00000110);//value

  MonkeyHardware* hardware = computer.getHardware();
  auto value = hardware->getRegister(1);

  System::console.println(value);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}




//