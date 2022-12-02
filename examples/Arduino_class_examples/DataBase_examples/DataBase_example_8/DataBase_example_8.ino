
#include <ETH.h>
#include <SPI.h>

// #define ETH_CLK_MODE    ETH_CLOCK_GPIO0_OUT          // Version with PSRAM
#define ETH_CLK_MODE    ETH_CLOCK_GPIO17_OUT            // Version with not PSRAM

// Pin# of the enable signal for the external crystal oscillator (-1 to disable for internal APLL source)
#define ETH_POWER_PIN   -1

// Type of the Ethernet PHY (LAN8720 or TLK110)
#define ETH_TYPE        ETH_PHY_LAN8720

// I²C-address of Ethernet PHY (0 or 1 for LAN8720, 31 for TLK110)
#define ETH_ADDR        0

// Pin# of the I²C clock signal for the Ethernet PHY
#define ETH_MDC_PIN     23

// Pin# of the I²C IO signal for the Ethernet PHY
#define ETH_MDIO_PIN    18

#define NRST            5
static bool eth_connected = false;


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

using namespace ame;

Application* app;

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

  pinMode(NRST, OUTPUT);
  digitalWrite(NRST, 0);
  delay(200);
  digitalWrite(NRST, 1);
  delay(200);
  digitalWrite(NRST, 0);
  delay(200);
  digitalWrite(NRST, 1);
  
  ETH.begin(ETH_ADDR, ETH_POWER_PIN, ETH_MDC_PIN, ETH_MDIO_PIN, ETH_TYPE, ETH_CLK_MODE);
  

  app = new DefaultApplication();

  SerialMessageState* serialState = app->getStateManager()->addState(new SerialMessageState());
  serialState->addSerialServer(new WIFISerialServer(ip,gateway,subnet,55), new DefaultServerProtocol<StartEndPortProtocol>());
  serialState->addSerialPort(new DefaultSerialPort(&Serial,"usb"), new StartEndPortProtocol());

  serialState->addListener(new SystemListener(app));

  DataBaseState* database = app->getStateManager()->addState(new DataBaseState());
  database->addDataBaseConfig("file", new FileDataBaseConfig());
  DataBaseConfig* objectCenter = database->addDataBaseConfig("object", new ObjectDataBaseConfig());
  objectCenter->setFileSize(5);
}

void loop() {
  app->update();
  Serial.println(ETH.localIP());
}
