

#ifndef Environment_h
#define Environment_h

#include "Arduino.h"
#include "AppSettings.h"

class Environment : public AppSettings{
    public:
		Environment(){}
		virtual ~Environment(){}
		
		virtual bool invokeGlobal(String method){return false;}
		virtual bool invokeGlobal(String method, String parameter1){return false;}
		virtual bool invokeGlobal(String method, String parameter1, String parameter2){return false;}
		virtual bool invoke(String method){return false;}
		virtual bool invoke(String method, String parameter1){return false;}
		virtual bool invoke(String method, String parameter1, String parameter2){return false;}
		
	protected:
};

#endif 
