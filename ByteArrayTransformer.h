
#ifndef ByteArrayTransformer_h
#define ByteArrayTransformer_h

#include "PrimitiveList.h"
#include "ByteArray.h"
#include "Iterator.h"
#include "ByteArrayForm.h"

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

#endif