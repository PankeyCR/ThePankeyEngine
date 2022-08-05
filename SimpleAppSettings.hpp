
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SimpleAppSettings)
	#define SimpleAppSettings_hpp
#endif

#ifndef SimpleAppSettings_hpp
#define SimpleAppSettings_hpp
#define SimpleAppSettings_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "KVMap.hpp"
#include "KPMap.hpp"
#include "AppSettings.hpp"

namespace ame{

template <int size>
class SimpleAppSettings : public AppSettings{
    public:
		SimpleAppSettings(){
			intMap = new KVMap<Note,int,size>();
			floatMap = new KVMap<Note,float,size>();
			NoteMap = new KVMap<Note,Note,size>();
			booleanMap = new KVMap<Note,bool,size>();
			cppObjectMap = new KPMap<Note,cppObject,size>(true);
		}
		~SimpleAppSettings(){
			delete intMap;
			delete floatMap;
			delete NoteMap;
			delete booleanMap;
			delete cppObjectMap;
		}
		Note toNote(){
			return "SimpleAppSettings";
		}
		cppObjectClass* getClass(){
			return Class<SimpleAppSettings>::classType;
		}
		SimpleAppSettings *clone(){
			return new SimpleAppSettings();
		}
		void onDelete(){
			intMap->onDelete();
			floatMap->onDelete();
			NoteMap->onDelete();
			booleanMap->onDelete();
		}
		void addInt(Note s, int i){
			intMap->addLValues(s,i);
		}
		void setInt(Note s, int i){
			intMap->setLValues(s,i);
		}
		int getInt(Note s){
			return *intMap->getByLValue(s);
		}
		boolean containInt(Note s){
			return intMap->containKeyByLValue(s);
		}
		void addFloat(Note s, float i){
			floatMap->addLValues(s,i);
		}
		void setFloat(Note s, float i){
			floatMap->setLValues(s,i);
		}
		float getFloat(Note s){
			return *floatMap->getByLValue(s);
		}
		boolean containFloat(Note s){
			return floatMap->containKeyByLValue(s);
		}
		void addNote(Note s, Note i){
			NoteMap->addLValues(s,i);
		}
		void setNote(Note s, Note i){
			NoteMap->setLValues(s,i);
		}
		boolean containNote(Note s){
			return NoteMap->containKeyByLValue(s);
		}
		Note getNote(Note s){
			return *NoteMap->getByLValue(s);
		}
		void addBoolean(Note s, bool i){
			booleanMap->addLValues(s,i);
		}
		void setBoolean(Note s, bool i){
			booleanMap->setLValues(s,i);
		}
		bool getBoolean(Note s){
			return *booleanMap->getByLValue(s);
		}
		bool containBoolean(Note s){
			return booleanMap->containKeyByLValue(s);
		}
		void addCppObject(Note s, cppObject *i){
			cppObjectMap->addPointer(s,i);
		}
		void setCppObject(Note s, cppObject *i){
			cppObjectMap->setPointer(s,i);
		}
		cppObject *getCppObject(Note s){
			return cppObjectMap->getByLValue(s);
		}
		bool containCppObject(Note s){
			return cppObjectMap->containKeyByLValue(s);
		}
	protected:
		Map<Note,int> *intMap;
		Map<Note,float> *floatMap;
		Map<Note,Note> *NoteMap;
		Map<Note,bool> *booleanMap;
		Map<Note,cppObject> *cppObjectMap;
};

}

#endif