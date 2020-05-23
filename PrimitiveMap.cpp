
#ifndef PrimitiveMap_cpp
#define PrimitiveMap_cpp

#include "PrimitiveMap.h"

	template <class K,class V>
	PrimitiveMap<K,V>::PrimitiveMap(){
		this->key = new K*[this->size];
		this->value = new V*[this->size];
		for(int x=0; x < this->size; x++){
			this->key[x] = nullptr;
			this->value[x] = nullptr;
		}
	}

	template <class K,class V>
	PrimitiveMap<K,V>::PrimitiveMap(int msize){
		this->key = new K*[msize];
		this->value = new V*[msize];
		this->size = msize;
		for(int x=0; x < this->size; x++){
			this->key[x] = nullptr;
			this->value[x] = nullptr;
		}
	}

	template <class K,class V>
	PrimitiveMap<K,V>::~PrimitiveMap(){
		iterate(this){
			delete this->getKeyPointer();
			delete this->getPointer();
		}
		delete[] this->key;
		delete[] this->value;
	}

	template <class K,class V>
	void PrimitiveMap<K,V>::setPos(int p){
		this->pos = p;
	}

	template <class K,class V>
	int PrimitiveMap<K,V>::getPos(){
		return this->pos;
	}

	template <class K,class V>
	int PrimitiveMap<K,V>::getSize(){
		return this->size;
	}

	template <class K,class V>
	void PrimitiveMap<K,V>::add(K *key, V *value){
		if(this->pos >= this->size){
			this->expandLocal(this->expandSize);
		}
		if(this->pos >= this->size){
			return;
		}
		this->key[this->pos] = key;
		this->value[this->pos] = value;
		this->pos++;
	}

	template <class K,class V>
	void PrimitiveMap<K,V>::add(K key, V value){
		if(this->pos >= this->size){
			this->expandLocal(this->expandSize);
		}
		if(this->pos >= this->size){
			return;
		}
		this->key[this->pos] = new K();
		this->value[this->pos] = new V();
		*this->key[this->pos] = key;
		*this->value[this->pos] = value;
		this->pos++;
	}

	template <class K,class V>
	void PrimitiveMap<K,V>::add(K key, V *value){
		if(this->pos >= this->size){
			this->expandLocal(this->expandSize);
		}
		if(this->pos >= this->size){
			return;
		}
		this->key[this->pos] = new K();
		*this->key[this->pos] = key;
		this->value[this->pos] = value;
		this->pos++;
	}

	template <class K,class V>
	void PrimitiveMap<K,V>::set(K *key, V *value){
		if(this->pos >= this->size){
			this->expandLocal(this->expandSize);
		}
		if(this->pos >= this->size){
			return;
		}
		iterate(this){
			if(this->getKeyPointer() == key){
				if(this->getPointer() != value){
					delete this->value[this->getIteration()];
					this->value[this->getIteration()] = value;
				}else{
					
				}
			}
		}
	}

	template <class K,class V>
	void PrimitiveMap<K,V>::set(K key, V value){
		if(this->pos >= this->size){
			this->expandLocal(10);
		}
		if(this->pos >= this->size){
			return;
		}
		iterate(this){
			if(this->getKey() == key){
				*this->value[this->getIteration()] = value;
			}
		}
	}

	template <class K,class V>
	void PrimitiveMap<K,V>::set(K key, V *value){
		if(this->pos >= this->size){
			this->expandLocal(10);
		}
		if(this->pos >= this->size){
			return;
		}
		iterate(this){
			if(this->getKey() == key){
				if(this->getPointer() != value){
					delete this->value[this->getIteration()];
					this->value[this->getIteration()] = value;
				}else{
					
				}
			}
		}
	}
		
	template <class K,class V>
	void PrimitiveMap<K,V>::setKeyByPos(int p, K key){
		if(this->pos >= this->size){
			return;
		}
		if(this->key[p] == nullptr){
			this->key[p] = new K();
			*this->key[p] = key;
		}else{
			if(*this->key[p] == key){
				*this->key[p] = key;
			}else{
				*this->key[p] = key;
			}
		}
	}
	
	template <class K,class V>
	void PrimitiveMap<K,V>::setKeyByPos(int p, K *key){
		if(this->pos >= this->size){
			return;
		}
		if(this->key[p] == nullptr){
			this->key[p] = key;
		}else{
			if(this->key[p] == key){
				this->key[p] = key;
			}else{
				delete this->key[p];
				this->key[p] = key;
			}
		}
	}
	
	template <class K,class V>
	void PrimitiveMap<K,V>::setValueByPos(int p, V value){
		if(this->pos >= this->size){
			return;
		}
		if(this->value[p] == nullptr){
			this->value[p] = new V();
			*this->value[p] = value;
		}else{
			if(*this->value[p] == value){
				*this->value[p] = value;
			}else{
				*this->value[p] = value;
			}
		}
	}
	
	template <class K,class V>
	void PrimitiveMap<K,V>::setValueByPos(int p, V *value){
		if(this->pos >= this->size){
			return;
		}
		if(this->value[p] == nullptr){
			this->value[p] = value;
		}else{
			if(this->value[p] == value){
				this->value[p] = value;
			}else{
				delete this->value[p];
				this->value[p] = value;
			}
		}
	}

	template <class K,class V>
	bool PrimitiveMap<K,V>::contain(K *key){
		iterate(this){
			if(this->getKeyPointer() == key){
				return true;
			}
		}
		return false;
	}

	template <class K,class V>
	bool PrimitiveMap<K,V>::contain(K key){
		iterate(this){
			if(this->getKey() == key){
				return true;
			}
		}
		return false;
	}

	template <class K,class V>
	bool PrimitiveMap<K,V>::containValue(V *value){
		iterate(this){
			if(this->getPointer() == value){
				return true;
			}
		}
		return false;
	}

	template <class K,class V>
	bool PrimitiveMap<K,V>::containValue(V value){
		iterate(this){
			if(this->getValue() == value){
				return true;
			}
		}
		return false;
	}

	template <class K,class V>
	V *PrimitiveMap<K,V>::get(K *key){
		iterate(this){
			if(this->getKeyPointer() == key){
				return this->getPointer();
			}
		}
		return nullptr;
	}

	template <class K,class V>
	V *PrimitiveMap<K,V>::get(K key){
		iterate(this){
			if(this->getKey() == key){
				return this->getPointer();
			}
		}
		return nullptr;
	}

	template <class K,class V>
	V *PrimitiveMap<K,V>::getByPos(int p){
		if(p >= this->size){
			return nullptr;
		}
		return this->value[p];
	}

	template <class K,class V>
	K *PrimitiveMap<K,V>::getKeyByPos(int p){
		if(p >= this->size){
			return nullptr;
		}
		return this->key[p];
	}

	template <class K,class V>
	K *PrimitiveMap<K,V>::getKey(V *value){
		iterate(this){
			if(this->getPointer() == value){
				return this->getKeyPointer();
			}
		}
		return nullptr;
	}

	template <class K,class V>
	K *PrimitiveMap<K,V>::getKey(V value){
		iterate(this){
			if(this->getValue() == value){
				return this->getKeyPointer();
			}
		}
		return nullptr;
	}

	template <class K,class V>
	void PrimitiveMap<K,V>::reset(){
		iterate(this){
			delete this->getKeyPointer();
			delete this->getPointer();
			this->key[this->getIteration()] = nullptr;
			this->value[this->getIteration()] = nullptr;
		}
		this->pos = 0;
	}

	template <class K,class V>
	void PrimitiveMap<K,V>::resetDelete(){
		iterate(this){
			delete this->getKeyPointer();
			delete this->getPointer();
			this->key[this->getIteration()] = nullptr;
			this->value[this->getIteration()] = nullptr;
		}
		this->pos = 0;
	}

	template <class K,class V>
	V *PrimitiveMap<K,V>::PrimitiveMap::remove(K *key){
		V *p = nullptr;
		bool is=false;
		for(int x=0; x < this->pos; x++){
			if(this->key[x] == key ){
				is = true;
			}
		}
		if(is){
			int nv =0;
			for(int x=0; x < this->pos; x++){
				if(this->key[x] != key ){
					this->key[nv] = this->key[x];
					this->value[nv] = this->value[x];
					nv++;
				}else{
					p=this->value[x];
				}
			}
			this->pos = nv;
		}
		return p;
	}

	template <class K,class V>
	V *PrimitiveMap<K,V>::remove(K key){
		V *p = nullptr;
		bool is=false;
		for(int x=0; x < this->pos; x++){
			if(*this->key[x] == key ){
				is = true;
			}
		}
		if(is){
			int nv =0;
			for(int x=0; x < this->pos; x++){
				if(*this->key[x] != key ){
					this->key[nv] = this->key[x];
					this->value[nv] = this->value[x];
					nv++;
				}else{
					p=this->value[x];
				}
			}
			this->pos = nv;
		}
		return p;
	}

	template <class K,class V>
	V *PrimitiveMap<K,V>::removeByPos(int p){
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
					this->key[nv] = this->key[x];
					this->value[nv] = this->value[x];
					nv++;
				}else{
					v=this->value[x];
				}
			}
			this->pos = nv;
		}
		return v;
	}

	template <class K,class V>
	void PrimitiveMap<K,V>::removeDelete(K *key){
		V *p = nullptr;
		bool is=false;
		for(int x=0; x < this->pos; x++){
			if(this->key[x] == key ){
				is = true;
			}
		}
		if(is){
			int nv =0;
			for(int x=0; x < this->pos; x++){
				if(this->key[x] != key ){
					this->key[nv] = this->key[x];
					this->value[nv] = this->value[x];
					nv++;
				}else{
					p=this->value[x];
					delete p;
				}
			}
			this->pos = nv;
		}
	}

	template <class K,class V>
	void PrimitiveMap<K,V>::removeDelete(K key){
		V *p = nullptr;
		bool is=false;
		for(int x=0; x < this->pos; x++){
			if(*this->key[x] == key ){
				is = true;
			}
		}
		if(is){
			int nv =0;
			for(int x=0; x < this->pos; x++){
				if(*this->key[x] != key ){
					this->key[nv] = this->key[x];
					this->value[nv] = this->value[x];
					nv++;
				}else{
					p=this->value[x];
					delete p;
				}
			}
			this->pos = nv;
		}
	}

	template <class K,class V>
	void PrimitiveMap<K,V>::removeDeleteByPos(int p){
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
					this->key[nv] = this->key[x];
					this->value[nv] = this->value[x];
					nv++;
				}else{
					v=this->value[x];
					delete v;
				}
			}
			this->pos = nv;
		}
	}

		
		//iterator part
	template <class K,class V>
	V PrimitiveMap<K,V>::getValue(){
		return *this->value[this->getIteration()];
	}

	template <class K,class V>
	V *PrimitiveMap<K,V>::getPointer(){
		return this->value[this->getIteration()];
	}

	template <class K,class V>
	K PrimitiveMap<K,V>::getKey(){
		return *this->key[this->getIteration()];
	}

	template <class K,class V>
	K *PrimitiveMap<K,V>::getKeyPointer(){
		return this->key[this->getIteration()];
	}

	template <class K,class V>
	int PrimitiveMap<K,V>::getIterationSize(){
		return this->getPos();
	}
		
		
		//cppObject part
	template <class K,class V>
	void PrimitiveMap<K,V>::onDelete(){
		iterate(this){
			delete this->getKeyPointer();
			delete this->getPointer();
		}
		delete[] this->key;
		delete[] this->value;
	}

	template <class K,class V>
	String PrimitiveMap<K,V>::getClassName(){
		return "PrimitiveMap";
	}

	template <class K,class V>
	String PrimitiveMap<K,V>::toString(){
		return "PrimitiveMap";
	}

	template <class K,class V>
	PrimitiveMap<K,V>* PrimitiveMap<K,V>::clone(){
		return new PrimitiveMap<K,V>(this->size);
	}

		//resize length by adding more space
	template <class K,class V>
	void PrimitiveMap<K,V>::expandLocal(int add){
		int nsize = this->size+add;
		K **nK;
		V **nV;
		nK = new K*[nsize];
		nV = new V*[nsize];
		for(int x=0; x < this->pos; x++){
			nK[x] = this->key[x];
			nV[x] = this->value[x];
		}
		delete[] this->key;
		delete[] this->value;
		this->key = nK;
		this->value = nV;
		this->size = nsize;
	}

	template <class K,class V>
	PrimitiveMap<K,V>* PrimitiveMap<K,V>::expand(int add){
		int nsize = this->size+add;
		PrimitiveMap<K,V> *nprimitive = new PrimitiveMap<K,V>(nsize);	
		for(int x=0; x < this->pos; x++){
			nprimitive->add(this->key[x],this->value[x]);
		}
		return nprimitive;
	}

	template class PrimitiveMap<String,String>;
	template class PrimitiveMap<String,int>;
	template class PrimitiveMap<String,float>;
	template class PrimitiveMap<String,double>;
	template class PrimitiveMap<String,bool>;
	template class PrimitiveMap<String,char>;
	template class PrimitiveMap<String,AbstractRead>;
	template class PrimitiveMap<String,cppObject>;
	template class PrimitiveMap<String,AppState>;
	template class PrimitiveMap<String,TimeElapsed>;
	
	template class PrimitiveMap<int,String>;
	template class PrimitiveMap<int,int>;
	template class PrimitiveMap<int,float>;
	template class PrimitiveMap<int,double>;
	template class PrimitiveMap<int,bool>;
	template class PrimitiveMap<int,char>;
	template class PrimitiveMap<int,AbstractRead>;
	template class PrimitiveMap<int,cppObject>;
	template class PrimitiveMap<int,AppState>;
	template class PrimitiveMap<int,TimeElapsed>;
	
	template class PrimitiveMap<float,String>;
	template class PrimitiveMap<float,int>;
	template class PrimitiveMap<float,float>;
	template class PrimitiveMap<float,double>;
	template class PrimitiveMap<float,bool>;
	template class PrimitiveMap<float,char>;
	template class PrimitiveMap<float,AbstractRead>;
	template class PrimitiveMap<float,cppObject>;
	template class PrimitiveMap<float,AppState>;
	template class PrimitiveMap<float,TimeElapsed>;
	
	template class PrimitiveMap<double,String>;
	template class PrimitiveMap<double,int>;
	template class PrimitiveMap<double,float>;
	template class PrimitiveMap<double,double>;
	template class PrimitiveMap<double,bool>;
	template class PrimitiveMap<double,char>;
	template class PrimitiveMap<double,AbstractRead>;
	template class PrimitiveMap<double,cppObject>;
	template class PrimitiveMap<double,AppState>;
	template class PrimitiveMap<double,TimeElapsed>;
#endif 
