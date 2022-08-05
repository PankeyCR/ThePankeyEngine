
#include "ame_Enviroment.hpp"

#if defined(DISABLE_PList)
	#define PList_hpp
#endif

#ifndef PList_hpp
#define PList_hpp
#define PList_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ListIterator.hpp"
#include "cppObject.hpp"
#include "List.hpp"

namespace ame{

template <class T,int size>
class PList : public List<T>{
	private:
		int pos;	
		bool owner = false;
    public:
		
		T* values[size];
		
		PList<T,size>(){
			pos=0;
			for(int x=0; x < size ; x++){
				values[x] = nullptr;
			}
		}
		
		PList<T,size>(bool own){
			pos=0;
			owner = own;
			for(int x=0; x < size ; x++){
				values[x] = nullptr;
			}
		}
		
		~PList<T,size>(){
			if(owner){
				for(int x=0; x < pos ; x++){
					if(values[x] != nullptr){
						delete values[x];
					}
				}
			}
		}

		bool isEmpty()const{
			return pos==0;
		}
		
		void setPosition(int p){
			pos=p;
		}
		
		int getPosition()const{
			return pos;
		}
		
		int getSize()const{
			return size;
		}
		
		T* getByPosition(int x)const{
			if(x >= pos){
				return nullptr;
			}
			return values[x];
		}
	
		virtual bool replace(int i, int j){
			if(i >= pos || j >= pos){
				return false;
			}
			T* it = values[i];
			T* jt = values[j];
			values[i] = jt;
			values[j] = it;
			return true;
		}
	
		template<class... args>
		void addPack(args... x){
			T array[] = {x...};
			//for(const T &a : array){
			for(T a : array){
				addLValue(a);
			}
		}
		
		template<class... Args>
		T* addParameters(Args... args){
            if(pos >= size){
				return nullptr;
            }
			while(values[pos] != nullptr){
				pos++;
			}
            if(pos >= size){
				return nullptr;
            }
			values[pos] = new T(args...);
			pos++;
			return values[pos-1];
		}
		
		T* addPointer(T* value){
            if(pos >= size){
				return nullptr;
            }
			values[pos] = value;
			pos++;
			return value;
		}
		
		T* addLValue(T value){
            if(pos >= size){
				return nullptr;
            }
			values[pos] = new T();
			*values[pos] = value;
			pos++;
			return values[pos-1];
		}
		
		T* setLValue(int position, T value){
            if(position >= size){
				return nullptr;
            }
			if(values[position] == nullptr){
				values[position] = new T();
			}
			*values[position] = value;
			return values[position];
		}
		
		T* setPointer(int position, T* value){
            if(position >= size){
				return nullptr;
            }
			if(values[position] != nullptr && values[position] != value && owner){
				delete this->values[position];
			}
			values[position] = value;
			return value;
		}
		
		T* insertLValue(int position, T value){
            if(position >= size){
				return nullptr;
            }
            if(position >= pos+1){
				return nullptr;
            }
			T* nVaule = nullptr;
			T* rVaule = new T();
			*rVaule = value;
			if(owner){
				for(int x = 0; x <= size; x++){
					if(x == size && nVaule != nullptr){
						delete nVaule;
					}
					if(x >= position && x != size){
						nVaule = values[x];
						values[x] = rVaule;
						rVaule = nVaule;
					}
				}
			}else{
				for(int x = 0; x <= pos; x++){
					if(x >= position){
						nVaule = values[x];
						values[x] = rVaule;
						rVaule = nVaule;
					}
				}
			}
			if(pos < size){
				pos++;
			}
			return values[position];
		}
		
		T* insertPointer(int position, T* value){
            if(value == nullptr || values[position] == value){
				return nullptr;
            }
            if(position >= size){
				return nullptr;
            }
            if(position >= pos+1){
				return nullptr;
            }
			T* nVaule;
			T* rVaule = value;
			if(owner){
				for(int x = 0; x <= pos; x++){
					if(x == size && nVaule != nullptr){
						delete nVaule;
					}
					if(x >= position && x != size){
						nVaule = values[x];
						values[x] = rVaule;
						rVaule = nVaule;
					}
				}
			}else{
				for(int x = 0; x <= pos; x++){
					if(x >= position){
						nVaule = values[x];
						values[x] = rVaule;
						rVaule = nVaule;
					}
				}
			}
			if(pos < size){
				pos++;
			}
			return values[position];
		}
		
