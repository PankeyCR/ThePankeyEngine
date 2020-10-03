
#ifndef Ethernet2SyncState_h
#define Ethernet2SyncState_h

#include "Application.h"
#include "AppState.h"
#include "Arduino.h"
#include "Command.h"
#include "List.h"
#include "PrimitiveList.h"
#include "Pair.h"
#include "Message.h"
#include <SPI.h>
#include <Ethernet2.h>

class Ethernet2SyncState : public AppState{	
    public:
		Ethernet2SyncState(int s, IPAddress IP, IPAddress GATEWAY, IPAddress SUBNET, byte MAC[6]):server(s){
			ip = IP;
			gateway = GATEWAY;
			subnet = SUBNET;
			for(int x = 0; x < 6; x++){
				mac[x] = MAC[x];
			}
			clients = new PrimitiveList<EthernetClient>();
			broadMessages = new PrimitiveList<String>();
			receivedMessage = new PrimitiveList<Message>();
			incummingMessages = new PrimitiveMap<int,String>();
			clientMessages = new PrimitiveMap<int,String>();
			listener = new PrimitiveList<Command<Message>>();
			delimiterType = new PrimitiveMap<String,Pair<char,char>>();
			isRecording = new PrimitiveList<bool>();
			whatsRecording = new PrimitiveList<String>();
		}
		virtual ~Ethernet2SyncState(){
			delete clients;
			delete broadMessages;
			delete receivedMessage;
			delete incummingMessages;
			delete clientMessages;
			delete listener;
			delete delimiterType;
			delete isRecording;
			delete whatsRecording;
		}
		void setId(String s){
			if(this->id == nullptr){
				this->id = new String(s);
				return;
			}
			delete this->id;
			this->id = new String(s);
		}
		
		virtual void initialize(Application *app){
			Ethernet.begin(mac, ip, gateway, subnet);
			server.begin();
			Serial.print("Chat server address:");
			Serial.println(Ethernet.localIP());
		}
		
		void send(String mns){
			broadMessages->add(mns);
		}
		
		void send(int index, String mns){
			clientMessages->add(index, mns);
		}
		
		void send(Message mns){
			if(mns.id() == -1){
				broadMessages->add(mns.text());
			}else{
				clientMessages->add(mns.id(), mns.text());
			}
			
		}
		
		void send(Message* mns){
			if(mns->id() == -1){
				broadMessages->add(mns->text());
			}else{
				clientMessages->add(mns->id(), mns->text());
			}
		}
		
		void addType(String type, char start, char end){
			delimiterType->add(type, new Pair<char,char>(start,end));
		}
		
		void addListener(Command<Message>* mnsCmd){
			listener->add(mnsCmd);
		}
		
		virtual void update(float tpc){
			EthernetClient client = server.available();
			if(client){
				int index = clients->getIndex(client);
				if(index == -1){
					clients->add(client);
					isRecording->add(false);
					whatsRecording->add("");
					index = clients->getIndex(client);
				}
				if (client.available() > 0) {
					char thisChar = client.read();
					String* mns = incummingMessages->get(index);
					bool* rec = isRecording->getByPos(index);
					if(rec != nullptr){
						if((*rec)){
							if(mns == nullptr){
								mns = new String();
								incummingMessages->add(index,mns);
							}
							if(*delimiterType->get(*whatsRecording->getByPos(index))->value == thisChar){
								(*rec) = false;
								(*mns) = "";
								Message* m = new Message();
								m->id(index);
								m->type(*whatsRecording->getByPos(index));
								m->text(*mns);
								receivedMessage->add(m);
							}else{
								(*mns)+=thisChar;
							}
						}else{
							iterate(delimiterType){
								if(*delimiterType->getPointer()->key == thisChar){
									whatsRecording->set(index, delimiterType->getKey());
									(*rec) = true;
								}
							}
						}
					}
				}
			}
			
			iterate(clients){
				if(!clients->getPointer()->connected()){
					clients->getPointer()->stop();
					clients->remove();
				}else{
					iterate(broadMessages){
						clients->getPointer()->print(broadMessages->getValue());
					}
					broadMessages->resetDelete();
				}
			}
			
			if(clients->getPos() == 0){
				return;
			}
			
			iterate(clientMessages){
				EthernetClient* c = clients->getByPos(clientMessages->getKey());
				if(c != nullptr){
					c->print(clientMessages->getValue());
				}
			}
			clientMessages->resetDelete();
			
			iterate(receivedMessage){
				iterate(listener){
					listener->getPointer()->execute(receivedMessage->getPointer());
				}
			}
			receivedMessage->resetDelete();
		}
		
		virtual String getClassName(){
			return "Ethernet2SyncState";
		}
		
	protected:
		byte mac[6];
		IPAddress ip;
		IPAddress gateway;
		IPAddress subnet;
		EthernetServer server;
		
		List<EthernetClient>* clients = nullptr;
		List<String>* broadMessages = nullptr;
		List<Message>* receivedMessage = nullptr;
		
		Map<int,String>* incummingMessages = nullptr;
		Map<int,String>* clientMessages = nullptr;
		
		List<Command<Message>>* listener = nullptr;
		
		Map<String,Pair<char,char>>* delimiterType = nullptr;
		List<bool>* isRecording = nullptr;
		List<String>* whatsRecording = nullptr;
};
#endif 
