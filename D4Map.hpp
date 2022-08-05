
#include "ame_Enviroment.hpp"

#if defined(DISABLE_D4Map)
	#define D4Map_hpp
#endif

#ifndef D4Map_hpp
#define D4Map_hpp
#define D4Map_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "DMap.hpp"

namespace ame{

template <class T,int i0,int i1,int i2,int i3>
class D4Map : DMap<T>{
	public:
		D4Map(){
		
		}
		~D4Map(){
			
		}
		void vector(int dimention,int pos){
			if(dimention == 0){
				x0 = pos;
			}
			if(dimention == 1){
				x1 = pos;
			}
			if(dimention == 2){
				x2 = pos;
			}
			if(dimention == 3){
				x3 = pos;
			}
		}
		
		void add(T t){
			map[x0][x1][x2][x3] = t;
		}
		
		void remove(){
			map[x0][x1][x2][x3] = 0;
		}
		
		T get(){
			return map[x0][x1][x2][x3];
		}
		
		int getDPos(int dimention){
			if(dimention == 0){
				return x0;
			}
			if(dimention == 1){
				return x1;
			}
			if(dimention == 2){
				return x2;
			}
			if(dimention == 3){
				return x3;
			}
		}
		
		int size(){
			return 4;
		}
    
	private:
		T map[i0][i1][i2][i3];
		int x0 = 0;
		int x1 = 0;
		int x2 = 0;
		int x3 = 0;
};

}

#endif