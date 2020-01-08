#ifndef ReflectionUtil_cpp
#define ReflectionUtil_cpp

#include "ReflectedObject.h"

	
	template <>
	int *ReflectedObject<int>::newInstance(){
		return new int();
	}
	
	template <>
	String *ReflectedObject<String>::newInstance(){
		return new String();
	}
	
	template <>
	Vector2f *ReflectedObject<Vector2f>::newInstance(){
		return new Vector2f();
	}

////////////////////////////////////////////////////////////////////////////////////


	template <>
	int *ReflectedObject<int>::newInstanceArray(int size){
		return new int[size];
	}
	
	template <>
	String *ReflectedObject<String>::newInstanceArray(int size){
		return new String[size];
	}
	
	template <>
	Vector2f *ReflectedObject<Vector2f>::newInstanceArray(int size){
		return new Vector2f[size];
	}

////////////////////////////////////////////////////////////////////////////////////


	template <>
	Vector2f *ReflectedObject<Vector2f>::cast(cppObject *obj){
		if(obj->getClassName() == "Vector2f"){
			return (Vector2f*)obj;
		}
		return NULL;
	}

////////////////////////////////////////////////////////////////////////////////////


	template <>
	bool ReflectedObject<int>::isType(String t){
		if(t == "int"){
			return true;
		}
		return false;
	}

	template <>
	bool ReflectedObject<String>::isType(String t){
		if(t == "String"){
			return true;
		}
		return false;
	}

	template <>
	bool ReflectedObject<Vector2f>::isType(String t){
		if(t == "Vector2f"){
			return true;
		}
		return false;
	}

#endif 