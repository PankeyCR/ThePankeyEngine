
#ifndef PMap_h
#define PMap_h

#include "cppObject.h"
#include "Map.h"

template <class K,class P,int size>
class PMap : public Map<K,P>{
	
    public:
		P *values[size];
		K *keys[size];
		
		PMap(){
			pos=0;
			for(int x=0; x < size; x++){
				keys[x] = nullptr;
				values[x] = nullptr;
			}
		}
		
		~PMap(){
			
		}
		
		void setPos(int p){
			pos = p;
		}
		
		int getPos(){
			return pos;
		}
		
		int getSize(){
			return size;
		}
		
		void add(K *key, P *value){
			if(size < pos){
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		void add(K key, P value){
			if(size < pos){
				return;
			}
			*keys[pos] = key;
			*values[pos] = value;
			pos++;
		}
		
		void add(K key, P *value){
			if(size < pos){
				return;
			}
			*keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		void set(K *key, P *value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					values[x] = value;
				}
			}
		}
		
		void set(K key, P value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					*values[x] = value;
				}
			}
		}
		
		void set(K key, P *value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					values[x] = value;
				}
			}
		}
		
		void setKeyByPos(int p, K key){
			if(size < p){
				return;
			}
			*keys[p] = key;
		}
		
		void setKeyByPos(int p, K *key){
			if(size < p){
				return;
			}
			keys[p] = key;
		}
		
		void setValueByPos(int p, P value){
			if(size < p){
				return;
			}
			*values[p] = value;
		}
		
		void setValueByPos(int p, P *value){
			if(size < p){
				return;
			}
			values[p] = value;
		}
		
		bool contain(K *key){
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		bool contain(K key){
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		bool containValue(P *value){
			for(int x=0; x < pos; x++){
				if(values[x] == value ){
					return true;
				}
			}
			return false;
		}
		
		bool containValue(P value){
			for(int x=0; x < pos; x++){
				if(*values[x] == value ){
					return true;
				}
			}
			return false;
		}
		
		P *get(K *key){
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		P *get(K key){
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					return values[x];
				}
			}
			return nullptr;
		}
		
		P *getByPos(int p){
			for(int x=0; x < pos; x++){
				if(x == p){
					return values[x];
				}
			}
			return nullptr;
		}
		
		K *getKeyByPos(int p){
			for(int x=0; x < pos; x++){
				if(x == p ){
					return keys[x];
				}
			}
			return nullptr;
		}
		
		K *getKey(P *value){
			for(int x=0; x < pos; x++){
				if(values[x] == value ){
					return keys[x];
				}
			}
			return nullptr;
		}
		
		K *getKey(P value){
			for(int x=0; x < pos; x++){
				if(*values[x] == value ){
					return keys[x];
				}
			}
			return nullptr;
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
		
		P *remove(K *key){
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(keys[x] != key ){
						keys[nv] = keys[x];
						values[nv] = values[x];
						nv++;
					}else{
						p=values[x];
					}
				}
				pos = nv;
			}
			return p;
		}
		
		P *remove(K key){
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(*keys[x] != key ){
						keys[nv] = keys[x];
						values[nv] = values[x];
						nv++;
					}else{
						p=values[x];
					}
				}
				pos = nv;
			}
			return p;
		}
		
		P *removeByPos(int ps){
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(x == ps ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(x != ps ){
						keys[nv] = keys[x];
						values[nv] = values[x];
						nv++;
					}else{
						p=values[x];
					}
				}
				pos = nv;
			}
			return p;
		}
		
		void removeDelete(K *key){
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(keys[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(keys[x] != key ){
						keys[nv] = keys[x];
						values[nv] = values[x];
						nv++;
					}else{
						p=values[x];
						delete p;
					}
				}
				pos = nv;
			}
		}
		
		void removeDelete(K key){
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(*keys[x] != key ){
						keys[nv] = keys[x];
						values[nv] = values[x];
						nv++;
					}else{
						p=values[x];
						delete p;
					}
				}
				pos = nv;
			}
		}
		
		void removeDeleteByPos(int ps){
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < pos; x++){
				if(x == ps ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < pos; x++){
					if(x != ps ){
						keys[nv] = keys[x];
						values[nv] = values[x];
						nv++;
					}else{
						p=values[x];
						delete p;
					}
				}
				pos = nv;
			}
		}
		
		void onDelete(){
			for(int x=0; x < pos; x++){
				delete values[x];
				delete keys[x];
			}
			delete this;
		}
		
		String getClassName(){
			return "PMap";
		}
		
		int getIterationSize(){
			return pos;
		}
		
		P getValue(){
			return *this->getByPos(this->getIteration());
		}
		
		P *getPointer(){
			return this->getByPos(this->getIteration());
		}
		
		K getKey(){
			return *this->getKeyByPos(this->getIteration());
		}
		
		K *getKeyPointer(){
			return this->getKeyByPos(this->getIteration());
		}
		
		Map<K,P>* clone(){
			Map<K,P>* cloneMap = new PMap<K,P,size>();
			
			for(int cm = 0; cm < pos; cm++){
				cloneMap->add(keys[cm], values[cm]);
			}
			
			return cloneMap;
		}
		
        void operator =(PMap<K,P,size> t){
			
		}
		
        bool operator ==(PMap<K,P,size> t){
			return this->getClassName() == t->getClassName();
		}
		
        bool operator !=(PMap<K,P,size> t){
			return this->getClassName() != t->getClassName();
		}
		
		
		
	private:
		int pos;
};

#endif 
