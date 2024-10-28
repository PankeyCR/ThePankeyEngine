
#ifndef ClassFunction_hpp
	#define ClassFunction_hpp
	
	namespace pankey{

		template<class T, class... Args>
		class ClassFunction{
			public:
				ClassFunction(){}
				virtual ~ClassFunction(){}
				
				virtual T run(Args... a_args){return T();}
				virtual bool fit(T a_result, Args... a_args){return false;}

				virtual void operator=(const ClassFunction<T,Args...>& a_cfun){}
				virtual bool operator==(const ClassFunction<T,Args...>& a_cfun){return true;}
				virtual bool operator!=(const ClassFunction<T,Args...>& a_cfun){return false;}
		};

	}

#endif