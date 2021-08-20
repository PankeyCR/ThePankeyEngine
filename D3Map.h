

#ifndef D3Map_h
#define D3Map_h

#include "DMap.h"

namespace ame{

template <class T,int i0,int i1,int i2>
class D3Map : DMap<T>{
	public:
		D3Map(){
		
		}
		~D3Map(){
			
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
		}
		
		void add(T t){
			map[x0][x1][x2] = t;
		}
		
		void remove(){
			map[x0][x1][x2] = 0;
		}
		
		T get(){
			return map[x0][x1][x2];
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
		}
		
		int size(){
			return 3;
		}
    
	private:
		T map[i0][i1][i2];
		int x0 = 0;
		int x1 = 0;
		int x2 = 0;
};

}

#endif 
