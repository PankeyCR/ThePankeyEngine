

#ifndef PrimitiveList_h
#define PrimitiveList_h

#include "List.h"
#include "MemoryFree.h"

template<class T>
class PrimitiveList : public List<T>{
	public:
		int expandSize=5;
		
		PrimitiveList(){
			this->values = new T*[this->size];
			for(int x=0; x < this->size; x++){
				this->values[x] = nullptr;
			}
		}
		
		PrimitiveList(int lsize){
			this->values = new T*[lsize];
			this->size = lsize;
			for(int x=0; x < this->size; x++){
				this->values[x] = nullptr;
			}
		}
		
		PrimitiveList(bool own){
			owner = own;
			this->values = new T*[this->size];
			for(int x=0; x < this->size; x++){
				this->values[x] = nullptr;
			}
		}
		
		PrimitiveList(int lsize, bool own){
			owner = own;
			this->values = new T*[lsize];
			this->size = lsize;
			for(int x=0; x < this->size; x++){
				this->values[x] = nullptr;
			}
		}
		
		virtual ~PrimitiveList(){
			//Serial.println("PrimitiveList");
			if(this->values != nullptr){
				if(owner && this->values != nullptr){
					for(int x=0; x < this->pos ; x++){
						if(this->values[x] != nullptr){
							delete this->values[x];
						}
					}
				}
				delete[] this->values;
				this->values = nullptr;
			}
			//Serial.println("end");
		}
		

		virtual bool isEmpty(){
			return pos==0;
		}
		
		virtual void setPos(int p){
			this->pos = p;
		}
		
		virtual int getPos(){
			return this->pos;
		}
		
		virtual int getSize(){
			return this->size;
		}
		
		virtual void add(List<T> *list){
			for(int x=0; x < list->getSize() ; x++){
				this->add(list->getByPos(x));
			}
		}
	
