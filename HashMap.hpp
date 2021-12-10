
#ifndef HashMap_hpp
#define HashMap_hpp

#include "Map.hpp"
#include "MapIterator.hpp"

namespace ame{

template <class K,class V>
class HashMap : public Map<K,V>{	
    public:
		
		HashMap(){
			this->keys = new K*[this->size];
			this->values = new V*[this->size];
		}
		
		HashMap(const HashMap& map){
			this->owner = map.owner;
			this->keys = new K*[map.getSize()];
			this->values = new V*[map.getSize()];
			for(int x = 0; x < map.getPosition(); x++){
				K k = *map.getKeyByPosition(x);
				V v = *map.getByPosition(x);
				this->addLValues(k,v);
			}
		}
		
		HashMap(bool own){
			this->owner = own;
			this->keys = new K*[this->size];
			this->values = new V*[this->size];
		}
		
		HashMap(int msize){
			this->keys = new K*[msize];
			this->values = new V*[msize];
			this->size = msize;
		}
		
		HashMap(bool own, int msize){
			this->owner = own;
			this->keys = new K*[msize];
			this->values = new V*[msize];
			this->size = msize;
		}
		
		~HashMap(){
			if(this->owner){
				for(int x = 0; x < this->pos; x++){
					delete this->keys[x];
					delete this->values[x];
				}
			}
			delete[] this->keys;
			delete[] this->values;
		}

		virtual bool isEmpty()const{
			return this->pos==0;
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
		
		virtual void addPointers(K *key, V *value){
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(this->pos >= this->size){
				return;
			}
			this->keys[this->pos] = key;
			this->values[this->pos] = value;
			this->pos++;
		}
		
		virtual void addLValues(K key, V value){
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(this->pos >= this->size){
				return;
			}
			this->keys[this->pos] = new K();
			this->values[this->pos] = new V();
			*this->keys[this->pos] = key;
			*this->values[this->pos] = value;
			this->pos++;
		}
		
		virtual void addPointer(K key, V *value){
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(this->pos >= this->size){
				return;
			}
			this->keys[this->pos] = new K();
			*this->keys[this->pos] = key;
			this->values[this->pos] = value;
			this->pos++;
		}
		
		virtual void add(K key, V value){
			if(size < pos){
				return;
			}
			keys[pos] = new K();
			values[pos] = new V();
			*keys[pos] = key;
			*values[pos] = value;
			pos++;
		}
		
		virtual void setPointers(K *key, V *value){
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(this->pos >= this->size){
				return;
			}
			for(int x = 0; x < this->pos; x++){
				if(this->keys[x] == key){
					if(this->values[x] != value){
						if(this->owner){
							delete this->values[x];
						}
						this->values[x] = value;
					}
				}
			}
		}
		
		virtual void setLValues(K key, V value){
			if(this->pos >= this->size){
				this->expandLocal(10);
			}
			if(this->pos >= this->size){
				return;
			}
			for(int x = 0; x < this->pos; x++){
				if(*this->keys[x] == key){
					*this->values[x] = value;
				}
			}
		}
		
		virtual void setPointer(K key, V *value){
			if(this->pos >= this->size){
				this->expandLocal(10);
			}
			if(this->pos >= this->size){
				return;
			}
			for(int x = 0; x < this->pos; x++){
				if(*this->keys[x] == key){
					if(this->values[x] != value){
						if(this->owner){
							delete this->values[x];
						}
						this->values[x] = value;
					}
				}
			}
		}
		virtual void setKeyLValueByPosition(int p, K key){
			if(this->pos >= this->size){
				return;
			}
			if(this->keys[p] == nullptr){
				this->keys[p] = new K();
				*this->keys[p] = key;
			}else{
				if(*this->keys[p] == key){
					*this->keys[p] = key;
				}else{
					*this->keys[p] = key;
				}
			}
		}
		
		virtual void setKeyPointerByPosition(int p, K *key){
			if(this->pos >= this->size){
				return;
			}
			if(this->keys[p] == nullptr){
				this->keys[p] = key;
			}else{
				if(this->keys[p] == key){
					this->keys[p] = key;
				}else{
					if(this->owner){
						delete this->keys[p];
					}
					this->keys[p] = key;
				}
			}
		}
		
		virtual void setValueByPosition(int p, V value){
			if(this->pos >= this->size){
				return;
			}
			if(this->values[p] == nullptr){
				this->values[p] = new V();
				*this->values[p] = value;
			}else{
				if(*this->values[p] == value){
					*this->values[p] = value;
				}else{
					*this->values[p] = value;
				}
			}
		}
		
		virtual void setValuePointerByPosition(int p, V *value){
			if(this->pos >= this->size){
				return;
			}
			if(this->values[p] == nullptr){
				this->values[p] = value;
			}else{
				if(this->values[p] == value){
					this->values[p] = value;
				}else{
					if(this->owner){
						delete this->values[p];
					}
					this->values[p] = value;
				}
			}
		}
		
		virtual void set(K key, V value){
			if(size < pos){
				return;
			}
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					if(values[x] == nullptr){
						return;
					}
					*values[x] = value;
					return;
				}
			}
		}
		
