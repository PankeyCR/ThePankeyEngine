
#ifndef SerialMessageState_h
#define SerialMessageState_h

#include "MessageProtocol.h"
#include "SerialServer.h"
#include "Application.h"
#include "AppState.h"
#include "Arduino.h"
#include "Command.h"
#include "List.h"
#include "PrimitiveList.h"
#include "Pair.h"
#include "Message.h"
#include "SerialPort.h"
#include "Note.h"
#include "Map.h"
#include "PrimitiveMap.h"

class SerialMessageState : public AppState{	
    public:
		Application* app;
		SerialMessageState(){
			servers = new PrimitiveList<SerialServer>();
			clients = new PrimitiveList<SerialPort>();
			broadMessages = new PrimitiveList<String>();
			receivedMessage = new PrimitiveList<Message>();
			incummingMessages = new PrimitiveList<String>();
			clientMessages = new PrimitiveMap<int,String>();
			listener = new PrimitiveList<Command<Message>>();
			delimiterType = new PrimitiveMap<String,Pair<char,char>>();
			isRecording = new PrimitiveList<bool>();
			whatsRecording = new PrimitiveList<String>();
			TimeOut = new PrimitiveList<float>();
			protocols = new PrimitiveList<MessageProtocol>();
		}
		virtual ~SerialMessageState(){
			delete servers;
			delete clients;
			delete broadMessages;
			delete receivedMessage;
			delete incummingMessages;
			delete clientMessages;
			delete listener;
			delete delimiterType;
			delete isRecording;
			delete whatsRecording;
			delete TimeOut;
			delete protocols;
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
			for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
				protocols->getByPos(prtcl)->initialize(app);
			}
		}
		
		void instantSend(String mns){
			for(int x = 0; x < clients->getPos(); x++){
				if(protocols->isEmpty()){
					clients->getByPos(x)->println(mns);
				}else{
					for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
						protocols->getByPos(prtcl)->InstantBroadcastMessage(clients->getByPos(x), mns);
					}
				}
			}
		}
		
		void instantSend(int index, String mns){
			SerialPort* port = clients->getByPos(index);
			if(port == nullptr){
				return;
			}
			if(protocols->isEmpty()){
				port->println(mns);
			}else{
				for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
					protocols->getByPos(prtcl)->InstantPrivateMessage(port, mns);
				}
			}
		}

		void instantSend(String name, String mns){
			SerialPort* port = this->getSerialPort(name);
			if(port == nullptr){
				return;
			}
			if(protocols->isEmpty()){
				port->println(mns);
			}else{
				for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
					protocols->getByPos(prtcl)->InstantPrivateMessage(port, mns);
				}
			}
		}
		
		void instantSend(Message mns){
			if(mns.id() == -1){
				for(int x = 0; x < clients->getPos(); x++){
					if(protocols->isEmpty()){
						clients->getByPos(x)->println(mns.text());
					}else{
						for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
							protocols->getByPos(prtcl)->InstantBroadcastMessage(clients->getByPos(x), mns.text());
						}
					}
				}
			}else{
				SerialPort* port = clients->getByPos(mns.id());
				if(port == nullptr){
					return;
				}
				if(protocols->isEmpty()){
					port->println(mns.text());
				}else{
					for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
						protocols->getByPos(prtcl)->InstantPrivateMessage(port, mns.text());
					}
				}
			}
		}
		
		void send(String mns){
			broadMessages->add(mns);
		}
		
		void send(int index, String mns){
			clientMessages->add(new int(index), new String(mns));
		}

		void send(String name, String mns){
			for(int x = 0 ; x < clients->getPos(); x++){
				if(clients->getByPos(x)->getName() == name){
					clientMessages->add(new int(x), new String(mns));
				}
			}
		}
		
		void send(Message mns){
			if(mns.id() == -1){
				broadMessages->add(mns.text());
			}else{
				clientMessages->add(new int(mns.id()), new String(mns.text()));
			}
		}
		
		void send(Message* mns){
			if(mns->id() == -1){
				broadMessages->add(mns->text());
			}else{
				clientMessages->add(new int(mns->id()), new String(mns->text()));
			}
		}
		
		void addType(String type, char start, char end){
			delimiterType->add(type, new Pair<char,char>(start,end));
		}

		void removeType(String type){
			delimiterType->removeDelete(type);
		}
		
		void addListener(Command<Message>* mnsCmd){
			listener->add(mnsCmd);
		}

		void removeListener(int index) {
			listener->removeByPos(index);
		}

		void removeAllListener() {
			listener->resetDelete();
		}
		
		template<class T>
		T* addSerialPort(T* serial, float t){
			clients->add(serial);
			isRecording->add(new bool(false));
			whatsRecording->add(new String(""));
			incummingMessages->add(new String(""));
			TimeOut->add(new float(t));
			return serial;
		}
		
		template<class T>
		T* addSerialPort(T* serial){
			clients->add(serial);
			isRecording->add(new bool(false));
			whatsRecording->add(new String(""));
			incummingMessages->add(new String(""));
			TimeOut->add(new float(0.0f));
			return serial;
		}
		
		List<SerialPort>* getSerialPorts(){
			return clients;
		}
		
		float getSerialPortTimeOut(int index){
			if(TimeOut->getByPos(index) == nullptr){
				return -1.0f;
			}
			return *TimeOut->getByPos(index);
		}
		
		float getSerialPortTimeOut(SerialPort* serial){
			int index = clients->getIndex(serial);
			if(TimeOut->getByPos(index) == nullptr){
				return -1.0f;
			}
			return *TimeOut->getByPos(index);
		}

		bool containsSerial(String name, String classname){
			for(int xp = 0; xp < clients->getPos(); xp++){
				if(clients->getByPos(xp)->getClassName() == classname && 
					clients->getByPos(xp)->getName() == name){
					return true;
				}
			}
			return false;
		}

		bool containsSerial(String classname){
			for(int x = 0; x < clients->getPos(); x++){
				if(clients->getByPos(x)->getClassName() == classname){
					return true;
				}
			}
			return false;
		}
		
		SerialPort* getSerialPort(String name, String classname){
			for(int x = 0; x < clients->getPos(); x++){
				if(clients->getByPos(x)->getName() == name && clients->getByPos(x)->getClassName() == classname){
					return clients->getByPos(x);
				}
			}
			return nullptr;
		}
		
		SerialPort* getSerialPort(int index){
			return clients->getByPos(index);
		}

		SerialPort* getSerialPort(String classname){
			for(int x = 0; x < clients->getPos(); x++){
				if(clients->getByPos(x)->getClassName() == classname){
					return clients->getByPos(x);
				}
			}
			return nullptr;
		}
		
		int getSerialPortSize(){
			return clients->getPos();
		}
		
		bool containSerialPort(SerialPort* serial){
			if(serial == nullptr){
				//Serial.println("containSerialPort serial == nullptr");
				return false;
			}
			for(int x = 0; x < clients->getPos(); x++){
				//Serial.println("containSerialPort start clients->getPos()");
				if(clients->getByPos(x) == nullptr){
					//Serial.println("containSerialPort clients->getByPos(x) == nullptr");
					continue;
				}
				//Serial.println("containSerialPort second clients->getPos()");
				if(serial->equal(clients->getByPos(x))){
					//Serial.println("containSerialPort equal");
					return true;
				}
				//Serial.println("containSerialPort clients->getPos()");
			}
			return false;
		}
		
		template<class T>
		bool containSerialPort(T serial){
			for(int x = 0; x < clients->getPos(); x++){
				if(serial.equal(clients->getByPos(x))){
					return true;
				}
			}
			return false;
		}
		
		bool containSerialPort(const char* serial){
			for(int x = 0; x < clients->getPos(); x++){
				if(clients->getByPos(x)->getClassName() == serial){
					return true;
				}
			}
			return false;
		}
		
		SerialPort* removeSerialPort(int index){
			isRecording->removeDeleteByPos(index);
			whatsRecording->removeDeleteByPos(index);
			incummingMessages->removeDeleteByPos(index);
			TimeOut->removeDeleteByPos(index);
			return clients->removeByPos(index);
		}
		
		void removeDeleteSerialPort(int index){
			isRecording->removeDeleteByPos(index);
			whatsRecording->removeDeleteByPos(index);
			incummingMessages->removeDeleteByPos(index);
			TimeOut->removeDeleteByPos(index);
			return clients->removeDeleteByPos(index);
		}
		
		SerialPort* removeSerialPort(SerialPort* serial){
			int x = clients->getIndex(serial);
			if(x == -1){
				//Serial.println("removeSerialPort: no index");
				return clients->remove(serial);
			}
			isRecording->removeDeleteByPos(x);
			whatsRecording->removeDeleteByPos(x);
			incummingMessages->removeDeleteByPos(x);
			TimeOut->removeDeleteByPos(x);
			return clients->remove(serial);
		}
		
		void removeDeleteSerialPort(SerialPort* serial){
			int x = clients->getIndex(serial);
			if(x == -1){
				clients->remove(serial);
			}
			isRecording->removeDeleteByPos(x);
			whatsRecording->removeDeleteByPos(x);
			incummingMessages->removeDeleteByPos(x);
			TimeOut->removeDeleteByPos(x);
			clients->removeDelete(serial);
		}
    
		void disconect() {
			for(int x = 0; x < clients->getPos(); x++){
				for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
					protocols->getByPos(prtcl)->Disconect(clients->getByPos(x));
				}
				clients->getByPos(x)->flush();
				clients->getByPos(x)->stop();
			}
		}
		
		void setRawTypeName(String name){
			rawMessageType = name;
		}
		
		void setRawTypeName(const char* name){
			rawMessageType = name;
		}
		
		String getRawTypeName(){
			return rawMessageType;
		}
		
		void addSerialServer(SerialServer* serial){
			servers->add(serial);
			serial->attach(this);
		}
    
		SerialServer* getSerialServer(int index){
			if(servers->getPos() <= index){
				return nullptr;
			}
			return servers->getByPos(index);
		}

		SerialServer* getSerialServer(String classname){
			for(int x = 0; x < servers->getPos(); x++){
				if(servers->getByPos(x)->getClassName() == classname){
					return servers->getByPos(x);
				}
			}
			return nullptr;
		}

		SerialServer* getSerialServer(String name, String classname){
			for(int x = 0; x < servers->getPos(); x++){
				if(servers->getByPos(x)->getClassName() == classname && 
						servers->getByPos(x)->getName() == name){
					return servers->getByPos(x);
				}
			}
			return nullptr;
		}
		
		int getSerialServerSize(){
			return servers->getPos();
		}
		
		bool containSerialServer(SerialServer* serial){
			for(int x = 0; x < servers->getPos(); x++){
				if(serial->equal(clients->getByPos(x))){
					return true;
				}
			}
			return false;
		}
		
		template<class T>
		bool containSerialServer(T serial){
			for(int x = 0; x < servers->getPos(); x++){
				if(serial.equal(servers->getByPos(x))){
					return true;
				}
			}
			return false;
		}
		
		bool containSerialServer(const char* serial){
			for(int x = 0; x < servers->getPos(); x++){
				if(servers->getByPos(x)->getClassName() == serial){
					return true;
				}
			}
			return false;
		}
		
		SerialServer* removeSerialServer(SerialServer* serial){
			return servers->remove(serial);
		}
		
		void removeDeleteSerialServer(SerialServer* serial){
			servers->removeDelete(serial);
		}

		void removeAllSerialServer(){
			servers->resetDelete();
		}
		
		void addReceivedMessage(Message* m){
			receivedMessage->add(m);
		}
		
		void ConcatMessage(int index, char thisChar){
			String* mns = incummingMessages->getByPos(index);
			if(mns == nullptr){
				return;
			}
			mns->concat(thisChar);
		}
		
		virtual void update(float tpc){
			for(int x = 0; x < servers->getPos(); x++){
				SerialPort* serial = servers->getByPos(x)->accept();
				if(serial != nullptr){
					//Serial.println("serial != nullptr");
					if(!containSerialPort(serial)){
						//Serial.println("!containSerialPort");
						for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
							protocols->getByPos(prtcl)->ServerAddingClient(serial);
						}
						addSerialPort(serial);
					}
				}
			}
			for(int index = 0; index < clients->getPos(); index++){
				SerialPort* serial = clients->getByPos(index);
				float timeout = *TimeOut->getByPos(index);
				if(timeout == -1.0f || maxTimeSerialPort == -1.0f){
					
				}else{
					if(timeout >= maxTimeSerialPort){
						clients->getByPos(index)->flush();
						clients->getByPos(index)->stop();
						isRecording->removeDeleteByPos(index);
						whatsRecording->removeDeleteByPos(index);
						TimeOut->removeDeleteByPos(index);
						clients->removeDeleteByPos(index);
						index--;
						continue;
					}else{
						addSerialPortTimeOut(serial, tpc);
					}
				}
				int available;
				if(protocols->isEmpty()){
					available = serial->available();
				}else{
					bool cont = false;
					for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
						available = protocols->getByPos(prtcl)->Available(serial);
						if(available == 0){
							cont = true;
						}
					}
					if(cont){
						continue;
					}
				}
				if(available > 0) {
					if(timeout != -1.0f){
						setSerialPortTimeOut(serial, 0.0f);
					}
					//Serial.println("clientsMain");
					char thisChar;
					if(protocols->isEmpty()){
						thisChar = serial->read();
					}else{
						thisChar = serial->read();
						for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
							if(protocols->getByPos(prtcl)->isReading(serial)){
								thisChar = protocols->getByPos(prtcl)->ReadSerialPort(serial);
							}
						}
					}
					//Serial.println(thisChar);
					//raw type
					String tp = *whatsRecording->getByPos(index);
					//multi type 
					String* mns = incummingMessages->getByPos(index);
					bool* rec = isRecording->getByPos(index);
					if(rec != nullptr){
						if((*rec)){
							if(tp != ""){// Serial.println("notraw");
								Pair<char,char>* p = delimiterType->get(tp);
								if(p != nullptr){
									if((*p->value) == thisChar){
										if(protocols->isEmpty()){
											Message* m = new Message();
											m->id(index);
											m->type(tp);
											m->text(String(*mns));
										}else{
											for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
												Message* m = protocols->getByPos(prtcl)->CreateTypeMessage(tp, index, String(*mns));
												if(m != nullptr){
													receivedMessage->add(m);
												}
											}
										}
										//incummingMessages->set(index, "");
										//whatsRecording->set(index, "");
										//isRecording->set(index, false);
										bool* r = isRecording->getByPos(index);
										if(r != nullptr){
											(*r) = false;
										}
										String* w = whatsRecording->getByPos(index);
										if(w != nullptr){
											(*w) = "";
										}
										String* i = incummingMessages->getByPos(index);
										if(i != nullptr){
											(*i) = "";
										}
										clients->getByPos(index)->flush();
										continue;
									}else{
										for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
											protocols->getByPos(prtcl)->ConcatTypeMessage(index, thisChar);
										}
										mns->concat(thisChar);
									}
								}
							}
						}else{
							if(tp == ""){//Serial.println("raw");
								if(thisChar == '\n' && mns->length() != 0){
									if(protocols->isEmpty()){
										Message* m = new Message();
										m->id(index);
										m->type(rawMessageType);
										m->text(String(*mns));
										receivedMessage->add(m);
									}else{
										for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
											Message* m = protocols->getByPos(prtcl)->CreateRawMessage(rawMessageType, index, String(*mns));
											if(m != nullptr){
												receivedMessage->add(m);
											}
										}
									}
									//incummingMessages->set(index, "");
									//whatsRecording->set(index, "");
									//isRecording->set(index, false);
									bool* r = isRecording->getByPos(index);
									if(r != nullptr){
										(*r) = false;
									}
									String* w = whatsRecording->getByPos(index);
									if(w != nullptr){
										(*w) = "";
									}
									String* i = incummingMessages->getByPos(index);
									if(i != nullptr){
										(*i) = "";
									}
									clients->getByPos(index)->flush();
									continue;
								}
								if(thisChar != '\n'){
									for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
										protocols->getByPos(prtcl)->ConcatRawMessage(index, thisChar);
									}
									mns->concat(thisChar);
								}
							}
							for(int xdt = 0; xdt <delimiterType->getPos(); xdt++){
								if((*(delimiterType->getByPos(xdt)->key)) == thisChar){
									for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
										protocols->getByPos(prtcl)->TypeCatch(index, *delimiterType->getKeyByPos(xdt));
									}
									//incummingMessages->set(index,"");
									//whatsRecording->set(index, *delimiterType->getKeyByPos(xdt));
									//isRecording->set(index, true);
									bool* r = isRecording->getByPos(index);
									if(r != nullptr){
										(*r) = true;
									}
									String* w = whatsRecording->getByPos(index);
									if(w != nullptr){
										(*w) = *delimiterType->getKeyByPos(xdt);
									}
									String* i = incummingMessages->getByPos(index);
									if(i != nullptr){
										(*i) = "";
									}
								}
							}
						}
					}
					
				}
			}
			
			for(int index = 0; index < clients->getPos(); index++){
				if(!clients->getByPos(index)->connected()){
					for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
						protocols->getByPos(prtcl)->PreRemoveClient(clients->getByPos(index));
					}
					//Serial.println("serial state safe remove port");
					clients->getByPos(index)->flush();
					clients->getByPos(index)->stop();
					isRecording->removeDeleteByPos(index);
					whatsRecording->removeDeleteByPos(index);
					TimeOut->removeDeleteByPos(index);
					clients->removeDeleteByPos(index);
					index--;
				}else{
					for(int x = 0; x < broadMessages->getPos(); x++){
						if(protocols->isEmpty()){
							clients->getByPos(index)->println(*broadMessages->getByPos(index));
						}else{
							for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
								protocols->getByPos(prtcl)->BroadcastMessage(clients->getByPos(index), *broadMessages->getByPos(x));
							}
						}
					}
				}
			}
			broadMessages->resetDelete();
			
			for(int x = 0; x < clientMessages->getPos(); x++){
				SerialPort* c = clients->getByPos(*clientMessages->getKeyByPos(x));
				if(c != nullptr){
					if(protocols->isEmpty()){
						c->println(*clientMessages->getByPos(x));
					}else{
						for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
							protocols->getByPos(prtcl)->PrivateMessage(c, *clientMessages->getByPos(x));
						}
					}
				}
			}
			clientMessages->resetDelete();
			
			for(int x = 0; x < receivedMessage->getPos(); x++){
				for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
					protocols->getByPos(prtcl)->ReceivedMessage(receivedMessage->getByPos(x));
				}
				for(int y = 0; y < listener->getPos(); y++){
					listener->getByPos(y)->execute(receivedMessage->getByPos(x));
				}
			}
			receivedMessage->resetDelete();
			
			for(int prtcl = 0; prtcl < protocols->getPos(); prtcl++){
				protocols->getByPos(prtcl)->update(tpc);
			}
		}
		
		virtual String getClassName(){
			return "SerialMessageState";
		}
		
		template<class T>
		T* addProtocol(T* p){
			protocols->add(p);
			return p;
		}
		
		virtual MessageProtocol* getProtocol(int index){
			return protocols->getByPos(index);
		}
		
		virtual MessageProtocol* removeProtocol(int index){
			return protocols->removeByPos(index);
		}
		
		virtual void setSerialPortMaxTime(float t){
			maxTimeSerialPort = t;
		}
		
		virtual void removeTimeOut(SerialPort* serial){
			float timeout = getSerialPortTimeOut(serial);
			if(timeout >= maxTimeSerialPort){
				removeDeleteSerialPort(serial);
			}
		}
		
		virtual void setSerialPortTimeOut(SerialPort* serial, float t){
			int index = clients->getIndex(serial);
			if(index == -1){
				return;
			}
			float* timeout = TimeOut->getByPos(index);
			if(timeout == nullptr){
				return;
			}
			(*timeout) = t;
		}
		
		virtual void addSerialPortTimeOut(SerialPort* serial, float t){
			int index = clients->getIndex(serial);
			if(index == -1){
				return;
			}
			float* timeout = TimeOut->getByPos(index);
			if(timeout == nullptr){
				return;
			}
			(*timeout) += t;
		}
		
	protected:
		float maxTimeSerialPort = 100.0f;
		String rawMessage = "";
		String rawMessageType = "";
		List<SerialServer>* servers = nullptr;
		List<SerialPort>* clients = nullptr;
		List<String>* broadMessages = nullptr;
		List<Message>* receivedMessage = nullptr;
		List<String>* incummingMessages = nullptr;
		
		Map<int,String>* clientMessages = nullptr;
		
		List<Command<Message>>* listener = nullptr;
		
		Map<String,Pair<char,char>>* delimiterType = nullptr;
		List<bool>* isRecording = nullptr;
		List<String>* whatsRecording = nullptr;
		List<float>* TimeOut = nullptr;
		List<MessageProtocol>* protocols = nullptr;
};
#endif 
