

#ifndef RobotiHandTransferData_cpp
#define RobotiHandTransferData_cpp

#include "RobotiHandTransferData.h"

	RobotiHandTransferData::RobotiHandTransferData(MultiServo *s){
        list = new ArrayList<String,6>();
        servos = s;
        servos->attach(0,24);        
        servos->attach(1,26);
        servos->attach(2,28);
        servos->attach(3,30);
        servos->attach(4,31);
        
        servos->MoveServo(0,45);
        servos->MoveServo(1,45);
        servos->MoveServo(2,45);
        servos->MoveServo(3,45);
        servos->MoveServo(4,45);
        
        list->add("angulos");
        list->add("indice");
        list->add("medio");
        list->add("anular");
        list->add("menique");
        list->add("pulgar");
        
	}
		
	RobotiHandTransferData::~RobotiHandTransferData(){
		if(servos == nullptr){
			delete servos;        
		}
		if(list == nullptr){
			delete list;
		}
	}
 
  SerialController *RobotiHandTransferData::getSerial(){
    if(!isValidControl()){
      return nullptr;
    }
    return (SerialController*)object;
  }
 
  bool RobotiHandTransferData::isValidControl(){
    if(object == nullptr){
      return false;
    }
    return this->object->getClassName()=="SerialController";
  }
  
  void RobotiHandTransferData::update(){
    if(!isValidControl()){
      return;
    }
   buff = getSerial()->safeReceive('{','}');     
 //  buff = getSerial()->safeReceive(list,"ok",'{','}');     
		String buff_0 = "";

		if(buff != ""){
        buff_0 = Split(buff,0,' ');
		}
      
		if(buff_0 == "angulos"){
        int buff_2 = Split(buff,1,' ').toInt();
        int buff_3 = Split(buff,2,' ').toInt();
        int buff_4 = Split(buff,3,' ').toInt();
        int buff_5 = Split(buff,4,' ').toInt();
        int buff_6 = Split(buff,5,' ').toInt();
        servos->MoveServo(0,buff_2);
        servos->MoveServo(1,buff_3);
        servos->MoveServo(2,buff_4);
        servos->MoveServo(3,buff_5);
        servos->MoveServo(4,buff_6);
		}
      if(buff_0 == "pulgar"){
        int buff_2 = Split(buff,1,' ').toInt();
        servos->MoveServo(0,buff_2);
      }
      if(buff_0 == "indice"){
        int buff_2 = Split(buff,1,' ').toInt();
        servos->MoveServo(1,buff_2);
      }
      if(buff_0 == "medio"){
        int buff_2 = Split(buff,1,' ').toInt();
        servos->MoveServo(2,buff_2);
      }
      if(buff_0 == "anular"){
        int buff_2 = Split(buff,1,' ').toInt();
        servos->MoveServo(3,buff_2);
      }
      if(buff_0 == "menique"){
        int buff_2 = Split(buff,1,' ').toInt();
        servos->MoveServo(4,buff_2);
      }
			
	}
   
  String RobotiHandTransferData::getMessage(){
    return buff;
  }
    
  void RobotiHandTransferData::onDelete(){
		if(servos == nullptr){
			delete servos;        
		}
		if(list == nullptr){
			delete list;
		}
		delete this;			
  }
  
  String RobotiHandTransferData::Split(String divide,int parte, char limiter){     
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
  
  int RobotiHandTransferData::SplitLenght(String divide,int parte, char limiter){     
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
  
  String RobotiHandTransferData::Split(String divide,int parte, char limiter, char fin){     
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
