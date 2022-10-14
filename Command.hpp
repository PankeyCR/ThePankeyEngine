
#ifndef Command_hpp
#define Command_hpp
#define Command_AVAILABLE 

#include "cppObject.hpp"
#include "AbstractClass.hpp"

namespace ame{

template<class C>
class Command : public cppObject{
    public:
		Command(){}
		virtual ~Command(){}
		virtual void execute(C* c){}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == AbstractClass<Command<C>>::getClass();
		}
		
		virtual cppObjectClass* getClass(){return AbstractClass<Command<C>>::getClass();}
		
		
		virtual void operator=(Command<C> b){
			
		}
		virtual bool operator==(Command<C> b){
			return false;
		}
		virtual bool operator!=(Command<C> b){
			return true;
		}
};

}

#endif