
#ifndef FunctionConfiguration_h
#define FunctionConfiguration_h

#include "GameBuilder.h"
#include "Function.h"
#include "FunctionSetup.h"

template<class type,class... any>
class FunctionConfiguration : public GameBuilder<Function<type,any...>>{
	public:
		FunctionConfiguration();
		virtual ~FunctionConfiguration();
		
	//	virtual FunctionConfiguration* setController(Controller* controller);
		
		virtual Function<type,any...>* build();
		
		virtual FunctionConfiguration<type,any...>* functionsetup(FunctionSetup a);
		virtual FunctionSetup functionsetup();  
		
	protected:
		FunctionSetup functionse=FunctionSetup::ZeroStart;
		
};

#endif 
