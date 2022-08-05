
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Trio)
	#define Trio_hpp
#endif

#ifndef Trio_hpp
#define Trio_hpp
#define Trio_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template<class T,class M,class B>
class Trio{
    public:
		T* top=nullptr;
		M* mid=nullptr;
		B* bot=nullptr;
		Trio(){}
		Trio(bool own){
			owner = own;
		}
		Trio(T t,M m,B b){
			top = new T(t);
			mid = new M(m);
			bot = new B(b);
			owner = true;
		}
		Trio(T* t,M* m,B* b){
			top = t;
			mid = m;
			bot = b;
		}
		Trio(T* t,M* m,B* b, bool own){
			top = t;
			mid = m;
			bot = b;
			owner = own;
		}
		~Trio(){
			if(owner){
				delete top;
				delete mid;
				delete bot;
			}
		}
		virtual void operator=(Trio b){
			top = b.top;
			mid = b.mid;
			bot = b.bot;
			owner = b.owner;
		}
		virtual bool operator==(Trio b){
			return top == b.top && mid == b.mid && bot == b.bot;
		}
		virtual bool operator!=(Trio b){
			return top != b.top && mid != b.mid && bot != b.bot;
		}
	protected:
		bool owner = false;
};

}

#endif