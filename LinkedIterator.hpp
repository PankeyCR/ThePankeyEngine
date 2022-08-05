
#include "ame_Enviroment.hpp"

#if defined(DISABLE_LinkedIterator)
	#define LinkedIterator_hpp
#endif

#ifndef LinkedIterator_hpp
#define LinkedIterator_hpp
#define LinkedIterator_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "LinkedListNode.hpp"

namespace ame{

template<class T>
class LinkedIterator{
	public:
	
		LinkedIterator(LinkedListNode<T>* i_node, int i_pos){
			m_node = i_node;
			m_pos = i_pos;
		}
	
		LinkedIterator(const LinkedIterator<T>& i_iterator){
			m_node = i_iterator.m_node;
			m_pos = i_iterator.m_pos;
		}
		virtual ~LinkedIterator(){}
		
		virtual T& operator *(){
			return *m_node->get();
		}
	
		void operator ++(){
			if(m_node == nullptr){
				return;
			}
			m_pos++;
			m_node = m_node->next;
		}
		
		bool operator ==(LinkedIterator<T> i){
			if(m_node == nullptr){
				return false;
			}
			return m_pos == i.m_pos;
		}
		
		bool operator !=(LinkedIterator<T> i){
			if(m_node == nullptr){
				return true;
			}
			return m_pos != i.m_pos;
		}
		virtual LinkedIterator<T>& operator =(const LinkedIterator<T>& i){
			m_node = i.m_node;
			m_pos = i.m_pos;
			return *this;
		}
	protected:
		LinkedListNode<T>* m_node = nullptr;
		int m_pos = 0;
		int m_size = 0;
};

}

#endif