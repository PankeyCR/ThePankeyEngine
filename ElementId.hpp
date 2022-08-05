
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ElementId)
	#define ElementId_hpp
#endif

#ifndef ElementId_hpp
#define ElementId_hpp
#define ElementId_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "cppObject.hpp"
#include "Note.hpp"
#include "Class.hpp"

#ifdef ElementIdLogApp
	#include "Logger.hpp"
	#define ElementIdLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define ElementIdLog(name,method,type,mns)
#endif

namespace ame{


#ifdef ame_Windows
class ElementId : public cppObject{
#endif

#ifdef ame_ArduinoIDE
class ElementId : public cppObject , public Printable{
#endif
	public:
		ElementId(){
			ElementIdLog("ElementId", "Contructor 1",  "println", Note("id ") + id);
			ElementIdLog("ElementId", "Contructor 1",  "println", Note("delimiter ") + m_delimiter);
		}
		
		ElementId(const char* i){
			id = i;
			ElementIdLog("ElementId", "Contructor 2",  "println", Note("id ") + id);
			ElementIdLog("ElementId", "Contructor 2",  "println", Note("delimiter ") + m_delimiter);
		}
		
		ElementId(const Note& i){
			id = i;
			ElementIdLog("ElementId", "Contructor 3",  "println", Note("id ") + id);
			ElementIdLog("ElementId", "Contructor 3",  "println", Note("delimiter ") + m_delimiter);
		}
		
		ElementId(const char* i, const char* i2){
			id = i;
			m_delimiter = i2;
			ElementIdLog("ElementId", "Contructor 4",  "println", Note("id ") + id);
			ElementIdLog("ElementId", "Contructor 4",  "println", Note("delimiter ") + m_delimiter);
		}
		
		ElementId(const Note& i, const Note& i2){
			id = i;
			m_delimiter = i2;
			ElementIdLog("ElementId", "Contructor 5",  "println", Note("id ") + id);
			ElementIdLog("ElementId", "Contructor 5",  "println", Note("delimiter ") + m_delimiter);
		}
		
		virtual ~ElementId(){
			ElementIdLog("ElementId", "Destructor",  "println", "");
		}
		
		ElementId child(const char* childId){
			ElementIdLog("ElementId", "child",  "println", Note(childId));
			if(id == ""){
				return ElementId(childId);
			}
			return ElementId(id + m_delimiter + childId);
		}
		
		ElementId child(const Note& childId){
			ElementIdLog("ElementId", "child",  "println", Note(childId));
			if(id == ""){
				return ElementId(childId);
			}
			return ElementId(id + m_delimiter + childId);
		}

		ElementId child(const ElementId& childId) {
			ElementIdLog("ElementId", "child",  "println", childId.getId());
			if(id == ""){
				return ElementId(childId.getId());
			}
			return ElementId(id + m_delimiter + childId.getId());
		}
		
		virtual void setId(Note i){
			ElementIdLog("ElementId", "setId",  "println", i);
			id = i;
		}
		
		virtual Note getId()const{
			ElementIdLog("ElementId", "getId",  "println", id);
			return id;
		}
		
