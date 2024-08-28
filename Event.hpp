
#ifndef Event_hpp
	#define Event_hpp

	namespace pankey{

		template<class... Args>
		class Event{
			public:
				Event(){}
				virtual ~Event(){}
				
				virtual void run(Args... a_values){
					this->runEvent(a_values...);
				}
				virtual void runEvent(Args... a_values){}
				
				virtual void operator=(Event b){}
				virtual bool operator==(Event b){return false;}
				virtual bool operator!=(Event b){return true;}
				
			protected:
		};

	}

#endif
