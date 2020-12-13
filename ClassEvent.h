
#ifndef ClassEvent_h
#define ClassEvent_h

#include "Arduino.h"
#include "Annotation.h"

template<class A,class R,class T,class P>
class ClassEvent : public Annotation<A,R,T,P>{
	protected:
		PrimitiveMap<String,P> vars;
		P var;
		T* inst = nullptr;
		
    public:
		using EventMethod = R (T::*)(P);
		ClassEvent(){}
		ClassEvent(T* i){
			inst = i;
		}
		ClassEvent(P v){
			var = v;
		}
		ClassEvent(T* i, P v){
			inst = i;
			var = v;
		}
		virtual ~ClassEvent(){}
		
		virtual P event(){
			if(inst == nullptr){
				return var;
			}
			for(int x = 0; x < this->pos; x++){
				this->invoke(this->inst,this->getByPos(x),var);
			}
			return var;
		}
		
		virtual void event(String name){
			if(inst == nullptr){
				return ;
			}
			for(int x = 0; x < this->pos; x++){
				this->invoke(this->inst,this->getByPos(x),*vars.get(name));
			}
		}
		virtual P event(P e){
			if(inst == nullptr || e == var){
				return e;
			}
			var = e;
			for(int x = 0; x < this->pos; x++){
				this->invoke(this->inst,this->getByPos(x),var);
			}
			return e;
		}
		virtual P event(A a, P e){
			if(inst == nullptr || e == var){
				return e;
			}
			var = e;
			this->invoke(inst, a, var);
			return e;
		}
		
		virtual P event(T* i){
			if(i == nullptr){
				return var;
			}
			for(int x = 0; x < this->pos; x++){
				this->invoke(i,this->getByPos(x),var);
			}
			return var;
		}
		
		virtual P event(String name, T* i){
			if(i == nullptr){
				return *vars.get(name);
			}
			for(int x = 0; x < this->pos; x++){
				this->invoke(i,this->getByPos(x),*vars.get(name));
			}
			return *vars.get(name);
		}
		virtual P event(T* i, P e){
			if(i == nullptr || e == var){
				return e;
			}
			var = e;
			for(int x = 0; x < this->pos; x++){
				this->invoke(i,this->getByPos(x),var);
			}
			return e;
		}
		virtual P event(T* i, A a, P e){
			if(i == nullptr || e == var){
				return e;
			}
			var = e;
			this->invoke(i, a, var);
			return e;
		}
		/////////////////////////////////////////////////////////
		
		virtual P event(EventMethod* m){
			if(inst == nullptr || m == nullptr){
				return var;
			}
			for(int x = 0; x < this->pos; x++){
				this->invoke(this->inst,m,var);
			}
			return var;
		}
		
		virtual P event(EventMethod* m, P e){
			if(inst == nullptr || e == var || m == nullptr){
				return e;
			}
			var = e;
			this->invoke(this->inst,m,var);
			return e;
		}
		
		virtual void event(T* i, EventMethod* m){
			if(i == nullptr || m == nullptr){
				return;
			}
			this->invoke(i,m,var);
		}
		
		virtual P event(T* i, EventMethod* m, P e){
			if(i == nullptr || e == var || m == nullptr){
				return e;
			}
			var = e;
			this->invoke(i,m,var);
			return e;
		}
		virtual P event(T* i, EventMethod m, P e){
			if(i == nullptr || e == var || m == nullptr){
				return e;
			}
			var = e;
			this->invoke(i,m,var);
			return e;
		}
		/////////////////////////////////////////////////////////
		
		virtual P event(String name, EventMethod* m){
			if(vars.get(name) == nullptr){
				vars.add(name,var);
			}
			if(inst == nullptr || m == nullptr){
				return *vars.get(name);
			}
			for(int x = 0; x < this->pos; x++){
				this->invoke(this->inst,m,*vars.get(name));
			}
			return *vars.get(name);
		}
		virtual P event(String name, EventMethod* m, P e){
			if(vars.get(name) == nullptr){
				vars.add(name,var);
			}
			if(inst == nullptr || e == *vars.get(name) || m == nullptr){
				return e;
			}
			vars.set(name,e);
			this->invoke(this->inst,m,*vars.get(name));
			return e;
		}
		
		virtual P event(String name, T* i, EventMethod* m){
			if(vars.get(name) == nullptr){
				vars.add(name,var);
			}
			if(i == nullptr || m == nullptr){
				return *vars.get(name);
			}
			this->invoke(i,m,*vars.get(name));
			return *vars.get(name);
		}
		virtual P event(String name, T* i, EventMethod* m, P e){
			if(vars.get(name) == nullptr){
				vars.add(name,var);
			}
			if(i == nullptr || e == *vars.get(name) || m == nullptr){
				return e;
			}
			vars.set(name,e);
			this->invoke(i,m,*vars.get(name));
			return e;
		}
		virtual P event(String name, T* i, EventMethod m, P e){
			if(vars.get(name) == nullptr){
				vars.add(name,var);
			}
			if(i == nullptr || e == *vars.get(name) || m == nullptr){
				return e;
			}
			vars.set(name,e);
			this->invoke(i,m,*vars.get(name));
			return e;
		}
		
};

#endif 
