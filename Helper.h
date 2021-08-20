
#ifndef Helper_h
#define Helper_h

#include "List.h"

namespace ame{

template<class T>
void swap(T* a, T* b){
	T a1 = *a;
	T b1 = *b;
	*a = b1;
	*b = a1;
}

template<class T>
void sort(List<T>* list){
	if(list == nullptr){
		return;
	}
	for(int x1 = 0; x1 < list->getPosition(); x1++){
		for(int x2 = 0; x2 < list->getPosition() - 1; x2++){
			T* t1 = list->getByPosition(x2);
			T* t2 = list->getByPosition(x2+1);
			if(t1 == nullptr || t2 == nullptr){
				continue;
			}
			if(*t1 > *t2){
				swap<T>(t1,t2);
			}
		}
	}
}

}

#endif 
