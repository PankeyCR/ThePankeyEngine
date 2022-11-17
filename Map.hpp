
#ifndef Map_hpp
#define Map_hpp
#define Map_AVAILABLE

#include "cppObject.hpp"
#include "RawMap.hpp"
#include "AbstractClass.hpp"

namespace ame{

template <class K,class V>
class Map : virtual public RawMap<K,V> IMPLEMENTING_cppObject {	
    public:
		virtual ~Map(){}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(AbstractClass_AVAILABLE)
		virtual cppObjectClass* getClass(){return AbstractClass<Map<K,V>>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == AbstractClass<Map<K,V>>::getClass() || cppObject::instanceof(cls);
		}
	
		virtual Map<K,V>* clone(void){return nullptr;}
		virtual Map<K,V>* clone(bool owningMemory){return nullptr;}
		
		virtual bool copy(cppObject* obj){
			return false;
		}
		
		virtual bool move(cppObject* obj){
			return false;
		}
		
		virtual bool duplicate(cppObject* obj){
			return false;
		}
		
		
		virtual bool equal(cppObject* obj){
			return this == obj;
		}
		
		virtual cppObject* move(){
			return nullptr;
		}
		
		virtual cppObject* duplicate(){
			return nullptr;
		}
		#endif
	private:
};

}

#endif