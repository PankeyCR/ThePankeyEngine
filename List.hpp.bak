
#ifndef List_hpp
#define List_hpp

#include "Iterator.hpp"
#include "cppObject.hpp"
#include "RawList.hpp"

namespace ame{

template <class T>
class List : public cppObject , public RawList<T>{	
	public:
	virtual ~List(){}
	//cppObject part
	virtual List<T>* clone(void)=0;
	virtual List<T>* clone(bool owningMemory)=0;
	
	virtual bool instanceof(cppObjectClass* cls){
		return cls == Class<List>::classType || cppObject::instanceof(cls);
	}
	
	virtual cppObjectClass* getClass(){return Class<List>::classType;}
	private:
};

}

#endif 
