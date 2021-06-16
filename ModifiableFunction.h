
#ifndef ModifiableFunction_h
#define ModifiableFunction_h

#include "List.h"
#include "PrimitiveList.h"
#include "Iterator.h"
#include "Function.h"

template<class T, class... args>
class ModifiableFunction : public Function<T, args...>, public Iterator{
	public:
		virtual ~ModifiableFunction(){}
    
		virtual T f(args... mf)=0;
		
		virtual void setConstante(int position, T var){
			if(constants == nullptr){
				return;
			}
			constants->setLValue(position, var);
		}
		
		virtual void set(int position, T var){
			if(modifiablevariables == nullptr){
				return;
			}
			modifiablevariables->setLValue(position, var);
		}
		
		virtual T* getPointer(int x){
			if(modifiablevariables == nullptr){
				return nullptr;
			}
			return modifiablevariables->getByPosition(x);
		}
		
		virtual T getLValue(int x){
			if(modifiablevariables == nullptr){
				return -1;
			}
			if(modifiablevariables->getByPosition(x) == nullptr){
				return -1;
			}
			return *modifiablevariables->getByPosition(x);
		}
		
		virtual int getIterationSize()=0;
		
		virtual T getLValue(Iterator i){
			if(modifiablevariables == nullptr){
				return -1;
			}
			return *modifiablevariables->getByPosition(i.getIteration());
		}
		
		virtual T* getPointer(Iterator i){
			if(modifiablevariables == nullptr){
				return nullptr;
			}
			return modifiablevariables->getByPosition(i.getIteration());
		}
		
		virtual void set(Iterator i, T var){
			if(modifiablevariables == nullptr){
				return;
			}
			modifiablevariables->setLValue(i.getIteration(), var);
		}
		virtual String getClassName(){return "ModifiableFunction";}
		virtual String toString(){return "ModifiableFunction";}
		virtual bool instanceof(String name){return name == "ModifiableFunction" || name == "Function";}
		
	protected:
		PrimitiveList<T>* constants = nullptr;
		PrimitiveList<T>* multivariables = nullptr;
		PrimitiveList<T>* modifiablevariables = nullptr;
		
		
	
};

#endif 
