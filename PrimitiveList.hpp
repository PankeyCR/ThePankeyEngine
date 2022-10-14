
#ifndef PrimitiveList_hpp
#define PrimitiveList_hpp
#define PrimitiveList_AVAILABLE

#include "ame_ErrorWarning.hpp"
#include "PrimitiveRawList.hpp"
#include "ListIterator.hpp"
#include "List.hpp"
#include "Class.hpp"

#ifdef PrimitiveList_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define PrimitiveListLog(location,method,type,mns) ame_Log(this,location,"PrimitiveList",method,type,mns)
	#define const_PrimitiveListLog(location,method,type,mns)
#else
	#ifdef PrimitiveList_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define PrimitiveListLog(location,method,type,mns) ame_LogDebug(this,location,"PrimitiveList",method,type)
		#define const_PrimitiveListLog(location,method,type,mns)
	#else
		#define PrimitiveListLog(location,method,type,mns)
		#define const_PrimitiveListLog(location,method,type,mns)
	#endif
#endif

namespace ame{

template<class T>
class PrimitiveList : public PrimitiveRawList<T>, public List<T>{
	protected:
		static cppObjectClass* m_primitive_list_class;
		
	public:
		PrimitiveList(){}
		
		PrimitiveList(const PrimitiveList<T>& a_list){
			this->m_values = new T*[a_list.getSize()];
			this->m_size = a_list.getSize();
			for(int x = 0; x < a_list.getPosition(); x++){
				this->addLValue(*a_list.getByPosition(x));
			}
		}
		
		PrimitiveList(int c_size) : PrimitiveRawList<T>(c_size){}
		
		PrimitiveList(int c_size, bool c_own, int c_reordering){}
		
		virtual ~PrimitiveList(){}
		
		//cppObject part
		virtual void onDelete(){
			for(int x=0; x < this->getPosition(); x++){
				if(this->m_values[x] != nullptr && this->m_owner){
					delete this->m_values[x];
				}
				this->m_values[x] = nullptr;
			}
			this->incrementPosition();
		}
		
		virtual cppObjectClass* getClass(){
			return Class<PrimitiveList<T>>::getClass();
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<PrimitiveList<T>>::getClass();
		}

		virtual PrimitiveList<T>* clone(){
			PrimitiveList<T>* list = new PrimitiveList<T>(this->m_size);
			for(int xl = 0; xl < this->getPosition(); xl++){
				list->addLValue(*this->m_values[xl]);
			}
			return list;
		}

		virtual PrimitiveList<T>* clone(bool owningMemory){
			PrimitiveList<T>* list = new PrimitiveList<T>(this->m_size, owningMemory, this->m_reorder);
			for(int xl = 0; xl < this->getPosition(); xl++){
				list->addLValue(*this->m_values[xl]);
			}
			return list;
		}
		
	
		////////////////////////////////////////////operator part///////////////////////////////////////////////
		
		
		virtual PrimitiveList& operator=(const PrimitiveList& a_list){
			this->resetDelete();
			for(int x = 0; x < a_list.getPosition(); x++){
				this->addLValue(*a_list.getByPosition(x));
			}
			return *this;
		}
		
	protected:
};

template<class T>
cppObjectClass* PrimitiveList<T>::m_primitive_list_class = new TemplateClass<PrimitiveList<T>>();

}

#endif