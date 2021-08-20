#ifndef ElementId_h
#define ElementId_h

#include "Arduino.h"
#include "PrimitiveList.h"
#include "List.h"
#include "cppObject.h"
#include "Printable.h"

namespace ame{

class ElementId : public cppObject , public Printable{
	public:
		ElementId(){}
		ElementId(const char* i){
			id=i;
			parts = new PrimitiveList<String>();
			for(int x = 0; x < getSize(); x++){
				parts->add(getPart(x));
			}
		}
		ElementId(const String& i){
			id=i;
			parts = new PrimitiveList<String>();
			for(int x = 0; x < getSize(); x++){
				parts->add(getPart(x));
			}
		}
		virtual ~ElementId(){
			if(parts != nullptr){
				delete parts;
			}
		}
		
		ElementId child(const char* childId){
			return ElementId(id + "." + childId);
		}
		
		ElementId child(const String& childId){
			return ElementId(id + "." + childId);
		}

		ElementId child(const ElementId& childId) {
			return ElementId(id + "." + childId.getId());
		}
		
		virtual void setId(String i){id=i;}
		virtual String getId()const{return id;}
		
		virtual String getPart(int x)const{
			String part="";     
			int delimiter=0;
			int respuesta_len = id.length() + 1; 
			char respuesta_array[respuesta_len];
			id.toCharArray(respuesta_array, respuesta_len);
			for(int i=0; i < respuesta_len; i++){
				if(respuesta_array[i] == '.'){                   
					delimiter++;  
				}
				if((x == delimiter) && (respuesta_array[i] != '.')){
					part.concat(id.charAt(i));
				}
			}
			return part;
		}
		virtual int getSize()const{  
			int delimiter=1;  
			int respuesta_len = id.length() + 1; 
			char respuesta_array[respuesta_len];
			id.toCharArray(respuesta_array, respuesta_len);
			for(int i=0; i < respuesta_len; i++){
				if(respuesta_array[i] == '.'){                   
					delimiter++;  
				}
			}
			return delimiter;
		}
		virtual List<String>* getParts()const{
			return parts;
		}
		virtual void operator=(const ElementId& b){id=b.id;}
		virtual bool operator==(const ElementId& b){return id == b.id;}
		virtual bool operator!=(const ElementId& b){return id != b.id;}
		virtual ElementId operator+(const ElementId& b){return ElementId(id + b.id);}
		
		virtual cppObjectClass* getClass(){return Class<ElementId>::classType;}
		virtual String toString(){return String("ElementId: ") + id;}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			if(!b->instanceof<ElementId>()){
				return false;
			}
			for(int x = 0; x < getSize(); x++){
				if(*parts->getByPos(x) != *((ElementId*)b)->parts->getByPos(x)){
					return false;
				}
			}
			return true;
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == "ElementId" || cppObject::instanceof(cls);
		}
	
		size_t printTo(Print& p) const{
			return p.print(id);
		}
	protected:
		String id = "";
		List<String>* parts = nullptr;
};

#endif 
