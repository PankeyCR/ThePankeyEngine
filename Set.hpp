
#include "ame_Enviroment.hpp"

#ifndef Set_hpp
#define Set_hpp

#include "ame_Level.hpp"

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PrimitiveList.hpp"

namespace ame{

class Set{
    public:
		Set():m_collection(false){}
		Set(const Set& c_set):m_collection(false){}
		virtual ~Set(){}
		
		virtual Set* add(const Set& a_set){
			// m_collection.addPointer(a_set);
			return nullptr;
		}
		virtual Set* get(int a_index){
			return nullptr;}
		virtual Set* getIndex(Set a_set){
			return nullptr;}
		virtual Set* remove(Set a_set){
			return nullptr;}
		virtual Set* removeIndex(int a_index){
			return nullptr;}
		
		virtual bool belongs(Set a_var){return false;}
		virtual bool equals(Set a_var){return false;}
		virtual bool similar(Set a_var){return false;}
		
		virtual bool belongs(Set* a_var){return false;}
		virtual bool equals(Set* a_var){return false;}
		virtual bool similar(Set* a_var){return false;}
		
		virtual Set Intersection(){return Set();}
		virtual Set Union(){return Set();}
		virtual Set Difference(){return Set();}
		virtual Set Complement(){return Set();}
		
		virtual Set Intersection(Set a_set){return Set();}
		virtual Set Union(Set a_set){return Set();}
		virtual Set Difference(Set a_set){return Set();}
		virtual Set Complement(Set a_set){return Set();}
		
		virtual Set Intersection(Set* a_set){return Set();}
		virtual Set Union(Set* a_set){return Set();}
		virtual Set Difference(Set* a_set){return Set();}
		virtual Set Complement(Set* a_set){return Set();}
		
		
		virtual Set operator=(const Set& a_set){
			return *this;
		}
		virtual bool operator==(const Set& a_set){
			return false;
		}
		virtual bool operator!=(const Set& a_set){
			return false;
		}
		
	protected:
		PrimitiveList<Set> m_collection;
};

}

#endif
