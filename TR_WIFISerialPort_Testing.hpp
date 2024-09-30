
#ifndef TR_WIFISerialPort_Testing_hpp
	#define TR_WIFISerialPort_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "WIFISerialPort.hpp"
	#include "Note.hpp"
	#include "WIFIConnection.hpp"

	namespace pankey{
		Note g_WIFISerialPort_mac = "10.10.10.10.10.150";
		Note g_WIFISerialPort_ip = "192.168.1.140";
		Note g_WIFISerialPort_gateway = "192.168.1.1";
		Note g_WIFISerialPort_subnet = "192.168.1.1";
		Note g_WIFISerialPort_dns = "255.255.255.0";
		Note g_WIFISerialPort_name = "MERCUSYS_6541";
		Note g_WIFISerialPort_password = "57924106";
		
		Note g_WIFISerialPort_test_ip = "192.168.5.63";
		int g_WIFISerialPort_test_port = 101;

		float g_WIFISerialPort_test_halt_time = 5.0f;
		
		bool TR_WIFISerialPort_WIFIConnection(TestResult& a_result){
			disconnectWIFI();

			haltUntilWIFIDisconnection(g_WIFISerialPort_test_halt_time);

			if(hasWifiLAN()){
				a_result.catchError("Lan network connection is still on");
				return false;
			}

			initializeWIFI(	g_WIFISerialPort_mac ,
							g_WIFISerialPort_ip ,
							g_WIFISerialPort_gateway ,
							g_WIFISerialPort_subnet ,
							g_WIFISerialPort_dns ,
							g_WIFISerialPort_name ,
							g_WIFISerialPort_password );

			haltUntilWIFIConnection(g_WIFISerialPort_test_halt_time);

			if(!hasWifiLAN()){
				a_result.catchError("No lan network connection");
				return false;
			}
			return true;
		}
		
		bool TR_WIFISerialPort_ETHERNETConnection(TestResult& a_result){
			// disconnectEthernet();

			// haltUntilEthernetDisconnection(g_WIFISerialPort_test_halt_time);

			// if(hasEthernetLAN()){
			// 	a_result.catchError("Llan network connection is still on");
			// 	return false;
			// }

			// initializeEthernet(	g_WIFISerialPort_mac ,
			// 					g_WIFISerialPort_ip ,
			// 					g_WIFISerialPort_gateway ,
			// 					g_WIFISerialPort_subnet ,
			// 					g_WIFISerialPort_dns ,
			// 					g_WIFISerialPort_name ,
			// 					g_WIFISerialPort_password );

			// haltUntilEthernetConnection(g_WIFISerialPort_test_halt_time);

			// if(!hasEthernetLAN()){
			// 	a_result.catchError("No lan network connection");
			// 	return false;
			// }
			return false;
		}
		
		TestResult TR_WIFISerialPort_Testing_1(){
			TestResult i_result;
			
			WIFISerialPort i_ethernet;
			
			return i_result;
		}
		
		TestResult TR_WIFISerialPort_Testing_2(){
			TestResult i_result;
			
			if(!TR_WIFISerialPort_WIFIConnection(i_result)){
				return i_result;
			}
			
			WIFISerialPort i_ethernet;
			
			if(!i_ethernet.connect(g_WIFISerialPort_test_ip , g_WIFISerialPort_test_port)){
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
		
		TestResult TR_WIFISerialPort_Testing_3(){
			TestResult i_result;
			
			if(!TR_WIFISerialPort_WIFIConnection(i_result)){
				return i_result;
			}
			
			WIFISerialPort i_ethernet;
			
			if(!i_ethernet.connect(g_WIFISerialPort_test_ip , g_WIFISerialPort_test_port)){
				i_result.catchError("Couldnt connect with the test client");
				return i_result;
			}

			i_ethernet.println("getIP");

			Note i_message = i_ethernet.readln(10.0f);

			System::console.println(i_message);

			i_result.assertTrue("Message doesnt contain the ip from the remote connection", i_message.contain(g_WIFISerialPort_test_ip));

			i_ethernet.stop();
			
			if(i_ethernet.connected()){
				i_result.catchError("Still connected to the client");
				return i_result;
			}
			
			return i_result;
		}
			
		void TR_WIFISerialPort_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("WIFISerialPort", TR_WIFISerialPort_Testing_1);
			a_test_runner.map.add("Wifi WIFISerialPort connect", TR_WIFISerialPort_Testing_2);
			a_test_runner.map.add("Wifi WIFISerialPort connect", TR_WIFISerialPort_Testing_3);
		}
	}

#endif
