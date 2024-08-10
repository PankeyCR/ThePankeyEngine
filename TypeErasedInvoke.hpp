
#ifndef TypeErasedInvoke_hpp
#define TypeErasedInvoke_hpp

#include "Note.hpp"

namespace higgs{

template<class... Args>
struct TypeErasedInvoke{
	template<typename T>
	TypeErasedInvoke(T&& t){
	    *this = t;
    }
	virtual ~TypeErasedInvoke(){
		if(m_value != nullptr){
			delete m_value;
		}
	}

	template<typename T>
	TypeErasedInvoke& operator=(T&& t){
		if(m_value != nullptr){
			delete m_value;
		}
		m_value = new Model<T>(t);
		return *this;
	}

	void invoke(Note name, Args... a){
		if(m_value == nullptr){
			return;
		}
		m_value->invoke(name, a...);
	}
	protected:
		struct Concept {
			virtual ~Concept(){}
			virtual void invoke(Note name, Args... a)=0;
		};
		template<typename M>
		struct Model : Concept{
			Model(M const& value) : m_val(value){}
			virtual ~Model(){}
			virtual void invoke(Note name, Args... a){
				m_val.invoke(name, a...);
			}
			M m_val;
		};
		Concept* m_value = nullptr;
};

}

#endif