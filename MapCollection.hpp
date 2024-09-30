
#ifndef MapCollection_hpp
	#define MapCollection_hpp

	#include "Collection.hpp"

	#ifdef MapCollection_LogApp
		#include "pankey_Logger.hpp"
		#define MapCollectionLog(location,method,type,mns) pankey_Log((void*)this,location,"MapCollection",method,type,mns)
	#else
		#define MapCollectionLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class H, class M>
		class MapCollection : virtual public Collection<H,M>{
			public:

				virtual ~MapCollection(){
					MapCollectionLog(pankey_Log_StartMethod, "Destructor", "println", "");
					MapCollectionLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

				virtual Member<H,M> getKeyByPointer(const Member<H,M>& a_value)const=0;

				virtual Member<H,M> getValueByPointer(const Member<H,M>& a_value)const=0;

				virtual Member<H,M> getKey(int x)const=0;

				virtual Member<H,M> getValue(int x)const=0;

				virtual bool containKeyByPointer(const Member<H,M>& a_value)const=0;

				virtual bool containValueByPointer(const Member<H,M>& a_value)const=0;
				
				virtual int getKeyIndexByPointer(const Member<H,M>& a_value)const=0;
				
				virtual int getValueIndexByPointer(const Member<H,M>& a_value)const=0;
				
				virtual bool removeKeyByPointer(const Member<H,M>& a_value)=0;
				
				virtual bool removeValueByPointer(const Member<H,M>& a_value)=0;
		};

	}

#endif