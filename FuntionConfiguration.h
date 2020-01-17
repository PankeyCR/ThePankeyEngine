
#ifndef FuntionConfiguration_h
#define FuntionConfiguration_h

#include "GameBuilder.h"
#include "Funtion.h"

template<class type,class... any>
class FuntionConfiguration : public GameBuilder<Funtion<type,any...>>{
	public:
		virtual ~FuntionConfiguration(){}
		
	//	virtual FuntionConfiguration* setController(Controller* controller);
		
		virtual Funtion<type,any...>* build();
		
	protected:
		
};

#endif 
