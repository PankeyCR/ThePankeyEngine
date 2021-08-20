

#ifndef SerialController_cpp
#define SerialController_cpp

#include "SerialController.h"

	ame::SerialController::SerialController() {
	}
	
	ame::SerialController::~SerialController() {
		if(validChars != nullptr){
			delete validChars;
		}
	}
	
	ame::cppObjectClass* ame::SerialController::getClass(){
		return ame::Class<ame::SerialController>::classType;
	}
	
	String ame::SerialController::toString(){
		return "SerialController";
	}
	
	ame::SerialController* ame::SerialController::clone(){
		ame::SerialController *serialc = new ame::SerialController();
		serialc->port = this->port;
		serialc->message = this->message;
		serialc->receive = this->receive;
		return serialc;
	}
  
	String ame::SerialController::Split(String divide,int parte, char limiter){     
        String return_1="";     
        int delimiter=0;  
        int respuesta_len = divide.length() + 1; 
        char respuesta_array[respuesta_len];
        divide.toCharArray(respuesta_array, respuesta_len);
        for(int i=0; i < respuesta_len; i++){
			if(respuesta_array[i] == limiter){                   
                delimiter++;  
            }
            if((parte == delimiter) && (respuesta_array[i] != limiter)){
                return_1=return_1+respuesta_array[i];
            }
        }
        return return_1;
    }
  
	int ame::SerialController::SplitLenght(String divide,int parte, char limiter){     
        String return_1="";     
        int delimiter=0;  
        int respuesta_len = divide.length() + 1; 
        char respuesta_array[respuesta_len];
        divide.toCharArray(respuesta_array, respuesta_len);
        for(int i=0; i < respuesta_len; i++){
			if(respuesta_array[i] == limiter){                   
                delimiter++;  
            }
        }
        return delimiter;
    }
  
	String ame::SerialController::Split(String divide,int parte, char limiter, char fin){     
        String return_1="";     
        int delimiter=0;  
        int respuesta_len = divide.length() + 1; 
        char respuesta_array[respuesta_len];
        divide.toCharArray(respuesta_array, respuesta_len);
        for(int i=0; i < respuesta_len; i++){
            if(respuesta_array[i] == limiter){                   
                delimiter++;  
            }
            if((parte == delimiter) && (respuesta_array[i] == fin)){                   
                delimiter++;  
            }
            if((parte == delimiter) && (respuesta_array[i] != limiter)){
                return_1=return_1+respuesta_array[i];
            }
        }
        return return_1;
	}
	

#endif 