

#ifndef SerialNetworkState_cpp
#define SerialNetworkState_cpp

#include "SerialNetworkState.h"

	SerialNetworkState::SerialNetworkState(){}
	
	SerialNetworkState::~SerialNetworkState(){}
	
	void SerialNetworkState::setId(String s){
		if(this->id == nullptr){
			this->id = new String(s);
			return;
		}
		delete this->id;
		this->id = new String(s);
	}
	
	cppObjectClass* SerialNetworkState::getClass(){
		return Class<SerialNetworkState>::classType;
	}
	bool SerialNetworkState::instanceof(cppObjectClass* cls){
		return cls == Class<SerialNetworkState>::classType || AppState::instanceof(cls);
	}
	
	void SerialNetworkState::addSerialNetwork(SerialNetwork* serial, SerialNetworkProtocol* protocol){
		networks.addPointer(serial);
		protocols.addPointer(protocol);
	}

	SerialNetwork* SerialNetworkState::getSerialNetwork(int index){
		if(networks.getPosition() >= index){
			return nullptr;
		}
		return networks.getByPosition(index);
	}

	SerialNetwork* SerialNetworkState::getSerialNetwork(cppObjectClass* cls){
		for(int x = 0; x < networks.getPosition(); x++){
			SerialNetwork* net = networks.getByPosition(x);
			if(net->getClass() == cls){
				return net;
			}
		}
		return nullptr;
	}

	SerialNetwork* SerialNetworkState::getSerialNetwork(String name, cppObjectClass* cls){
		for(int x = 0; x < networks.getPosition(); x++){
			SerialNetwork* net = networks.getByPosition(x);
			if(net->getClass() == cls && net->getName() == name){
				return net;
			}
		}
		return nullptr;
	}
	
	int SerialNetworkState::getSerialNetworkSize(){
		return networks.getPosition();
	}
	
	bool SerialNetworkState::containSerialNetwork(SerialNetwork* serial){
		return networks.containByPointer(serial);
	}
	
	bool SerialNetworkState::containSerialNetwork(cppObjectClass* cls){
		for(int x = 0; x < networks.getPosition(); x++){
			SerialNetwork* net = networks.getByPosition(x);
			if(net->getClass() == cls){
				return true;
			}
		}
		return false;
	}
	
	bool SerialNetworkState::containSerialNetwork(String name, cppObjectClass* cls){
		for(int x = 0; x < networks.getPosition(); x++){
			SerialNetwork* net = networks.getByPosition(x);
			if(net->getClass() == cls && net->getName() == name){
				return true;
			}
		}
		return false;
	}
	
	SerialNetwork* SerialNetworkState::removeSerialNetwork(SerialNetwork* serial){
		
	}
	
	SerialNetwork* SerialNetworkState::removeSerialNetwork(cppObjectClass* cls){
		
	}
	
	SerialNetwork* SerialNetworkState::removeSerialNetwork(int index){
		
	}
	
	void SerialNetworkState::removeDeleteSerialNetwork(SerialNetwork* serial){
		
	}
	
	void SerialNetworkState::removeDeleteSerialNetwork(cppObjectClass* cls){
		
	}
	
	void SerialNetworkState::removeDeleteSerialNetwork(int index){
		
	}

	void SerialNetworkState::removeDeleteAllSerialNetwork(){
		
	}
	
	void SerialNetworkState::instantSend(ByteArray array){
		
	}
	void SerialNetworkState::instantSend(int index, ByteArray array){
		
	}
	void SerialNetworkState::instantSend(String name, ByteArray array){
		
	}
	
	void SerialNetworkState::instantSend(Message mns){
		
	}
	
	void SerialNetworkState::send(ByteArray array){
		
	}
	void SerialNetworkState::send(int index, ByteArray array){
		
	}
	void SerialNetworkState::send(String name, ByteArray array){
		
	}
	
	void SerialNetworkState::send(Message mns){
		
	}
	
	void SerialNetworkState::addListener(Command<Message>* mnsCmd){
		
	}

	void SerialNetworkState::removeDeleteListener(int index){
		
	}

	void SerialNetworkState::removeAllListener(){
		
	}

	void SerialNetworkState::disconect(void){
		
	}
	
	void SerialNetworkState::disconect(SerialNetwork* port){
		
	}
	
	void SerialNetworkState::addReceivedMessage(Message* m){
		
	}
	
	void SerialNetworkState::update(float tpc){
	}
	

#endif 
