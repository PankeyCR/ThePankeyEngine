
#ifndef cppObjectMacros_hpp
#define cppObjectMacros_hpp

#define IMPLEMENTING_CPPOBJECT_POLYMORPHISM(TYPE_CLASS_IN){												\
	virtual bool instanceof(cppObjectClass* cls){														\
		return cls == Class<TYPE_CLASS_IN>::classType || cls == Class<cppObject>::classType;			\
	}																									\
	virtual cppObjectClass* getClass(){																	\
		return Class<TYPE_CLASS_IN>::classType;															\
	}																									\
}

#endif



