
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

		virtual bool isEmpty(){
			return this->pos==0;
		}
		
		void setPosition(int p){
			this->pos = p;
		}
		
		int getPosition(){
			return this->pos;
		}
		
		int getSize(){
			return size;
		}
		
		void addPointers(K *key, P *value){
			if(size < this->pos){
				return;
			}
			this->keys[pos] = *key;
			this->values[pos] = *value;
			this->pos++;
			delete key;
			delete value;
		}
		
		void addLValues(K key, P value){
			if(size < this->pos){
				return;
			}
			this->keys[pos] = key;
			this->values[pos] = value;
			this->pos++;
		}
		
		void addPointer(K key, P *value){
			if(size < this->pos){
				return;
			}
			this->keys[pos] = key;
			this->values[pos] = *value;
			this->pos++;
			delete value;
		}
		
		void setPointers(K *key, P *value){
			if(size < this->pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(this->keys[x] == *key ){
					this->values[x] = *value;
				}
			}
		}
		
		void setLValues(K key, P value){
			if(size < this->pos){
				return;
			}
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					this->values[x] = value;
				}
			}
		}
		
		void setPointer(K key, P *value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(this->keys[x] == key ){
					this->values[x] = *value;
				}
			}
		}
		
		void setKeyLValueByPosition(int p, K key){
			if(size < p){
				return;
			}
			keys[p] = key;
		}
		
		void setKeyPointerByPosition(int p, K *key){
			if(size < p){
				return;
			}
			keys[p] = *key;
		}
		
		void setValueByPosition(int p, P value){
			if(size < p){
				return;
			}
			values[p] = value;
		}
		
		void setValuePointerByPosition(int p, P *value){
			if(size < p){
				return;
			}
			values[p] = *value;
		}
		
		bool containKeyByPointer(K *key){
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == *key ){
					return true;
				}
			}
			return false;
		}
		
		bool containKeyByLValue(K key){
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					return true;
				}
			}
			return false;
		}
		
		bool containValueByPointer(P *value){
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == *value ){
					return true;
				}
			}
			return false;
		}
		
		bool containValueByLValue(P value){
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == value ){
					return true;
				}
			}
			return false;
		}
		
		P *getByPointer(K *key){
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == *key ){
					return &this->values[x];
				}
			}
			return nullptr;
		}
		
		P *getByLValue(K key){
			for(int x=0; x < this->pos; x++){
				if(this->keys[x] == key ){
					return &this->values[x];
				}
			}
			return nullptr;
		}
		
		P *getByPosition(int p){
			for(int x=0; x < this->pos; x++){
				if(x == p){
					return &this->values[x];
				}
			}
			return nullptr;
		}
		
		K *getKeyByPosition(int p){
			for(int x=0; x < this->pos; x++){
				if(x == p ){
					return &this->keys[x];
				}
			}
			return nullptr;
		}
		
		K *getKeyByPointer(P *value){
			for(int x=0; x < this->pos; x++){
				if(this->values[x] == *value ){
					return &this->keys[x];
				}
			}
			return nullptr;
		}
	
		K *getKeyByLValue(P value){
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
			this->pos=0;
		}
		
		P *removeByPointer(K *key){
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
		
		P *removeByLValue(K key){
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
		
		P *removeByPosition(int ps){
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
		
		void removeDeleteByPointer(K *key){
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
					}
				}
				this->pos = nv;
			}
		}
		
		void removeDeleteByLValue(K key){
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
					}
				}
				this->pos = nv;
			}
		}
		
		void removeDeleteByPosition(int ps){
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
		
		P getLValue(Iterator iterate){
			return *this->getByPosition(iterate.getIteration());
		}
		
		P *getPointer(Iterator iterate){
			return this->getByPosition(iterate.getIteration());
		}
		
		K getKey(Iterator iterate){
			return *this->getKeyByPosition(iterate.getIteration());
		}
		
		K *getKeyPointer(Iterator iterate){
			return this->getKeyByPosition(iterate.getIteration());
		}
		
		Map<K,P>* clone(void){
			Map<K,P>* cloneMap = new KVMap<K,P,size>();
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(keys[cm], values[cm]);
			}
			return cloneMap;
		}
		
		Map<K,P>* clone(bool owningMemory){
			Map<K,P>* cloneMap = new KVMap<K,P,size>();
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(keys[cm], values[cm]);
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
