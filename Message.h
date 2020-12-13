

#ifndef Message_h
#define Message_h

#include "Note.h"

class Message{
public:
Message(){}
Message(String txt){
	m_text = txt;
}
Message(int i,String txt){
	m_id = i;
	m_text = txt;
}
Message(String mname,String txt){
	m_name = mname;
	m_text = txt;
}
Message(String mname, String mType,String txt){
	m_name = mname;
	m_type = mType;
	m_text = txt;
}
Message(int i, String mname, String mType,String txt){
	m_name = mname;
	m_type = mType;
	m_id = i;
	m_text = txt;
}
// Message(Note txt){
	// m_text = txt;
// }
// Message(int i,Note txt){
	// m_id = i;
	// m_text = txt;
// }
// Message(Note mType,Note txt){
	// m_type = mType;
	// m_text = txt;
// }
// Message(Note mType,int i,Note txt){
	// m_type = mType;
	// m_id = i;
	// m_text = txt;
// }
virtual ~Message(){}

virtual int id(){
	return m_id;
}
virtual String name(){
	return m_text;
}
virtual String text(){
	return m_text;
}
virtual String type(){
	return m_type;
}
// virtual String textString(){
	// return m_text.toString();
// }
// virtual String typeString(){
	// return m_type.toString();
// }

virtual void id(int i){
	m_id = i;
}
virtual void name(String n){
	m_name = n;
}
virtual void text(String t){
	m_text = t;
}
virtual void type(String t){
	m_type = t;
}
// virtual void text(const Note& t){
	// m_text = t;
// }
// virtual void type(const Note& t){
	// m_type = t;
// }
// virtual void operator=(const Note& b){
	// m_text = b;
// }
virtual void operator=(const String& b){
	m_text = b;
}
virtual void operator=(const Message& b){
	m_id = b.m_id;
	m_name = b.m_name;
	m_text = b.m_text;
	m_type = b.m_type;
}
virtual bool operator==(const Message& b){
	return m_id == b.m_id && m_name == b.m_name && m_text == b.m_text && m_type == b.m_type;
}
virtual bool operator!=(const Message& b){
	return m_id != b.m_id && m_name != b.m_name && m_text != b.m_text && m_type != b.m_type;
}
protected:
int m_id = -1;
String m_name;
String m_text;
String m_type;
};

#endif 
