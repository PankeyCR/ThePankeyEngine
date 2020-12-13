
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

template <class K,class V>
class PrimitiveMap : public Map<K,V>{	
    public:
		
		PrimitiveMap(){
			this->keys = new K*[this->size];
			this->values = new V*[this->size];
			for(int x=0; x < this->size; x++){
				this->keys[x] = nullptr;
				this->values[x] = nullptr;
			}
		}
		
		PrimitiveMap(bool own){
			this->owner = own;
			this->keys = new K*[this->size];
			this->values = new V*[this->size];
			for(int x=0; x < this->size; x++){
				this->keys[x] = nullptr;
				this->values[x] = nullptr;
			}
		}
		
		PrimitiveMap(int msize){
			this->keys = new K*[msize];
			this->values = new V*[msize];
			this->size = msize;
			for(int x=0; x < this->size; x++){
				this->keys[x] = nullptr;
				this->values[x] = nullptr;
			}
		}
		
		~PrimitiveMap(){
			if(this->owner){
				iterate(this){
					delete this->getKeyPointer();
					delete this->getPointer();
				}
			}
			delete[] this->keys;
			delete[] this->values;
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
		
		virtual void add(K *key, V *value){
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
		
		virtual void add(K key, V value){
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
		
		virtual void add(K key, V *value){
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
		
		virtual void set(K *key, V *value){
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
		
		virtual void set(K key, V value){
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
		
		virtual void set(K key, V *value){
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
		virtual void setKeyByPos(int p, K key){
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
		
		virtual void setKeyByPos(int p, K *key){
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
		
		virtual void setValueByPos(int p, V value){
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
		
		virtual void setValueByPos(int p, V *value){
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
		
		virtual bool contain(K *key){
			iterate(this){
				if(this->getKeyPointer() == key){
					return true;
				}
			}
			return false;
		}
		
		virtual bool contain(K key){
			iterate(this){
				if(this->getKey() == key){
					return true;
				}
			}
			return false;
		}
		
		virtual bool containValue(V *value){
			iterate(this){
				if(this->getPointer() == value){
					return true;
				}
			}
			return false;
		}
		
		virtual bool containValue(V value){
			iterate(this){
				if(this->getValue() == value){
					return true;
				}
			}
			return false;
		}
		
		virtual V* get(K *key){
			for(int xk = 0; xk < this->getPos(); xk++){
				if(this->keys[xk] == key){
					return this->values[xk];
				}
			}
			return nullptr;
		}
		
		virtual V* get(K key){
			for(int xk = 0; xk < this->pos; xk++){
				if(*this->keys[xk] == key){
					return this->values[xk];
				}
			}
			return nullptr;
		}
		
		virtual V *getByPos(int p){
			if(p >= this->size){
				return nullptr;
			}
			return this->values[p];
		}
		
		virtual K *getKeyByPos(int p){
			if(p >= this->size){
				return nullptr;
			}
			return this->keys[p];
		}
		
		virtual K *getKey(V *value){
			iterate(this){
				if(this->getPointer() == value){
					return this->getKeyPointer();
				}
			}
			return nullptr;
		}
		
		virtual K *getKey(V value){
			iterate(this){
				if(this->getValue() == value){
					return this->getKeyPointer();
				}
			}
			return nullptr;
		}
		
		virtual void reset(){
			iterate(this){
				delete this->getKeyPointer();
				delete this->getPointer();
				this->keys[this->getIteration()] = nullptr;
				this->values[this->getIteration()] = nullptr;
			}
			this->pos = 0;
		}
		
		virtual void resetDelete(){
			for(int rd = 0; rd < this->pos; rd++){
				if(this->owner){
					if(this->keys[rd] == nullptr){
						delete this->keys[rd];
						this->keys[rd] = nullptr;
					}
					if(this->values[rd] == nullptr){
						delete this->values[rd];
						this->values[rd] = nullptr;
					}
				}
			}
			this->pos = 0;
		}
		
		virtual V *remove(K *key){
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
		
		virtual V *remove(K key){
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
		
		virtual V *removeByPos(int p){
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
		
		virtual void removeDelete(K *key){
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
		
		virtual void removeDelete(K key){
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
		
		virtual void removeDeleteByPos(int p){
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
		virtual V getValue(){
			return *this->values[this->getIteration()];
		}
		virtual V *getPointer(){
			return this->values[this->getIteration()];
		}
		virtual K getKey(){
			return *this->keys[this->getIteration()];
		}
		virtual K *getKeyPointer(){
			return this->keys[this->getIteration()];
		}		
		virtual int getIterationSize(){
			return this->getPos();
		}
		
		
		//cppObject part
		virtual void onDelete(){
			if(this->owner){
				iterate(this){
					delete this->getKeyPointer();
					delete this->getPointer();
				}
			}
		}
		virtual String getClassName(){
			return "PrimitiveMap";
		}
		virtual String toString(){
			return "PrimitiveMap";
		}
		virtual Map<K,V>* clone(){
			Map<K,V>* cloneMap = new PrimitiveMap<K,V>(this->size);
			
			for(int cm = 0; cm < pos; cm++){
				cloneMap->add(*this->keys[cm], *this->values[cm]);
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
				nprimitive->add(this->keys[x],this->values[x]);
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
#endif 
