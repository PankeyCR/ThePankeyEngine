
#ifndef PrimitiveMap_h
#define PrimitiveMap_h

#include "TimeElapsed.h"
#include "AbstractRead.h"
#include "LinkedList.h"
#include "cppObject.h"
#include "AppState.h"
#include "Arduino.h"
#include "GameOn.h"
#include "Map.h"

namespace ame{

template <class K,class V>
class PrimitiveMap : public Map<K,V>{	
    public:
		
		PrimitiveMap(){
			this->keys = new K*[this->size];
			this->values = new V*[this->size];
		}
		
		PrimitiveMap(bool own){
			this->owner = own;
			this->keys = new K*[this->size];
			this->values = new V*[this->size];
		}
		
		PrimitiveMap(int msize){
			this->keys = new K*[msize];
			this->values = new V*[msize];
			this->size = msize;
		}
		
		PrimitiveMap(bool own, int msize){
			this->owner = own;
			this->keys = new K*[msize];
			this->values = new V*[msize];
			this->size = msize;
		}
		
		~PrimitiveMap(){
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
			//this->keys[this->pos] = new K(key);
			this->keys[this->pos] = new K();
			*this->keys[this->pos] = key;
			this->values[this->pos] = value;
			this->pos++;
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
		
		virtual V *getByPosition(int p){
			if(p >= this->size){
				return nullptr;
			}
			return this->values[p];
		}
		
		virtual K *getKeyByPosition(int p){
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
		
		//iterator part
		virtual V getLValue(Iterator iterate){
			return *this->values[iterate.getIteration()];
		}
		virtual V *getPointer(Iterator iterate){
			return this->values[iterate.getIteration()];
		}
		virtual K getKey(Iterator iterate){
			return *this->keys[iterate.getIteration()];
		}
		virtual K *getKeyPointer(Iterator iterate){
			return this->keys[iterate.getIteration()];
		}		
		virtual int getIterationSize(){
			return this->getPosition();
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
		virtual String getClassName(){
			return "PrimitiveMap";
		}
		virtual String toString(){
			return "PrimitiveMap";
		}
		virtual Map<K,V>* clone(){
			Map<K,V>* cloneMap = new PrimitiveMap<K,V>(true, this->size);
			for(int cm = 0; cm < this->pos; cm++){
				cloneMap->addLValues(*this->keys[cm], *this->values[cm]);
			}
			return cloneMap;
		}
		virtual Map<K,V>* clone(bool owningMemory){
			Map<K,V>* cloneMap = new PrimitiveMap<K,V>(owningMemory, this->size);
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
		virtual PrimitiveMap<K,V>* expand(int add){
			int nsize = this->size+add;
			PrimitiveMap<K,V> *nprimitive = new PrimitiveMap<K,V>(nsize);	
			for(int x=0; x < this->pos; x++){
				nprimitive->addPointers(this->keys[x],this->values[x]);
			}
			return nprimitive;
		}
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
