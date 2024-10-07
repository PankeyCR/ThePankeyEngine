
#include "Application.hpp"
#include "SerialState.hpp"
#include "WIFISerialServer.hpp"
#include "DefaultServerProtocol.hpp"
#include "DefaultPortProtocol.hpp"
#include "WIFIConnection.hpp"

using namespace pankey;

Application app;

void setup() {
  Serial.begin(9600);

  delay(4000);

  initializeWIFI( "10.10.10.10.10.150"  ,     //mac
                  "192.168.1.141"       ,     //ip
                  "192.168.1.1"         ,     //gateway
                  "192.168.1.1"         ,     //subnet
                  "255.255.255.0"       ,     //dns
                  "MERCUSYS_6541"       ,     //router name
                  "57924106");                //router password

                  //router name MERCUSYS_6541 - pokemon - Cristo - PankeyCR
                  //router password 57924106 - tania1919 - Jesucristo#1 - gtuz4549

  haltUntilWIFIConnection();

  SerialState serial;
  WIFISerialServer server = 101;
  DefaultServerProtocol<DefaultPortProtocol> protocol;
  serial.addSerialServer(server, protocol);
  serial.addDelivery(Event_Message);

  auto& i_manager = app.getStateManager();
  i_manager.app_state_timed_functions_list.add(serial);
  
  app.initialize();
}

void loop() {
  app.update();
}

void Event_Message(Application& a_app, const Note& a_message){
  System::console.println(a_message);
  int i_message_size = a_message.getSplitSize(' ');
  if(i_message_size == 0){
    if(a_message == "getRam"){
      System::console.println(getRamSize());
    }
  }
}