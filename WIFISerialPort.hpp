
#ifndef WIFISerialPort_hpp
	#define WIFISerialPort_hpp

	#ifdef pankey_Windows

	#endif

	#ifdef pankey_ArduinoIDE
		#include "Arduino.h"
		#include "Printable.h"
		#include "IPAddress.h"
	#endif

	#include "SerialPort.hpp"
	#include "NoteHelper.hpp"

	#if defined(ARDUINO_ARCH_ESP8266)
		#include "WiFi.h"
	#elif defined(ARDUINO_ARCH_ESP32)
		#include "WiFi.h"
	#endif

	#ifdef WIFISerialPort_LogApp
		#include "pankey_Logger_config.hpp"
		#define WIFISerialPortLog(location,method,type,mns) pankey_Log((void*)this,location,"WIFISerialPort",method,type,mns)
	#else
		#define WIFISerialPortLog(location,method,type,mns)
	#endif

	namespace pankey{

		class WIFISerialPort : public SerialPort{	
			public:
				WIFISerialPort(){
					WIFISerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", "");
					WIFISerialPortLog(pankey_Log_EndMethod, "Contructor",  "println", "");
				}
				
				WIFISerialPort(Note a_name){
					WIFISerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", a_name);
					m_name = a_name;
					WIFISerialPortLog(pankey_Log_EndMethod, "Contructor",  "println", "");
				}

				virtual ~WIFISerialPort(){
					WIFISerialPortLog(pankey_Log_StartMethod, "Destructor",  "println", "");
					if(connected()){
						stop();
					}
					WIFISerialPortLog(pankey_Log_EndMethod, "Destructor",  "println", "");
				}

				#ifdef pankey_ArduinoIDE

					WIFISerialPort(const WIFISerialPort& a_serialport){
						WIFISerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", "eclient");
						m_client = a_serialport.m_client;
						m_name = a_serialport.m_name;
						WIFISerialPortLog(pankey_Log_EndMethod, "Contructor",  "println", "");
					}

					WIFISerialPort(WiFiClient a_client){
						WIFISerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", "eclient");
						m_client = a_client;
						m_name = "eclient";
						WIFISerialPortLog(pankey_Log_EndMethod, "Contructor",  "println", "");
					}

					WIFISerialPort(WiFiClient a_client, Note a_name){
						WIFISerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", a_name);
						m_client = a_client;
						m_name = a_name;
						WIFISerialPortLog(pankey_Log_EndMethod, "Contructor",  "println", "");
					}

					virtual int status(){
						WIFISerialPortLog(pankey_Log_StartMethod, "status",  "println", "");
						// return m_client.status();
						WIFISerialPortLog(pankey_Log_EndMethod, "status",  "println", "");
						return 0;
					}

					virtual int available(){
						WIFISerialPortLog(pankey_Log_StartMethod, "available",  "println", "");
						WIFISerialPortLog(pankey_Log_EndMethod, "available",  "println", "");
						return m_client.available();
					}

					virtual int read(){
						WIFISerialPortLog(pankey_Log_StartMethod, "read",  "println", "");
						WIFISerialPortLog(pankey_Log_EndMethod, "read",  "println", "");
						return m_client.read();
					}

					virtual Note readln(float a_time){
						WIFISerialPortLog(pankey_Log_StartMethod, "readln",  "println", "");
						Note i_message;
						long i_time_limit = 1000 * a_time;
						long i_start_time = millis();
						WIFISerialPortLog(pankey_Log_Statement, "readln",  "println", "time limit:");
						WIFISerialPortLog(pankey_Log_Statement, "readln",  "println", i_time_limit);
						WIFISerialPortLog(pankey_Log_Statement, "readln",  "println", "start limit:");
						WIFISerialPortLog(pankey_Log_Statement, "readln",  "println", i_start_time);
						while ((millis() - i_start_time) < i_time_limit) {
							WIFISerialPortLog(pankey_Log_Statement, "readln",  "println", "while is running");
							if(this->available() != 0){
								char i_capture = (char)this->read();
								WIFISerialPortLog(pankey_Log_Statement, "readln",  "println", "char capture:");
								WIFISerialPortLog(pankey_Log_Statement, "readln",  "println", i_capture);
								if(i_capture == '\n'){
									WIFISerialPortLog(pankey_Log_Statement, "readln",  "println", "note capture:");
									WIFISerialPortLog(pankey_Log_Statement, "readln",  "println", i_message);
									return i_message;
								}
								WIFISerialPortLog(pankey_Log_Statement, "readln",  "println", "adding char to note:");
								WIFISerialPortLog(pankey_Log_Statement, "readln",  "println", i_message);
								i_message.addLocalValue(i_capture);
								Watchdog::feed();
							}
						}
						WIFISerialPortLog(pankey_Log_EndMethod, "readln",  "println", "");
						return "";
					}

					virtual int peek(){
						WIFISerialPortLog(pankey_Log_StartMethod, "peek",  "println", "");
						WIFISerialPortLog(pankey_Log_EndMethod, "peek",  "println", "");
						return m_client.peek();
					}

					virtual pointer_size write(int chr){
						WIFISerialPortLog(pankey_Log_StartMethod, "write",  "println", chr);
						WIFISerialPortLog(pankey_Log_EndMethod, "write",  "println", "");
						return m_client.write(chr);
					}

					virtual size_t write(uint8_t chr){
						WIFISerialPortLog(pankey_Log_StartMethod, "write",  "println", chr);
						WIFISerialPortLog(pankey_Log_EndMethod, "write",  "println", "");
						return m_client.write(chr);
					}

					virtual bool connected(){
						WIFISerialPortLog(pankey_Log_StartMethod, "connected",  "println", "");
						WIFISerialPortLog(pankey_Log_EndMethod, "connected",  "println", "");
						return m_client.connected();
					}
					
					virtual bool connect(const Note& a_address){
						WIFISerialPortLog(pankey_Log_StartMethod, "connect",  "println", "");
						WIFISerialPortLog(pankey_Log_EndMethod, "connect",  "println", "");
						return connect(a_address, -1);
					}
					
					virtual bool connect(const Note& a_address, int port){
						WIFISerialPortLog(pankey_Log_StartMethod, "connect",  "println", "");
						
						IPAddress ip = toIPAddress(a_address);
						
						WIFISerialPortLog(pankey_Log_EndMethod, "connect",  "println", "");
						return m_client.connect(ip, port);
					}
					
					virtual void stop(){
						WIFISerialPortLog(pankey_Log_StartMethod, "stop",  "println", "");
						m_client.stop();
						WIFISerialPortLog(pankey_Log_EndMethod, "stop",  "println", "");
					}

					virtual void flush(){
						WIFISerialPortLog(pankey_Log_StartMethod, "flush",  "println", "");
						m_client.flush();
						WIFISerialPortLog(pankey_Log_EndMethod, "flush",  "println", "");
					}
					
					virtual pointer_size print(Note s){
						WIFISerialPortLog(pankey_Log_StartMethod, "print",  "println", "");
						WIFISerialPortLog(pankey_Log_EndMethod, "print",  "println", "");
						return m_client.print(s);
					}
					
					virtual pointer_size println(Note s){
						WIFISerialPortLog(pankey_Log_StartMethod, "println",  "println", "");
						WIFISerialPortLog(pankey_Log_EndMethod, "println",  "println", "");
						return m_client.println(s);
					}

					virtual void operator=(const WIFISerialPort& a_serialport){
						m_client = a_serialport.m_client;
					}

					virtual bool operator==(const WIFISerialPort& a_serialport){
						return m_client == a_serialport.m_client;
					}

					virtual bool operator!=(const WIFISerialPort& a_serialport){
						return m_client != a_serialport.m_client;
					}

					virtual operator bool(){
						return m_client;
					}

				#endif

			protected:
				#ifdef pankey_Windows

				#endif

				#ifdef pankey_ArduinoIDE
					WiFiClient m_client;
				#endif
		};

	}

#endif