		template<class... args>
		void addPack(args... x){
			T array[] = {x...};
			for(const T &a : array){
				add(a);
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
		
		virtual T* add(T* value){
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
			return this->values[this->pos-1];
		}
		
		virtual T* add(T value){
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(this->pos >= this->size){
				return nullptr;
			}
			if(this->values[this->pos] == nullptr){
				this->values[this->pos] = new T();
			}
			*this->values[this->pos] = value;
			this->pos++;
			return this->values[this->pos-1];
		}
		
		virtual T* set(int position,T value){
			if(position >= this->size){
				return nullptr;			
			}
			if(this->values[position] == nullptr){
				this->values[position] = new T();
			}
			*this->values[position] = value;
			return this->values[position];
		}
		
		virtual T* set(int position,T* value){
			if(position >= this->size){
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
		
		virtual T* insert(int position, T value){
			if(position >= this->size){
				this->expandLocal(this->expandSize+(position-this->size));
			}
            if(position >= size){
				return nullptr;
            }
            if(position >= pos+1){
				return nullptr;
            }
			T* nVaule;
			T* rVaule = new T();
			*rVaule = value;
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
		
		virtual T* insert(int position, T* value){
            if(value == nullptr || values[position] == value){
				return nullptr;
            }
			if(position >= this->size){
				this->expandLocal(this->expandSize+(position-this->size));
			}
            if(position >= size){
				return nullptr;
            }
            if(position >= pos+1){
				return nullptr;
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
		
		virtual T* get(T* key){
			iterate(this){
				if(key == this->getPointer()){
					return this->getPointer();
				}
			}
			return nullptr;
		}
		
		virtual T* get(T key){
			iterate(this){
				if(key == this->getValue()){
					return this->getPointer();
				}
			}
			return nullptr;
		}
		
		virtual T* getByPos(int x){
			if(x < this->pos){
				return this->values[x];
			}
			return nullptr;
		}
		
		virtual bool contain(T* key){
		for(int xk = 0; xk < this->pos; xk++){
			if(key == this->values[xk]){
				return true;
			}
		}
		return false;
		}
		
		virtual bool contain(T key){
		for(int xk = 0; xk < this->pos; xk++){
			if(key == *this->values[xk]){
				return true;
			}
		}
			return false;
		}
		
		virtual int getIndex(T* key){
		iterate(this){
			if(key == this->getPointer()){
				return this->getIteration();
			}
		}
		return false;
		}
		
		virtual int getIndex(T key){
			iterate(this){
				if(key == this->getValue()){
					return this->getIteration();
				}
			}
			return false;
		}
		
		virtual void reset(){
			this->pos = 0;
		}
		
		virtual void resetDelete(){
			if(this->pos == 0){
				return;
			}
			// Serial.println("resetDelete");
			// Serial.println(freeMemory());
			for(int x=0; x < this->pos; x++){
				if(this->values[x] != nullptr && this->owner){
					delete this->values[x];
					//Serial.println("delinting");
				}
				this->values[x] = nullptr;
			}
			// Serial.println("end resetDelete");
			// Serial.println(freeMemory());
			this->pos = 0;
		}
		
		virtual T* remove(T *key){
			T *t = nullptr;
			bool is=false;
			iterate(this){
				if(key == this->getPointer()){
					is = true;
				}
			}
			if(is){
				int nv =0;
				iterate(this){
					if(key != this->getPointer()){
						this->values[nv] = this->values[this->getIteration()];
						nv++;
					}else{
						t = this->values[this->getIteration()];
					}
				}
				pos = nv;
				return t;
			}
			return nullptr;
		}
		
		virtual T* remove(T key){
			T *t = nullptr;
			bool is=false;
			iterate(this){
				if(key == this->getValue()){
					is = true;
				}
			}
			if(is){
				int nv =0;
				iterate(this){
					if(key != this->getValue()){
						this->values[nv] = this->values[this->getIteration()];
						nv++;
					}else{
						t = this->values[this->getIteration()];
					}
				}
				pos = nv;
				return t;
			}
			return nullptr;
		}
		
		virtual T* removeByPos(int p){
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
		
		virtual void removeDelete(T* key){
			T* t = this->remove(key);
			if(t != nullptr && owner){
				delete t;
			}
		}
		
		virtual void removeDelete(T key){
			T* t = this->remove(key);
			if(t != nullptr && owner){
				delete t;
			}
		}
		
		virtual void removeDeleteByPos(int p){
			if(p >= pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(x == p ){
					if(values[x] != nullptr && owner){
						delete values[x];
					}
				}
				if(x > p ){
					values[x-1] = values[x];
				}
			}
			pos--;
		}
		
		virtual T& operator[](int x){
			if(x >= size){
				return *this->values[size-1];
			}
			if(pos == x){
				pos++;
			}
			this->values[x] = new T();
			return *this->values[x];
		}
		
		
		//iterator part
		virtual T getValue(){
			return *this->values[this->getIteration()];
		}
		
		virtual T* getPointer(){
			return this->values[this->getIteration()];
		}
		
		virtual T* set(T s){
			return this->set(this->getIteration() , s);
		}
		
		virtual T* set(T* s){
			return this->set(this->getIteration() , s);
		}
		
		virtual T* insert(T s){
			int p = this->iterateCount;
			this->iterateCount++;
			return this->insert(p , s);
		}
		
		virtual T* insert(T* s){
			int p = this->iterateCount;
			this->iterateCount++;
			return this->insert(p , s);
		}
		
		virtual T* remove(){
			int p = this->iterateCount;
			this->iterateCount--;
			return this->removeByPos(p);
		}
		
		void removeDelete(){
			int p = this->iterateCount;
			this->iterateCount--;
			this->removeDeleteByPos(p);
		}
		
		virtual int getIterationSize(){
			return this->pos;
		}
		
		
		//cppObject part
		virtual void onDelete(){
			for(int x=0; x < pos; x++){
				if(this->values[x] != nullptr && owner){
					delete this->values[x];
				}
				this->values[x] = nullptr;
			}
			pos = 0;
		}
		
		virtual String getClassName(){
			return "PrimitiveList";
		}
		
		virtual String toString(){
			return "PrimitiveList";
		}
		
		virtual PrimitiveList<T>* clone(){
			return new PrimitiveList<T>(this->size);
		}
		
		
		//resize length by adding more space
		//bug unkown for template = char on feather m0
		virtual void expandLocal(int add){
			int nsize = this->size+add;
			T **nT;
			nT = new T*[nsize];
			for(int x=0; x < this->pos; x++){
				nT[x] = this->values[x];
			}
			delete[] this->values;
			this->values = nT;
			this->size = nsize;
		}
		
		virtual PrimitiveList<T>* expand(int add){
			int nsize = this->size+add;
			PrimitiveList<T> *nprimitive = new PrimitiveList<T>(nsize);	
			for(int x=0; x < this->pos; x++){
				nprimitive->add(this->values[x]);
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
