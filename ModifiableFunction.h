
#ifndef ModifiableFunction_h
#define ModifiableFunction_h

#include "List.h"
#include "Iterator.h"
#include "Function.h"

template<class type, class... args>
class ModifiableFunction : public Function<type, args...>, public Iterator{
	public:
		virtual ~ModifiableFunction(){}
    
		virtual type f(args... mf)=0;
		
		virtual void setConstante(int position, type var){
			if(constants == nullptr){
				return;
			}
			constants->setLValue(position, var);
		}
		
		virtual void setVariable(int position, type var){
			if(variables == nullptr){
				return;
			}
			variables->setLValue(position, var);
		}
		
		virtual int getIterationSize()=0;
		
		virtual type getLValue(Iterator i){
			if(variables == nullptr){
				return -1;
			}
			return *variables->getByPosition(i.getIteration());
		}
		
		virtual type* getPointer(Iterator i){
			if(variables == nullptr){
				return nullptr;
			}
			return variables->getByPosition(i.getIteration());
		}
		
		virtual void set(Iterator i, type var){
			if(variables == nullptr){
				return;
			}
			variables->setLValue(i.getIteration(), var);
		}
		virtual String getClassName(){return "ModifiableFunction";}
		virtual String toString(){return "ModifiableFunction";}
		virtual bool instanceof(String name){return name == "ModifiableFunction" || name == "Function";}
		
	protected:
		List<type>* constants = nullptr;
		List<type>* variables = nullptr;
		
		
	
};

#endif 
