
#include "ame_Enviroment.hpp"

#if defined(DISABLE_AppSettings) || defined(DISABLE_DefaultSettings)
	#define DefaultSettings_hpp
#endif

#ifndef DefaultSettings_hpp
#define DefaultSettings_hpp
#define DefaultSettings_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PrimitiveMap.hpp"
#include "AppSettings.hpp"

namespace ame{

class DefaultSettings : public AppSettings{
    public:
		DefaultSettings(){
			intMap = new PrimitiveMap<Note,int>(2);
			floatMap = new PrimitiveMap<Note,float>(2);
			NoteMap = new PrimitiveMap<Note,Note>(2);
			boolMap = new PrimitiveMap<Note,bool>(2);
			cppObjectMap = new PrimitiveMap<Note,cppObject>(2);
		}
		virtual ~DefaultSettings(){
			delete intMap;
			delete floatMap;
			delete NoteMap;
			delete boolMap;
			delete cppObjectMap;
		}
		
		virtual void addInt(Note s, int i){
			this->intMap->addLValues(s,i);
		}
		virtual void setInt(Note s, int i){
			this->intMap->setLValues(s,i);
		}
		virtual int getInt(Note s){
			int* i = this->intMap->getByLValue(s);
			if(i == nullptr){
				return -1;
			}
			return *i;
		}
		virtual bool containInt(Note s){
			return this->intMap->containKeyByLValue(s);
		}
		
		virtual void addFloat(Note s, float i){
			this->floatMap->addLValues(s,i);
		}
		virtual void setFloat(Note s, float i){
			this->floatMap->setLValues(s,i);
		}
		virtual float getFloat(Note s){
			float* f = this->floatMap->getByLValue(s);
			if(f == nullptr){
				return -1.0f;
			}
			return *f;
		}
		virtual bool containFloat(Note s){
			return this->floatMap->containKeyByLValue(s);
		}
		
		virtual void addNote(Note s, Note i){
			this->NoteMap->addLValues(s,i);
		}
		virtual void setNote(Note s, Note i){
			this->NoteMap->setLValues(s,i);
		}
		virtual Note getNote(Note s){
			Note* st = this->NoteMap->getByLValue(s);
			if(st == nullptr){
				return "";
			}
			return *st;
		}
		virtual bool containNote(Note s){
			return this->NoteMap->containKeyByLValue(s);
		}
		
		virtual void addBoolean(Note s, bool i){
			this->boolMap->addLValues(s,i);
		}
		virtual void setBoolean(Note s, bool i){
			this->boolMap->setLValues(s,i);
		}
		virtual bool getBoolean(Note s){
			bool* b = this->boolMap->getByLValue(s);
			if(b == nullptr){
				return false;
			}
			return *b;
		}
		virtual bool containBoolean(Note s){
			return this->boolMap->containKeyByLValue(s);
		}
		
		virtual void addCppObject(Note s, cppObject *i){
			this->cppObjectMap->addPointer(s,i);
		}
		virtual void setCppObject(Note s, cppObject *i){
			this->cppObjectMap->setPointer(s,i);
		}
		virtual cppObject *getCppObject(Note s){
			return this->cppObjectMap->getByLValue(s);
		}
		virtual bool containCppObject(Note s){
			return this->cppObjectMap->containKeyByLValue(s);
		}
		
		virtual Note toNote(){
			return "DefaultSettings";
		}
		virtual cppObjectClass* getClass(){
			return ame::Class<DefaultSettings>::classType;
		}
		
	protected:
		Map<Note,int> *intMap;
		Map<Note,float> *floatMap;
		Map<Note,Note> *NoteMap;
		Map<Note,bool> *boolMap;
		Map<Note,cppObject> *cppObjectMap;
};

}

#endif 
