
#ifndef PList_h
#define PList_h

#include "cppObject.h"
#include "List.h"

template <class T,int size>
class PList : public List<T>{
	private:
		int pos;	
    public:
		
		T *values[size];
		
		PList<T,size>(){
			pos=0;
		}
		
		~PList<T,size>(){
			
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
				return nullptr;
			}
			return values[x];
		}
		
		void add(List<T> *list){
            if(list == nullptr){
				return;
            }
			for(int x=0; x < pos ; x++){
				values[pos] = list->getByPos(x);
				pos++;
			}
		}
		
		void add(T *value){
            if(pos >= size){
				return;
            }
			values[pos] = value;
			pos++;
		}
		
		void add(T value){
            if(pos >= size){
				return;
            }
			*values[pos] = value;
			pos++;
		}
		
		void set(int posIn,T value){
            if(posIn >= size){
				return;
            }
			*values[posIn] = value;
		}
		
		void set(int posIn,T *value){
            if(posIn >= size){
				return;
            }
			values[posIn] = value;
		}
		
		T *get(T *key){
			for(int x=0; x < pos; x++){
				if(values[x] == key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		T *get(T key){
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
				delete values[x];
			}
			pos=0;
		}
		
		T *remove(T *key){
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
			T *t = nullptr;
				int nv =0;
				for(int x=0; x < pos; x++){
					if(x != p ){
						values[nv] = values[x];
						nv++;
					}else{
						t = values[x];
					}
				}
				pos = nv;
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
						delete values[x];
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
						delete values[x];
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
						delete values[x];
					}
				}
				pos = nv;
		}
	
		void onDelete(){
			for(int x=0; x < pos; x++){
				delete values[x];
			}
		}
		
		String getClassName(){
			return "PList";
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
