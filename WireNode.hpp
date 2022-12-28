
#ifndef WireNode_hpp
#define WireNode_hpp
#define WireNode_AVAILABLE

#include "cppObject.hpp"
#include "Class.hpp"

namespace ame{

template<class Data>
class WireNode IMPLEMENTATION_cppObject {
	public:
		WireNode(){}
		WireNode(const WireNode& c_wire){
			m_data = c_wire.m_data;
		}
		WireNode(const Data& c_data){
			m_data = c_data;
		}
		virtual ~WireNode(){}

		virtual WireNode& operator=(const WireNode& a_wire){
			m_data = a_wire.m_data;
			return *this;
		}

		virtual bool operator==(const WireNode& a_wire){
			return this->m_data == a_wire.m_data;
		}

		virtual bool operator!=(const WireNode& a_wire){
			return this->m_data != a_wire.m_data;
		}

		virtual WireNode& operator=(const Data& a_data){
			m_data = a_wire.m_data;
			return *this;
		}

		virtual bool operator==(const Data& a_data){
			return this->m_data == a_data;
		}

		virtual bool operator!=(const Data& a_data){
			return this->m_data != a_data;
		}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<WireNode>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<WireNode>::getClass() || BaseAppState::instanceof(cls);
		}
		#endif

	protected:
		Data m_data;
		PrimitiveList<WireNode<Data>> m_wire_connestions_list;
};

}

#endif