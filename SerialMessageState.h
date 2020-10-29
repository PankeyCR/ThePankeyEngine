
#ifndef SerialMessageState_h
#define SerialMessageState_h

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
		SerialMessageState(){
			clientsMain = new PrimitiveList<SerialPort>();
			clients = new PrimitiveList<SerialPort>();
			broadMessages = new PrimitiveList<String>();
			receivedMessage = new PrimitiveList<Message>();
			incummingMessages = new PrimitiveMap<int,String>();
			clientMessages = new PrimitiveMap<int,String>();
			listener = new PrimitiveList<Command<Message>>();
			delimiterType = new PrimitiveMap<String,Pair<char,char>>();
			isRecording = new PrimitiveList<bool>();
			whatsRecording = new PrimitiveList<String>();
		}
		virtual ~SerialMessageState(){
			delete clientsMain;
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
		}
		
		void send(String mns){
			broadMessages->add(mns);
			//broadMessages->add(Note(mns));
		}
		
		// void send(Note mns){
			// broadMessages->add(mns);
		// }
		
		void send(int index, String mns){
			clientMessages->add(index, mns);
			//clientMessages->add(index, Note(mns));
		}
		
		// void send(int index, Note mns){
			// clientMessages->add(index, mns);
		// }
		
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
		
		void addSerial(SerialPort* serial){
			clientsMain->add(serial);
		}
		
		template<class SerialP>
		bool containSerial(SerialP serial){
			iterate(clientsMain){
				if(clientsMain->getValue() == serial){
					return true;
				}
			}
			return false;
		}
		
		SerialPort* removeSerial(SerialPort* serial){
			clients->remove(serial);
			return clientsMain->remove(serial);
		}
		
		void removeDeleteSerial(SerialPort* serial){
			clients->remove(serial);
			clientsMain->removeDelete(serial);
		}
		
		void setRawTypeName(String name){
			rawMessageType = name;
		}
		
		// void setRawTypeName(Note name){
			// rawMessageType = name;
		// }
		
		void setRawTypeName(const char* name){
			rawMessageType = name;
		}
		
		virtual void update(float tpc){
			iterate(clientsMain){
				// Serial.print("client size");Serial.println(clientsMain->getPos());
				SerialPort* serial = clientsMain->getPointer();
				int index = clientsMain->getIteration();
				if (serial->available() > 0) {
					//Serial.println("clientsMain");
					if(!clients->contain(serial)){
						//Serial.println("not contain serial");
						clients->add(serial);
						isRecording->add(false);
						whatsRecording->add("");
					}
					char thisChar = serial->read();
					//raw type
					String tp = *whatsRecording->getByPos(index);
					// if(tp == ""){
						// if(thisChar == '\n' && !rawMessage.isEmpty()){//rawMessage != ""
							// Message* m = new Message();
							// m->id(index);
							// m->type(rawMessageType);
							// m->text(rawMessage.toString());
							// rawMessage.resetDelete();
							// receivedMessage->add(m);
							//Serial.print("sending to receivedMessage: ");Serial.println(m->text());
						// }else{
							//Serial.print("adding thisChar: ");Serial.println(thisChar);
							// rawMessage+=thisChar;
						// }
					// }else{
						// rawMessage.resetDelete();
					// }
					//multi type 
					String* mns = incummingMessages->get(index);
					bool* rec = isRecording->getByPos(index);
					if(mns == nullptr){
						mns = new String();
						incummingMessages->add(index,mns);
					}
					if(rec != nullptr){
						if((*rec)){
							if(tp != ""){// Serial.println("notraw");
								Pair<char,char>* p = delimiterType->get(tp);
								if(p != nullptr){
									if((*p->value) == thisChar){
										// Serial.println("nn ending");
										// Serial.println(*mns);
										Message* m = new Message();
										m->id(index);
										m->type(tp);
										m->text(*mns);
										receivedMessage->add(m);
										incummingMessages->set(index,"");
										whatsRecording->set(index, "");
										isRecording->set(index, false);
									}else{
										mns->concat(thisChar);
									}
								}
							}
						}else{
							if(tp == ""){//Serial.println("raw");
								if(thisChar == '\n' && mns->length() != 0){
									Message* m = new Message();
									m->id(index);
									m->type(rawMessageType);
									m->text(*mns);
									//Serial.println("raw ending");
									// Serial.println("length: ");
									// Serial.println(mns->length());
									// Serial.println(mns->toString());
									// for(int x = 0 ; x < mns->getPos(); x++){
									// Serial.print(*mns->getByPos(x));
									// }Serial.println();
									// Serial.println(*mns);
									// Serial.println(m->text());
									receivedMessage->add(m);
									incummingMessages->set(index,"");
									whatsRecording->set(index, "");
									isRecording->set(index, false);
								}
								if(thisChar != '\n'){
									// Serial.print("adding raw: ");
									// Serial.println(thisChar);
									mns->concat(thisChar);
									// Serial.println(*t);
									// Serial.println(*mns);
									// Serial.println(thisChar);
								}
							}
							iterate(delimiterType){
								if((*(delimiterType->getPointer()->key)) == thisChar){
									incummingMessages->set(index,"");
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
						clients->getPointer()->println(broadMessages->getValue());
					}
					broadMessages->resetDelete();
				}
			}
			
			// if(clients->getPos() == 0){
				// Serial.println("clients->getPos() == 0");
				// return;
			// }
			
			iterate(clientMessages){
				SerialPort* c = clients->getByPos(clientMessages->getKey());
				if(c != nullptr){
					c->println(clientMessages->getValue());
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
			return "SerialMessageState";
		}
		
	protected:
		String rawMessage = "";
		String rawMessageType = "";
		List<SerialPort>* clientsMain = nullptr;
		List<SerialPort>* clients = nullptr;
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
