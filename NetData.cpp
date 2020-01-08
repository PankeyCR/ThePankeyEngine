#ifndef NetData_cpp
#define NetData_cpp

#include "NetData.h"

	NetData::NetData(){
	}
	
	NetData::~NetData(){
	}
	
	void NetData::initialize(cppObject *obj){
		if(obj->getClassName() == ""){
			
		}
		
	}
	
	void NetData::update(){
		
	}
	
	String NetData::getClassName(){
		return "NetData";
	}
	
	String NetData::toString(){
		return "NetData";
	}
	
	NetData *NetData::clone(){
		return new NetData();
	}
	

	
#endif