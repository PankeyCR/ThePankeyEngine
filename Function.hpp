
#include "ame_Level.hpp"

#if defined(ame_untilLevel_6)

#ifndef Function_hpp
#define Function_hpp

#include "cppObject.hpp"

namespace ame{

template<class T,class... args>
class Function : public cppObject{
// #if defined(ame_upToLevel_6)
// class Function{
// #elif defined(ame_upToLevel_7)
// class Function : public cppObject{
// #endif
	public:
		Function(){}
		virtual ~Function(){}
		virtual T f(args... mf)=0;
	protected:
};

}

#endif 

#endif 
