
/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef CONFIGURATION_MonkeyExporter_hpp
#define CONFIGURATION_MonkeyExporter_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_MonkeyExporter)
		#define MonkeyExporter_hpp

		#define IMPLEMENTATION_MonkeyExporter
		#define IMPLEMENTING_MonkeyExporter
	#else
		#if defined(DISABLE_IMPLEMENTATION_MonkeyExporter)
			#define IMPLEMENTATION_MonkeyExporter
			#define IMPLEMENTING_MonkeyExporter
		#endif
	#endif
#endif

#ifndef MonkeyExporter_hpp
#define MonkeyExporter_hpp
#define MonkeyExporter_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_MonkeyExporter
	#define IMPLEMENTATION_MonkeyExporter IMPLEMENTATION(public MonkeyExporter)
	#define IMPLEMENTING_MonkeyExporter IMPLEMENTING(public MonkeyExporter)
#endif

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "ElementId.hpp"
#include "Note.hpp"
#include "ByteArray.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"
#include "MonkeyFile.hpp"
#include "Message.hpp"

namespace ame{

class MonkeyExporter IMPLEMENTATION_cppObject {
    public:
		virtual ~MonkeyExporter(){}
		
    	virtual PrimitiveList<ElementId> read(ElementId id, PrimitiveList<ElementId> value)=0;
    	virtual PrimitiveMap<ElementId,Note> read(ElementId id, PrimitiveMap<ElementId,Note> value)=0;
		
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
		
		// Note primitive
    	virtual bool write(ElementId id, const Note& value)=0;
    	virtual bool write(ElementId id, const char* value)=0;
    	virtual bool write(ElementId id, const LinkedList<Note>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveList<Note>& value)=0;
		
		// long primitive
    	virtual bool write(ElementId id, const long& value)=0;
    	virtual bool write(ElementId id, const LinkedList<long>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveList<long>& value)=0;
		
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
    	virtual bool write(ElementId id, const PrimitiveMap<Note,Note>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<int,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,Note>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<int,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,Note>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<bool,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<char,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,Note>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<char,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<long,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,Note>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<long,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<float,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,Note>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<float,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<Note,int>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveMap<Note,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Note,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Note,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Note,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Note,Savable>& value)=0;
		
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,int>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,bool>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,char>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,long>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,float>& value)=0;
    	// virtual bool write(ElementId id, const PrimitiveMap<Savable,Note>& value)=0;
    	virtual bool write(ElementId id, const PrimitiveMap<ElementId,Note>& value)=0;
		
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
		virtual void addType(ElementId m_id, Note m_type)=0;
		virtual void addType(PrimitiveMap<ElementId,Note>& m_idsType)=0;
		
		virtual bool containType(ElementId id)=0;
		virtual PrimitiveMap<ElementId,Note>& getTypes()=0;
		virtual Note getType(ElementId id)=0;
		virtual int getTypeSize()=0;
		
		virtual void removeType(ElementId m_id)=0;
		virtual void removeTypes(PrimitiveMap<ElementId,Note>& m_idsType)=0;
		virtual void removeTypes()=0;
		
		virtual void writeTypes()=0;
		virtual void writeType(ElementId id, Note type)=0;
		virtual void eraseType(ElementId id)=0;
		virtual void eraseTypes()=0;
		
		virtual void clearTypes()=0;
		
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
		
	protected:
};

}

#endif