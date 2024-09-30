
#ifndef EthernetSerialPort_hpp
	#define EthernetSerialPort_hpp

	#include "SerialPort.hpp"
	#include "NoteHelper.hpp"

	#ifdef pankey_Windows

	#endif

	#ifdef pankey_ArduinoIDE
		#include "Arduino.h"
		#include "IPAddress.h"
		#include "Ethernet.h"
		#include "EthernetServer.h"
		#include "EthernetClient.h"
	#endif

	#ifdef EthernetSerialPort_LogApp
		#include "pankey_Logger_config.hpp"
		#define EthernetSerialPortLog(location,method,type,mns) pankey_Log((void*)this,location,"EthernetSerialPort",method,type,mns)
	#else
		#define EthernetSerialPortLog(location,method,type,mns)
	#endif

	namespace pankey{

		class EthernetSerialPort : public SerialPort{	
			public:
				EthernetSerialPort(){
					EthernetSerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", "");
					EthernetSerialPortLog(pankey_Log_EndMethod, "Contructor",  "println", "");
				}

				EthernetSerialPort(Note a_name){
					EthernetSerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", a_name);
					m_name = a_name;
					EthernetSerialPortLog(pankey_Log_EndMethod, "Contructor",  "println", "");
				}

				virtual ~EthernetSerialPort(){
					EthernetSerialPortLog(pankey_Log_StartMethod, "Destructor",  "println", "");
					if(connected()){
						stop();
					}
					EthernetSerialPortLog(pankey_Log_EndMethod, "Destructor",  "println", "");
				}

				#ifdef pankey_ArduinoIDE

					EthernetSerialPort(const EthernetSerialPort& a_ethernet){
						EthernetSerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", a_name);
						m_client = a_ethernet.m_client;
						m_name = a_ethernet.m_name;
						EthernetSerialPortLog(pankey_Log_EndMethod, "Contructor",  "println", "");
					}

					EthernetSerialPort(EthernetClient a_client){
						EthernetSerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", "eclient");
						m_client = a_client;
						m_name = "eclient";
						EthernetSerialPortLog(pankey_Log_EndMethod, "Contructor",  "println", "");
					}

					EthernetSerialPort(EthernetClient a_client,Note a_name){
						EthernetSerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", a_name);
						m_client = a_client;
						m_name = a_name;
						EthernetSerialPortLog(pankey_Log_EndMethod, "Contructor",  "println", "");
					}

					int status(){
						EthernetSerialPortLog(pankey_Log_StartMethod, "status",  "println", "");
						EthernetSerialPortLog(pankey_Log_EndMethod, "status",  "println", "");
						return m_client.status();
					}

					int available(){
						EthernetSerialPortLog(pankey_Log_StartMethod, "available",  "println", "");
						EthernetSerialPortLog(pankey_Log_EndMethod, "available",  "println", "");
						return m_client.available();
					}

					int read(){
						EthernetSerialPortLog(pankey_Log_StartMethod, "read",  "println", "");
						EthernetSerialPortLog(pankey_Log_EndMethod, "read",  "println", "");
						return m_client.read();
					}

					virtual int peek(){
						EthernetSerialPortLog(pankey_Log_StartMethod, "peek",  "println", "");
						EthernetSerialPortLog(pankey_Log_EndMethod, "peek",  "println", "");
						return m_client.peek();
					}

					virtual pointer_size write(int chr){
						EthernetSerialPortLog(pankey_Log_StartMethod, "write",  "println", Note(chr));
						EthernetSerialPortLog(pankey_Log_EndMethod, "write",  "println", "");
						return m_client.write(chr);
					}

					virtual size_t write(uint8_t chr){
						EthernetSerialPortLog(pankey_Log_StartMethod, "write",  "println", Note(chr));
						EthernetSerialPortLog(pankey_Log_EndMethod, "write",  "println", "");
						return m_client.write(chr);
					}

					virtual bool connected(){
						EthernetSerialPortLog(pankey_Log_StartMethod, "connected",  "println", "");
						EthernetSerialPortLog(pankey_Log_EndMethod, "connected",  "println", "");
						return m_client.connected();
					}
					
					virtual bool connect(const Note& a_address){
						EthernetSerialPortLog(pankey_Log_StartMethod, "connect",  "println", "");
						EthernetSerialPortLog(pankey_Log_EndMethod, "connect",  "println", "");
						return connect(a_address,-1);
					}
					
					virtual bool connect(const Note& a_address, int port){
						EthernetSerialPortLog(pankey_Log_StartMethod, "connect",  "println", "");
						
						IPAddress ip = toIPAddress(a_address);
						
						EthernetSerialPortLog(pankey_Log_EndMethod, "connect",  "println", "");
						return m_client.connect(ip, port);
					}
					
					virtual void stop(){
						EthernetSerialPortLog(pankey_Log_StartMethod, "stop",  "println", "");
						m_client.stop();
						EthernetSerialPortLog(pankey_Log_EndMethod, "stop",  "println", "");
					}

					virtual void flush(){
						EthernetSerialPortLog(pankey_Log_StartMethod, "flush",  "println", "");
						m_client.flush();
						EthernetSerialPortLog(pankey_Log_EndMethod, "flush",  "println", "");
					}
					
					virtual pointer_size print(Note s){
						EthernetSerialPortLog(pankey_Log_StartMethod, "print",  "println", "");
						EthernetSerialPortLog(pankey_Log_EndMethod, "print",  "println", "");
						return m_client.print(s);
					}
					
					virtual pointer_size println(Note s){
						EthernetSerialPortLog(pankey_Log_StartMethod, "println",  "println", "");
						EthernetSerialPortLog(pankey_Log_EndMethod, "println",  "println", "");
						return m_client.println(s);
					}
					
					virtual void send(Note s){
						EthernetSerialPortLog(pankey_Log_StartMethod, "send",  "println", "");
						m_client.println(s);
						EthernetSerialPortLog(pankey_Log_EndMethod, "send",  "println", "");
					}

					virtual void operator=(EthernetClient c){
						EthernetSerialPortLog(pankey_Log_StartMethod, "operator=",  "println", "");
						m_client = c;
						EthernetSerialPortLog(pankey_Log_EndMethod, "operator=",  "println", "");
					}
					virtual bool operator==(EthernetSerialPort c){
						EthernetSerialPortLog(pankey_Log_StartMethod, "operator==",  "println", "");
						EthernetSerialPortLog(pankey_Log_EndMethod, "operator==",  "println", "");
						return m_client == c.m_client;
					}
					virtual bool operator!=(EthernetSerialPort c){
						EthernetSerialPortLog(pankey_Log_StartMethod, "operator!=",  "println", "");
						EthernetSerialPortLog(pankey_Log_EndMethod, "operator!=",  "println", "");
						return m_client != c.m_client;
					}
					virtual operator bool(){
						EthernetSerialPortLog(pankey_Log_StartMethod, "operator bool",  "println", "");
						EthernetSerialPortLog(pankey_Log_EndMethod, "operator bool",  "println", "");
						return m_client;
					}
					
				#endif

			protected:
				#ifdef pankey_Windows

				#endif

				#ifdef pankey_ArduinoIDE
					EthernetClient m_client;
				#endif
		};

	}

#endif