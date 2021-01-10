
#ifndef ScriptClass_h
#define ScriptClass_h

#include "Annotation.h"
#include "Stream.h"

class ScriptClass{
public:
ScriptClass(){
  annotationGlobal1 = false;
  annotationGlobal2 = false;
  annotationGlobal3 = false;
  annotation1 = false;
  annotation2 = false;
  annotation3 = false;
  annotationGlobal1.addLValues("command01",&ScriptClass::command01);
}
~ScriptClass(){}

void setSerial(Stream* port){
  serial = port;
}
virtual bool invokeGlobal(String method){return annotationGlobal1.invoke(this,method);}
virtual bool invokeGlobal(String method, String parameter1){return annotationGlobal2.invoke(this,method,parameter1);}
virtual bool invokeGlobal(String method, String parameter1, String parameter2){return annotationGlobal3.invoke(this,method,parameter1,parameter2);}
virtual bool invoke(String method){return annotation1.invoke(this,method);}
virtual bool invoke(String method, String parameter1){return annotation2.invoke(this,method,parameter1);}
virtual bool invoke(String method, String parameter1, String parameter2){return annotation3.invoke(this,method,parameter1,parameter2);}
virtual void operator=(ScriptClass b){}
virtual bool operator==(ScriptClass b){return annotationGlobal1 == b.annotationGlobal1 &&
                                              annotationGlobal2 == b.annotationGlobal2 &&
                                              annotationGlobal3 == b.annotationGlobal3 &&
                                              annotation1 == b.annotationGlobal1 &&
                                              annotation2 == b.annotation2 &&
                                              annotation3 == b.annotation3;}
virtual bool operator!=(ScriptClass b){return annotationGlobal1 != b.annotationGlobal1 &&
                                              annotationGlobal2 != b.annotationGlobal2 &&
                                              annotationGlobal3 != b.annotationGlobal3 &&
                                              annotation1 != b.annotationGlobal1 &&
                                              annotation2 != b.annotation2 &&
                                              annotation3 != b.annotation3;}

void type(String t){
  m_type = t;
}
void messageId(int i){
  m_id = i;
}
String type(){
  return m_type;
}
int messageId(){
  return m_id;
}

bool command01(){
  //to something
  if(serial == nullptr){
    return false;
  }
  serial->println("command01");
  return true;
}
protected:
String m_type;
int m_id;
Stream* serial = nullptr;
Annotation<String,bool,ScriptClass> annotationGlobal1;
Annotation<String,bool,ScriptClass,String> annotationGlobal2;
Annotation<String,bool,ScriptClass,String,String> annotationGlobal3;
Annotation<String,bool,ScriptClass> annotation1;
Annotation<String,bool,ScriptClass,String> annotation2;
Annotation<String,bool,ScriptClass,String,String> annotation3;
};

#endif 