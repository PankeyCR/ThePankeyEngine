

#ifndef SerialNetworkState_cpp
#define SerialNetworkState_cpp

#include "SerialNetworkState.h"

	ame::SerialNetworkState::SerialNetworkState(){}
	
	ame::SerialNetworkState::~SerialNetworkState(){}
	
	void ame::SerialNetworkState::setId(String s){
		if(this->id == nullptr){
			this->id = new String(s);
			return;
		}
		delete this->id;
		this->id = new String(s);
	}
	
	ame::cppObjectClass* ame::SerialNetworkState::getClass(){
		return ame::Class<ame::SerialNetworkState>::classType;
	}
	bool ame::SerialNetworkState::instanceof(ame::cppObjectClass* cls){
		return cls == ame::Class<ame::SerialNetworkState>::classType ||ame:: AppState::instanceof(cls);
	}
	
	void ame::SerialNetworkState::addSerialNetwork(ame::SerialNetwork* serial, ame::SerialNetworkProtocol* protocol){
		networks.addPointer(serial);
		protocols.addPointer(protocol);
	}

	ame::SerialNetwork* ame::SerialNetworkState::getSerialNetwork(int index){
		if(networks.getPosition() >= index){
			return nullptr;
		}
		return networks.getByPosition(index);
	}

	ame::SerialNetwork* ame::SerialNetworkState::getSerialNetwork(ame::cppObjectClass* cls){
		for(int x = 0; x < networks.getPosition(); x++){
			SerialNetwork* net = networks.getByPosition(x);
			if(net->getClass() == cls){
				return net;
			}
		}
		return nullptr;
	}

	ame::SerialNetwork* ame::SerialNetworkState::getSerialNetwork(String name, ame::cppObjectClass* cls){
		for(int x = 0; x < networks.getPosition(); x++){
			SerialNetwork* net = networks.getByPosition(x);
			if(net->getClass() == cls && net->getName() == name){
				return net;
			}
		}
		return nullptr;
	}
	
	int ame::SerialNetworkState::getSerialNetworkSize(){
		return networks.getPosition();
	}
	
	bool ame::SerialNetworkState::containSerialNetwork(ame::SerialNetwork* serial){
		return networks.containByPointer(serial);
	}
	
	bool ame::SerialNetworkState::containSerialNetwork(ame::cppObjectClass* cls){
		for(int x = 0; x < networks.getPosition(); x++){
			SerialNetwork* net = networks.getByPosition(x);
			if(net->getClass() == cls){
				return true;
			}
		}
		return false;
	}
	
	bool ame::SerialNetworkState::containSerialNetwork(String name, ame::cppObjectClass* cls){
		for(int x = 0; x < networks.getPosition(); x++){
			SerialNetwork* net = networks.getByPosition(x);
			if(net->getClass() == cls && net->getName() == name){
				return true;
			}
		}
		return false;
	}
	
	ame::SerialNetwork* ame::SerialNetworkState::removeSerialNetwork(ame::SerialNetwork* serial){
		
	}
	
	ame::SerialNetwork* ame::SerialNetworkState::removeSerialNetwork(ame::cppObjectClass* cls){
		
	}
	
	ame::SerialNetwork* ame::SerialNetworkState::removeSerialNetwork(int index){
		
	}
	
	void ame::SerialNetworkState::removeDeleteSerialNetwork(ame::SerialNetwork* serial){
		
	}
	
	void ame::SerialNetworkState::removeDeleteSerialNetwork(ame::cppObjectClass* cls){
		
	}
	
	void ame::SerialNetworkState::removeDeleteSerialNetwork(int index){
		
	}

	void ame::SerialNetworkState::removeDeleteAllSerialNetwork(){
		
	}
	
	void ame::SerialNetworkState::instantSend(ame::ByteArray array){
		
	}
	void ame::SerialNetworkState::instantSend(int index, ame::ByteArray array){
		
	}
	void ame::SerialNetworkState::instantSend(String name, ame::ByteArray array){
		
	}
	
	void ame::SerialNetworkState::instantSend(Message mns){
		
	}
	
	void ame::SerialNetworkState::send(ame::ByteArray array){
		
	}
	void ame::SerialNetworkState::send(int index, ame::ByteArray array){
		
	}
	void ame::SerialNetworkState::send(String name, ame::ByteArray array){
		
	}
	
	void ame::SerialNetworkState::send(ame::Message mns){
		
	}
	
	void ame::SerialNetworkState::addListener(ame::Command<Message>* mnsCmd){
		
	}

	void ame::SerialNetworkState::removeDeleteListener(int index){
		
	}

	void ame::SerialNetworkState::removeAllListener(){
		
	}

	void ame::SerialNetworkState::disconect(void){
		
	}
	
	void ame::SerialNetworkState::disconect(ame::SerialNetwork* port){
		
	}
	
	void ame::SerialNetworkState::addReceivedMessage(ame::Message* m){
		
	}
	
	void ame::SerialNetworkState::update(float tpc){
	}
	

#endif 
