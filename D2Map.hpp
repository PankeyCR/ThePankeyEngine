
#include "ame_Enviroment.hpp"

#if defined(DISABLE_D2Map)
	#define D2Map_hpp
#endif

#ifndef D2Map_hpp
#define D2Map_hpp
#define D2Map_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "DMap.hpp"

namespace ame{

template <class T,int i0,int i1>
class D2Map : DMap<T>{
	public:
		D2Map(){
		
		}
		~D2Map(){
			
		}
		void vector(int dimention,int pos){
			if(dimention == 0){
				x0 = pos;
			}
			if(dimention == 1){
				x1 = pos;
			}
		}
		
		void add(T t){
			map[x0][x1] = t;
		}
		
		void remove(){
			map[x0][x1] = 0;
		}
		
		T get(){
			return map[x0][x1];
		}
		
		int getDPos(int dimention){
			if(dimention == 0){
				return x0;
			}
			if(dimention == 1){
				return x1;
			}
		}
		
		int size(){
			return 2;
		}
    
	private:
		T map[i0][i1];
		int x0 = 0;
		int x1 = 0;
};

}

#endif