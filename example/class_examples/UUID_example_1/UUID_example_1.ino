
#include "UUID.hpp"
#include "SerialConnection.hpp"
#include "Note.hpp"

long count = 0;
long precount = 0;
long sameValue = 0;

using namespace ame;

UUID uuid;
SerialConnection* serialConnection;

void setup() {
  Serial.begin(9600);
  uuid = UUID();
  serialConnection = new SerialConnection();
  serialConnection->setPort(&Serial);
}

void loop() {
  UUID uuid_2;
//  Serial.print("uuid ");Serial.println(uuid);
//  Serial.print("uuid_2 ");Serial.println(uuid_2);
  if(uuid == uuid_2){
    Serial.println("same");
    Serial.print("uuid ");Serial.println(uuid);
    Serial.print("uuid_2 ");Serial.println(uuid_2);
    sameValue++;
    Serial.print("sameValue ");Serial.println(sameValue);
    Serial.print("precount ");Serial.println(precount);
    Serial.print("count ");Serial.println(count);
    precount = 0;
  }
  count++;
  precount++;
  Note text = serialConnection->safeReceive('\n');
//  Serial.print("text ");Serial.println(text);
  if(text != ""){
    if(text == "uuid"){
      uuid = UUID();
      Serial.print("uuid ");Serial.println(uuid);
      Serial.print("uuid_2 ");Serial.println(uuid_2);
      sameValue = 0;
      count = 0;
      precount = 0;
    }
  }
}
