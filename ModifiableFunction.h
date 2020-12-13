
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
			constants->set(position, var);
		}
		
		virtual void setVariable(int position, type var){
			if(variables == nullptr){
				return;
			}
			variables->set(position, var);
		}
		
		virtual int getIterationSize()=0;
		
		virtual type getValue(){
			if(variables == nullptr){
				return -1;
			}
			return *variables->getByPos(this->getIteration());
		}
		
		virtual type* getPointer(){
			if(variables == nullptr){
				return nullptr;
			}
			return variables->getByPos(this->getIteration());
		}
		
		virtual void set(type var){
			if(variables == nullptr){
				return;
			}
			variables->set(this->getIteration(), var);
		}
		virtual String getClassName(){return "ModifiableFunction";}
		virtual String toString(){return "ModifiableFunction";}
		virtual bool instanceof(String name){return name == "ModifiableFunction" || name == "Function";}
		
	protected:
		List<type>* constants = nullptr;
		List<type>* variables = nullptr;
		
		
	
};

#endif 
