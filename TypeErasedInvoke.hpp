
#ifndef TypeErasedInvoke_hpp
#define TypeErasedInvoke_hpp

namespace ame{

template<class... Args>
struct TypeErasedInvoke{
	template<typename T>
	TypeErasedInvoke(T&& t){ *this = t;Serial.println("rvalue construct invoke");}
	virtual ~TypeErasedInvoke(){
		if(m_value != nullptr){
			delete m_value;
		}
	}
	
	template<typename T>
	TypeErasedInvoke& operator=(T&& t){Serial.println("rvalue operator invoke");
		if(m_value != nullptr){
			delete m_value;
		}
		m_value = new Model<T>(t);
		return *this;
	}
	
	void invoke(String name, Args... a){
		if(m_value == nullptr){
			return;
		}
		m_value->invoke(name, a...);
	}
	protected:
		struct Concept {
			virtual ~Concept(){}
			virtual void invoke(String name, Args... a)=0;
		};
		template<typename M>
		struct Model : Concept{
			Model(M const& value) : m_val(value){}
			virtual ~Model(){}
			virtual void invoke(String name, Args... a){
				m_val.invoke(name, a...);
			}
			M m_val;
		};
		Concept* m_value = nullptr;
};

}

#endif 
