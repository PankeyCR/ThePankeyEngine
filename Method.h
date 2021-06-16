#ifndef Method_h
#define Method_h

#include "RawList.h"
#include "PrimitiveRawList.h"
#include "Annotation.h"

class Method{
public:
	Method(){
	}
	virtual ~Method(){}
	
	void setName(String n){
		m_name = n;
	}
	String getName(){
		return m_name;
	}
		
	virtual RawList<Annotation>* getAnnotations(){
		return nullptr;
	}
	
	virtual Annotation* getAnnotation(cppObjectClass* cls){
		return nullptr;
	}
	virtual void operator=(Method b){}
	virtual bool operator==(Method b){return true;}
	virtual bool operator!=(Method b){return false;}
		
protected:
	String m_name;
};

#endif