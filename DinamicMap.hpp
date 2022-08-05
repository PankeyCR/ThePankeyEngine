
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DinamicMap)
	#define DinamicMap_hpp
#endif

#ifndef DinamicMap_hpp
#define DinamicMap_hpp
#define DinamicMap_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "DMap.hpp"

namespace ame{

template <class T>
class DinamicMap : DMap{
	public:
		DinamicMap(){
			createPositions(2);
			createMap();
		}
		DinamicMap(int c_d){
			create(c_d);
			createMap();
		}
		DinamicMap(const DinamicMap& c_map){}
		
		virtual ~DinamicMap(){}
		
		
		
		virtual void createPositions(int a_dimention_size){
			this->m_dimentionSize = a_dimention_size;
			this->m_position = new int*[this->m_dimentionSize];
		}
		
		virtual void createMap(){
			if(this->m_position == nullptr){
				return;
			}
			if(a_dimention_size == 1){
				this->m_values = new int*[this->m_dimentionSize];
			}
			if(a_dimention_size == 2){
				this->m_values = new int*[this->m_dimentionSize];
			}
			if(a_dimention_size == 3){
				this->m_values = new int*[this->m_dimentionSize];
			}
			if(a_dimention_size == 4){
				this->m_values = new int*[this->m_dimentionSize];
			}
		}
		
		virtual void setSize(int a_dimention, int a_position){
			if(this->m_position == nullptr){
				return;
			}
			
		}
		
		virtual void vector(int dimention,int pos){}
		virtual void add(T t){}
		virtual void remove(){}
		virtual T get(){}
		virtual int getDPos(int dimention){}
		virtual int size(){}
	protected:
		T** m_values = nullptr;
		int** m_position = nullptr;
		
		int m_dimentionSize = 2;
		int m_size = 0;
};

}

#endif