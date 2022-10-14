
#ifndef Set_hpp
#define Set_hpp

#include "cppObject.hpp"
#include "cppObjectClass.hpp"
#include "LinkedList.hpp"
#include "TemplateClass.hpp"

namespace ame{

class Set : public cppObject{
    public:
		Set(){}
		Set(const Set& c_set){
			
		}
		// template<class... args>
		// Set(args... x){
			// m_sets.addPack(x...);
		// }
		virtual ~Set(){}
		/*
		virtual bool belongs(const Set& a_var){
			return m_sets.containByLValue(a_var);
		}
		virtual bool equals(const Set& a_var){
			if(a_var.m_sets.getPosition() != m_sets.getPosition()){
				return false;
			}
			for(int x = 0; x < m_sets.getPosition(); x++){
				Set* i_set_1 = m_sets.getByPosition(x);
				Set* i_set_2 = a_var.m_sets.getByPosition(x);
				if(i_set_1 != i_set_2){
					return false;
				}
			}
			return true;
		}
		virtual bool similar(const Set& a_var){
			if(a_var.m_sets.getPosition() != m_sets.getPosition()){
				return false;
			}
			for(int x = 0; x < m_sets.getPosition(); x++){
				Set& i_set_1 = m_sets.getByIndex(x);
				Set& i_set_2 = a_var.m_sets.getByIndex(x);
				if(!i_set_1.similar(i_set_2)){
					return false;
				}
			}
			return true;
		}
		
		virtual Set Intersection(){
			
			return Set();
		}
		virtual Set Union(){return Set();}
		virtual Set Difference(){return Set();}
		virtual Set Complement(){return Set();}
		
		virtual Set Intersection(const Set& a_set){return Set();}
		virtual Set Union(const Set& a_set){return Set();}
		virtual Set Difference(const Set& a_set){return Set();}
		virtual Set Complement(const Set& a_set){return Set();}
		
		
		virtual Set& operator=(const Set& a_set){
			return *this;
		}
		virtual bool operator==(const Set& a_set){
			return false;
		}
		virtual bool operator!=(const Set& a_set){
			return false;
		}
		
		virtual bool copy(cppObject* obj){return false;}
		virtual bool move(cppObject* obj){return false;}
		virtual bool duplicate(cppObject* obj){return false;}
		
		virtual bool equal(cppObject* obj){return this == obj;}
		
		virtual cppObjectClass* getClass(){return m_class;}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == m_class;
		}

		virtual cppObject* clone(void){return nullptr;}
		virtual cppObject* clone(bool owningMemory){return nullptr;}
		
		virtual cppObject* move(){return nullptr;}
		virtual cppObject* duplicate(){return nullptr;}
	protected:
		LinkedList<Set> m_sets;
		
	public:
		static cppObjectClass* m_class;
		*/
};

// cppObjectClass* Set::m_class = new TemplateClass<Set>();

}

#endif
