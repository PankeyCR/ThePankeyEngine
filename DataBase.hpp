
#ifndef DataBase_hpp
#define DataBase_hpp
#define DataBase_AVAILABLE

#include "MonkeyFile.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"

#ifdef DataBase_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define DataBaseLog(location,method,type,mns) ame_Log((void*)this,location,"DataBase",method,type,mns)
#else
	#ifdef DataBase_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define DataBaseLog(location,method,type,mns) ame_LogDebug((void*)this,location,"DataBase",method,type)
	#else
		#define DataBaseLog(location,method,type,mns)
	#endif
#endif

namespace higgs{

template<class M, class D>
class DataBase{
    public:
		virtual ~DataBase(){}
		
		virtual void initialize(){}
		virtual void update(float tpc){}

		virtual bool put(const M& a_meta, const D& a_data)=0;
		virtual D get(const M& a_meta)=0;
		virtual bool erase(const M& a_meta)=0;
		virtual bool copy(const M& a_meta)=0;
		virtual bool cut(const M& a_meta)=0;
};

}

#endif