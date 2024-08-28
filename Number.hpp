
#ifndef Number_hpp
#define Number_hpp
#define Number_AVAILABLE

#define NUMBER_TYPE_VALUE 0
#define NUMBER_TYPE_VARIABLE 1

#include "cppObject.hpp"
#include "TemplateClass.hpp"
#include "Set.hpp"

namespace pankey{

class Number : public Set{
    public:
		Number(){}
		Number(const long& c_number){
			
		}
		Number(const int& c_number){
			
		}
		Number(const float& c_number){
			
		}
		Number(const Number& c_number){
			
		}
		virtual ~Number(){}
		
		virtual void onDelete(){}
		
		virtual bool copy(cppObject* obj){
			if(obj == nullptr ){
				return false;
			}
			if(!obj->instanceof(m_class)){
				return false;
			}
			Number* i_num = (Number*)obj;
			
			return true;
		}
		virtual bool move(cppObject* obj){
			if(obj == nullptr ){
				return false;
			}
			if(!obj->instanceof(m_class)){
				return false;
			}
			Number* i_num = (Number*)obj;
			
			return true;
		}
		virtual bool duplicate(cppObject* obj){
			if(obj == nullptr ){
				return false;
			}
			if(!obj->instanceof(m_class)){
				return false;
			}
			Number* i_num = (Number*)obj;
			
			return true;
		}
		
		virtual bool equal(cppObject* obj){
			if(this == obj){
				return true;
			}
			if(obj == nullptr ){
				return false;
			}
			if(!obj->instanceof(m_class)){
				return false;
			}
			Number* i_num = (Number*)obj;
			return false;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == m_class || Set::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return m_class;}

		virtual Number* clone(void){
			return new Number();
		}
		virtual Number* clone(bool owningMemory){
			return new Number();
		}
		
		virtual Number* move(){
			return new Number();
		}
		virtual Number* duplicate(){
			return new Number();
		}

		virtual Number& operator=(const Number& a_number){
			
			return *this;
		}
		virtual bool operator==(Number a_number){
			return false;
		}
		virtual bool operator!=(Number a_number){
			return true;
		}
		
		virtual Number operator+(const Number& a_number){
			Number i_num;
			
			return i_num;
		}
		
		virtual Number operator+=(const Number& a_number){
			
			return *this;
		}
		
		virtual Number operator-(const Number& a_number){
			
			return *this;
		}
		
		virtual Number operator-=(const Number& a_number){
			
			return *this;
		}
		
		virtual Number operator*(const Number& a_number){
			
			return *this;
		}
		
		virtual Number operator*=(const Number& a_number){
			
			return *this;
		}
		
		virtual Number operator/(const Number& a_number){
			
			return *this;
		}
		
		virtual Number operator/=(const Number& a_number){
			
			return *this;
		}
		
	protected:
		
		virtual void normalize(){
			
		}
		
	protected:
		long m_size = 0;
		float m_fraction = 0.0f;
		int m_type = 0;
		
	public:
		static cppObjectClass* m_class;
};

cppObjectClass* Number::m_class = new TemplateClass<Number>();

}

#endif