
#ifndef Command_hpp
	#define Command_hpp

	namespace pankey{

		template<class... Args>
		class Command{
			public:
				virtual ~Command(){}
				virtual void execute(Args... args)=0;
		};

	}

#endif