
#ifndef CONFIGURATION_Command_hpp
#define CONFIGURATION_Command_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_Command)
		#define Command_hpp

		#define IMPLEMENTATION_Command
		#define IMPLEMENTING_Command
	#else
		#if defined(DISABLE_IMPLEMENTATION_Command)
			#define IMPLEMENTATION_Command
			#define IMPLEMENTING_Command
		#endif
	#endif
#endif

#ifndef Command_hpp
#define Command_hpp
#define Command_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_Command
	#define IMPLEMENTATION_Command IMPLEMENTATION(public Command)
	#define IMPLEMENTING_Command IMPLEMENTING(public Command)
#endif

#include "cppObject.hpp"
#include "AbstractClass.hpp"

namespace ame{

/*
*	Class Configuration:
*	DISABLE_cppObject
*/
template<class C>
class Command IMPLEMENTATION_cppObject{
    public:
		Command(){}
		virtual ~Command(){}
		virtual void execute(C* c){}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(AbstractClass_AVAILABLE)
		virtual cppObjectClass* getClass(){return AbstractClass<Command<C>>::getClass();}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == AbstractClass<Command<C>>::getClass();
		}
		#endif
		
		virtual void operator=(Command<C> b){}
		virtual bool operator==(Command<C> b){return false;}
		virtual bool operator!=(Command<C> b){return true;}
};

}

#endif