		virtual bool containKeyByPointer(K *key){
			for(int x = 0; x < this->pos; x++){
				if(this->keys[x] == key){
					return true;
				}
			}
			return false;
		}
		
		virtual bool containKeyByLValue(K key){
			for(int x = 0; x < this->pos; x++){
				if(*this->keys[x] == key){
					return true;
				}
			}
			return false;
		}
		
		virtual bool containValueByPointer(V *value){
			for(int x = 0; x < this->pos; x++){
				if(this->values[x] == value){
					return true;
				}
			}
			return false;
		}
		
		virtual bool containValueByLValue(V value){
			for(int x = 0; x < this->pos; x++){
				if(*this->values[x] == value){
					return true;
				}
			}
			return false;
		}
		
		virtual V* getByPointer(K *key){
			for(int xk = 0; xk < this->pos; xk++){
				if(this->keys[xk] == key){
					return this->values[xk];
				}
			}
			return nullptr;
		}
		
		virtual V* getByLValue(K key){
			for(int xk = 0; xk < this->pos; xk++){
				if(*this->keys[xk] == key){
					return this->values[xk];
				}
			}
			return nullptr;
		}
		
		virtual V *getByPosition(int p) const{
			if(p >= this->size){
				return nullptr;
			}
			return this->values[p];
		}
		
		virtual K *getKeyByPosition(int p) const{
			if(p >= this->size){
				return nullptr;
			}
			return this->keys[p];
		}
		
		virtual K *getKeyByPointer(V *value){
			for(int x = 0; x < this->pos; x++){
				if(this->values[x] == value){
					return this->keys[x];
				}
			}
			return nullptr;
		}
		
		virtual K *getKeyByLValue(V value){
			for(int x = 0; x < this->pos; x++){
				if(*this->values[x] == value){
					return this->keys[x];
				}
			}
			return nullptr;
		}
		
