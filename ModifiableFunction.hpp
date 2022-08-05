
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ModifiableFunction)
	#define ModifiableFunction_hpp
#endif

#ifndef ModifiableFunction_hpp
#define ModifiableFunction_hpp
#define ModifiableFunction_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "List.hpp"
#include "PrimitiveList.hpp"
#include "Iterator.hpp"
#include "Function.hpp"

namespace ame{

template<class T, class... args>
class ModifiableFunction : public Function<T, args...>, public Iterator{
	public:
		virtual ~ModifiableFunction(){}
    
		virtual T f(args... mf)=0;
		
		virtual void setConstante(int position, T var){
			constants.setLValue(position, var);
		}
		
		virtual void set(int position, T var){
			modifiablevariables.setLValue(position, var);
		}
		
		virtual T* getPointer(int x){
			return modifiablevariables.getByPosition(x);
		}
		
		virtual T getLValue(int x){
			if(modifiablevariables.getByPosition(x) == nullptr){
				return -1;
			}
			return *modifiablevariables.getByPosition(x);
		}
		
		virtual int getIterationSize()=0;
		
		virtual T getLValue(Iterator i){
			return *modifiablevariables.getByPosition(i.getIteration());
		}
		
		virtual T* getPointer(Iterator i){
			return modifiablevariables.getByPosition(i.getIteration());
		}
		
		virtual void set(Iterator i, T var){
			modifiablevariables.setLValue(i.getIteration(), var);
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls || Class<ModifiableFunction<T,args...>>::classType 
			|| Function<T,args...>::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<ModifiableFunction<T,args...>>::classType;}
		virtual Note toNote(){return "ModifiableFunction";}
		
	protected:
		PrimitiveList<T> constants;
		PrimitiveList<T> multivariables;
		PrimitiveList<T> modifiablevariables;
};

}

#endif