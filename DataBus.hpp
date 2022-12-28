
#ifndef DataBus_hpp
#define DataBus_hpp
#define DataBus_AVAILABLE

#include "cppObject.hpp"
#include "Class.hpp"
#include "WireNode.hpp"

namespace ame{

template<class Data, int size>
class DataBus IMPLEMENTATION_cppObject {
	public:
		class enum Type{
			INPUT = 0;
			OUTPUT = 1;
			OUTPUT = 1;
		}

	public:
		DataBus(){
			m_hardware = new DataBus_HardWare();
		}
		virtual ~DataBus(){
			delete m_hardware;
		}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<DataBus>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<DataBus>::getClass() || BaseAppState::instanceof(cls);
		}
		#endif

	protected:
};

}

#endif