

#ifndef MachineState_h
#define MachineState_h

namespace ame{

template<class T>
class StateMachineSystem;

template<class T>
class MachineState{
    public:
		MachineState(){}
		virtual ~MachineState(){}
		virtual void update(StateMachineSystem<T>* system, T* t, float tpc){}
		virtual void operator=(MachineState b){}
		virtual bool operator==(MachineState b){return true;}
		virtual bool operator!=(MachineState b){return true;}
	protected:
};

}

#endif 
