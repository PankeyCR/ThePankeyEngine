
#ifndef Ethernet2SerialPortServer_h
#define Ethernet2SerialPortServer_h

#include "SerialPort.h"
#include "EthernetServer.h"
#include "IPAddress.h"
#include "EthernetClient.h"
#include "Ethernet2.h"

#if defined(ESP8266)
  // default for ESPressif
  #define WIZ_CS 15
#elif defined(ESP32)
  #define WIZ_CS 33
#elif defined(ARDUINO_STM32_FEATHER)
  // default for WICED
  #define WIZ_CS PB4
#elif defined(TEENSYDUINO)
  #define WIZ_CS 10
#elif defined(ARDUINO_FEATHER52)
  #define WIZ_CS 11
#else   // default for 328p, 32u4 and m0
  #define WIZ_CS 10
#endif

class Ethernet2SerialPortServer : public SerialPort{	
    public:
		Ethernet2SerialPortServer(int s, 
							IPAddress IP, 
							IPAddress GATEWAY, 
							IPAddress SUBNET,
							byte MAC[6]):server(s){
			ip = IP;
			gateway = GATEWAY;
			subnet = SUBNET;
			for(int x = 0; x < 6; x++){
				mac[x] = MAC[x];
			}
			Ethernet.init(WIZ_CS);
			Ethernet.begin(mac, ip, gateway, subnet);
			server.begin();
		}
		virtual ~Ethernet2SerialPortServer(){
		}
		int available(String s){
			client = server.available();
			Serial.println("cliente");
			if(client){
				return client.available();
			}
			return false;
		}
		int read(){
			return client.read();
		}
		virtual int peek(){
			return client.peek();
		}
		virtual size_t write(uint8_t chr){
			return client.write(chr);
		}
		virtual bool connected(){
			return client.connected();
		}
		virtual void stop(){
			client.stop();
		}
		virtual void flush(){
			client.flush();
		}
		virtual operator bool(){return client;}
	protected:
		EthernetClient client;
		byte mac[6];
		IPAddress ip;
		IPAddress gateway;
		IPAddress subnet;
		EthernetServer server;
};
#endif 
