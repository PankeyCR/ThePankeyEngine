
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ByteArrayIterator)
	#define ByteArrayIterator_hpp
#endif

#ifndef ByteArrayIterator_hpp
#define ByteArrayIterator_hpp
#define ByteArrayIterator_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ame_Byte.hpp"

namespace ame{

class ByteArrayIterator{
	public:
	
		ByteArrayIterator(ame_Byte* i_byte, int i_pos){
			m_byte = i_byte;
			m_pos = i_pos;
		}
	
		ByteArrayIterator(const ByteArrayIterator& i_iterator){
			m_byte = i_iterator.m_byte;
			m_pos = i_iterator.m_pos;
		}
		virtual ~ByteArrayIterator(){}
		
		virtual char& operator *(){
			return m_byte[m_pos];
		}
	
		void operator ++(){
			if(m_byte == nullptr){
				return;
			}
			m_pos++;
		}
		
		bool operator ==(ByteArrayIterator i){
			if(m_byte == nullptr){
				return false;
			}
			return m_pos == i.m_pos;
		}
		
		bool operator !=(ByteArrayIterator i){
			if(m_byte == nullptr){
				return true;
			}
			return m_pos != i.m_pos;
		}
		virtual ByteArrayIterator& operator =(const ByteArrayIterator& i){
			m_byte = i.m_byte;
			m_pos = i.m_pos;
			return *this;
		}
	protected:
		ame_Byte* m_byte = nullptr;
		int m_pos = 0;
};

}

#endif