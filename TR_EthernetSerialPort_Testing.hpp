
#ifndef TR_EthernetSerialPort_Testing_hpp
	#define TR_EthernetSerialPort_Testing_hpp
	
	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "EthernetSerialPort.hpp"
	#include "Note.hpp"
	#include "WIFIConnection.hpp"

	namespace pankey{
		Note g_EthernetSerialPort_mac = "10.10.10.10.10.150";
		Note g_EthernetSerialPort_ip = "192.168.1.140";
		Note g_EthernetSerialPort_gateway = "192.168.1.1";
		Note g_EthernetSerialPort_subnet = "192.168.1.1";
		Note g_EthernetSerialPort_dns = "255.255.255.0";
		Note g_EthernetSerialPort_name = "MERCUSYS_6541";
		Note g_EthernetSerialPort_password = "57924106";
		
		Note g_EthernetSerialPort_test_ip = "192.168.5.63";
		int g_EthernetSerialPort_test_port = 101;

		float g_EthernetSerialPort_test_halt_time = 5.0f;
		
		bool TR_EthernetSerialPort_WIFIConnection(TestResult& a_result){
			disconnectWIFI();

			haltUntilWIFIDisconnection(g_EthernetSerialPort_test_halt_time);

			if(hasWifiLAN()){
				a_result.catchError("Lan network connection is still on");
				return false;
			}

			initializeWIFI(	g_EthernetSerialPort_mac ,
							g_EthernetSerialPort_ip ,
							g_EthernetSerialPort_gateway ,
							g_EthernetSerialPort_subnet ,
							g_EthernetSerialPort_dns ,
							g_EthernetSerialPort_name ,
							g_EthernetSerialPort_password );

			haltUntilWIFIConnection(g_EthernetSerialPort_test_halt_time);

			if(!hasWifiLAN()){
				a_result.catchError("No lan network connection");
				return false;
			}
			return true;
		}
		
		bool TR_EthernetSerialPort_ETHERNET_Connection(TestResult& a_result){
			// disconnectEthernet();

			// haltUntilEthernetDisconnection(g_EthernetSerialPort_test_halt_time);

			// if(hasEthernetLAN()){
			// 	a_result.catchError("Llan network connection is still on");
			// 	return false;
			// }

			// initializeEthernet(	g_EthernetSerialPort_mac ,
			// 					g_EthernetSerialPort_ip ,
			// 					g_EthernetSerialPort_gateway ,
			// 					g_EthernetSerialPort_subnet ,
			// 					g_EthernetSerialPort_dns ,
			// 					g_EthernetSerialPort_name ,
			// 					g_EthernetSerialPort_password );

			// haltUntilEthernetConnection(g_EthernetSerialPort_test_halt_time);

			// if(!hasEthernetLAN()){
			// 	a_result.catchError("No lan network connection");
			// 	return false;
			// }
			return false;
		}
		
		TestResult TR_EthernetSerialPort_Testing_1(){
			TestResult i_result;
			
			EthernetSerialPort i_ethernet;
			
			return i_result;
		}
		
		TestResult TR_EthernetSerialPort_Testing_2(){
			TestResult i_result;
			
			if(!TR_EthernetSerialPort_WIFIConnection(i_result)){
				return i_result;
			}
			
			EthernetSerialPort i_ethernet;
			
			if(!i_ethernet.connect(g_EthernetSerialPort_test_ip , g_EthernetSerialPort_test_port)){
				i_result.catchError("Couldnt connect with the test client");
				return i_result;
			}

			i_ethernet.stop();
			
			if(i_ethernet.connected()){
				i_result.catchError("Still connected to the client");
				return i_result;
			}
			
			return i_result;
		}
		
		TestResult TR_EthernetSerialPort_Testing_3(){
			TestResult i_result;
			
			if(!TR_EthernetSerialPort_ETHERNET_Connection(i_result)){
				return i_result;
			}
			
			EthernetSerialPort i_ethernet;
			
			if(!i_ethernet.connect(g_EthernetSerialPort_test_ip , g_EthernetSerialPort_test_port)){
				i_result.catchError("Couldnt connect with the test client");
				return i_result;
			}

			i_ethernet.stop();
			
			if(i_ethernet.connected()){
				i_result.catchError("Still connected to the client");
				return i_result;
			}
			
			return i_result;
		}
			
		void TR_EthernetSerialPort_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("EthernetSerialPort", TR_EthernetSerialPort_Testing_1);
			a_test_runner.map.add("Wifi EthernetSerialPort connect", TR_EthernetSerialPort_Testing_2);
			a_test_runner.map.add("Ethernet EthernetSerialPort connect", TR_EthernetSerialPort_Testing_3);
		}
	}

#endif
