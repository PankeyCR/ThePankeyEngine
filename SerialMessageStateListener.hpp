

#ifndef SerialMessageStateListener_hpp
#define SerialMessageStateListener_hpp

#include "SerialMessageState.hpp"

namespace ame{

template<class T>
class SerialMessageStateListener : public T{
    public:
		SerialMessageStateListener(SerialMessageState* s){
			serialState = s;
		}
		virtual ~SerialMessageStateListener(){}
		virtual ame::cppObjectClass* getClass(){return ame::Class<SerialMessageStateListener>::classType;}
		
		void broadcastSerialServerSize(){
			serialState->send(String("SerialServerSize ") + String(serialState->getSerialServerSize()));
		}
		
	protected:
		SerialMessageState* serialState;
};

template<class T>
void broadcastSerialServerSize(T* t){
	t->broadcastSerialServerSize();
}

template<class T>
void initializeSerialMessageStateListenerAnnotations(){
  ClassMethod<SerialMessageStateListener<T>>::add("broadcastSerialServerSize");
  
  StaticMethodMap<String,T*>* map = StaticInvoker<T,T*>::getMap();
  map->add("broadcastSerialServerSize",&broadcastSerialServerSize<T>);
  
  // StaticMethodMap<String,T*,String>* map1 = StaticInvoker<T,T*,String>::getMap();
  // map1->add("requestSendContainNetwork",&requestSendContainNetwork<T>);
  
  // StaticMethodMap<String,T*,String,String>* map2 = StaticInvoker<T,T*,String,String>::getMap();
  // map2->add("requestConnexionWifi",&requestConnexionWifi<T>);
}

}

#endif 
