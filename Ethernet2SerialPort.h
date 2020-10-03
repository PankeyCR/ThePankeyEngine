
#ifndef Ethernet2SerialPort_h
#define Ethernet2SerialPort_h

#include "SerialPort.h"
#include "EthernetServer.h"
#include "IPAddress.h"
#include "EthernetClient.h"

class Ethernet2SerialPort : public SerialPort{	
    public:
		Ethernet2SerialPort(int s, 
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
		}
		virtual ~Ethernet2SerialPort(){
		}
		bool available(String s){
			client = server.available();
			if(client){
				return client.available();
			}
			return false;
		}
		char read(){
			return client.read();
		}
		virtual void print(String mns){
			// if(client == nullptr){
				// return;
			// }
			client.print(mns);
		}
		virtual bool connected(){
			return client.connected();
		}
		virtual void stop(){
			client.stop();
		}
	protected:
		EthernetClient client;
		byte mac[6];
		IPAddress ip;
		IPAddress gateway;
		IPAddress subnet;
		EthernetServer server;
};
#endif 
