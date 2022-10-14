
#include "CommandReader.hpp"

using namespace ame;

CommandReader cmd;

String text = "";

void setup() {
  Serial.begin(9600);
  Serial.println("CommandReader_example_1");
  text += "start playing\n";
  text += "singleCommand_1\n";
  text += "end playing_2\n";
  text += "singleCommand_2\n";
  text += "turn right\n";
  text += "onturn left\n";

  Serial.println(text);
  cmd.setText(text);
}

void loop() {
  Serial.println("/////////////////////////////////////// start");
  int x_1 = cmd.getCommandOrder("start");
  int x_2 = cmd.getCommandOrder("singleCommand_1");
  int x_3 = cmd.getCommandOrder("end");
  int x_4 = cmd.getCommandOrder("singleCommand_2");
  int x_5 = cmd.getCommandOrder("turn");
  int x_6 = cmd.getCommandOrder("onturn");

  Serial.print("x_1 ");Serial.println(x_1);
  Serial.print("x_2 ");Serial.println(x_2);
  Serial.print("x_3 ");Serial.println(x_3);
  Serial.print("x_4 ");Serial.println(x_4);
  Serial.print("x_5 ");Serial.println(x_5);
  Serial.print("x_6 ");Serial.println(x_6);
  
  Serial.print("Line 1: ");Serial.println(cmd.getLine(0));
  Serial.print("Line 2: ");Serial.println(cmd.getLine(1));
  Serial.print("Line 3: ");Serial.println(cmd.getLine(2));
  Serial.print("Line 4: ");Serial.println(cmd.getLine(3));
  Serial.print("Line 5: ");Serial.println(cmd.getLine(4));
  Serial.print("Line 6: ");Serial.println(cmd.getLine(5));
  
  Serial.print("Command 1: ");Serial.println(cmd.getCommand(0));
  Serial.print("Command 2: ");Serial.println(cmd.getCommand(1));
  Serial.print("Command 3: ");Serial.println(cmd.getCommand(2));
  Serial.print("Command 4: ");Serial.println(cmd.getCommand(3));
  Serial.print("Command 5: ");Serial.println(cmd.getCommand(4));
  Serial.print("Command 6: ");Serial.println(cmd.getCommand(5));
  
  Serial.print("Argument 1: ");Serial.println(cmd.getArgument(0));
  Serial.print("Argument 2: ");Serial.println(cmd.getArgument(1));
  Serial.print("Argument 3: ");Serial.println(cmd.getArgument(2));
  Serial.print("Argument 4: ");Serial.println(cmd.getArgument(3));
  Serial.print("Argument 5: ");Serial.println(cmd.getArgument(4));
  Serial.print("Argument 6: ");Serial.println(cmd.getArgument(5));
  
  Serial.print("Enter Size: ");Serial.println(cmd.getEnterSize());
  
  Serial.println("/////////////////////////////////////// end");
}
