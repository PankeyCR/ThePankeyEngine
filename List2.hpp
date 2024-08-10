
#ifndef List_hpp
#define List_hpp
#define List_AVAILABLE

#include "cppObject.hpp"
#include "RawList.hpp"
#include "AbstractClass.hpp"

#ifdef List_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define ListLog(location,method,type,mns) ame_Log(this,location,"List",method,type,mns)
	#define const_ListLog(location,method,type,mns)
#else
	#ifdef List_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define ListLog(location,method,type,mns) ame_LogDebug(this,location,"List",method,type)
		#define const_ListLog(location,method,type,mns)
	#else
		#define ListLog(location,method,type,mns)
		#define const_ListLog(location,method,type,mns)
	#endif
#endif

namespace ame{

#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(AbstractClass_AVAILABLE)
template<class T>
T* CastList(cppObject* obj){
	if(obj == nullptr){
		return nullptr;
	}
	if(obj->instanceof(AbstractClass<T>::getClass())){
		return (T*)obj;
	}
	return nullptr;
}
#endif

/*
*	Class Configuration:
*	DISABLE_IMPLEMENTING_cppObject
*/
template <class T>
class List : virtual public RawList<T> IMPLEMENTING_cppObject {	
	public:
	virtual ~List(){}
	//cppObject part
	
	#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(AbstractClass_AVAILABLE)
	virtual cppObjectClass* getClass(){return AbstractClass<List<T>>::getClass();}
	virtual bool instanceof(cppObjectClass* cls){
		return cls == AbstractClass<List<T>>::getClass();
	}
		
	virtual bool copy(cppObject* obj){
		List<T>* i_list = CastList<List<T>>(obj);
		if(i_list == nullptr){
			return false;
		}
		this->resetDelete();
		for(int x = 0; x < i_list->getPosition(); x++){
			T* i_value = i_list->getByPosition(x);
			if(i_value == nullptr){
				this->addPointer(nullptr);
			}else{
				this->addLValue(*i_value);
			}
		}
		return true;
	}
	virtual bool move(cppObject* obj){
		List<T>* i_list = CastList<List<T>>(obj);
		if(i_list == nullptr){
			return false;
		}
		this->resetDelete();
		for(int x = 0; x < i_list->getPosition(); x++){
			T* i_value = i_list->getByPosition(x);
			this->addPointer(i_value);
		}
		i_list->reset();
		this->setOwner(i_list->isOwner());
		return true;
	}
	virtual bool duplicate(cppObject* obj){
		List<T>* i_list = CastList<List<T>>(obj);
		if(i_list == nullptr){
			return false;
		}
		this->resetDelete();
		for(int x = 0; x < i_list->getPosition(); x++){
			T* i_value = i_list->getByPosition(x);
			this->addPointer(i_value);
		}
		if(i_list->isOwner()){
			this->setOwner(false);
		}
		return true;
	}

	virtual bool equal(cppObject* obj){
		List<T>* i_list = CastList<List<T>>(obj);
		if(i_list == nullptr){
			return false;
		}
		for(int x = 0; x < i_list->getPosition(); x++){
			T* i_value = i_list->getByPosition(x);
			T* i_value_t = this->getByPosition(x);
			if(i_value_t != i_value){
				return false;
			}
		}
		return true;
	}

	virtual cppObject* clone(){
		return clone(true);
	}
	virtual cppObject* clone(bool owningMemory){
		cppObjectClass* i_class = this->getClass();
		if(i_class == nullptr){
			return nullptr;
		}
		cppObject* i_obj = i_class->newInstance();
		if(i_obj == nullptr){
			return nullptr;
		}
		
		if(!i_obj->instanceof(AbstractClass<List<T>>::getClass())){
			delete i_obj;
			return nullptr;
		}
		List<T>* i_list = (List<T>*)i_obj;
		i_list->copy(this);
		return i_list;
	}

	virtual cppObject* move(){
		cppObjectClass* i_class = this->getClass();
		if(i_class == nullptr){
			return nullptr;
		}
		cppObject* i_obj = i_class->newInstance();
		if(i_obj == nullptr){
			return nullptr;
		}
		
		if(!i_obj->instanceof(AbstractClass<List<T>>::getClass())){
			delete i_obj;
			return nullptr;
		}
		List<T>* i_list = (List<T>*)i_obj;
		i_list->move(this);
		return i_list;
	}
	virtual cppObject* duplicate(){
		cppObjectClass* i_class = this->getClass();
		if(i_class == nullptr){
			return nullptr;
		}
		cppObject* i_obj = i_class->newInstance();
		if(i_obj == nullptr){
			return nullptr;
		}
		
		if(!i_obj->instanceof(AbstractClass<List<T>>::getClass())){
			delete i_obj;
			return nullptr;
		}
		List<T>* i_list = (List<T>*)i_obj;
		i_list->duplicate(this);
		return i_list;
	}
	#endif
	
	private:
};

}

#endif