
#ifndef DISABLE_Class_hpp
#define DISABLE_Class_hpp

	#if defined(DISABLE_cppObject) || defined(DISABLE_cppObjectClass) || defined(DISABLE_Class)
		#define Class_hpp
	#endif
#endif

#ifndef Class_hpp
#define Class_hpp
#define Class_AVAILABLE

#include "cppObject.hpp"
#include "TemplateClass.hpp"
#include "ClassCount.hpp"
#include "Number.hpp"
// #include "Set.hpp"

namespace ame{

template<class cls = cppObject>
struct Class{
	static cppObjectClass* classType;
	
	static cppObjectClass* getClass(){return classType;}
	
	static long getType(){
		return ClassCount<cls>::get();
	}
	
	Class(){}
	Class(const Class& c_cls){
		m_class = c_cls.m_class;
	}
	Class(cppObjectClass* c_cls){
		m_class = c_cls;
	}
	virtual ~Class(){}
	
	cppObjectClass* get(){ return m_class; }
	
	void operator=(const Class& o_cls){
		m_class = o_cls.m_class;
	}
	void operator=(cppObjectClass* o_cls){
		m_class = o_cls;
	}
	bool operator==(const Class& o_cls){
		return m_class == o_cls.m_class;
	}
	bool operator!=(const Class& o_cls){
		return m_class != o_cls.m_class;
	}
	bool operator==(cppObjectClass* o_cls){
		return m_class == o_cls;
	}
	bool operator!=(cppObjectClass* o_cls){
		return m_class != o_cls;
	}
	
	cppObjectClass* m_class = nullptr;
};

template<class cls> cppObjectClass* Class<cls>::classType = new TemplateClass<cls>();

template<> cppObjectClass* Class<int>::classType = Number::m_class;
template<> cppObjectClass* Class<double>::classType = Number::m_class;
template<> cppObjectClass* Class<float>::classType = Number::m_class;
template<> cppObjectClass* Class<Number>::classType = Number::m_class;

// template<> cppObjectClass* Class<Set>::classType = Set::m_class;

}

#endif