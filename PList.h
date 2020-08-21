
#ifndef PList_h
#define PList_h

#include "cppObject.h"
#include "List.h"

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
				for(int x=0; x < size ; x++){
					if(values[x] != nullptr){
						delete values[x];
					}
				}
			}
		}
		
		void setPos(int p){
			pos=p;
		}
		
		int getPos(){
			return pos;
		}
		
		int getSize(){
			return size;
		}
		
		T* getByPos(int x){
			if(x >= pos){
				return nullptr;
			}
			return values[x];
		}
		
		void add(List<T> *list){
            if(list == nullptr){
				return;
            }
			for(int x=0; x < list->getPos() ; x++){
				while(values[pos] != nullptr){
					pos++;
				}
				if(pos >= size){
					return;
				}
				values[pos] = list->getByPos(x);
				pos++;
			}
		}
		
		template<class... Args>
		T* add(Args... args){
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
		
		T* add(T* value){
            if(pos >= size){
				return nullptr;
            }
			while(values[pos] != nullptr){
				pos++;
			}
            if(pos >= size){
				return nullptr;
            }
			values[pos] = value;
			pos++;
			return value;
		}
		
		T* add(T value){
            if(pos >= size){
				return nullptr;
            }
			while(values[pos] != nullptr){
				pos++;
			}
            if(pos >= size){
				return nullptr;
            }
			values[pos] = new T();
			*values[pos] = value;
			pos++;
			return values[pos-1];
		}
		
		T* set(int position, T value){
            if(position >= size){
				return nullptr;
            }
			if(values[position] == nullptr){
				values[position] = new T();
			}
			*values[position] = value;
			return values[position];
		}
		
		T* set(int position, T* value){
            if(position >= size){
				return nullptr;
            }
			if(values[position] != nullptr && values[position] != value && owner){
				delete this->values[position];
			}
			values[position] = value;
			return value;
		}
		
		T* insert(int position, T value){
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
		
		T* insert(int position, T* value){
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
		
		T* get(T* key){
			for(int x=0; x < pos; x++){
				if(values[x] == key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		T* get(T key){
			for(int x=0; x < pos; x++){
				if(*values[x] == key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		bool contain(T *key){
			for(int x=0; x < pos; x++){
				if(values[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		bool contain(T key){
			for(int x=0; x < pos; x++){
				if(*values[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		void reset(){
			pos=0;
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
		
		T *remove(T* key){
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
		
		T *remove(T key){
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
		
		T *removeByPos(int p){
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
	
		void removeDelete(T *key){
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
						if(values[x] != nullptr && owner){
							delete values[x];
						}
					}
				}
				pos = nv;
			}
		}
	
		void removeDelete(T key){
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
						if(values[x] != nullptr && owner){
							delete values[x];
						}
					}
				}
				pos = nv;
			}
		}
		
		void removeDeleteByPos(int p){
			if(p >= pos){
				return;
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
			if(t != nullptr && owner){
				delete t;
			}
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
		
		String getClassName(){
			return "PList";
		}
		
		int getIterationSize(){
			return pos;
		}
		
		T getValue(){
			return *values[this->getIteration()];
		}
		
		T* getPointer(){
			return values[this->getIteration()];
		}
		
		T* set(T s){
			return this->set(this->getIteration() , s);
		}
		
		T* set(T* s){
			return this->set(this->getIteration() , s);
		}
		
		T* insert(T s){
			int p = this->iterateCount;
			this->iterateCount++;
			return this->insert(p , s);
		}
		
		T* insert(T* s){
			int p = this->iterateCount;
			this->iterateCount++;
			return this->insert(p , s);
		}
		
		T* remove(){
			int p = this->iterateCount;
			this->iterateCount--;
			return this->removeByPos(p);
		}
		
		void removeDelete(){
			int p = this->iterateCount;
			this->iterateCount--;
			this->removeDeleteByPos(p);
		}
		
		List<T>* clone(){
			List<T>* list = new PList<T,size>();
			
			for(int xl=0; xl < size; xl++){
				list->add(values[xl]);
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
};

#endif 
