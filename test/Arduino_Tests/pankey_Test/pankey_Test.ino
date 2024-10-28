
#include "config.hpp"

void setup() {
  Serial.begin(9600);
  Serial.println("Starting the test");
}

void loop() {
  Serial.print("Enviroment: ");
  Serial.print(pankey_Enviroment);
  Serial.print(" ");
  Serial.println(pankey_Enviroment_Name);
  
  Serial.print("IDE: ");
  Serial.print(pankey_IDE);
  Serial.print(" ");
  Serial.println(pankey_IDE_Name);
  
  Serial.print("Chip: ");
  Serial.print(pankey_Chip);
  Serial.print(" ");
  Serial.println(pankey_Chip_Name);
  
  Serial.print("Hardware: ");
  Serial.print(pankey_Hardware);
  Serial.print(" ");
  Serial.println(pankey_Hardware_Name);
  
  Serial.print("Level: ");
  Serial.println(pankey_Level);
  
  Serial.print("Context: ");
  Serial.print(pankey_Context);
  Serial.print(" ");
  Serial.println(pankey_Context_Name);
  delay(5000);
}