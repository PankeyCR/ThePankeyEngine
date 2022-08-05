
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DMap)
	#define DMap_hpp
#endif

#ifndef DMap_hpp
#define DMap_hpp
#define DMap_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template <class T>
class DMap {
	public:
		virtual ~DMap(){}
		
		virtual void vector(int dimention,int pos){}
		virtual void add(T t){}
		virtual void remove(){}
		virtual T get(){}
		/*
		template<class... P>
		void put(T t, P... a_pos){
			T array[] = {a_pos...};
			int xc = 0;
			for(const int& a : array){
				vector(xc, a);
				xc++;
			}
			add(t);
		}
		*/
		virtual int getDPos(int dimention){}
		virtual int size(){}
	private:
};

}

#endif