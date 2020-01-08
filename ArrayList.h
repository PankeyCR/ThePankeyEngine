
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
		
		ArrayList<T,size>(ArrayList<T,size> *array){
			pos=0;
			for(int x=0; x<array->getPos(); x++){
				this->add(*array->getByPos(x));
			}
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
			for(int x=0; x < pos ; x++){
				values[pos] = *list->getByPos(x);
				pos++;
			}
		}
		
		void add(T *value){
            if(pos >= size){
				return;
            }
			values[pos] = *value;
			pos++;
		}
		
		void add(T value){
            if(pos >= size){
				return;
            }
			values[pos] = value;
			pos++;
		}
		
		void set(int posIn,T value){
            if(posIn >= size){
				return;
            }
			values[posIn] = value;
		}
		
		void set(int posIn,T *value){
            if(posIn >= size){
				return;
            }
			values[posIn] = *value;
		}
		
		T *get(T *key){
			for(int x=0; x < pos; x++){
				if(values[x] == *key ){
					return &values[x];
				}
			}
			return NULL;
		}
		
		T *get(T key){
			for(int x=0; x < pos; x++){
				if(values[x] == key ){
					return &values[x];
				}
			}
			return NULL;
		}
		
		bool contain(T *key){
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
			for(int x=0; x < pos; x++){
				delete &values[x];
			}
			pos=0;
		}
		
		T *remove(T *key){
			T *t = NULL;
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
		
		T *remove(T key){
			T *t = NULL;
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
		
		T *removeByPos(int p){
			T *t = NULL;
				int nv =0;
				for(int x=0; x < pos; x++){
					if(x != p ){
						values[nv] = values[x];
						nv++;
					}else{
						t = &values[x];
					}
				}
				pos = nv;
			return t;
		}
	
		void removeDelete(T *key){
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
						delete &values[x];
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
					}else{
						delete &values[x];
					}
				}
				pos = nv;
			}
		}
		
		void removeDeleteByPos(int p){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(x != p ){
						values[nv] = values[x];
						nv++;
					}else{
						delete &values[x];
					}
				}
				pos = nv;
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
		
		T *getPointer(){
			return this->getByPos(this->getIteration());
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
			return this->getClassName() == t->getClassName();
		}
		
        bool operator !=(ArrayList<T,size> t){
			return this->getClassName() != t->getClassName();
		}
};

#endif 
