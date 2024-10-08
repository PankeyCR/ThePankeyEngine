
#ifndef RawList_hpp
#define RawList_hpp

#include "RawPointerList.hpp"

#ifdef RawList_LogApp
	#include "pankey_Logger.hpp"
	#define RawListLog(location,method,type,mns) pankey_Log(this,location,"RawList",method,type,mns)
#else
	#define RawListLog(location,method,type,mns)
#endif

namespace pankey{

template <class T>
class RawList : virtual public RawPointerList<T>{	
	public:
		virtual ~RawList(){}

		virtual void addCopy(RawPointerList<T>* a_list){
			RawPointerListLog(pankey_Log_StartMethod, "addCopy", "println", "");
			for(int x = 0; x < a_list->getPosition(); x++){
				T* f_value = a_list->getByPosition(x);
				if(f_value == nullptr){
					continue;
				}
				this->addLValue(*f_value);
			}
			RawPointerListLog(pankey_Log_EndMethod, "addCopy", "println", "");
		}

		virtual T* addLValue(T a_value)=0;

		virtual T* add(T a_value){
			RawListLog(pankey_Log_StartMethod, "add", "println", "");
			RawListLog(pankey_Log_EndMethod, "add", "println", "");
			return this->addLValue(a_value);
		}

		virtual T* setLValue(int a_position, T a_value)=0;
		
		virtual T* set(int a_position, T a_value){
			RawListLog(pankey_Log_StartMethod, "set", "println", "");
			RawListLog(pankey_Log_EndMethod, "set", "println", "");
			return this->setLValue(a_position, a_value);
		}
		
		virtual T* insertLValue(int a_position, T a_value)=0;
		
		virtual T* insert(int a_position, T a_value){
			RawListLog(pankey_Log_StartMethod, "insert", "println", "");
			RawListLog(pankey_Log_EndMethod, "insert", "println", "");
			return this->insertLValue(a_position, a_value);
		}
		
		virtual T* getByLValue(T a_value)=0;
		
		virtual T* get(T a_value){
			RawListLog(pankey_Log_StartMethod, "get", "println", "");
			RawListLog(pankey_Log_EndMethod, "get", "println", "");
			return this->getByLValue(a_value);
		}
		
		virtual T& getReferenceByIndex(int x)const{
			RawListLog(pankey_Log_StartMethod, "getByIndex", "println", "");
			RawListLog(pankey_Log_EndMethod, "getByIndex", "println", "");
			return *this->getByPosition(x);
		}
		
		virtual T getByIndex(int x)const{
			RawListLog(pankey_Log_StartMethod, "getByIndex", "println", "");
			T* i_pointer = this->getByPosition(x);
			if(i_pointer == nullptr){
				return T();
			}
			RawListLog(pankey_Log_EndMethod, "getByIndex", "println", "");
			return *i_pointer;
		}
		
		virtual bool containByLValue(T a_value)=0;
		
		virtual bool contain(T a_value){
			RawListLog(pankey_Log_StartMethod, "contain", "println", "");
			RawListLog(pankey_Log_EndMethod, "contain", "println", "");
			return this->containByLValue(a_value);
		}
		
		virtual int getIndexByLValue(T a_value)=0;
		
		virtual int getIndex(T a_value){
			RawListLog(pankey_Log_StartMethod, "getIndex", "println", "");
			RawListLog(pankey_Log_EndMethod, "getIndex", "println", "");
			return this->getIndexByLValue(a_value);
		}

		virtual T* removeByLValue(T a_value)=0;
		
		virtual bool remove(T a_value){
			RawListLog(pankey_Log_StartMethod, "remove", "println", "");
			RawListLog(pankey_Log_EndMethod, "remove", "println", "");
			return this->removeDeleteByLValue(a_value);
		}
		
		virtual bool removeByIndex(int a_position){
			RawListLog(pankey_Log_StartMethod, "removeByIndex", "println", "");
			RawListLog(pankey_Log_EndMethod, "removeByIndex", "println", "");
			return this->removeDeleteByPosition(a_position);
		}

		virtual bool removeDeleteByLValue(T a_value){
			RawListLog(pankey_Log_StartMethod, "removeDeleteByLValue", "println", "");
			T* t = this->removeByLValue(a_value);
			bool removed = t != nullptr;
			if(removed && this->isOwner()){
				RawListLog(pankey_Log_Statement, "removeDeleteByLValue", "println", "deleting pointer");
				delete t;
			}
			RawListLog(pankey_Log_EndMethod, "removeDeleteByLValue", "println", "");
			return removed;
		}
		
		//special removes
		virtual bool removeAll(T a_value)=0;
		virtual bool removeFirst(T a_value)=0;
		virtual bool removeLast(T a_value)=0;
	
		template<class... Args>
		void addPack(Args... x){
			RawListLog(pankey_Log_StartMethod, "addPack", "println", "");
			T array[] = {x...};
			for(const T& a : array){
				this->addPointer(new T(a));
			}
			RawListLog(pankey_Log_EndMethod, "addPack", "println", "");
		}
		
		template<class... Args>
		T* addWithParameters(Args... x){
			RawListLog(pankey_Log_StartMethod, "addWithParameters", "println", "");
			RawListLog(pankey_Log_EndMethod, "addWithParameters", "println", "");
			return this->addPointer(new T(x...));
		}
		
		virtual T* put(T a_value){
			RawListLog(pankey_Log_StartMethod, "put", "println", "");
			if(this->containByLValue(a_value)){
				return nullptr;
			}
			RawListLog(pankey_Log_EndMethod, "put", "println", "");
			return this->addLValue(a_value);
		}
		
		virtual int repeated(T a_value){
			RawListLog(pankey_Log_StartMethod, "repeated", "println", "");
			int size = 0;
			for(int x = 0; x < this->getPosition(); x++){
				T t = *this->getByPosition(x);
				if(a_value == t){
					size++;
				}
			}
			RawListLog(pankey_Log_EndMethod, "repeated", "println", "");
			return size;
		}
		
		virtual T* addFirst(T a_value){
			RawListLog(pankey_Log_StartMethod, "addFirst", "println", "");
			RawListLog(pankey_Log_EndMethod, "addFirst", "println", "");
			return this->insertLValue(0, a_value);
		}
		
		virtual T* addLast(T a_value){
			RawListLog(pankey_Log_StartMethod, "addLast", "println", "");
			RawListLog(pankey_Log_EndMethod, "addLast", "println", "");
			return this->addLValue(a_value);
		}
		
		//operators
		virtual T& operator[](int x)=0;
	private:
};

}

#endif