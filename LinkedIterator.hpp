
#ifndef LinkedIterator_hpp
#define LinkedIterator_hpp
#define LinkedIterator_AVAILABLE

#include "LinkedListNode.hpp" 

#ifdef LinkedIterator_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define LinkedIteratorLog(location,method,type,mns) ame_Log((void*)this,location,"LinkedIterator",method,type,mns)
	#define const_LinkedIteratorLog(location,method,type,mns)
#else
	#ifdef LinkedIterator_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define LinkedIteratorLog(location,method,type,mns) ame_LogDebug((void*)this,location,"LinkedIterator",method,type)
		#define const_LinkedIteratorLog(location,method,type,mns)
	#else
		#define LinkedIteratorLog(location,method,type,mns)
		#define const_LinkedIteratorLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template<class T>
class LinkedIterator{
	public:
	
		LinkedIterator(LinkedListNode<T>* i_node, int i_pos){
			LinkedIteratorLog(ame_Log_StartMethod, "Constructor", "println", "");
			m_node = i_node;
			m_pos = i_pos;
			LinkedIteratorLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
	
		LinkedIterator(const LinkedIterator<T>& i_iterator){
			LinkedIteratorLog(ame_Log_StartMethod, "Constructor", "println", "");
			m_node = i_iterator.m_node;
			m_pos = i_iterator.m_pos;
			LinkedIteratorLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		virtual ~LinkedIterator(){
			LinkedIteratorLog(ame_Log_StartMethod, "Destructor", "println", "");
			LinkedIteratorLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual T& operator *(){
			LinkedIteratorLog(ame_Log_StartMethod, "operator *", "println", "");
			LinkedIteratorLog(ame_Log_EndMethod, "operator *", "println", "");
			return *m_node->get();
		}
	
		virtual void operator ++(){
			LinkedIteratorLog(ame_Log_StartMethod, "operator ++", "println", "");
			LinkedIteratorLog(ame_Log_EndMethod, "operator ++", "println", "");
			if(m_node == nullptr){
				return;
			}
			m_pos++;
			m_node = m_node->next;
		}
		
		virtual bool operator ==(LinkedIterator<T> i){
			LinkedIteratorLog(ame_Log_StartMethod, "operator ==", "println", "");
			if(m_node == nullptr){
				LinkedIteratorLog(ame_Log_EndMethod, "operator ==", "println", "return false");
				return false;
			}
			LinkedIteratorLog(ame_Log_EndMethod, "operator ==", "print", "return ");
			LinkedIteratorLog(ame_Log_EndMethod, "operator ==", "println", m_pos == i.m_pos);
			return m_pos == i.m_pos;
		}
		
		virtual bool operator !=(LinkedIterator<T> i){
			LinkedIteratorLog(ame_Log_StartMethod, "operator !=", "println", "");
			if(m_node == nullptr){
				LinkedIteratorLog(ame_Log_EndMethod, "operator !=", "println", "return true");
				return false;
			}
			LinkedIteratorLog(ame_Log_EndMethod, "operator !=", "print", "return ");
			LinkedIteratorLog(ame_Log_EndMethod, "operator !=", "println", m_pos != i.m_pos);
			return m_pos != i.m_pos;
		}
		virtual LinkedIterator<T>& operator =(const LinkedIterator<T>& i){
			LinkedIteratorLog(ame_Log_StartMethod, "operator =", "println", "");
			m_node = i.m_node;
			m_pos = i.m_pos;
			LinkedIteratorLog(ame_Log_EndMethod, "operator =", "println", "");
			return *this;
		}
	protected:
		LinkedListNode<T>* m_node = nullptr;
		int m_pos = 0;
		int m_size = 0;
};

}

#endif