
#ifndef ArrayIterator_hpp
#define ArrayIterator_hpp
#define ArrayIterator_AVAILABLE

#ifdef ArrayIterator_LogApp
	#include "higgs_Logger_config.hpp"
	#include "higgs_Logger.hpp"

	#define ArrayIteratorLog(location,method,type,mns) higgs_Log((void*)this,location,"ArrayIterator",method,type,mns)
	#define const_ArrayIteratorLog(location,method,type,mns)
#else
	#ifdef ArrayIterator_LogDebugApp
		#include "higgs_Logger_config.hpp"
		#include "higgs_Logger.hpp"

		#define ArrayIteratorLog(location,method,type,mns) higgs_LogDebug((void*)this,location,"ArrayIterator",method,type)
		#define const_ArrayIteratorLog(location,method,type,mns)
	#else
		#define ArrayIteratorLog(location,method,type,mns)
		#define const_ArrayIteratorLog(location,method,type,mns)
	#endif
#endif

namespace higgs{

template<class T>
class ArrayIterator{
	public:
	
		ArrayIterator(T* i_array, int i_pos){
			ArrayIteratorLog(higgs_Log_StartMethod, "Constructor", "println", "");
			m_array = i_array;
			m_pos = i_pos;
			ArrayIteratorLog(higgs_Log_EndMethod, "Constructor", "println", "");
		}
	
		ArrayIterator(const ArrayIterator& i_iterator){
			ArrayIteratorLog(higgs_Log_StartMethod, "Constructor", "println", "");
			m_array = i_iterator.m_array;
			m_pos = i_iterator.m_pos;
			ArrayIteratorLog(higgs_Log_EndMethod, "Constructor", "println", "");
		}
		virtual ~ArrayIterator(){
			ArrayIteratorLog(higgs_Log_StartMethod, "Destructor", "println", "");
			ArrayIteratorLog(higgs_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual T& operator *(){
			ArrayIteratorLog(higgs_Log_StartMethod, "operator *", "println", "");
			ArrayIteratorLog(higgs_Log_EndMethod, "operator *", "println", "");
			return m_array[m_pos];
		}
	
		void operator ++(){
			ArrayIteratorLog(higgs_Log_StartMethod, "operator ++", "println", "");
			if(m_array == nullptr){
				return;
			}
			m_pos++;
			ArrayIteratorLog(higgs_Log_EndMethod, "operator ++", "println", "");
		}
		
		bool operator ==(ArrayIterator i){
			ArrayIteratorLog(higgs_Log_StartMethod, "operator ==", "println", "");
			if(m_array == nullptr){
				return false;
			}
			ArrayIteratorLog(higgs_Log_EndMethod, "operator ==", "println", "");
			return m_pos == i.m_pos;
		}
		
		bool operator !=(ArrayIterator i){
			ArrayIteratorLog(higgs_Log_StartMethod, "operator !=", "println", "");
			if(m_array == nullptr){
				return false;
			}
			ArrayIteratorLog(higgs_Log_EndMethod, "operator !=", "println", "");
			return m_pos != i.m_pos;
		}
		virtual ArrayIterator& operator =(const ArrayIterator& i){
			ArrayIteratorLog(higgs_Log_StartMethod, "operator =", "println", "");
			m_array = i.m_array;
			m_pos = i.m_pos;
			ArrayIteratorLog(higgs_Log_EndMethod, "operator =", "println", "");
			return *this;
		}
	protected:
		T* m_array = nullptr;
		int m_pos = 0;
};

}

#endif