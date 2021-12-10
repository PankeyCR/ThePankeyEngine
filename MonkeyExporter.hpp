
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef MonkeyExporter_hpp
#define MonkeyExporter_hpp

#include "ElementId.hpp"
#include "ByteArray.hpp"
#include "UUID.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"
#include "MonkeyFile.hpp"
#include "Message.hpp"

#ifdef MonkeyExporterLogApp
	#include "Logger.hpp"
	#define MonkeyExporterLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define MonkeyExporterLog(name,method,type,mns)
#endif

namespace ame{

class MonkeyExporter{
    public:
		virtual ~MonkeyExporter(){}
		
    	virtual PrimitiveList<ElementId> read(ElementId id, PrimitiveList<ElementId> value)=0;
    	virtual PrimitiveMap<ElementId,String> read(ElementId id, PrimitiveMap<ElementId,String> value)=0;
		
		// int primitive
    	virtual bool write(ElementId id, const int& value)=0;
    	virtual bool write(ElementId id, const LinkedList<int>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveList<int>& value)=0;

		// ByteArray primitive
    	virtual bool write(ElementId id, const ByteArray& value)=0;
    	virtual bool write(ElementId id, const LinkedList<ByteArray>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveList<ByteArray>& value)=0;

		// bool primitive
    	virtual bool write(ElementId id, const bool& value)=0;
    	virtual bool write(ElementId id, const LinkedList<bool>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveList<bool>& value)=0;
		
		// char primitive
    	virtual bool write(ElementId id, const char& value)=0;
    	virtual bool write(ElementId id, const LinkedList<char>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveList<char>& value)=0;

		// ElementId primitive
    	virtual bool write(ElementId id, const ElementId& value)=0;
    	virtual bool write(ElementId id, const PrimitiveList<ElementId>& value)=0;
		
		// String primitive
    	virtual bool write(ElementId id, const String& value)=0;
    	virtual bool write(ElementId id, const char* value)=0;
    	virtual bool write(ElementId id, const LinkedList<String>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveList<String>& value)=0;
		
		// long primitive
    	virtual bool write(ElementId id, const long& value)=0;
    	virtual bool write(ElementId id, const LinkedList<long>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveList<long>& value)=0;
		
		// UUID primitive
    	virtual bool write(ElementId id, UUID value)=0;
		
		// float primitive
    	virtual bool write(ElementId id, const float& value)=0;
    	virtual bool write(ElementId id, const LinkedList<float>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveList<float>& value)=0;
		
		// Savable primitive
    	// virtual bool write(ElementId id, const LinkedList<Savable>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveList<Savable>& value)=0;
		
		// PrimitiveMap primitive
		// template<class K,class V>
    	// virtual bool write(ElementId id, Map<K,V>* value){
			
		// }
		
    	// virtual bool write(ElementId id, const PrimitiveMap<int,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,float>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveMap<String,String>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<int,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,String>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,String>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<char,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,String>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<long,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,String>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<float,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,String>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<String,int>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveMap<String,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<String,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<String,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<String,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<String,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,String>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveMap<ElementId,String>& value)=0;
		
		virtual PrimitiveList<ElementId> getIds()=0;
		virtual bool containType(ElementId id)=0;
		virtual String readType(ElementId id)=0;
		
		virtual void addIds(PrimitiveList<ElementId> m_ids)=0;
		virtual void removeIds(PrimitiveList<ElementId> m_ids)=0;
		
		virtual void writeIds(ElementId id)=0;
		virtual void removeIds(ElementId id)=0;
		virtual void removeIds()=0;
		
		virtual void addIdsType(PrimitiveMap<ElementId,String> m_idsType)=0;
		virtual void removeIdsType(PrimitiveMap<ElementId,String> m_idsType)=0;
		
		virtual void writeIdsType(ElementId id, String type)=0;
		virtual void removeIdsType(ElementId id)=0;
		virtual void removeIdsType()=0;
		
		// virtual void fix()=0;
		virtual void remove(ElementId id)=0;
		virtual void setMessage(Message* message)=0;
		virtual void read(MonkeyFile* file, String path)=0;
		virtual void write(MonkeyFile* file, String path)=0;
		virtual void clear()=0;
		
	protected:
};

}

#endif 
