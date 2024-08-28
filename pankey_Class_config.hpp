
#ifndef pankey_Class_config_hpp
	#define pankey_Class_config_hpp

	#include "ClassType.hpp"
	#include "cppObject.hpp"
	#include "Number.hpp"

	template<> cppObjectClass* ClassType<int,cppObjectClass>::type = Number::m_class;
	template<> cppObjectClass* ClassType<double,cppObjectClass>::type = Number::m_class;
	template<> cppObjectClass* ClassType<float,cppObjectClass>::type = Number::m_class;
	template<> cppObjectClass* ClassType<Number,cppObjectClass>::type = Number::m_class;

	namespace ame{

		template<class O>
		using EngineClass = Class<O,cppObjectClass>;

	}

#endif