

#ifndef SerialScriptState_h
#define SerialScriptState_h

#include "Arduino.h"
#include "Application.h"
#include "AppState.h"
#include "SerialConnection.h"
#include "Stream.h"
#include "Lexer.h"

class SerialScriptState : public AppState{
    public:
		SerialScriptState(Stream* serialPort);
		SerialScriptState(Stream* serialPort,Stream* extraPort);
		virtual ~SerialScriptState();
		
		virtual void initialize(Application *app);
		virtual void update();
		
		virtual void setSerialStart(char s);
		virtual void setSerialEnd(char e);
		
		String getClassName();
		String toString();
		
	protected:
		Lexer* lexer = nullptr;
		SerialConnection* serial = nullptr;
		Stream* extraSerial = nullptr;
		Stream* port = nullptr;
		char start = '<';
		char end = '>';
};

#endif 
