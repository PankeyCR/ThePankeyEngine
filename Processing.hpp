
#ifndef Processing_hpp
	#define Processing_hpp

	namespace pankey{

		template<class V>
		class Processing{
			public:
				Processing(){}
				virtual ~Processing(){}
				
				virtual V processing(V plantValue, V controlValue){}
				
			protected:
		};

	}

#endif