
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ListIterator) || defined(ame_upToLevel_1)
	#define ListIterator_hpp
#endif

#ifndef ListIterator_hpp
#define ListIterator_hpp
#define ListIterator_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "RawList.hpp"

namespace ame{

template<class T>
class ListIterator{

	public:
	
	ListIterator(RawList<T>* sList, int i_pos, int i_size){
		m_list = sList;
		m_pos = i_pos;
		m_size = i_size;
	}
	
	ListIterator(const ListIterator<T>& list_iterator){
		m_list = list_iterator.m_list;
		m_pos = list_iterator.m_pos;
		m_size = list_iterator.m_size;
	}
	virtual ~ListIterator(){}
	
	T& operator* (){
		return *m_list->getByPosition(m_pos);
	}
	
	ListIterator<T> &operator++ (){
		++m_pos;
		return *this;
	}
	
	ListIterator<T> &operator-- (){
		--m_pos;
		return *this;
	}
	
	bool operator== (const ListIterator<T> &ar) const{
		return m_pos == ar.m_size;
	}

	bool operator!= (const ListIterator<T> &ar) const{
		return m_pos != ar.m_size;
	}

	protected:
	
	RawList<T>* m_list = nullptr;
	
	int m_pos = 0;
	int m_size = 0;
};

}

#endif