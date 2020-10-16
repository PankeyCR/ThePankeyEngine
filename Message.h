

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
Message(String mType,String txt){
	m_type = mType;
	m_text = txt;
}
Message(String mType,int i,String txt){
	m_type = mType;
	m_id = i;
	m_text = txt;
}
virtual ~Message(){}

virtual int id(){
	return m_id;
}
virtual String text(){
	return m_text;
}
virtual String type(){
	return m_type;
}

virtual void id(int i){
	m_id = i;
}
virtual void text(const String& t){
	m_text = t;
}
virtual void type(const String& t){
	m_type = t;
}
virtual void operator=(const String& b){
	m_text = b;
}
virtual void operator=(const Message& b){
	m_id = b.m_id;
	m_text = b.m_text;
	m_type = b.m_type;
}
virtual bool operator==(const Message& b){
	return m_id == b.m_id && m_text == b.m_text && m_type == b.m_type;
}
virtual bool operator!=(const Message& b){
	return m_id != b.m_id && m_text != b.m_text && m_type != b.m_type;
}
protected:
int m_id = -1;
String m_text;
String m_type;
};

#endif 
