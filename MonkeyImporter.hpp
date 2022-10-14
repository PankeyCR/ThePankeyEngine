
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MonkeyImporter)
	#define MonkeyImporter_hpp
#endif

#ifndef MonkeyImporter_hpp
#define MonkeyImporter_hpp
#define MonkeyImporter_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ElementId.hpp"
#include "ByteArray.hpp"
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
		
		// ByteArray primitive
    	virtual ByteArray read(ElementId id, ByteArray value)=0;
    	virtual LinkedList<ByteArray> read(ElementId id, LinkedList<ByteArray> value)=0;
    	virtual PrimitiveList<ByteArray> read(ElementId id, PrimitiveList<ByteArray> value)=0;
		
		// bool primitive
    	virtual bool read(ElementId id, bool value)=0;
    	virtual LinkedList<bool> read(ElementId id, LinkedList<bool> value)=0;
    	virtual PrimitiveList<bool> read(ElementId id, PrimitiveList<bool> value)=0;
		
		// char primitive
    	virtual char read(ElementId id, char value)=0;
    	virtual LinkedList<char> read(ElementId id, LinkedList<char> value)=0;
    	virtual PrimitiveList<char> read(ElementId id, PrimitiveList<char> value)=0;

		// ElementId primitive
    	virtual ElementId read(ElementId id, ElementId value)=0;
    	virtual PrimitiveList<ElementId> read(ElementId id, PrimitiveList<ElementId> value)=0;

		// Note primitive
    	virtual Note read(ElementId id, Note value)=0;
    	virtual Note read(ElementId id, char* value)=0;
    	virtual LinkedList<Note> read(ElementId id, LinkedList<Note> value)=0;
    	virtual PrimitiveList<Note> read(ElementId id, PrimitiveList<Note> value)=0;
		
		// long primitive
    	virtual long read(ElementId id, long value)=0;
    	virtual LinkedList<long> read(ElementId id, LinkedList<long> value)=0;
    	virtual PrimitiveList<long> read(ElementId id, PrimitiveList<long> value)=0;
		
		// float primitive
    	virtual float read(ElementId id, float value)=0;
    	virtual LinkedList<float> read(ElementId id, LinkedList<float> value)=0;
    	virtual PrimitiveList<float> read(ElementId id, PrimitiveList<float> value)=0;
		
		// Savable primitive
    	/*virtual LinkedList<Savable> read(ElementId id, LinkedList<Savable> value)=0;
    	virtual PrimitiveList<Savable> read(ElementId id, PrimitiveList<Savable> value)=0;
		*/
		
    	// virtual PrimitiveMap<int> read(ElementId id, PrimitiveMap<int> value)=0;
    	// virtual PrimitiveMap<bool> read(ElementId id, PrimitiveMap<bool> value)=0;
    	// virtual PrimitiveMap<bool> read(ElementId id, PrimitiveMap<bool> value)=0;
    	// virtual PrimitiveMap<char> read(ElementId id, PrimitiveMap<char> value)=0;
    	// virtual PrimitiveMap<Note> read(ElementId id, PrimitiveMap<Note> value)=0;
    	// virtual PrimitiveMap<long> read(ElementId id, PrimitiveMap<long> value)=0;
    	// virtual PrimitiveMap<float> read(ElementId id, PrimitiveMap<float> value)=0;
    	// virtual PrimitiveMap<float> read(ElementId id, PrimitiveMap<float> value)=0;
		
    	virtual PrimitiveMap<Note,bool> read(ElementId id, PrimitiveMap<Note,bool> value)=0;
    	virtual PrimitiveMap<Note,Note> read(ElementId id, PrimitiveMap<Note,Note> value)=0;
    	virtual PrimitiveMap<ElementId,Note> read(ElementId id, PrimitiveMap<ElementId,Note> value)=0;
		
		
		virtual void remove(ElementId id)=0;
		virtual void clear()=0;
		
		//////////// list ids
		virtual void addId(ElementId m_id)=0;
		virtual void addIds(PrimitiveList<ElementId>& m_ids)=0;
		
		virtual bool containId(ElementId m_id)=0;
		virtual PrimitiveList<ElementId>& getIds()=0;
		virtual ElementId getId(int x)=0;
		virtual int getIdSize()=0;
		
		virtual void removeId(ElementId id)=0;
		virtual void removeIds(PrimitiveList<ElementId>& m_ids)=0;
		virtual void removeIds()=0;
		
		virtual void writeIds()=0;
		virtual void writeId(ElementId id)=0;
		virtual void eraseId(ElementId id)=0;
		virtual void eraseIds()=0;
		
		virtual void clearIds()=0;
		
		///////////////// map id types
		virtual void addIdType(ElementId m_id, Note m_type)=0;
		virtual void addIdType(PrimitiveMap<ElementId,Note>& m_idsType)=0;
		
		virtual bool containIdType(ElementId id)=0;
		virtual PrimitiveMap<ElementId,Note>& getIdTypes()=0;
		virtual Note getIdType(ElementId id)=0;
		virtual int getIdTypeSize()=0;
		
		virtual void removeIdType(ElementId m_id)=0;
		virtual void removeIdTypes(PrimitiveMap<ElementId,Note>& m_idsType)=0;
		virtual void removeIdTypes()=0;
		
		virtual void writeIdTypes()=0;
		virtual void writeIdType(ElementId id, Note type)=0;
		virtual void eraseIdType(ElementId id)=0;
		virtual void eraseIdTypes()=0;
		
		virtual void clearIdTypes()=0;
		
		///////////////// tags
		virtual void addTag(ElementId id, Note tag)=0;
		virtual void addTag(PrimitiveMap<ElementId,Note>& m_tags)=0;
		
		virtual bool containTag(ElementId id)=0;
		virtual PrimitiveMap<ElementId,Note>& getTags()=0;
		virtual Note getTag(ElementId id)=0;
		virtual int getTagSize()=0;
		
		virtual void removeTag(ElementId id)=0;
		virtual void removeTags(PrimitiveMap<ElementId,Note>& m_tags)=0;
		virtual void removeTags()=0;
		
		virtual void writeTags()=0;
		virtual void writeTag(ElementId id, Note tag)=0;
		virtual void eraseTag(ElementId id)=0;
		virtual void eraseTags()=0;
		
		virtual void clearTags()=0;
		
		virtual void setMessage(Message* message)=0;
		virtual void read(MonkeyFile* file, Note path)=0;
		virtual void write(MonkeyFile* file, Note path)=0;
		
		virtual void fix()=0;
		
		virtual Note toNote()=0;
	protected:
};

}

#endif