#ifndef PrimitiveList_cpp
#define PrimitiveList_cpp

#include "PrimitiveList.h"

	template<class T>
	PrimitiveList<T>::PrimitiveList(){
		this->value = new T*[this->size];
		for(int x=0; x < this->size; x++){
			this->value[x] = nullptr;
		}
	}
	
	template<class T>
	PrimitiveList<T>::PrimitiveList(int lsize){
		this->value = new T*[lsize];
		this->size = lsize;
		for(int x=0; x < this->size; x++){
			this->value[x] = nullptr;
		}
	}
	
	template<class T>
	PrimitiveList<T>::~PrimitiveList(){
		iterate(this){
			delete this->getPointer();
		}
		delete[] this->value;
	}
	
	template<class T>
	void PrimitiveList<T>::setPos(int p){
		this->pos = p;
	}
	
	template<class T>
	int PrimitiveList<T>::getPos(){
		return this->pos;
	}
	
	template<class T>
	int PrimitiveList<T>::getSize(){
		return this->size;
	}
	
	template<class T>
	void PrimitiveList<T>::add(List<T> *list){
		iterate(list){
			this->add(list->getValue());
		}
	}
	
	template<class T>
	void PrimitiveList<T>::add(T *value){
		if(this->pos >= this->size){
			this->expandLocal(this->expandSize);
		}
		if(this->pos >= this->size){
			return;
		}
		this->value[this->pos] = value;
		this->pos++;
	}
	
	template<class T>
	void PrimitiveList<T>::add(T value){
		if(this->pos >= this->size){
			this->expandLocal(this->expandSize);
		}
		if(this->pos >= this->size){
			return;
		}
		//if(this->value[this->pos] == NULL){
		//	this->value[this->pos] = new T();
		//}
		this->value[this->pos] = new T();
		*this->value[this->pos] = value;
		this->pos++;
	}
	
	template<class T>
	void PrimitiveList<T>::set(int position,T *value){
		if(position >= this->size){
			return;			
		}
		this->value[position] = value;
	}
	
	template<class T>
	void PrimitiveList<T>::set(int position,T value){
		if(position >= this->size){
			return;			
		}
		*this->value[position] = value;
	}
	
	template<class T>
	bool PrimitiveList<T>::contain(T *key){
		iterate(this){
			if(key == this->getPointer()){
				return true;
			}
		}
		return false;
	}
	
	template<class T>
	bool PrimitiveList<T>::contain(T key){
		iterate(this){
			if(key == this->getValue()){
				return true;
			}
		}
		return false;
	}
	
	template<class T>
	T *PrimitiveList<T>::get(T *key){
		iterate(this){
			if(key == this->getPointer()){
				return this->getPointer();
			}
		}
		return NULL;
	}
	
	template<class T>
	T *PrimitiveList<T>::get(T key){
		iterate(this){
			if(key == this->getValue()){
				return this->getPointer();
			}
		}
		return NULL;
	}
	
	template<class T>
	T *PrimitiveList<T>::getByPos(int key){
		if(key < this->pos){
			return this->value[key];
		}
		return NULL;
	}
	
	template<class T>
	void PrimitiveList<T>::reset(){
		this->pos = 0;
	}
	
	template<class T>
	void PrimitiveList<T>::resetDelete(){
		this->pos = 0;
		this->onDelete();
	}
	//////////////////////////////////////////////////////////////////////////////////
	template<class T>
	T *PrimitiveList<T>::remove(T *key){
		T *t = NULL;
		bool is=false;
		iterate(this){
			if(key == this->getPointer()){
				is = true;
			}
		}
		if(is){
			int nv =0;
			iterate(this){
				if(key != this->getPointer()){
					value[nv] = value[this->getIteration()];
					nv++;
				}else{
					t = value[this->getIteration()];
				}
			}
			pos = nv;
			return t;
		}
		return NULL;
	}
	
	template<class T>
	T *PrimitiveList<T>::remove(T key){
		T *t = NULL;
		bool is=false;
		iterate(this){
			if(key == this->getValue()){
				is = true;
			}
		}
		if(is){
			int nv =0;
			iterate(this){
				if(key != this->getValue()){
					value[nv] = value[this->getIteration()];
					nv++;
				}else{
					t = value[this->getIteration()];
				}
			}
			pos = nv;
			return t;
		}
		return NULL;
	}
	
	template<class T>
	T *PrimitiveList<T>::removeByPos(int p){
		if(p >= size){
			return NULL;
		}
		T *t = NULL;
		int nv =0;
		iterate(this){
			if(p != this->getIteration()){
				value[nv] = value[this->getIteration()];
				nv++;
			}else{
				t = value[this->getIteration()];
			}
		}
		pos = nv;
		return t;
	}
	
	template<class T>
	void PrimitiveList<T>::removeDelete(T *key){
		T* t = this->remove(key);
		if(t != NULL){
			delete t;
		}
	}
	
	template<class T>
	void PrimitiveList<T>::removeDelete(T key){
		T* t = this->remove(key);
		if(t != NULL){
			delete t;
		}
	}
	
	template<class T>
	void PrimitiveList<T>::removeDeleteByPos(int p){
		T* t = this->removeByPos(p);
		if(t != NULL){
			delete t;
		}
	}
	
	template<class T>
	T PrimitiveList<T>::getValue(){
		return *this->getByPos(this->getIteration());
	}
	
	template<class T>
	T *PrimitiveList<T>::getPointer(){
		return this->getByPos(this->getIteration());
	}
		
	template<class T>
	int PrimitiveList<T>::getIterationSize(){
		return this->pos;
	}
	
	template<class T>
	String PrimitiveList<T>::getClassName(){
		return "PrimitiveList";
	}
	
	template<class T>
	String PrimitiveList<T>::toString(){
		return "PrimitiveList";
	}
	
	template<class T>
	PrimitiveList<T> *PrimitiveList<T>::clone(){
		return new PrimitiveList<T>(this->size);
	}
	
	template<class T>
	void PrimitiveList<T>::onDelete(){
		iterate(this){
			delete this->getPointer();
		}
		delete[] this->value;
	}
	
	template<class T>
	void PrimitiveList<T>::expandLocal(int add){
		int nsize = this->size+add;
		T **nT;
		nT = new T*[nsize];
		for(int x=0; x < this->pos; x++){
			nT[x] = this->value[x];
		}
		delete[] this->value;
		this->value = nT;
		this->size = nsize;
	}
	
	template<class T>
	PrimitiveList<T>* PrimitiveList<T>::expand(int add){
		int nsize = this->size+add;
		PrimitiveList<T> *nprimitive = new PrimitiveList<T>(nsize);	
		for(int x=0; x < this->pos; x++){
			nprimitive->add(this->value[x]);
		}
		return nprimitive;
	}

	//////////////////////////////////////////////////////////////////
	
	template class PrimitiveList<float>;
	template class PrimitiveList<int>;
	template class PrimitiveList<double>;
	template class PrimitiveList<bool>;
	template class PrimitiveList<String>;
	template class PrimitiveList<TimeElapsed>;
	template class PrimitiveList<AbstractRead>;
	template class PrimitiveList<cppObject>;
	template class PrimitiveList<AppState>;
	template class PrimitiveList<GameOn>;
	template class PrimitiveList<Neuron<float,float,float>>;
	
#endif