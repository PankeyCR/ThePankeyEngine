
#ifndef SerialListener_hpp
#define SerialListener_hpp

#include "Command.hpp"
#include "Message.hpp"
#include "cppObject.hpp"

namespace ame{

class SerialListener : public Command<Message>{
    public:
		SerialListener(){}
		virtual ~SerialListener(){}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialListener>::classType;
		}
		virtual cppObjectClass* getClass(){return Class<SerialListener>::classType;}
	protected:
};

}

#endif 
