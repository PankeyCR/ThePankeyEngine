
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MachineState)
	#define MachineState_hpp
#endif

#ifndef MachineState_hpp
#define MachineState_hpp
#define MachineState_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template<class T>
class ClassStateMachineSystem;

template<class T>
class MachineState{
    public:
		MachineState(){}
		virtual ~MachineState(){}
		virtual void update(ClassStateMachineSystem<T>* system, T* t, float tpc){}
		virtual void operator=(MachineState b){}
		virtual bool operator==(MachineState b){return true;}
		virtual bool operator!=(MachineState b){return true;}
	protected:
};

}

#endif