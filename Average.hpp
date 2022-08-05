
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Average)
	#define Average_hpp
#endif

#ifndef Average_hpp
#define Average_hpp
#define Average_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template<class T>
class Average{
	public:
		Average(){
			this->value = new T();
			this->size = 0;
			this->mm = true;
		}
		
		Average(T *t){
			this->value = t;
			this->size = 0;
			this->mm = true;
		}
		
		Average(T *t, bool manageMemory){
			this->value = t;
			this->size = 0;
			this->mm = manageMemory;
		}
		
		virtual ~Average(){
			if(this->value != nullptr && this->mm){
				delete this->value;
			}
		}
		
		virtual int getSize(){
			return this->size;
		}
		
		virtual T getLValue(){
			return *this->value;
		}
		
		virtual T* getPointer(){
			return this->value;
		}
		
		virtual void addRValue(T&& t){
			*this->value += t;
			this->size++;
		}
		
		void addLValue(T t){
			this->addLValue(t);
		}
		
		virtual void add(T t){
			*this->value += t;
			this->size++;
		}
		
		virtual void addPointer(T *t){
			*this->value += *t;
			this->size++;
		}
		
		virtual T getAverage(){
			return *this->value / this->size;
		}
		
		virtual void reset(){
			*this->value = 0;
			this->size = 0;
		}
		
	protected:
		T *value = nullptr;
		int size = 0;
		bool mm = true;
};

}

#endif
