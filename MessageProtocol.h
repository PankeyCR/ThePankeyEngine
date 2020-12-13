
#ifndef MessageProtocol_h
#define MessageProtocol_h

#include "Application.h"
#include "SerialPort.h"
#include "Message.h"

class MessageProtocol{	
    public:
		MessageProtocol(){
		}
		virtual ~MessageProtocol(){
		}
		//runs at the initialize method of the serialmessagestate
		virtual void initialize(Application* app){}
		
		//this method has control of the sending of the message, so remember sending it
		virtual void InstantBroadcastMessage(SerialPort* port, String mns){}
		
		//this method has control of the sending of the message, so remember sending it
		virtual void InstantPrivateMessage(SerialPort* port, String mns){}
		
		virtual void Disconect(SerialPort* port){}
		
		//this method doent need to add the port to the sistem, its done automatic by the serialmessagestate
		virtual void ServerAddingClient(SerialPort* port){}
		
		virtual int Available(SerialPort* port){return port->available();}
		
		virtual bool isReading(SerialPort* port){return false;}
		
		virtual char ReadSerialPort(SerialPort* port){return port->read();}
		
		//this method needs to creat a message class or it will not receive messages, but you dont need to added, that done on the serialmessagestate
		virtual Message* CreateTypeMessage(String t, int index, String mns){
			// Message* m = new Message();
			// m->id(index);
			// m->type(t);
			// m->text(mns);
			// return m;
			return nullptr;
		}
		//this method needs to creat a message class or it will not receive messages, but you dont need to added, that done on the serialmessagestate
		virtual Message* CreateRawMessage(String t, int index, String mns){
			// Message* m = new Message();
			// m->id(index);
			// m->type(t);
			// m->text(mns);
			// return m;
			return nullptr;
		}
		//you dont need to concat the message yourself, that done by the serialmessagestate
		virtual void ConcatTypeMessage(int index, char c){}
		//you dont need to concat the message yourself, that done by the serialmessagestate
		virtual void ConcatRawMessage(int index, char c){}
		//this catches the start of the type message incoming data
		virtual void TypeCatch(int index, String t){}
		
		virtual void PreRemoveClient(SerialPort* port){}
		//you need to send to message manually
		virtual void BroadcastMessage(SerialPort* port, String mns){}
		//you need to send to message manually
		virtual void PrivateMessage(SerialPort* port, String mns){}
		//this runs first than the commands, but it doesnt remove them from execution
		virtual void ReceivedMessage(Message* mns){}
		//runs at the end of the update method of the serialmessagestate
		virtual void update(float tpc){}
		
		virtual void operator=(MessageProtocol b){}
		virtual bool operator==(MessageProtocol b){return true;}
		virtual bool operator!=(MessageProtocol b){return true;}
		
	protected:
};
#endif 
