
#ifndef Ethernet2SerialPortClient_h
#define Ethernet2SerialPortClient_h

#include "SerialPort.h"
#include "EthernetServer.h"
#include "IPAddress.h"
#include "EthernetClient.h"
#include "Ethernet2.h"

class Ethernet2SerialPortClient : public SerialPort{	
    public:
		Ethernet2SerialPortClient(IPAddress s,IPAddress i, byte MAC[6]){
			server = s;
			ip = i;
			for(int x = 0; x < 6; x++){
				mac[x] = MAC[x];
			}
			client.connect(server, 5510);
			Ethernet.begin(mac, ip);
		}
		virtual ~Ethernet2SerialPortClient(){
		}
		int available(String s){
			return client.available();
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
		IPAddress server;
		IPAddress ip;
};
#endif 
