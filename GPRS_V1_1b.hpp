
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef GPRS_V1_1b_hpp
#define GPRS_V1_1b_hpp

#include "Arduino.h"
#include "Stream.h"

namespace ame{

class GPRS_V1_1b {
    public:
		GPRS_V1_1b(){}
		~GPRS_V1_1b(){}
		String AtMode_List(int atmode_list){
			String at="";
			if(atmode_list == 0){ at="AT"; }
			if(atmode_list == 1){ at="ATA"; }
			if(atmode_list == 2){ at="ATD"; }
			if(atmode_list == 3){ at="ATDL"; }
			if(atmode_list == 4){ at="ATE"; }
			if(atmode_list == 5){ at="ATH"; }
			if(atmode_list == 6){ at="ATI"; }
			if(atmode_list == 7){ at="ATL"; }
			if(atmode_list == 8){ at="ATM"; }
			if(atmode_list == 9){ at="+++"; }
			if(atmode_list == 10){ at="ATO"; }
			if(atmode_list == 11){ at="ATP"; }
			if(atmode_list == 12){ at="ATQ"; }
			if(atmode_list == 13){ at="ATS0"; }
			if(atmode_list == 14){ at="ATS3"; }
			if(atmode_list == 15){ at="ATS4"; }
			if(atmode_list == 16){ at="ATS5"; }
			if(atmode_list == 17){ at="ATS7"; }
			if(atmode_list == 18){ at="ATS8"; }
			if(atmode_list == 19){ at="ATS10"; }
			if(atmode_list == 20){ at="ATT"; }
			if(atmode_list == 21){ at="ATX"; }
			if(atmode_list == 22){ at="ATZ"; }
			if(atmode_list == 23){ at="AT&C"; }
			if(atmode_list == 24){ at="AT&D"; }
			if(atmode_list == 25){ at="AT&F"; }
			if(atmode_list == 26){ at="AT&V"; }
			if(atmode_list == 27){ at="AT&W"; }
			if(atmode_list == 28){ at="AT+GCAP"; }
			if(atmode_list == 29){ at="AT+GMI"; }
			if(atmode_list == 30){ at="AT+GMM"; }
			if(atmode_list == 31){ at="AT+GMR"; }
			if(atmode_list == 32){ at="AT+GOI"; }
			if(atmode_list == 33){ at="AT+GSN"; }
			if(atmode_list == 34){ at="AT+ICF"; }
			if(atmode_list == 35){ at="AT+IFC"; }
			if(atmode_list == 36){ at="AT+IPR"; }
			if(atmode_list == 37){ at="AT+HVOIC"; }
			if(atmode_list == 38){ at="A/"; }

			return at;
		}

		void SendSim800cMns(Stream *port,String telefono,String mns){
			port->println("AT+CMGF=1");
			delay(500);
			port->println("AT+CSMP=17,167,0,16");
			delay(500);
			port->println(telefono);
			delay(500);
			port->println(mns);
			delay(500);
			port->write((char)26);
			delay(1000);
		}

		void SendSim800cLongMns(Stream *port,String telefono,String mns[],int sizee){
			port->println("AT+CMGF=1");
			delay(500);
			port->println("AT+CSMP=17,167,0,16");
			delay(500);
			port->println(telefono);
			delay(500);
			for(int pp=0; pp< sizee;pp++){
				port->println(mns[pp]);
			}
			delay(500);
			port->write((char)26);
			delay(1000);
		}


		void ListenerSim800cMns(Stream *port){
			port->println("AT+CMGF=1");
			delay(1000);
			port->println("AT+CNMI=2,2,0,0,0");
			delay(1000);
		}

		String ReceiveSim800cMns(Stream *port){    
			char reading =' ';
			boolean wipe= false;
			inputStringGprs="";
			if (port->available()) {
				reading = (char)port->read();
				inputStringGprs = reading;
				wipe=true;
			}
			while(wipe==true){   
				if (port->available()){
					reading = (char)port->read();
					if(reading=='\n'){
						wipe=false;
					}else{
						inputStringGprs = inputStringGprs+reading;
					}
				}
			}
			port->flush();
			return inputStringGprs;
		}
		
		String Sim800cSplit(String cmd,int parte, char limiter){ 
			String return_1="";     
			if(cmd!=""){   
				int delimiter=-1;  
				int respuesta_len = cmd.length() + 1; 
				char respuesta_array[respuesta_len];
				cmd.toCharArray(respuesta_array, respuesta_len);
				for(int i=0; i < respuesta_len; i++){
					if(respuesta_array[i] == '@'){                   
						delimiter++;  
					}
					if((respuesta_array[i] == limiter) && ( delimiter>=0 ) ){
						delimiter++;
					}
					if((parte == delimiter) && (respuesta_array[i] != limiter)){
						if(respuesta_array[i] != '@'){    
							return_1=return_1+respuesta_array[i];
						}
					}
				}
			}
			return return_1;
		}
      
    private:  
		Stream *port;
		String inputStringGprs="";
};

}

#endif 

#endif 
