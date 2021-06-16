
#ifndef SerialNetworkState_h
#define SerialNetworkState_h

#include "SerialNetwork.h"
#include "SerialNetworkProtocol.h"
#include "Application.h"
#include "AppState.h"
#include "Arduino.h"
#include "Command.h"
#include "List.h"
#include "PrimitiveList.h"
#include "Message.h"

class SerialNetworkState : public AppState{	
    public:
		SerialNetworkState();
		virtual ~SerialNetworkState();
		
		virtual void setId(String s);
		
		virtual cppObjectClass* getClass();
		virtual bool instanceof(cppObjectClass* cls);
		
		virtual void addSerialNetwork(SerialNetwork* serial, SerialNetworkProtocol* protocol);
    
		virtual SerialNetwork* getSerialNetwork(int index);

		virtual SerialNetwork* getSerialNetwork(cppObjectClass* cls);
		virtual SerialNetwork* getSerialNetwork(String name, cppObjectClass* cls);
		
		virtual int getSerialNetworkSize();
		
		virtual bool containSerialNetwork(SerialNetwork* serial);
		virtual bool containSerialNetwork(cppObjectClass* cls);
		virtual bool containSerialNetwork(String name, cppObjectClass* cls);
		
		virtual SerialNetwork* removeSerialNetwork(SerialNetwork* serial);
		virtual SerialNetwork* removeSerialNetwork(cppObjectClass* cls);
		virtual SerialNetwork* removeSerialNetwork(String name, cppObjectClass* cls);
		virtual SerialNetwork* removeSerialNetwork(int index);
		
		virtual void removeDeleteSerialNetwork(SerialNetwork* serial);
		virtual void removeDeleteSerialNetwork(cppObjectClass* cls);
		virtual void removeDeleteSerialNetwork(String name, cppObjectClass* cls);
		virtual void removeDeleteSerialNetwork(int index);

		virtual void removeDeleteAllSerialNetwork();
		
		virtual void instantSend(ByteArray array);
		virtual void instantSend(int index, ByteArray array);
		virtual void instantSend(String name, ByteArray array);
		
		virtual void instantSend(Message mns);
		
		virtual void send(ByteArray array);
		virtual void send(int index, ByteArray array);
		virtual void send(String name, ByteArray array);
		
		virtual void send(Message mns);
		
		virtual void addListener(Command<Message>* mnsCmd);

		virtual void removeDeleteListener(int index);

		virtual void removeAllListener();
    
		virtual void disconect(void);
		
		virtual void disconect(SerialNetwork* port);
		
		virtual void addReceivedMessage(Message* m);
		
		virtual void update(float tpc);
		
	protected:
		Application* app;
		
		PrimitiveList<SerialNetwork> networks;
		PrimitiveList<SerialNetworkProtocol> protocols;
		
		PrimitiveList<Message> receivedMessage;
		
		PrimitiveList<Command<Message>> listener;
};
#endif