		T* getByPointer(T* key){
			for(int x=0; x < pos; x++){
				if(values[x] == key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		T* getByLValue(T key){
			for(int x=0; x < pos; x++){
				if(*values[x] == key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		bool containByPointer(T *key){
			for(int x=0; x < pos; x++){
				if(values[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		bool containByLValue(T key){
			for(int x=0; x < pos; x++){
				if(*values[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		int getIndexByPointer(T *key){
			for(int x=0; x < pos; x++){
				if(values[x] == key ){
					return x;
				}
			}
			return -1;
		}
		
		int getIndexByLValue(T key){
			for(int x=0; x < pos; x++){
				if(*values[x] == key ){
					return x;
				}
			}
			return -1;
		}
		
		void reset(){
			pos=0;
			for(int x=0; x < pos; x++){
				values[x] = nullptr;
			}
		}
		
		void resetDelete(){
			for(int x=0; x < pos; x++){
				if(values[x] != nullptr && owner){
					delete values[x];
				}
				values[x] = nullptr;
			}
			pos=0;
		}
		
		T* removeByPointer(T* key){
			T *t = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(values[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(values[x] != key ){
						values[nv] = values[x];
						nv++;
					}else{
						t = values[x];
					}
				}
				pos = nv;
			}
			return t;
		}
		
		T* removeByLValue(T key){
			T *t = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(*values[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(*values[x] != key ){
						values[nv] = values[x];
						nv++;
					}else{
						t = values[x];
					}
				}
				pos = nv;
			}
			return t;
		}
		
		T* removeByPosition(int p){
			if(p >= pos){
				return nullptr;
			}
			T* t = nullptr;
			for(int x=0; x < pos; x++){
				if(x == p ){
					t = values[x];
				}
				if(x > p ){
					values[x-1] = values[x];
				}
			}
			pos--;
			return t;
		}
	
		void onDelete(){
			for(int x=0; x < pos; x++){
				if(values[x] != nullptr && owner){
					delete values[x];
				}
				values[x] = nullptr;
			}
			pos = 0;
		}
	
		////////////////////////////////////////////special removes part///////////////////////////////////////////////
		virtual bool removeAll(T value){
			bool r_val = false;
			int p_x = 0;
			for(int x = 0; x < pos; x++){
				if(value == *values[x]){
					if(owner){
						delete values[x];
					}
					r_val = true;
				}else{
					values[p_x] = values[x];
					p_x++;
				}
			}
			pos = p_x;
			return r_val;
		}
		
		virtual bool removeFirst(T value){
			bool r_val = false;
			bool r_once = true;
			int p_x = 0;
			for(int x = 0; x < pos; x++){
				if(value == *values[x] && r_once){
					if(owner){
						delete values[x];
					}
					r_once = false;
					r_val = true;
				}else{
					values[p_x] = values[x];
					p_x++;
				}
			}
			pos = p_x;
			return r_val;
			// return false;
		}
		
		virtual bool removeLast(T value){
			int r_pos = pos;
			for(int x = pos - 1; x >= 0; x--){
				if(value == *values[x]){
					r_pos = x;
					break;
				}
			}
			
			bool r_val = false;
			bool r_once = true;
			int p_x = r_pos;
			for(int x = p_x; x < pos; x++){
				if(value == *values[x] && r_once){
					if(owner){
						delete values[x];
					}
					r_once = false;
					r_val = true;
				}else{
					values[p_x] = values[x];
					p_x++;
				}
			}
			pos = p_x;
			return r_val;
			// return false;
		}
	
		////////////////////////////////////////////operator part///////////////////////////////////////////////
		
		T& operator[](int x){
			if(x >= size){
				return *values[size-1];
			}
			if(pos == x){
				pos++;
			}
			values[x] = new T();
			return *values[x];
		}
		
		cppObjectClass* getClass(){
			return Class<PList>::classType;
		}
		
		int getIterationSize(){
			return pos;
		}
		
		T getLValue(Iterator iterate){
			return *values[iterate.getIteration()];
		}
		
		T* getPointer(Iterator iterate){
			return values[iterate.getIteration()];
		}
		
		T* setLValue(Iterator iterate, T s){
			return this->setLValue(iterate.getIteration() , s);
		}
		
		T* setPointer(Iterator iterate, T* s){
			return this->setPointer(iterate.getIteration() , s);
		}
		
		T* insertLValue(Iterator& iterate, T s){
			int p = iterate.getIteration();
			iterate.next();
			return this->insertLValue(p , s);
		}
		
		T* insertPointer(Iterator& iterate, T* s){
			int p = iterate.getIteration();
			iterate.next();
			return this->insertPointer(p , s);
		}
		
		T* remove(Iterator& iterate){
			int p = iterate.getIteration();
			iterate.last();
			return this->removeByPosition(p);
		}
		
		void removeDelete(Iterator& iterate){
			int p = iterate.getIteration();
			iterate.last();
			this->removeDeleteByPosition(p);
		}
		
		List<T>* clone(){
			List<T>* list = new PList<T,size>(true);
			for(int xl=0; xl < pos; xl++){
				list->addLValue(*values[xl]);
			}
			return list;
		}
		
		List<T>* clone(bool owningMemory){
			List<T>* list = new PList<T,size>(owningMemory);
			for(int xl=0; xl < pos; xl++){
				list->addLValue(*values[xl]);
			}
			return list;
		}
		
        void operator =(PList<T,size> t){
			
		}
		
        bool operator ==(PList<T,size> t){
			return this->getClassName() == t.getClassName();
		}
		
        bool operator !=(PList<T,size> t){
			return this->getClassName() != t.getClassName();
		}
	
		////////////////////////////////////////////Iterator part///////////////////////////////////////////////
		
		ListIterator<T> begin(){
		  return ListIterator<T>(this, 0, this->getPosition());
		}
		
		ListIterator<T> end(){
		  return ListIterator<T>(this, this->getPosition(), this->getPosition());
		}
};

}

#endif