		virtual V get(K key){
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					if(values[x] == nullptr){
						return V();
					}
					return *values[x];
				}
			}
			return V();
		}
		
		K getKey(int p){
			K key;
			for(int x=0; x < pos; x++){
				if(x == p ){
					if(keys[x] == nullptr){
						return key;
					}
					key = *keys[x];
					return key;
				}
			}
			return key;
		}
		
		virtual V getValue(int p){
			for(int x=0; x < pos; x++){
				if(x == p ){
					if(values[x] == nullptr){
						return V();
					}
					return *values[x];
				}
			}
			return V();
		}
		
		virtual void reset(){
			for(int x = 0; x < this->pos; x++){
				delete this->keys[x];
				delete this->values[x];
			}
			this->pos = 0;
		}
		
		virtual void resetDelete(){
			for(int x = 0; x < this->pos; x++){
				if(this->owner){
					delete this->keys[x];
					delete this->values[x];
				}
			}
			this->pos = 0;
		}
		
		virtual void resetDeleteKey(){
			for(int rd = 0; rd < this->pos; rd++){
				if(this->owner){
					delete this->keys[rd];
				}
			}
			this->pos = 0;
		}
		
		virtual void resetDeleteValue(){
			for(int rd = 0; rd < this->pos; rd++){
				if(this->owner){
					delete this->values[rd];
				}
			}
			this->pos = 0;
		}
		
		virtual V *removeByPointer(K *key){
			V *p = nullptr;
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
						this->keys[nv] = this->keys[x];
						this->values[nv] = this->values[x];
						nv++;
					}else{
						p=this->values[x];
					}
				}
				this->pos = nv;
			}
			return p;
		}
		
		virtual V *removeByLValue(K key){
			V *p = nullptr;
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(*this->keys[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(*this->keys[x] != key ){
						this->keys[nv] = this->keys[x];
						this->values[nv] = this->values[x];
						nv++;
					}else{
						p=this->values[x];
					}
				}
				this->pos = nv;
			}
			return p;
		}
		
		virtual V *removeByPosition(int p){
			V *v = nullptr;
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(x == p){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(x != p){
						this->keys[nv] = this->keys[x];
						this->values[nv] = this->values[x];
						nv++;
					}else{
						v=this->values[x];
					}
				}
				this->pos = nv;
			}
			return v;
		}
		
		virtual void removeDeleteByPointer(K *key){
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
						this->keys[nv] = this->keys[x];
						this->values[nv] = this->values[x];
						nv++;
					}else{
						if(this->owner){
							delete this->keys[x];
							delete this->values[x];
						}
					}
				}
				this->pos = nv;
			}
		}
		
		virtual void removeDeleteByLValue(K key){
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(*this->keys[x] == key ){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(*this->keys[x] != key ){
						this->keys[nv] = this->keys[x];
						this->values[nv] = this->values[x];
						nv++;
					}else{
						if(this->owner){
							delete this->keys[x];
							delete this->values[x];
						}
					}
				}
				this->pos = nv;
			}
		}
		
		virtual void removeDeleteByPosition(int p){
			bool is=false;
			for(int x=0; x < this->pos; x++){
				if(x == p){
					is = true;
				}
			}
			if(is){
				int nv =0;
				for(int x=0; x < this->pos; x++){
					if(x != p){
						this->keys[nv] = this->keys[x];
						this->values[nv] = this->values[x];
						nv++;
					}else{
						if(this->owner){
							delete this->keys[x];
							delete this->values[x];
						}
					}
				}
				this->pos = nv;
			}
		}
		
		V remove(K key){
			int nv =0;
			V v;
			for(int x=0; x < pos; x++){
				if(*keys[x] == key ){
					if(values[x] != nullptr){
						v = *values[x];
					}
					if(!owner){
						continue;
					}
					delete keys[x];
					if(values[x] != nullptr){
						delete values[x];
					}
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
			return v;
		}
		
		V removeIndex(int ps){
			int nv =0;
			V v;
			for(int x=0; x < pos; x++){
				if(x == ps){
					if(values[x] != nullptr){
						v = *values[x];
					}
					if(!owner){
						continue;
					}
					delete keys[x];
					if(values[x] != nullptr){
						delete values[x];
					}
				}else{
					keys[nv] = keys[x];
					values[nv] = values[x];
					nv++;
				}
			}
			pos = nv;
			return v;
		}
		
		void putPointers(K* key, V* value){
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					if(values[x] != value){
						if(owner && values[x] != nullptr){
							delete values[x];
						}
						values[x] = value;
					}
					return;
				}
			}
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(size < pos){
				return;
			}
			keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		void putLValues(K key, V value){
			for(int x=0; x < pos; x++){
				if(key == *keys[x]){
					if(values[x] == nullptr){
						values[x] = new V();
					}
					*values[x] = value;
					return;
				}
			}
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(size < pos){
				return;
			}
			this->keys[this->pos] = new K();
			this->values[this->pos] = new V();
			*keys[pos] = key;
			*values[pos] = value;
			pos++;
		}
		
		void putPointer(K key, V* value){
			for(int x=0; x < pos; x++){
				if(key == *keys[x]){
					if(values[x] != value){
						if(owner && values[x] != nullptr){
							delete values[x];
						}
						values[x] = value;
					}
					return;
				}
			}
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(size < pos){
				return;
			}
			this->keys[this->pos] = new K();
			*keys[pos] = key;
			values[pos] = value;
			pos++;
		}
		
		void put(K key, V value){
			for(int x=0; x < pos; x++){
				if(key == *keys[x]){
					if(values[x] == nullptr){
						values[x] = new V();
					}
					*values[x] = value;
					return;
				}
			}
			if(this->pos >= this->size){
				this->expandLocal(this->expandSize);
			}
			if(size < pos){
				return;
			}
			this->keys[this->pos] = new K();
			this->values[this->pos] = new V();
			*keys[pos] = key;
			*values[pos] = value;
			pos++;
		}
		
		int getKeyIndexByPointer(K* key){
			for(int x=0; x < pos; x++){
				if(key == keys[x]){
					return x;
				}
			}
			return -1;
		}
		
		int getKeyIndexByLValue(K key){
			for(int x=0; x < pos; x++){
				if(key == *keys[x]){
					return x;
				}
			}
			return -1;
		}
		
		int getIndexByPointer(V* v){
			for(int x=0; x < pos; x++){
				if(v == values[x]){
					return x;
				}
			}
			return -1;
		}
		
		int getIndexByLValue(V v){
			for(int x=0; x < pos; x++){
				if(values[x] == nullptr){
					continue;
				}
				if(v == *values[x]){
					return x;
				}
			}
			return -1;
		}
		
		//cppObject part
		virtual void onDelete(){
			if(this->owner){
				for(int x = 0; x < this->pos; x++){
					delete this->keys[x];
					delete this->values[x];
				}
				this->pos = 0;
			}
		}
		virtual cppObjectClass* getClass(){
			return Class<HashMap>::classType;
		}
		virtual String toString(){
			return "HashMap";
		}
		virtual Map<K,V>* clone(){
			Map<K,V>* cloneMap = new HashMap<K,V>(true, this->size);
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(*this->keys[cm], *this->values[cm]);
			}
			return cloneMap;
		}
		virtual Map<K,V>* clone(bool owningMemory){
			Map<K,V>* cloneMap = new HashMap<K,V>(owningMemory, this->size);
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(*this->keys[cm], *this->values[cm]);
			}
			return cloneMap;
		}
		
		//resize length by adding more space
		virtual void expandLocal(int add){
			int nsize = this->size+add;
			K **nK;
			V **nV;
			nK = new K*[nsize];
			nV = new V*[nsize];
			for(int x=0; x < this->pos; x++){
				nK[x] = this->keys[x];
				nV[x] = this->values[x];
			}
			delete[] this->keys;
			delete[] this->values;
			this->keys = nK;
			this->values = nV;
			this->size = nsize;
		}
		virtual HashMap<K,V>* expand(int add){
			int nsize = this->size+add;
			HashMap<K,V> *nprimitive = new HashMap<K,V>(nsize);	
			for(int x=0; x < this->pos; x++){
				nprimitive->addPointers(this->keys[x],this->values[x]);
			}
			return nprimitive;
		}
		
		virtual HashMap& operator=(const HashMap& map){
			this->resetDelete();
			for(int x = 0; x < map.getPosition(); x++){
				K k = *map.getKeyByPosition(x);
				V v = *map.getByPosition(x);
				this->addLValues(k,v);
			}
			return *this;
		}
		
		virtual MapIterator<K,V> getEntry(int p){
			for(int x=0; x < pos; x++){
				if(x == p ){
					return MapIterator<K,V>(this,p,pos);
				}
			}
			return MapIterator<K,V>(nullptr,0,0);
		}
		
		
	public:
		K **keys;
		V **values;
	protected:
		int pos=0;
		int size=10;
		int expandSize=5;
		bool owner = true;
};

}
#endif 
