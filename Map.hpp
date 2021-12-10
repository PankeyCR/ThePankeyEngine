
#ifndef Map_hpp
#define Map_hpp

#include "cppObject.hpp"
#include "RawMap.hpp"
#include "MapIterator.hpp"

namespace ame{

template <class K,class V>
class Map : public cppObject, public RawMap<K,V>{	
    public:
		virtual ~Map(){}
		virtual MapIterator<K,V> getIterator(int p)=0;
		//MapIteratorIterator part
		virtual MapIterator<K,V> begin(){
			return this->getIterator(0);
		}
		virtual MapIterator<K,V> end(){
			return this->getIterator(this->getPosition()-1);
		}
		//cppObject part
		virtual Map<K,V>* clone(void)=0;
		virtual Map<K,V>* clone(bool owningMemory)=0;
	private:
};

}
#endif 
