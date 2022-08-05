
#include "ame_Enviroment.hpp"

#if defined(DISABLE_RawList)
	#define RawList_hpp
#endif

#ifndef RawList_hpp
#define RawList_hpp
#define RawList_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#define ame_LIST_COPY 0
#define ame_LIST_MOVE 1

namespace ame{

template <class T>
class RawList{	
	public:
	virtual ~RawList(){}
	virtual bool isEmpty()const=0;
	virtual bool isOwner()const{return false;}
	virtual void setPosition(int p)=0;
	virtual int getPosition()const=0;
	virtual int getSize()const=0;
	virtual bool replace(int i, int j)=0;
		
	virtual void addList(RawList<T>* list){
		for(int x=0; x < list->getPosition() ; x++){
			this->addLValue(*list->getByPosition(x));
		}
	}
	
	virtual T* addPointer(T* value)=0;
	virtual T* add(T value){
		return this->addLValue(value);
	}
	virtual void put(T value){
		if(this->containByLValue(value)){
			return;
		}
		this->addLValue(value);
	}
	virtual int repeated(T value){
		int size = 0;
		for(int x = 0; x < this->getPosition(); x++){
			T t = *this->getByPosition(x);
			if(value == t){
				size++;
			}
		}
		return size;
	}
	virtual T* addLValue(T value)=0;
	virtual T* setLValue(int position, T value)=0;
	virtual T* set(int position, T value){
		return this->setLValue(position, value);
	}
	virtual T* setPointer(int position, T* value)=0;
	virtual T* insertLValue(int position, T value)=0;
	virtual T* insertPointer(int position, T* value)=0;
	virtual T* getByPointer(T* key)=0;
	virtual T* get(T value){
		return this->getByLValue(value);
	}
	virtual T* getByLValue(T key)=0;
	virtual T* getByPosition(int x)const=0;
	virtual bool containByPointer(T* key)=0;
	virtual bool containByLValue(T key)=0;
	virtual bool contain(T key){return this->containByLValue(key);}
	virtual int getIndexByPointer(T* key)=0;
	virtual int getIndexByLValue(T key)=0;
	virtual int getIndex(T key){return this->getIndexByLValue(key);}
	virtual void reset()=0;
	virtual void resetDelete()=0;
	virtual T* removeByPointer(T* key)=0;
	virtual T* removeByLValue(T key)=0;
	virtual bool remove(T value){
		return this->removeDeleteByLValue(value);
	}
	virtual T* removeByPosition(int p)=0;
	
	virtual bool removeDeleteByPointer(T* key){
		T* t = this->removeByPointer(key);
		bool removed = t != nullptr;
		if(removed && isOwner()){
			delete t;
		}
		return removed;
	}
	
	virtual bool removeDeleteByLValue(T key){
		T* t = this->removeByLValue(key);
		bool removed = t != nullptr;
		if(removed && isOwner()){
			delete t;
		}
		return removed;
	}
	
	virtual bool removeDeleteByPosition(int p){
		T* t = this->removeByPosition(p);
		bool removed = t != nullptr;
		if(removed && isOwner()){
			delete t;
		}
		return removed;
	}
	
	//special removes
	virtual bool removeAll(T value)=0;
	virtual bool removeFirst(T value)=0;
	virtual bool removeLast(T value)=0;
	
	virtual T* addFirst(T value){
		return this->insertLValue(0, value);
	}
	virtual T* addLast(T value){
		return this->addLValue(value);
	}
	
	virtual bool removeFirst(){
		if(this->isEmpty()){
			return false;
		}
		return this->removeDeleteByPosition(0);
	}
	virtual bool removeLast(){
		if(this->isEmpty()){
			return false;
		}
		return this->removeDeleteByPosition(this->getPosition() - 1);
	}
	
	//operators
	virtual T& operator[](int x)=0;
	virtual bool operator<(int x) const{
		return this->getPosition() < x;
	}
	virtual bool operator>(int x) const{
		return this->getPosition() > x;
	}
	virtual bool operator<=(int x) const{
		return this->getPosition() <= x;
	}
	virtual bool operator>=(int x) const{
		return this->getPosition() >= x;
	}
	// virtual bool operator==(int x) const{
		// return this->getPosition() == x;
	// }
	// virtual bool operator!=(int x) const{
		// return this->getPosition() != x;
	// }
	private:
};

}

#endif