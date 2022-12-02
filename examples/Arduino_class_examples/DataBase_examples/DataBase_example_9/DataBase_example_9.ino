
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
//#include "esp_wifi.h"
//#include "esp_system.h"
//#include "esp_err.h"
//#include "esp_event_loop.h"
//#include "freertos/event_groups.h"
//#include "esp_event.h"
//#include "esp_attr.h"
//#include "esp_log.h"
//#include "esp_eth.h"
//
//
//#include "rom/ets_sys.h"
//#include "rom/gpio.h"
//
//#include "soc/dport_reg.h"
//#include "soc/io_mux_reg.h"
//#include "soc/rtc_cntl_reg.h"
//#include "soc/gpio_reg.h"
//#include "soc/gpio_sig_map.h"
//
//#include "tcpip_adapter.h"
//#include "nvs_flash.h"
//#include "driver/gpio.h"
//
//#include "eth_phy/phy_lan8720.h"
//
//#include "lwip/err.h"
//#include "lwip/sockets.h"
//#include "lwip/sys.h"
//#include "lwip/netdb.h"
//#include "lwip/dns.h"
//
//#define DEFAULT_ETHERNET_PHY_CONFIG phy_lan8720_default_ethernet_config
// #define PIN_PHY_POWER CONFIG_PHY_POWER_PIN        //not needed for our board configuration

#define PIN_SMI_MDC   GPIO_NUM_23
#define PIN_SMI_MDIO  GPIO_NUM_18

#define TCP_SERVER_PORT     3000


#define RESET_P  26

#define LogApp
#define DataBaseStateLogApp
//#define ObjectDataBaseConfigLogApp
//#define TextExporterLogApp
//#define TextImporterLogApp
//#define MonkeyFileLogApp

#include "DefaultLogging.hpp"
#include "Logger.hpp"

#include "Application.hpp"
#include "DefaultApplication.hpp"

#include "SerialMessageState.hpp"
#include "DefaultSerialPort.hpp"
#include "StartEndPortProtocol.hpp"//has to be next to SerialMessageState

#include <WiFi.h>
#include "WIFISerialServer.hpp"
#include "DefaultServerProtocol.hpp"

#include "DataBaseState.hpp"
#include "ObjectDataBaseConfig.hpp"
#include "FileDataBaseConfig.hpp"

#include "SystemListener.hpp"
#include "Now.hpp"
#include "TimeCheck.hpp"

IPAddress ip(192, 168, 4, 151);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(192, 168, 4, 1);
byte mac[] = {0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0};

using namespace ame;

Application* app;

void WizReset() {
    Serial.print("Resetting Wiz W5500 Ethernet Board...  ");
    pinMode(RESET_P, OUTPUT);
    digitalWrite(RESET_P, HIGH);
    delay(250);
    digitalWrite(RESET_P, LOW);
    delay(50);
    digitalWrite(RESET_P, HIGH);
    delay(350);
    Serial.println("Done.");
}

void setup() {
  Serial.begin(9600);
  initializeLogger(new DefaultLogging(&Serial, true, false));
  LogClass("DataBaseState");
//  LogClass("ObjectDataBaseConfig");
//  LogClass("TextExporter");
//  LogClass("TextImporter");
//  LogClass("MonkeyFile");

//  WiFi.mode(WIFI_STA);
//  WiFi.setSleep(false);
    Ethernet.init(5);           // GPIO5 on the ESP32.
    WizReset();
    Ethernet.begin(mac, ip, dns, gateway, subnet);
    // Check for Ethernet hardware present
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
         Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
        while (true) {
             delay(1); // do nothing, no point running without Ethernet hardware
        }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
          Serial.println("Ethernet cable is not connected.");
    }

  

  app = new DefaultApplication();

  SerialMessageState* serialState = app->getStateManager()->addState(new SerialMessageState());
  serialState->addSerialServer(new WIFISerialServer(ip,gateway,subnet,55), new DefaultServerProtocol<StartEndPortProtocol>());
  serialState->addSerialPort(new DefaultSerialPort(&Serial,"usb"), new StartEndPortProtocol());

  serialState->addListener(new SystemListener(app));

  DataBaseState* database = app->getStateManager()->addState(new DataBaseState());
  database->addDataBaseConfig("file", new FileDataBaseConfig());
  DataBaseConfig* objectCenter = database->addDataBaseConfig("object", new ObjectDataBaseConfig());
  objectCenter->setFileSize(5);

  
    Serial.print("Ethernet IP is: ");
    Serial.println(Ethernet.localIP());
}
EthernetUDP Udp;
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
char ReplyBuffer[] = "acknowledged";

void runConnectLocal() {
  int packetSize = Udp.parsePacket();
  if (packetSize) {
  Serial.println("Passou conexão local " + packetSize);
  Serial.print("Received packet of size ");
  Serial.println(packetSize);
  Serial.print("From ");
  IPAddress remote = Udp.remoteIP();
  for (int i=0; i < 4; i++) {
  Serial.print(remote[i], DEC);
  if (i < 3) {
  Serial.print(".");
  }
  }
  Serial.print(", port ");
  Serial.println(Udp.remotePort());
  
  // read the packet into packetBufffer
  Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
  Serial.print("Contents: ");
  Serial.println(packetBuffer);
  
  // send a reply to the IP address and port that sent us the packet we received
  Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
  Udp.write(ReplyBuffer);
  Udp.endPacket();
  }
}
void loop() {
  app->update();
//  runConnectLocal();
}
