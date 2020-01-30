

#ifndef DataSet_cpp
#define DataSet_cpp

#include "DataSet.h"

	template<class T>
	DataSet<T>::DataSet(){
		
	}
	
	template<class T>
	DataSet<T>::~DataSet(){
	}
	
	template<class T>
	DataSet<T>* DataSet<T>::dimention(int dimentionPos){
		return this;
	}
	
	template<class T>
	DataSet<T>* DataSet<T>::vector(int vectorPos, int pointPos){
		
		return this;
	}
	
	template<class T>
	DataSet<T>* DataSet<T>::set(T t){
		
		return this;
	}
	
	template<class T>
	DataSet<T>* DataSet<T>::remove(){
		
		return this;
	}	
	
	template<class T>
	T DataSet<T>::getValue(){
		
	}
	
	template<class T>
	T *DataSet<T>::getPointer(){
		
	}
	
	template<class T>
	int DataSet<T>::dimentionSize(){
		return -1;
	}
	
	template<class T>
	int DataSet<T>::dimentionVectorSize(int dimentionPos){
		return -1;
	}
	
	template<class T>
	int DataSet<T>::vectorSize(int dimentionPos, int vectorPos){
		return -1;
	}
	
	template<class T>
	void DataSet<T>::setIteration(int iter){
	}
	
	template<class T>
	DataSet<T>* DataSet<T>::iterateDimention(int dimention){
		this->iteratedimention=dimention;
		return this;
	}
	
	template<class T>
	int DataSet<T>::getIterationSize(){
		return -1;
	}
	
	template<class T>
	void DataSet<T>::last(){
	}
	
	template<class T>
	void DataSet<T>::next(){
	}
	
	template<class T>
	int DataSet<T>::dimention(){
		return -1;
	}
	
	template<class T>
	int DataSet<T>::vector(int dimentionPos){
		return -1;
	}
	
	template<class T>
	String DataSet<T>::getClassName(){
		return "DataSet";
	}
	
	template<class T>
	String DataSet<T>::toString(){
		return "DataSet";
	}
	
	template<class T>
	bool DataSet<T>::equal(cppObject *b){
		if(b == this){
			return true;
		}
		if(b->getClassName() != this->getClassName()){
			return false;
		}
		((DataSet<T>*)b)->setIteration(0);
		this->setIteration(0);
		iterate(this){
			if(((DataSet<T>*)b)->getValue() != this->getValue()){
				return false;
			}
			((DataSet<T>*)b)->next();
		}
		((DataSet<T>*)b)->setIteration(0);
		this->setIteration(0);
		return true;
	}

	
	template<class T>
	DataSet<T>* DataSet<T>::clone(){
		return this;
	}

	
	template<class T>
	void DataSet<T>::operator=(DataSet<T> b){
		
	}

	
	template<class T>
	bool DataSet<T>::operator==(DataSet<T> b){
		b.setIteration(0);
		this->setIteration(0);
		iterate(this){
			if( b.getValue() != this->getValue()){
				return false;
			}
			b.next();
		}
		b.setIteration(0);
		this->setIteration(0);
		return true;
	}

	
	template<class T>
	bool DataSet<T>::operator!=(DataSet<T> b){
		b.setIteration(0);
		this->setIteration(0);
		iterate(this){
			if( b.getValue() != this->getValue()){
				return true;
			}
			b.next();
		}
		b.setIteration(0);
		this->setIteration(0);
		return false;
	}
	
	template class DataSet<long>;
	template class DataSet<char>;
	template class DataSet<float>;
	template class DataSet<double>;
	
#endif 
