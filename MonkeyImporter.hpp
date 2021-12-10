
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef MonkeyImporter_hpp
#define MonkeyImporter_hpp

#include "ElementId.hpp"
#include "ByteArray.hpp"
#include "UUID.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"
#include "MonkeyFile.hpp"
#include "Message.hpp"

#ifdef MonkeyImporterLogApp
	#include "Logger.hpp"
	#define MonkeyImporterLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define MonkeyImporterLog(name,method,type,mns)
#endif

namespace ame{

class MonkeyImporter{
    public:
		virtual ~MonkeyImporter(){}
		// int primitive
    	virtual int read(ElementId id, int value)=0;
    	virtual LinkedList<int> read(ElementId id, LinkedList<int> value)=0;
    	virtual PrimitiveList<int> read(ElementId id, PrimitiveList<int> value)=0;
    	// virtual PrimitiveMap<int> read(ElementId id, PrimitiveMap<int> value)=0;
		
		// ByteArray primitive
    	virtual ByteArray read(ElementId id, ByteArray value)=0;
    	virtual LinkedList<ByteArray> read(ElementId id, LinkedList<ByteArray> value)=0;
    	virtual PrimitiveList<ByteArray> read(ElementId id, PrimitiveList<ByteArray> value)=0;
    	// virtual PrimitiveMap<bool> read(ElementId id, PrimitiveMap<bool> value)=0;
		
		// bool primitive
    	virtual bool read(ElementId id, bool value)=0;
    	virtual LinkedList<bool> read(ElementId id, LinkedList<bool> value)=0;
    	virtual PrimitiveList<bool> read(ElementId id, PrimitiveList<bool> value)=0;
    	// virtual PrimitiveMap<bool> read(ElementId id, PrimitiveMap<bool> value)=0;
		
		// char primitive
    	virtual char read(ElementId id, char value)=0;
    	virtual LinkedList<char> read(ElementId id, LinkedList<char> value)=0;
    	virtual PrimitiveList<char> read(ElementId id, PrimitiveList<char> value)=0;
    	// virtual PrimitiveMap<char> read(ElementId id, PrimitiveMap<char> value)=0;

		// ElementId primitive
    	virtual ElementId read(ElementId id, ElementId value)=0;
    	virtual PrimitiveList<ElementId> read(ElementId id, PrimitiveList<ElementId> value)=0;

		// String primitive
    	virtual String read(ElementId id, String value)=0;
    	virtual String read(ElementId id, char* value)=0;
    	virtual LinkedList<String> read(ElementId id, LinkedList<String> value)=0;
    	virtual PrimitiveList<String> read(ElementId id, PrimitiveList<String> value)=0;
    	// virtual PrimitiveMap<String> read(ElementId id, PrimitiveMap<String> value)=0;
		
		// long primitive
    	virtual long read(ElementId id, long value)=0;
    	virtual LinkedList<long> read(ElementId id, LinkedList<long> value)=0;
    	virtual PrimitiveList<long> read(ElementId id, PrimitiveList<long> value)=0;
    	// virtual PrimitiveMap<long> read(ElementId id, PrimitiveMap<long> value)=0;
		
		// UUID primitive
    	virtual UUID read(ElementId id, UUID value)=0;
		
		// float primitive
    	virtual float read(ElementId id, float value)=0;
    	virtual LinkedList<float> read(ElementId id, LinkedList<float> value)=0;
    	virtual PrimitiveList<float> read(ElementId id, PrimitiveList<float> value)=0;
    	// virtual PrimitiveMap<float> read(ElementId id, PrimitiveMap<float> value)=0;
		
		// Savable primitive
    	/*virtual LinkedList<Savable> read(ElementId id, LinkedList<Savable> value)=0;
    	virtual PrimitiveList<Savable> read(ElementId id, PrimitiveList<Savable> value)=0;
    	// virtual PrimitiveMap<float> read(ElementId id, PrimitiveMap<float> value)=0;
		*/
		
    	virtual PrimitiveMap<String,bool> read(ElementId id, PrimitiveMap<String,bool> value)=0;
    	virtual PrimitiveMap<String,String> read(ElementId id, PrimitiveMap<String,String> value)=0;
    	virtual PrimitiveMap<ElementId,String> read(ElementId id, PrimitiveMap<ElementId,String> value)=0;
		
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
