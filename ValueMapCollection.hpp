
#ifndef ValueMapCollection_hpp
	#define ValueMapCollection_hpp

	#include "MapCollection.hpp"

	#ifdef ValueMapCollection_LogApp
		#include "pankey_Logger.hpp"
		#define ValueMapCollectionLog(location,method,type,mns) pankey_Log((void*)this,location,"ValueMapCollection",method,type,mns)
	#else
		#define ValueMapCollectionLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class K, class V, class H, class M>
		class ValueMapCollection : virtual public MapCollection<H,M>{
			public:

				virtual ~ValueMapCollection(){
					ValueMapCollectionLog(pankey_Log_StartMethod, "Destructor", "println", "");
					ValueMapCollectionLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

				virtual Member<H,M> getKeyByValue(const Member<H,M>& a_value)const=0;

				virtual Member<H,M> getValueByValue(const Member<H,M>& a_value)const=0;

				// virtual bool containByValue(const Member<H,M>& a_value)const=0;

				// virtual bool containKeyByValue(const Member<H,M>& a_value)const=0;

				// virtual bool containValueByValue(const Member<H,M>& a_value)const=0;
				
				// virtual int getKeyIndexByValue(const Member<H,M>& a_value)const=0;
				
				// virtual int getValueIndexByValue(const Member<H,M>& a_value)const=0;
				
				// virtual bool removeKeyByValue(const Member<H,M>& a_value)=0;
				
				// virtual bool removeValueByValue(const Member<H,M>& a_value)=0;
		};

	}

#endif