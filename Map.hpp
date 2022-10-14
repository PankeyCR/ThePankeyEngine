
#ifndef Map_hpp
#define Map_hpp
#define Map_AVAILABLE

#include "cppObject.hpp"
#include "RawMap.hpp"
#include "AbstractClass.hpp"

namespace ame{

template <class K,class V>
class Map : public cppObject, virtual public RawMap<K,V>{	
    public:
		virtual ~Map(){}
		
		//cppObject part
	
		virtual bool instanceof(cppObjectClass* cls){
			return cls == AbstractClass<Map<K,V>>::getClass() || cppObject::instanceof(cls);
		}
		
		virtual cppObjectClass* getClass(){return AbstractClass<Map<K,V>>::getClass();}
	
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
	private:
};

}

#endif