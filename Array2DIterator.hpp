
#include "higgs_Enviroment.hpp"

#ifndef Array2DIterator_hpp
#define Array2DIterator_hpp
#define Array2DIterator_AVAILABLE

#ifndef higgs_Enviroment_Defined

#endif

#ifdef higgs_Windows

#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
#endif

namespace higgs{

template<class T>
class Array2DIterator{
	public:
	
		Array2DIterator(T** i_array, int p_x, int p_y, int i_x, int i_y){
			m_array = i_array;
			m_pos_X = p_x;
			m_pos_Y = p_y;
			m_size_X = i_x;
			m_size_Y = i_y;
		}
	
		Array2DIterator(const Array2DIterator& i){
			m_array = i.m_array;
			m_pos_X = i.m_pos_X;
			m_pos_Y = i.m_pos_Y;
			m_size_X = i.m_size_X;
			m_size_Y = i.m_size_Y;
		}
		virtual ~Array2DIterator(){}
		
		virtual T& operator *(){
			return m_array[m_pos_X][m_pos_Y];
		}
	
		void operator ++(){
			if(m_array == nullptr){
				return;
			}
			m_pos_X++;
			if(m_pos_X >= m_size_X){
				m_pos_X = 0;
				m_pos_Y++;
			}
		}
		
		bool operator ==(Array2DIterator i){
			if(m_array == nullptr && i.m_array == nullptr){
				return true;
			}
			if(m_array == nullptr){
				return false;
			}
			if(i.m_array == nullptr){
				return false;
			}
			
			return m_pos_X == i.m_pos_X && m_pos_Y == i.m_pos_Y;
		}
		
		bool operator !=(Array2DIterator i){
			if(m_array == nullptr && i.m_array == nullptr){
				return false;
			}
			if(m_array == nullptr){
				return true;
			}
			if(i.m_array == nullptr){
				return true;
			}
			
			return m_pos_X != i.m_pos_X && m_pos_Y != i.m_pos_Y;
		}
		virtual Array2DIterator& operator =(const Array2DIterator& i){
			m_array = i.m_array;
			m_pos_X = i.m_pos_X;
			m_pos_Y = i.m_pos_Y;
			m_size_X = i.m_size_X;
			m_size_Y = i.m_size_Y;
			return *this;
		}
	protected:
		T** m_array = nullptr;
		int m_pos_X = 0;
		int m_pos_Y = 0;
		
		int m_size_X = 0;
		int m_size_Y = 0;
};

}

#endif