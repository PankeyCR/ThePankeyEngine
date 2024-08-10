
#ifndef AppEvent_hpp
	#define AppEvent_hpp

	namespace higgs{

		template<class A, class... Args>
		class AppEvent{
			public:
				AppEvent(){}
				virtual ~AppEvent(){}

				virtual void run(A& a_app, Args... a_values){
					this->runEvent(a_app, a_values...);
				}
				virtual void runEvent(A& a_app, Args... a_values){}
				
				virtual void operator=(AppEvent b){}
				virtual bool operator==(AppEvent b){return false;}
				virtual bool operator!=(AppEvent b){return true;}
				
			protected:
		};

	}

#endif
