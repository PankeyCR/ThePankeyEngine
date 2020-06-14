
#ifndef KVMap_h
#define KVMap_h

#include "cppObject.h"
#include "Map.h"

template <class K,class P,int size>
class KVMap : public Map<K,P>{
	
    public:
		int pos=0;
		P values[size];
		K keys[size];
		
		KVMap(){
			
		}
		
		virtual ~KVMap(){
			
		}
		
		void setPos(int p){
			this->pos = p;
		}
		
		int getPos(){
			return this->pos;
		}
		
		int getSize(){
			return size;
		}
		
		void add(K *key, P *value){
			if(size < this->pos){
				return;
			}
			this->keys[pos] = *key;
			this->values[pos] = *value;
			this->pos++;
		}
		
		void add(K key, P value){
			if(size < this->pos){
				return;
			}
			this->keys[pos] = key;
			this->values[pos] = value;
			this->pos++;
		}
		
		void add(K key, P *value){
			if(size < this->pos){
				return;
			}
			this->keys[pos] = key;
			this->values[pos] = *value;
			this->pos++;
		}
		
		void set(K *key, P *value){
			if(size < this->pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(this->keys[x] == *key ){
					this->values[x] = *value;
				}
			}
		}
		
		void set(K key, P value){
			if(size < this->pos){
				return;
			}
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					this->values[x] = value;
				}
			}
		}
		
		void set(K key, P *value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(this->keys[x] == key ){
					this->values[x] = *value;
				}
			}
		}
		
		void setKeyByPos(int p, K key){
			if(size < p){
				return;
			}
			keys[p] = key;
		}
		
		void setKeyByPos(int p, K *key){
			if(size < p){
				return;
			}
			keys[p] = *key;
		}
		
		void setValueByPos(int p, P value){
			if(size < p){
				return;
			}
			values[p] = value;
		}
		
		void setValueByPos(int p, P *value){
			if(size < p){
				return;
			}
			values[p] = *value;
		}
		
		bool contain(K *key){
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == *key ){
					return true;
				}
			}
			return false;
		}
		
		bool contain(K key){
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		bool containValue(P *value){
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == *value ){
					return true;
				}
			}
			return false;
		}
		
		bool containValue(P value){
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == value ){
					return true;
				}
			}
			return false;
		}
		
		P *get(K *key){
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == *key ){
					return &this->values[x];
				}
			}
			return nullptr;
		}
		
		P *get(K key){
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					return &this->values[x];
				}
			}
			return nullptr;
		}
		
		P *getByPos(int p){
			for(int x=0; x < this->pos; x++){
				if(x == p){
					return &this->values[x];
				}
			}
			return nullptr;
		}
		
		K *getKeyByPos(int p){
			for(int x=0; x < this->pos; x++){
				if(x == p ){
					return &this->keys[x];
				}
			}
			return nullptr;
		}
		
		K *getKey(P *value){
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == *value ){
					return &this->keys[x];
				}
			}
			return nullptr;
		}
	
		K *getKey(P value){
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == value ){
					return &this->keys[x];
				}
			}
			return nullptr;
		}
		
		void reset(){
			this->pos=0;
		}
		
		void resetDelete(){
			for(int x=0; x < this->pos; x++){
				delete &this->values[x];
			}
			pos=0;
		}
		
		P *remove(K *key){
			P *p =nullptr;
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == *key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(this->keys[x] != *key ){
						this->keys[nv] = keys[x];
						this->values[nv] = values[x];
						nv++;
					}else{
						p=&this->values[x];
					}
				}
				this->pos = nv;
			}
			return p;
		}
		
		P *remove(K key){
			P *p =nullptr;
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(this->keys[x] != key ){
						this->keys[nv] = keys[x];
						this->values[nv] = values[x];
						nv++;
					}else{
						p=&this->values[x];
					}
				}
				this->pos = nv;
			}
			return p;
		}
		
		P *removeByPos(int ps){
			P *p = nullptr;
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(x == ps ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(x != ps ){
						this->keys[nv] = keys[x];
						this->values[nv] = values[x];
						nv++;
					}else{
						p=&this->values[x];
					}
				}
				this->pos = nv;
			}
			return p;
		}
		
		void removeDelete(K *key){
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == *key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(this->keys[x] != *key ){
						this->keys[nv] = keys[x];
						this->values[nv] = values[x];
						nv++;
					}else{
						delete &this->values[x];
					}
				}
				this->pos = nv;
			}
		}
		
		void removeDelete(K key){
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(this->keys[x] != key ){
						this->keys[nv] = keys[x];
						this->values[nv] = values[x];
						nv++;
					}else{
						delete &this->values[x];
					}
				}
				this->pos = nv;
			}
		}
		
		void removeDeleteByPos(int ps){
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(x == ps ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(x != ps ){
						this->keys[nv] = keys[x];
						this->values[nv] = values[x];
						nv++;
					}else{
						delete &this->values[x];
					}
				}
				this->pos = nv;
			}
		}
		
		void onDelete(){
			
		}
		
		String getClassName(){
			return "KVMap";
		}
		
		int getIterationSize(){
			return this->pos;
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
			Map<K,P>* cloneMap = new KVMap<K,P,size>();
			
			for(int cm = 0; cm < pos; cm++){
				cloneMap->add(keys[cm], values[cm]);
			}
			
			return cloneMap;
		}
		
        void operator =(KVMap<K,P,size> t){
			
		}
		
        bool operator ==(KVMap<K,P,size> t){
			return this->getClassName() == t->getClassName();
		}
		
        bool operator !=(KVMap<K,P,size> t){
			return this->getClassName() != t->getClassName();
		}
	
		
	private:
};

#endif 
