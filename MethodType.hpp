
#ifndef MethodType_hpp
#define MethodType_hpp
#define MethodType_AVAILABLE

namespace ame{

enum class MethodType {
	Method,
	MethodReturn,
	
	ObjectMethod,
	ObjectMethodReturn,
	
	ClassMethod,
	ClassMethodReturn
};

}

#endif