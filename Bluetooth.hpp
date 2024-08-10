
#include "higgs_Enviroment.hpp"

#if defined(DISABLE_Bluetooth)
	#define Bluetooth_hpp
#endif

#ifndef Bluetooth_hpp
#define Bluetooth_hpp
#define Bluetooth_AVAILABLE

#ifndef higgs_Enviroment_Defined

#endif

#ifdef higgs_Windows

#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
#endif

#define MODE_SLAVE 0
#define MODE_MASTER 1
#define STATE_DISCONNECTED 0
#define STATE_CONNECTED 1
#define STATE_ATMODE_1 2
#define STATE_ATMODE_2 3

namespace higgs{

class Bluetooth {
	public:
		Bluetooth(){}
		
		int getMode(){
			return -1;
		}
		int getState(){
			return -1;
		}
		Note AtMode_List(int atmode_list){
			Note at="AT";
			if(atmode_list == 0){ at="AT"; }
			if(atmode_list == 1){ at="AT+CMODE=0"; }
			if(atmode_list == 2){ at="AT+INQM=0,5,9"; }
			if(atmode_list == 3){ at="AT+INIT"; }
			if(atmode_list == 4){ at="AT+INQ"; }
			if(atmode_list == 5){ at="AT+RNAME?"; }
			if(atmode_list == 6){ at="AT+PAIR="; }
			if(atmode_list == 7){ at="AT+BIND="; }
			if(atmode_list == 8){ at="AT+CMODE=1"; }
			if(atmode_list == 9){ at="AT+LINK="; }
			if(atmode_list == 10){ at="AT+RESET"; }
			if(atmode_list == 11){ at="AT+VERSION?"; }
			if(atmode_list == 12){ at="AT+ORGL"; }
			if(atmode_list == 13){ at="AT+ADDR?"; }
			if(atmode_list == 14){ at="AT+NAME?"; }
			if(atmode_list == 15){ at="AT+CLASS?"; }
			if(atmode_list == 16){ at="AT+IAC?"; }
			if(atmode_list == 17){ at="AT+INQM?"; }
			if(atmode_list == 18){ at="AT+PSWD?"; }
			if(atmode_list == 19){ at="AT+CMODE?"; }
			if(atmode_list == 20){ at="AT+BIND?"; }
			if(atmode_list == 21){ at="AT+PIO="; }
			if(atmode_list == 22){ at="AT+MPIO="; }
			if(atmode_list == 23){ at="AT+MPIO?"; }
			if(atmode_list == 24){ at="AT+IPSCAN="; }
			if(atmode_list == 25){ at="AT+ROLE=0"; }
			if(atmode_list == 26){ at="AT+ROLE=1"; }
			if(atmode_list == 27){ at="AT+ROLE?"; }
			if(atmode_list == 28){ at="AT+UART?"; }
			if(atmode_list == 29){ at="AT+UART=9600,0,0"; }
			if(atmode_list == 30){ at="AT+UART=38400,0,0"; }

			return at;
		}
    private:
};

}

#endif