
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ByteArrayTransformer)
	#define ByteArrayTransformer_hpp
#endif

#ifndef ByteArrayTransformer_hpp
#define ByteArrayTransformer_hpp
#define ByteArrayTransformer_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PrimitiveList.hpp"
#include "ByteArray.hpp"
#include "Iterator.hpp"
#include "ByteArrayForm.hpp"

namespace ame{

template<class T>
class ByteTransformer{
public:
ByteTransformer(){}
virtual ~ByteTransformer(){}

virtual T* ByteTransform(ByteArray array){return nullptr;}

};

template<class T>
struct ByteTransformerList{
	static PrimitiveList<ByteTransformer<T>>* list;
};
template<class T> PrimitiveList<ByteTransformer<T>>* ByteTransformerList<T>::list = nullptr;

class ByteArrayTransformer{
public:
ByteArrayTransformer(){}
virtual ~ByteArrayTransformer(){}

template<class T>
void addTransform(ByteTransformer<T>* t){
	if(ByteTransformerList<T>::list == nullptr){
		ByteTransformerList<T>::list = new PrimitiveList<ByteTransformer<T>>();
	}
	ByteTransformerList<T>::list->addPointer(t);
}
template<class T>
void removeTransform(ByteTransformer<T>* t){
	if(ByteTransformerList<T>::list == nullptr){
		return;
	}
	ByteTransformerList<T>::list->removeByPointer(t);
}
template<class T>
void deleteByteTransformerList(){
	if(ByteTransformerList<T>::list != nullptr){
		delete ByteTransformerList<T>::list;
	}
}

template<class T>
T* Transform(ByteArray array){
	if(ByteTransformerList<T>::list == nullptr){
		return nullptr;
	}
	for(Iterator i : ByteTransformerList<T>::list){
		T* t = ByteTransformerList<T>::list->getPointer(i)->ByteTransform(array);
		if(t != nullptr){
			return t;
		}
	}
	return nullptr;
}

template<class T>
T ByteArrayForm(const ByteArray& array){
	T t;
	t.setByteArray(array);
	return t;
}
};

}

#endif