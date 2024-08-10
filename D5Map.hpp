
#ifndef D5Map_hpp
	#define D5Map_hpp

	#include "DMap.hpp"

	namespace ame{

		template <class T,int i0,int i1,int i2,int i3,int i4>
		class D5Map : DMap<T>{
			public:
				D5Map(){
				
				}
				~D5Map(){
					
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
					if(dimention == 4){
						x4 = pos;
					}
				}
				
				void add(T t){
					map[x0][x1][x2][x3][x4] = t;
				}
				
				void remove(){
					map[x0][x1][x2][x3][x4] = 0;
				}
				
				T get(){
					return map[x0][x1][x2][x3][x4];
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
					if(dimention == 4){
						return x4;
					}
				}
				
				int size(){
					return 5;
				}
			
			private:
				T map[i0][i1][i2][i3][i4];
				int x0 = 0;
				int x1 = 0;
				int x2 = 0;
				int x3 = 0;
				int x4 = 0;
		};

	}

#endif