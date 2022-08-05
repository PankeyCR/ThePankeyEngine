
#include "ame_Enviroment.hpp"

#ifndef ArrayIterator_hpp
#define ArrayIterator_hpp
#define ArrayIterator_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template<class T>
class ArrayIterator{
	public:
	
		ArrayIterator(T* i_array, int i_pos){
			m_array = i_array;
			m_pos = i_pos;
		}
	
		ArrayIterator(const ArrayIterator& i_iterator){
			m_array = i_iterator.m_array;
			m_pos = i_iterator.m_pos;
		}
		virtual ~ArrayIterator(){}
		
		virtual T& operator *(){
			return m_array[m_pos];
		}
	
		void operator ++(){
			if(m_array == nullptr){
				return;
			}
			m_pos++;
		}
		
		bool operator ==(ArrayIterator i){
			if(m_array == nullptr){
				return false;
			}
			return m_pos == i.m_pos;
		}
		
		bool operator !=(ArrayIterator i){
			if(m_array == nullptr){
				return true;
			}
			return m_pos != i.m_pos;
		}
		virtual ArrayIterator& operator =(const ArrayIterator& i){
			m_array = i.m_array;
			m_pos = i.m_pos;
			return *this;
		}
	protected:
		T* m_array = nullptr;
		int m_pos = 0;
};

}

#endif