
#ifndef State_hpp
	#define State_hpp

	namespace higgs{

		template<class... Args>
		class State{
			public:
				State(){}
				virtual ~State(){}

				virtual void initialize(){
					this->initializeState();
				}
				virtual void initializeState(){}
				virtual bool hasInitialize(){return false;}
				virtual void onEnable(){}
				virtual void onDisable(){}
				virtual void update(Args... a_values){
					this->updateState(a_values...);
				}
				virtual void updateState(Args... a_values){}
				
				virtual void operator=(State b){}
				virtual bool operator==(State b){return false;}
				virtual bool operator!=(State b){return true;}
				
			protected:
		};

	}

#endif
