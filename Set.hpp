
#ifndef Set_hpp
	#define Set_hpp
		
	#include "higgs_Enviroment.hpp"
	#include "higgs_Enviroment_config.hpp"

	namespace higgs{

		class Set;

		using set = instance<Set>;

		class Set{
			public:
				Set(){}
				Set(const Set& c_set){
					this->m_members.duplicate(c_set.m_members);
				}

				virtual ~Set(){}

				virtual bool isEmpty(){
					return this->m_members.isEmpty();
				}
				
				virtual void add(set& a_set){
					this->m_members.add(a_set);
				}
				
				virtual bool belongs(const set& a_set){
					return this->m_members.contain(a_set);
				}
				/*
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
				}*/
			protected:
				TList<Set> m_members;
		};

	}

#endif
