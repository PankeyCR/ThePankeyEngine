
#include "ame_Level.hpp"

#if defined(ame_untilLevel_1)

#ifndef ElementId_hpp
#define ElementId_hpp

#include "Arduino.h"
#include "cppObject.hpp"
#include "Printable.h"

#ifdef ElementIdLogApp
	#include "Logger.hpp"
	#define ElementIdLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define ElementIdLog(name,method,type,mns)
#endif

namespace ame{

class ElementId : public cppObject , public Printable{
	public:
		ElementId(){
			ElementIdLog("ElementId", "Contructor 1",  "println", String("id ") + id);
			ElementIdLog("ElementId", "Contructor 1",  "println", String("delimiter ") + m_delimiter);
		}
		
		ElementId(const char* i){
			id = i;
			ElementIdLog("ElementId", "Contructor 2",  "println", String("id ") + id);
			ElementIdLog("ElementId", "Contructor 2",  "println", String("delimiter ") + m_delimiter);
		}
		
		ElementId(const String& i){
			id = i;
			ElementIdLog("ElementId", "Contructor 3",  "println", String("id ") + id);
			ElementIdLog("ElementId", "Contructor 3",  "println", String("delimiter ") + m_delimiter);
		}
		
		ElementId(const char* i, const char* i2){
			id = i;
			m_delimiter = i2;
			ElementIdLog("ElementId", "Contructor 4",  "println", String("id ") + id);
			ElementIdLog("ElementId", "Contructor 4",  "println", String("delimiter ") + m_delimiter);
		}
		
		ElementId(const String& i, const String& i2){
			id = i;
			m_delimiter = i2;
			ElementIdLog("ElementId", "Contructor 5",  "println", String("id ") + id);
			ElementIdLog("ElementId", "Contructor 5",  "println", String("delimiter ") + m_delimiter);
		}
		
		virtual ~ElementId(){
			ElementIdLog("ElementId", "Destructor",  "println", "");
		}
		
		ElementId child(const char* childId){
			ElementIdLog("ElementId", "child",  "println", String(childId));
			if(id == ""){
				return ElementId(childId);
			}
			return ElementId(id + m_delimiter + childId);
		}
		
		ElementId child(const String& childId){
			ElementIdLog("ElementId", "child",  "println", String(childId));
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
		
		virtual void setId(String i){
			ElementIdLog("ElementId", "setId",  "println", i);
			id = i;
		}
		
		virtual String getId()const{
			ElementIdLog("ElementId", "getId",  "println", id);
			return id;
		}
		
		virtual String getPart(int x)const{
			ElementIdLog("ElementId", "getPart",  "println", "");
			String part = "";
			int delimiter = 0;
			int delimiterSize = m_delimiter.length();
			int delimiterEqual = 0;
			bool startConcat = false;
			ElementIdLog("ElementId", "getPart",  "println", String("id.length() ") + String(id.length()));
			for(int i=0; i < id.length(); i++){
				char c = id.charAt(i);
				char c2 = m_delimiter.charAt(delimiterEqual);
				ElementIdLog("ElementId", "getPart",  "println", String("iteration ") + String(i));
				ElementIdLog("ElementId", "getPart",  "println", String("char ") + String(c));
				ElementIdLog("ElementId", "getPart",  "println", String("char delimiter ") + String(c2));
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
			ElementIdLog("ElementId", "getPart",  "println", String("Part ") + part);
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
		
		virtual bool hasPart(String s){
			ElementIdLog("ElementId", "hasPart",  "println", "");
			int sizeOriginal = getSize();
			for(int x = 0; x < sizeOriginal; x++){
				if(s == getPart(x)){
					return true;
				}
			}
			return false;
		}
		
		virtual ElementId removePart(String s){
			ElementIdLog("ElementId", "removePart",  "println", "");
			String newId = "";
			int sizeOriginal = getSize();
			for(int x = 0; x < sizeOriginal; x++){
				String partE = getPart(x);
				if(s != partE){
					if(newId == ""){
						newId = partE;
						continue;
					}
					newId += String(".") + partE;
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
				String partE = getPart(x);
				String partN = nid.getPart(positionNID);
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
			String newId = "";
			int sizeOriginal = getSize();
			for(int x = 1; x < sizeOriginal; x++){
				String partE = getPart(x);
				if(newId == ""){
					newId = partE;
					continue;
				}
				newId += String(".") + partE;
			}
			return ElementId(newId);
		}
		
		virtual ElementId changeDelimiter(String n_delimiter){
			ElementIdLog("ElementId", "changeDelimiter",  "println", "");
			String newId = "";
			int sizeOriginal = getSize();
			for(int x = 0; x < sizeOriginal; x++){
				String partE = getPart(x);
				newId += m_delimiter + partE;
			}
			return ElementId(newId, n_delimiter);
		}
		
		virtual ElementId changeDelimiterLocal(String n_delimiter){
			ElementIdLog("ElementId", "changeDelimiterLocal",  "println", "");
			String newId = "";
			int sizeOriginal = getSize();
			for(int x = 0; x < sizeOriginal; x++){
				String partE = getPart(x);
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
				String partE = b.getPart(x);
				if(id == ""){
					id = partE;
					continue;
				}
				id += m_delimiter + partE;
			}
		}
		
		virtual void operator+=(String b){
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
		
		virtual bool operator==(const String& b){
			ElementIdLog("ElementId", "operator==",  "println", "");
			return id == b;
		}
		
		virtual bool operator!=(const String& b){
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
		
		virtual String toString(){
			ElementIdLog("ElementId", "toString",  "println", "");
			return String("ElementId: ") + id;
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
	
		size_t printTo(Print& p) const{
			ElementIdLog("ElementId", "printTo",  "println", "");
			return p.print(id);
		}
	protected:
		String id = "";
		String m_delimiter = ".";
};

}

#endif 

#endif 
