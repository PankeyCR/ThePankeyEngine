
#ifndef ETHERNETConnection_hpp
	#define ETHERNETConnection_hpp

	#include "pankey.hpp"

	#if pankey_Enviroment == pankey_Windows_Enviroment

	#endif

	#if pankey_IDE == pankey_Arduino_IDE
		#include "Arduino.h"
	#endif

	#include "NoteHelper.hpp"

	#ifdef ETHERNETConnection_LogApp
		#include "pankey_Logger.hpp"
		#define ETHERNETConnectionLog(location,method,type,mns) pankey_Log(nullptr,location,"ETHERNETConnection",method,type,mns)
	#else
		#define ETHERNETConnectionLog(location,method,type,mns)
	#endif

	namespace pankey{

		#if pankey_IDE == pankey_Arduino_IDE
			void initializeETHERNET(IPAddress a_ip, IPAddress a_gateway, IPAddress a_subnet, int CS_pin, byte* mac){
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "IPAddress");
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "a_ip");
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", a_ip);
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "a_gateway");
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", a_gateway);
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "a_subnet");
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", a_subnet);
				
				Ethernet.init(CS_pin);
				Ethernet.begin(mac, a_ip, a_gateway, a_subnet);
				
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "connected");
			}

			void initializeETHERNET(Note a_ip, Note a_gateway, Note a_subnet, int CS_pin, byte* mac){
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "Note");

				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "a_ip");
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", a_ip);
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "a_gateway");
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", a_gateway);
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "a_subnet");
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", a_subnet);
				
				initializeETHERNET(toIPAddress(a_ip), toIPAddress(a_gateway), toIPAddress(a_subnet), CS_pin, mac);
				ETHERNETConnectionLog(pankey_Log_StartMethod, "initializeETHERNET",  "println", "");
			}

			// void initializeETHERNET(Note a_ip, Note a_gateway, Note a_subnet, int CS_pin, ByteArray mac){
				// initializeETHERNET(a_ip.toIPAddress(), a_gateway.toIPAddress(), a_subnet.toIPAddress(), CS_pin, mac.pointer());
			// }

			void haltUntilEthernetConnection(){
				ETHERNETConnectionLog(pankey_Log_StartMethod, "haltUntilEthernetConnection",  "println", "");
				while (Ethernet.linkStatus() != LinkON) {
					ETHERNETConnectionLog(pankey_Log_StartMethod, "haltUntilEthernetConnection",  "println", ".");
					System::sleep(1000);
				}
				ETHERNETConnectionLog(pankey_Log_EndMethod, "haltUntilEthernetConnection",  "println", "");
			}

			void haltUntilEthernetConnection(float a_time){
				ETHERNETConnectionLog(pankey_Log_StartMethod, "haltUntilEthernetConnection",  "println", "");
				long i_time_limit = 1000 * a_time;
				long i_start_time = millis();
				while ((millis() - i_start_time) < i_time_limit) {
					WIFIConnectionLog(pankey_Log_StartMethod, "haltUntilWIFIConnection",  "println", ".");
					Watchdog::feed();
					if(Ethernet.linkStatus() != LinkON){
						return;
					}
				}
				ETHERNETConnectionLog(pankey_Log_EndMethod, "haltUntilEthernetConnection",  "println", "");
			}


			bool hasEthernetLAN(){
				return Ethernet.linkStatus() == LinkON;
			}

		#endif

	}

#endif
