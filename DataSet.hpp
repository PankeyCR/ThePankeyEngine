/*
 *
 *
 *
 *
 */

#include "ame_Enviroment.hpp"

#if defined(DISABLE_DataSet)
	#define DataSet_hpp
#endif

#ifndef DataSet_hpp
#define DataSet_hpp
#define DataSet_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows
	#include "Printable.hpp"
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "cppObjectClass.hpp"
#include "Class.hpp"
#include "LinkedList.hpp"

namespace ame{
	
template <class T>
class DataSet : public LinkedList<DataSet<T>>{
public:
	DataSet(){}
	DataSet(const DataSet<T>& c_dataset){}
	DataSet(const T& c_data){
		this->set(c_data);
	}
	template<class... args>
	DataSet<T>(args... x){
		this->addPack(x...);
	}
	virtual ~DataSet(){}

	virtual size_t printTo(Print& a_print) const{
		size_t i_size = 0;
		if(this->m_value != nullptr){
			i_size += a_print.print(*this->m_value);
		}
		for(int x = 0; x < this->getPosition(); x++){
			if(x == 0){
				i_size += a_print.print(init_array);
			}
			DataSet<T>* i_dset = this->getByPosition(x);
			if(i_dset == nullptr){
				if(x == this->getPosition() - 1){
					i_size += a_print.print(end_array);
				}
				continue;
			}
			i_size += i_dset->printTo(a_print);
			if(x == this->getPosition() - 1){
				i_size += a_print.print(end_array);
				break;
			}
			i_size += a_print.print(separator_array);
		}
		return i_size;
	}
	
	virtual void setData(T* a_value){
		m_value = a_value;
	}
	
	virtual T* getData(){
		return m_value;
	}
	
	virtual void set(const T& a_value){
		if(m_value == nullptr){
			m_value = new T();
		}
		*m_value = a_value;
	}
	
	virtual T get(){
		if(m_value == nullptr){
			return T();
		}
		return *m_value;
	}

	//cppObject part
	virtual bool instanceof(cppObjectClass* cls){
		return LinkedList<DataSet<T>>::instanceof(cls) || 
				cls == Class<DataSet<T>>::getClass();
	}
	virtual cppObjectClass* getClass(){return Class<DataSet<T>>::classType;}
	
	virtual bool equal(cppObject *b){
		if(b == this){
			return true;
		}
		if(!b->instanceof(Class<DataSet<T>>::classType)){
			return false;
		}
		return true;
	}
		
	virtual DataSet<T>* clone(){
		return new DataSet<T>();
	}
protected:
	T* m_value = nullptr;
	char init_array = '{';
	char end_array = '}';
	char separator_array = ',';
};

}

#endif