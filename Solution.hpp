
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Solution)
	#define Solution_hpp
#endif

#ifndef Solution_hpp
#define Solution_hpp
#define Solution_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template<class T>
class Solution{
    public:
		Solution(){}
		Solution(T s){
			t = s;
		}
		Solution(const Solution& e){
			t = e.t;
		}
		virtual ~Solution(){
			
		}
		
		virtual int solutionType(){return -1;}
		virtual bool hasSolution(){return false;}
		virtual T getSolution(){return t;}
		virtual bool operator=(Solution e){
			t = e.t;
		}
		virtual bool operator==(Solution e){
			return t == e.t;
		}
		virtual bool operator!=(Solution e){
			return t != e.t;
		}
	protected:
		T t;
};

}

#endif