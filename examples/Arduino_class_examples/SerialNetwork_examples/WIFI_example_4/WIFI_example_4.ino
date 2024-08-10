
#include "higgs_WIFI.hpp"

using namespace higgs;

void setup() {
  Serial.begin(9600);

  delay(4000);

  configWIFI( "10.10.10.10.10.150");    //mac
}

void loop() {

  configWIFI( "192.168.1.140"       ,   //ip
              "192.168.1.1"         ,   //gateway
              "192.168.1.1"         ,   //subnet
              "255.255.255.0");         //dns

  connectWIFI("MERCUSYS_6541" ,       //router name
              "57924106");            //router password

              //router name MERCUSYS_6541 - pokemon - Cristo
              //router password 57924106 - tania1919 - Jesucristo#1

  Serial.println("Connecting");

  delay(10000);

  disconnectWIFI();
  Serial.println("Disconnected");
  
  delay(2000);

  configWIFI( "192.168.1.141"       ,   //ip
              "192.168.1.1"         ,   //gateway
              "192.168.1.1"         ,   //subnet
              "255.255.255.0");         //dns

  connectWIFI("MERCUSYS_6541" ,       //router name
              "57924106");            //router password

              //router name MERCUSYS_6541 - pokemon - Cristo
              //router password 57924106 - tania1919 - Jesucristo#1
              
  Serial.println("Connecting");
  
  delay(10000);

  disconnectWIFI();
  Serial.println("Disconnected");
  
  delay(2000);
}