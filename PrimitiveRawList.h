
#ifndef PrimitiveRawList_h
#define PrimitiveRawList_h

#include "RawList.h"

template<class T>
class PrimitiveRawList : public RawList<T>{
	public:
		int expandSize=5;
		
		PrimitiveRawList(){
			this->values = new T*[this->size];
		}
		
		PrimitiveRawList(int lsize){
			this->values = new T*[lsize];
			this->size = lsize;
		}
		
		PrimitiveRawList(bool own){
			owner = own;
			this->values = new T*[this->size];
		}
		
		PrimitiveRawList( bool own, int lsize){
			owner = own;
			this->values = new T*[lsize];
			this->size = lsize;
		}
		
		virtual ~PrimitiveRawList(){
			if(owner){
				for(int x=0; x < this->pos ; x++){
					delete this->values[x];
				}
			}
			delete[] this->values;
		}
		

		virtual bool isEmpty()const{
			return pos==0;
		}
		
		virtual void setPosition(int p){
			this->pos = p;
		}
		
		virtual int getPosition()const{
			return this->pos;
		}
		
		virtual int getSize()const{
			return this->size;
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
		
		virtual void addList(RawList<T>* list){
			for(int x=0; x < list->getPosition() ; x++){
				this->addPointer(list->getByPosition(x));
			}
		}
	
		template<class... args>
		void addPack(args... x){
			T array[] = {x...};
			for(const T& a : array){
			//for(T a : array){
				addPointer(new T(a));
			}
		}
		
		template<class... Args>
		T* addParameters(Args... args){
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(this->pos >= this->size){
				return nullptr;
			}
			this->values[this->pos] = new T(args...);
			this->pos++;
			return this->values[this->pos-1];
		}
		
		virtual T* addPointer(T* value){
			if(value == nullptr){
				return nullptr;
			}
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(this->pos >= this->size){
				return nullptr;
			}
			this->values[this->pos] = value;
			this->pos++;
			//Memory<T>::(value);
			return this->values[this->pos-1];
		}
		
		virtual T* addLValue(T value){
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(this->pos >= this->size){
				return nullptr;
			}
			this->values[this->pos] = new T();
			*this->values[this->pos] = value;
			this->pos++;
			return this->values[this->pos-1];
		}
		
		virtual T* setLValue(int position, T value){
			if(position >= this->pos){
				return nullptr;			
			}
			*this->values[position] = value;
			return this->values[position];
		}
		
		virtual T* setPointer(int position, T* value){
			if(position >= this->pos){
				return nullptr;			
			}
			if(value == nullptr){
				return nullptr;
			}
			if(this->values[position] != nullptr && this->values[position] != value && owner){
				delete this->values[position];
			}
			this->values[position] = value;
			return value;
		}
		
		virtual T* insertLValue(int position, T value){
            if(position >= this->pos+1){
				return nullptr;
            }
			if(this->size == this->pos){
				this->expandLocal(this->expandSize);
			}
			T* nVaule;
			T* rVaule = new T();
			*rVaule = value;
			for(int x = 0; x <= this->pos; x++){
				if(x >= position){
					nVaule = values[x];
					values[x] = rVaule;
					rVaule = nVaule;
				}
			}
			this->pos++;
			return this->values[position];
		}
		
		virtual T* insertPointer(int position, T* value){
            if(value == nullptr || values[position] == value){
				return nullptr;
            }
            if(position >= this->pos+1){
				return nullptr;
            }
			if(this->size == this->pos){
				this->expandLocal(this->expandSize);
			}
			T* nVaule;
			T* rVaule = value;
			for(int x = 0; x <= pos; x++){
				if(x >= position){
					nVaule = values[x];
					values[x] = rVaule;
					rVaule = nVaule;
				}
			}
			pos++;
			return values[position];
		}
		
		virtual T* getByPointer(T* t){
			for(int x = 0; x < this->pos; x++){
				if(t == this->values[x]){
					return this->values[x];
				}
			}
			return nullptr;
		}
		
		virtual T* getByLValue(T t){
			for(int x = 0; x < this->pos; x++){
				if(t == *this->values[x]){
					return this->values[x];
				}
			}
			return nullptr;
		}
		
		virtual T* getByPosition(int x)const{
			if(x < this->pos){
				return this->values[x];
			}
			return nullptr;
		}
		
		virtual bool containByPointer(T* t){
		for(int x = 0; x < this->pos; x++){
			if(t == this->values[x]){
				return true;
			}
		}
		return false;
		}
		
		virtual bool containByLValue(T t){
		for(int x = 0; x < this->pos; x++){
			if(t == *this->values[x]){
				return true;
			}
		}
			return false;
		}
		
		virtual int getIndexByPointer(T* t){
			for(int x = 0; x < this->pos; x++){
				if(t == this->values[x]){
					return x;
				}
			}
			return -1;
		}
		
		virtual int getIndexByLValue(T t){
			for(int x = 0; x < this->pos; x++){
				if(t == *this->values[x]){
					return x;
				}
			}
			return -1;
		}
		
		virtual void reset(){
			this->pos = 0;
		}
		
		virtual void resetDelete(){
			if(this->owner){
				for(int x=0; x < this->pos; x++){
					delete this->values[x];
				}
			}
			this->pos = 0;
		}
		
		virtual T* removeByPointer(T *key){
			T* t = nullptr;
			int nv =0;
			for(int x = 0; x < this->pos; x++){
				if(key != this->values[x]){
					this->values[nv] = this->values[x];
					nv++;
				}else{
					t = this->values[x];
				}
			}
			this->pos = nv;
			return t;
		}
		
		virtual T* removeByLValue(T key){
			T* t = nullptr;
			int nv =0;
			for(int x = 0; x < this->pos; x++){
				if(key != *this->values[x]){
					this->values[nv] = this->values[x];
					nv++;
				}else{
					t = this->values[x];
				}
			}
			this->pos = nv;
			return t;
		}
		
		virtual T* removeByPosition(int p){
			if(p >= this->pos){
				return nullptr;
			}
			T* t = nullptr;
			for(int x=0; x < this->pos; x++){
				if(x == p ){
					t = this->values[x];
				}
				if(x > p ){
					this->values[x-1] = this->values[x];
				}
			}
			this->pos--;
			return t;
		}
		
		virtual void removeDeleteByPointer(T* key){
			T* t = this->removeByPointer(key);
			if(t != nullptr && owner){
				delete t;
			}
		}
		
		virtual void removeDeleteByLValue(T key){
			T* t = this->removeByLValue(key);
			if(t != nullptr && owner){
				delete t;
			}
		}
		
		virtual void removeDeleteByPosition(int p){
			T* t = this->removeByPosition(p);
			if(t != nullptr && owner){
				delete t;
			}
		}
		
		virtual T& operator[](int x){
			if(x > this->pos){
				return *this->values[this->pos-1];
			}
			if(this->pos == x){
				this->pos++;
			}
			this->values[x] = new T();
			return *this->values[x];
		}
		
		//resize length by adding more space
		//bug unkown for template = char on feather m0
		virtual void expandLocal(int add){
			int nsize = this->size+add;
			T **nT;
			nT = new T*[nsize];
			for(int x=0; x < this->pos; x++){
				if(x < this->pos){
					nT[x] = this->values[x];
				}else{
					nT[x] = nullptr;
				}
			}
			delete[] this->values;
			this->values = nT;
			this->size = nsize;
		}
		
		virtual PrimitiveRawList<T>* expand(int add){
			int nsize = this->size+add;
			PrimitiveRawList<T> *nprimitive = new PrimitiveRawList<T>(nsize);	
			for(int x=0; x < this->pos; x++){
				nprimitive->addPointer(this->values[x]);
			}
			return nprimitive;
		}
		
	protected:
		T **values = nullptr;
		int pos=0;
		int size=10;
		bool owner = true;
};

#endif 
