
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MethodGameSystem)
	#define MethodGameSystem_hpp
#endif

#ifndef MethodGameSystem_hpp
#define MethodGameSystem_hpp
#define MethodGameSystem_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "GameSystem.hpp"
#include "Note.hpp"
#include "PrimitiveList.hpp"

#ifdef MethodGameSystem_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define MethodGameSystemLog(location,method,type,mns) ame_Log(this,location,"MethodGameSystem",method,type,mns)
	#define MethodGameSystemMethodLog(location,method,type,mns) ame_Log(nullptr,location,"RawMethod",method,type,mns)
	#define const_MethodGameSystemLog(location,method,type,mns) 
	#define StaticMethodGameSystemLog(pointer,location,method,type,mns) ame_Log(pointer,location,"MethodGameSystem",method,type,mns)
#else
	#ifdef MethodGameSystem_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define MethodGameSystemLog(location,method,type,mns) ame_LogDebug(this,location,"MethodGameSystem",method,type)
		#define MethodGameSystemMethodLog(location,method,type,mns) ame_LogDebug(nullptr,location,"RawMethod",method,type)
		#define const_MethodGameSystemLog(location,method,type,mns) 
		#define StaticMethodGameSystemLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"MethodGameSystem",method,type)
	#else
		#define MethodGameSystemLog(location,method,type,mns) 
		#define MethodGameSystemMethodLog(location,method,type,mns) 
		#define const_MethodGameSystemLog(location,method,type,mns) 
		#define StaticMethodGameSystemLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{
	
template<class T>
class MethodGameSystem : public GameSystem<T>{
using m_Method = void (*)(T*,float);
public:

MethodGameSystem(){}

MethodGameSystem(Note i){
	this->setId(i);
}

virtual ~MethodGameSystem(){}

virtual cppObjectClass* getClass(){
	return Class<MethodGameSystem>::classType;
}

virtual bool instanceof(cppObjectClass* cls){
	return cls == Class<MethodGameSystem>::classType || GameSystem<T>::instanceof(cls);
}

virtual void updateComponents(T* component, float tpc){
	MethodGameSystemLog(ame_Log_Statement, "updateComponents",  "println", "");
	for(int x = 0; x < m_method.getPosition(); x++){
		(**m_method.getByPosition(x))(component,tpc);
	}
}

protected:
PrimitiveList<m_Method> m_method;
};

}

#endif