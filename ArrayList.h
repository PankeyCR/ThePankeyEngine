
#ifndef ArrayList_h
#define ArrayList_h

#include "cppObject.h"
#include "List.h"

template <class T,int size=20>
class ArrayList : public List<T>{
	private:
	
    public:
		int pos;
		T values[size];
		
		ArrayList<T,size>(){
			pos=0;
		}
		
		ArrayList<T,size>(T t[],int s){
			pos=0;
			for(int x=0; x<s; x++){
				this->add(t[x]);
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
		
		T *getByPos(int x){
			if(x >= pos){
				return NULL;
			}
			return &values[x];
		}
		
		void add(List<T> *list){
            if(list == NULL){
				return;
            }
			for(int x=0; x < list->getSize() ; x++){
				values[pos] = *list->getByPos(x);
				pos++;
			}
		}
		
		template<class... Args>
		T* add(Args... args){
            if(pos >= size){
				return nullptr;
            }
			values[pos] = T(args...);
			pos++;
			return &values[pos-1];
		}
		
		T* add(T *value){
            if(pos >= size){
				delete value;
				return nullptr;
            }
			values[pos] = *value;
			delete value;
			pos++;
			return &values[pos-1];
		}
		
		T* add(T value){
            if(pos >= size){
				return nullptr;
            }
			values[pos] = value;
			pos++;
			return &values[pos-1];
		}
		
		T* set(int position,T value){
            if(position >= size){
				return nullptr;
            }
			values[position] = value;
			return &values[position];
		}
		
		T* set(int position,T* value){
            if(position >= size){
				return nullptr;
            }
			if(value == nullptr){
				return nullptr;
			}
			values[position] = *value;
			delete value;
			return &values[position];
		}
		
		T* insert(int position, T value){
            if(position >= size){
				return nullptr;
            }
            if(position >= pos+1){
				return nullptr;
            }
			T nVaule;
			T rVaule = value;
			for(int x = 0; x <= pos; x++){
				if(x >= position){
					nVaule = values[x];
					values[x] = rVaule;
					rVaule = nVaule;
				}
			}
			return &values[position];
		}
		
		T* insert(int position, T* value){
            if(position >= size){
				return nullptr;
            }
            if(position >= pos+1){
				return nullptr;
            }
            if(value == nullptr){
				return nullptr;
            }
			T nVaule;
			T rVaule = *value;
			for(int x = 0; x <= pos; x++){
				if(x >= position){
					nVaule = values[x];
					values[x] = rVaule;
					rVaule = nVaule;
				}
			}
			return &values[position];
		}
		
		T *get(T *key){
			for(int x=0; x < pos; x++){
				if(values[x] == *key ){
					return &values[x];
				}
			}
			return nullptr;
		}
		
		T* get(T key){
			for(int x=0; x < pos; x++){
				if(values[x] == key ){
					return &values[x];
				}
			}
			return nullptr;
		}
		
		bool contain(T* key){
			for(int x=0; x < pos; x++){
				if(values[x] == *key ){
					return true;
				}
			}
			return false;
		}
		
		bool contain(T key){
			for(int x=0; x < pos; x++){
				if(values[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		void reset(){
			pos=0;
		}
		
		void resetDelete(){
			pos=0;
		}
		
		T* remove(T* key){
			T *t = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(values[x] == *key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(values[x] != *key ){
						values[nv] = values[x];
						nv++;
					}else{
						t = &values[x];
					}
				}
				pos = nv;
			}
			return t;
		}
		
		T* remove(T key){
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
						t = &values[x];
					}
				}
				pos = nv;
			}
			return t;
		}
		
		T* removeByPos(int p){
			if(p >= pos){
				return nullptr;
			}
			T* t = nullptr;
			for(int x=0; x < pos; x++){
				if(x == p ){
					t = &values[x];
				}
				if(x > p ){
					values[x-1] = values[x];
				}
			}
			pos--;
			return t;
		}
	
		void removeDelete(T* key){
			bool is=false;
			for(int x=0; x < pos; x++){
				if(values[x] == *key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(values[x] != *key ){
						values[nv] = values[x];
						nv++;
					}
				}
				pos = nv;
			}
		}
	
		void removeDelete(T key){
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
					}
				}
				pos = nv;
			}
		}
		
		void removeDeleteByPos(int p){
			if(p >= pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(x > p ){
					values[x-1] = values[x];
				}
			}
			pos--;
		}
		
		T& operator[](int x){
			if(x >= size){
				return values[size-1];
			}
			if(pos == x){
				pos++;
			}
			return values[x];
		}
		
		String getClassName(){
			return "ArrayList";
		}
		
		int getIterationSize(){
			return pos;
		}
		
		T getValue(){
			return *this->getByPos(this->getIteration());
		}
		
		T* getPointer(){
			return this->getByPos(this->getIteration());
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
			List<T>* list = new ArrayList<T,size>();
			
			for(int xl=0; xl < this->pos; xl++){
				list->add(values[xl]);
			}
			
			return list;
		}
		
        void operator =(ArrayList<T,size> t){
			for(int xtst=0; xtst<size; xtst++){
				values[xtst] == *t.getByPos(xtst);
			}
		}
		
        void operator =(const T a[size]){
			for(int xtst=0; xtst<size; xtst++){
				values[xtst] == a[xtst];
			}
		}
		
        bool operator ==(ArrayList<T,size> t){
			return this->getClassName() == t.getClassName();
		}
		
        bool operator !=(ArrayList<T,size> t){
			return this->getClassName() != t.getClassName();
		}
};

#endif 
