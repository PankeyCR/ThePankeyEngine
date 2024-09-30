
#ifndef TR_SerialState_Testing_hpp
	#define TR_SerialState_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "SerialState.hpp"
	#include "Note.hpp"
	#include "WIFIConnection.hpp"

	namespace pankey{
		Note g_SerialState_mac = "10.10.10.10.10.150";
		Note g_SerialState_ip = "192.168.1.140";
		Note g_SerialState_gateway = "192.168.1.1";
		Note g_SerialState_subnet = "192.168.1.1";
		Note g_SerialState_dns = "255.255.255.0";
		Note g_SerialState_name = "MERCUSYS_6541";
		Note g_SerialState_password = "57924106";
		
		Note g_SerialState_test_ip = "192.168.5.63";
		int g_SerialState_test_port = 101;

		float g_SerialState_test_halt_time = 5.0f;
		
		bool TR_SerialState_WIFIConnection(TestResult& a_result){
			disconnectWIFI();

			haltUntilWIFIDisconnection(g_SerialState_test_halt_time);

			if(hasWifiLAN()){
				a_result.catchError("Lan network connection is still on");
				return false;
			}

			initializeWIFI(	g_SerialState_mac ,
							g_SerialState_ip ,
							g_SerialState_gateway ,
							g_SerialState_subnet ,
							g_SerialState_dns ,
							g_SerialState_name ,
							g_SerialState_password );

			haltUntilWIFIConnection(g_SerialState_test_halt_time);

			if(!hasWifiLAN()){
				a_result.catchError("No lan network connection");
				return false;
			}
			return true;
		}
		
		bool TR_SerialState_ETHERNETConnection(TestResult& a_result){
			// disconnectEthernet();

			// haltUntilEthernetDisconnection(g_SerialState_test_halt_time);

			// if(hasEthernetLAN()){
			// 	a_result.catchError("Llan network connection is still on");
			// 	return false;
			// }

			// initializeEthernet(	g_SerialState_mac ,
			// 					g_SerialState_ip ,
			// 					g_SerialState_gateway ,
			// 					g_SerialState_subnet ,
			// 					g_SerialState_dns ,
			// 					g_SerialState_name ,
			// 					g_SerialState_password );

			// haltUntilEthernetConnection(g_SerialState_test_halt_time);

			// if(!hasEthernetLAN()){
			// 	a_result.catchError("No lan network connection");
			// 	return false;
			// }
			return false;
		}
		
		TestResult TR_SerialState_Testing_1(){
			TestResult i_result;
			
			SerialState i_serial;
			
			return i_result;
		}
		
		TestResult TR_SerialState_Testing_2(){
			TestResult i_result;
			
			if(!TR_SerialState_WIFIConnection(i_result)){
				return i_result;
			}
			
			SerialState i_serial;
			
			return i_result;
		}
			
		void TR_SerialState_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("SerialState", TR_SerialState_Testing_1);
		}
	}

#endif
