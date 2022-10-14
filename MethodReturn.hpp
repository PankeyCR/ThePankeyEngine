
#ifndef MethodReturn_hpp
#define MethodReturn_hpp
#define MethodReturn_AVAILABLE

namespace ame{
	
template<class R>
struct MethodReturn{
	static R* m_return_method;
	
	static void set(R a_r){
		if(m_return_method == nullptr){
			m_return_method = new R();
		}
		*m_return_method = a_r;
	}
	static R getReturn(){
		if(m_return_method == nullptr){
			return R();
		}
		*m_return_method;
	}
};

template<class R> R* MethodReturn<R>::m_return_method = nullptr;

}

#endif