
#ifndef AppState_hpp
	#define AppState_hpp

	namespace pankey{

		template<class A, class... Args>
		class AppState{
			public:
				AppState(){}
				virtual ~AppState(){}

				virtual void initialize(A& app){
					this->initializeState(app);
				}
				virtual void initializeState(A& app){}
				virtual bool hasInitialize(){return false;}
				virtual void onEnable(){}
				virtual void onDisable(){}
				virtual void update(A& a_app, Args... a_values){
					this->updateState(a_app, a_values...);
				}
				virtual void updateState(A& a_app, Args... a_values){}
				
				virtual void operator=(AppState b){}
				virtual bool operator==(AppState b){return false;}
				virtual bool operator!=(AppState b){return true;}
				
			protected:
		};

	}

#endif
