
#ifndef TR_UsbNetwork_Testing_hpp
	#define TR_UsbNetwork_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "UsbNetwork.hpp"

	namespace pankey{
		
		TestResult TR_UsbNetwork_Testing_1(){
			TestResult i_result;
			
			UsbNetwork i_usb;
			
			return i_result;
		}

		void TR_UsbNetwork_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("UsbNetwork Constructor", TR_UsbNetwork_Testing_1);
		}
	}

#endif