		virtual Note getPart(int x)const{
			ElementIdLog("ElementId", "getPart",  "println", "");
			Note part = "";
			int delimiter = 0;
			int delimiterSize = m_delimiter.length();
			int delimiterEqual = 0;
			bool startConcat = false;
			ElementIdLog("ElementId", "getPart",  "println", Note("id.length() ") + Note(id.length()));
			for(int i=0; i < id.length(); i++){
				char c = id.charAt(i);
				char c2 = m_delimiter.charAt(delimiterEqual);
				ElementIdLog("ElementId", "getPart",  "println", Note("iteration ") + Note(i));
				ElementIdLog("ElementId", "getPart",  "println", Note("char ") + Note(c));
				ElementIdLog("ElementId", "getPart",  "println", Note("char delimiter ") + Note(c2));
				if(c == c2){
					ElementIdLog("ElementId", "getPart",  "println", "c == c2");
					delimiterEqual++;
					if(delimiterEqual == delimiterSize){
						ElementIdLog("ElementId", "getPart",  "println", "delimiterEqual == delimiterSize");
						delimiter++;
						delimiterEqual = 0;
					}
					continue;
				}else{
					ElementIdLog("ElementId", "getPart",  "println", "else delimiterEqual = 0");
					delimiterEqual = 0;
				}
				if((x == delimiter)){
					ElementIdLog("ElementId", "getPart",  "println", "x == delimiter");
					part.concat(c);
					startConcat = true;
				}
				if((x != delimiter) && startConcat){
					return part;
				}
			}
			ElementIdLog("ElementId", "getPart",  "println", Note("Part ") + part);
			return part;
		}
		
		virtual int getSize()const{
			ElementIdLog("ElementId", "getSize",  "println", "");
			int delimiter = 1;
			int delimiterSize = m_delimiter.length();
			int delimiterEqual = 0;
			for(int i=0; i < id.length(); i++){
				char c = id.charAt(i);
				if(c == m_delimiter.charAt(delimiterEqual)){                   
					delimiterEqual++;
					if(delimiterEqual == delimiterSize){
						delimiter++;
						delimiterEqual = 0;
					}
					continue;
				}else{
					delimiterEqual = 0;
				}
			}
			return delimiter;
		}
		
		virtual bool containParent(ElementId m_parent){
			ElementIdLog("ElementId", "containParent",  "println", "");
			int sizeParent = m_parent.getSize();
			int sizeChild = getSize();
			if(sizeParent >= sizeChild){
				return false;
			}
			for(int x = 0; x < sizeParent; x++){
				if(m_parent.getPart(x) != getPart(x)){
					return false;
				}
			}
			return true;
		}
		
		virtual bool containChild(ElementId m_child){
			ElementIdLog("ElementId", "containChild",  "println", "");
			int sizeParent = getSize();
			int sizeChild = m_child.getSize();
			if(sizeParent >= sizeChild){
				return false;
			}
			for(int x = 0; x < sizeParent; x++){
				if(m_child.getPart(x) != getPart(x)){
					return false;
				}
			}
			return true;
		}
		
		virtual bool hasPart(Note s){
			ElementIdLog("ElementId", "hasPart",  "println", "");
			int sizeOriginal = getSize();
			for(int x = 0; x < sizeOriginal; x++){
				if(s == getPart(x)){
					return true;
				}
			}
			return false;
		}
		
		virtual ElementId removePart(Note s){
			ElementIdLog("ElementId", "removePart",  "println", "");
			Note newId = "";
			int sizeOriginal = getSize();
			for(int x = 0; x < sizeOriginal; x++){
				Note partE = getPart(x);
				if(s != partE){
					if(newId == ""){
						newId = partE;
						continue;
					}
					newId += Note(".") + partE;
				}
			}
			return ElementId(newId);
		}
		
		virtual ElementId remove(ElementId nid){
			ElementIdLog("ElementId", "remove",  "println", "");
			int sizeNID = nid.getSize();
			int sizeOriginal = getSize();
			if(sizeNID > sizeOriginal){
				return *this;
			}
			ElementId newId;
			int positionNID = 0;
			bool startN = false;
			for(int x = 0; x < sizeOriginal; x++){
				Note partE = getPart(x);
				Note partN = nid.getPart(positionNID);
				if(partE == partN){
					positionNID++;
					startN = true;
				}else{
					if(startN && positionNID < sizeNID){
						return *this;
					}
					newId += partE;
				}
			}
			if(newId.getSize() == sizeOriginal - sizeNID){
				return newId;
			}
			return *this;
		}
		
