
#ifndef ClassMethodReturn_hpp
#define ClassMethodReturn_hpp
#define ClassMethodReturn_AVAILABLE

namespace ame{
	
template<class T, class R>
struct ClassMethodReturn{
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

template<class T, class R> R* ClassMethodReturn<T,R>::m_return_method = nullptr;

}

#endif