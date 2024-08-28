
#ifndef ArrayIterator_hpp
	#define ArrayIterator_hpp

	#ifdef ArrayIterator_LogApp
		#include "pankey_Logger.hpp"
		#define ArrayIteratorLog(location,method,type,mns) pankey_Log(nullptr,location,"ArrayIterator",method,type,mns)
	#else
		#define ArrayIteratorLog(location,method,type,mns) 
	#endif

	namespace pankey{

		template<class T>
		class ArrayIterator{
			public:
			
				ArrayIterator(T* i_array, int i_pos){
					ArrayIteratorLog(pankey_Log_StartMethod, "Constructor", "println", "");
					m_array = i_array;
					m_pos = i_pos;
					ArrayIteratorLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
			
				ArrayIterator(const ArrayIterator& i_iterator){
					ArrayIteratorLog(pankey_Log_StartMethod, "Constructor", "println", "");
					m_array = i_iterator.m_array;
					m_pos = i_iterator.m_pos;
					ArrayIteratorLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~ArrayIterator(){
					ArrayIteratorLog(pankey_Log_StartMethod, "Destructor", "println", "");
					ArrayIteratorLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual T& operator *(){
					ArrayIteratorLog(pankey_Log_StartMethod, "operator *", "println", "");
					ArrayIteratorLog(pankey_Log_EndMethod, "operator *", "println", "");
					return m_array[m_pos];
				}
			
				void operator ++(){
					ArrayIteratorLog(pankey_Log_StartMethod, "operator ++", "println", "");
					if(m_array == nullptr){
						return;
					}
					m_pos++;
					ArrayIteratorLog(pankey_Log_EndMethod, "operator ++", "println", "");
				}
				
				bool operator ==(ArrayIterator i){
					ArrayIteratorLog(pankey_Log_StartMethod, "operator ==", "println", "");
					if(m_array == nullptr){
						return false;
					}
					ArrayIteratorLog(pankey_Log_EndMethod, "operator ==", "println", "");
					return m_pos == i.m_pos;
				}
				
				bool operator !=(ArrayIterator i){
					ArrayIteratorLog(pankey_Log_StartMethod, "operator !=", "println", "");
					if(m_array == nullptr){
						return false;
					}
					ArrayIteratorLog(pankey_Log_EndMethod, "operator !=", "println", "");
					return m_pos != i.m_pos;
				}
				virtual ArrayIterator& operator =(const ArrayIterator& i){
					ArrayIteratorLog(pankey_Log_StartMethod, "operator =", "println", "");
					m_array = i.m_array;
					m_pos = i.m_pos;
					ArrayIteratorLog(pankey_Log_EndMethod, "operator =", "println", "");
					return *this;
				}
			protected:
				T* m_array = nullptr;
				int m_pos = 0;
		};

	}

#endif