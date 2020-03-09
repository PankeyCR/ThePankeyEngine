#ifndef MFNEntry_h
#define MFNEntry_h

#include "Function.h"

template<class function_return, class... arr>
class MFNEntry {
	public:
		MFNEntry();
		MFNEntry(int inputD,int outputD, 
				 Function<function_return,arr...>* functionD);
		~MFNEntry();
		
		int input(); 
		int output(); 
		Function<function_return,arr...>* function();
		
		void operator=(MFNEntry<function_return,arr...> b);
		bool operator==(MFNEntry<function_return,arr...> b);
		bool operator!=(MFNEntry<function_return,arr...> b);
	protected:
		int inputE=0;
		int outputE=1;
		Function<function_return,arr...>* functionE;
};

#endif