		virtual ElementId removeParent(){
			ElementIdLog("ElementId", "removeParent",  "println", "");
			Note newId = "";
			int sizeOriginal = getSize();
			for(int x = 1; x < sizeOriginal; x++){
				Note partE = getPart(x);
				if(newId == ""){
					newId = partE;
					continue;
				}
				newId += Note(".") + partE;
			}
			return ElementId(newId);
		}
		
		virtual ElementId changeDelimiter(Note n_delimiter){
			ElementIdLog("ElementId", "changeDelimiter",  "println", "");
			Note newId = "";
			int sizeOriginal = getSize();
			for(int x = 0; x < sizeOriginal; x++){
				Note partE = getPart(x);
				newId += m_delimiter + partE;
			}
			return ElementId(newId, n_delimiter);
		}
		
		virtual ElementId changeDelimiterLocal(Note n_delimiter){
			ElementIdLog("ElementId", "changeDelimiterLocal",  "println", "");
			Note newId = "";
			int sizeOriginal = getSize();
			for(int x = 0; x < sizeOriginal; x++){
				Note partE = getPart(x);
				if(newId == ""){
					newId = partE;
				}else{
					newId += n_delimiter + partE;
				}
			}
			id = newId;
			m_delimiter = n_delimiter;
			return ElementId(newId, n_delimiter);
		}
		
		virtual void operator=(const ElementId& b){
			ElementIdLog("ElementId", "operator=",  "println", "");
			id=b.id;
		}
		
		virtual void operator+=(const ElementId& b){
			ElementIdLog("ElementId", "operator+=",  "println", "");
			int sizeNew = b.getSize();
			for(int x = 1; x < sizeNew; x++){
				Note partE = b.getPart(x);
				if(id == ""){
					id = partE;
					continue;
				}
				id += m_delimiter + partE;
			}
		}
		
		virtual void operator+=(Note b){
			ElementIdLog("ElementId", "operator+=",  "println", "");
			if(id == ""){
				id = b;
				return;
			}
			id += m_delimiter + b;
		}
		
		virtual bool operator==(const ElementId& b){
			ElementIdLog("ElementId", "operator==",  "println", "");
			return id == b.id;
		}
		
		virtual bool operator!=(const ElementId& b){
			ElementIdLog("ElementId", "operator!=",  "println", "");
			return id != b.id;
		}
		
		virtual bool operator==(const Note& b){
			ElementIdLog("ElementId", "operator==",  "println", "");
			return id == b;
		}
		
		virtual bool operator!=(const Note& b){
			ElementIdLog("ElementId", "operator!=",  "println", "");
			return id != b;
		}
		
		virtual bool operator==(const char* b){
			ElementIdLog("ElementId", "operator==",  "println", "");
			return id == b;
		}
		
		virtual bool operator!=(const char* b){
			ElementIdLog("ElementId", "operator!=",  "println", "");
			return id != b;
		}
		
		virtual ElementId operator+(const ElementId& b){
			ElementIdLog("ElementId", "operator+",  "println", "");
			return ElementId(id + b.id);
		}
		
		virtual cppObjectClass* getClass(){
			ElementIdLog("ElementId", "getClass",  "println", "");
			return Class<ElementId>::classType;
		}
		
		virtual Note toNote(){
			ElementIdLog("ElementId", "toNote",  "println", "");
			return Note("ElementId: ") + id;
		}
		
		virtual bool equal(cppObject *b){
			ElementIdLog("ElementId", "equal",  "println", "");
			if(b == this){
				return true;
			}
			if(!b->instanceof(Class<ElementId>::classType)){
				return false;
			}
			return id == ((ElementId*)b)->id;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			ElementIdLog("ElementId", "instanceof",  "println", "");
			return cls == Class<ElementId>::classType || cppObject::instanceof(cls);
		}
	

#ifdef ame_ArduinoIDE
		size_t printTo(Print& p) const{
			ElementIdLog("ElementId", "printTo",  "println", "");
			return p.print(id);
		}
#endif 
	protected:
		Note id = "";
		Note m_delimiter = ".";
};

}

#endif