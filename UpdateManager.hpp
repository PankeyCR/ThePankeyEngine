
#ifndef UpdateManager_hpp
	#define UpdateManager_hpp

	namespace pankey{

		template<class... Args>
		class UpdateManager{
			public:
				virtual ~UpdateManager(){}
				
				virtual void removeAll()=0;
				
				virtual void update(Args... a_update)=0;
		};

	}

#endif
