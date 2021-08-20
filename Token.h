

#ifndef Token_h
#define Token_h

#include "Printable.h"

namespace ame{

class Token : public Printable{
public:
String name;
String value;
String info;
int text_Position;
int line_Position;
int list_Position;

Token(){
	name = "";
	value = "";
	info = "";
	text_Position = -1;
	line_Position = -1;
	list_Position = -1;
}
Token(const Token& t){
	name = t.name;
	value = t.value;
	info = t.info;
	text_Position = t.text_Position;
	line_Position = t.line_Position;
	list_Position = t.list_Position;
}
Token(String n, String t, String i, int tP, int lP, int lstP){
	name = n;
	value = t;
	info = i;
	text_Position = tP;
	line_Position = lP;
	list_Position = lstP;
}
Token(String n, String t, String i){
	name = n;
	value = t;
	info = i;
	text_Position = -1;
	line_Position = -1;
	list_Position = -1;
}
Token(String n, String t){
	name = n;
	value = t;
	info = "";
	text_Position = -1;
	line_Position = -1;
	list_Position = -1;
}
Token(const String& n){
	name = n;
	value = "";
	info = "";
	text_Position = -1;
	line_Position = -1;
	list_Position = -1;
}
virtual ~Token(){}
virtual void operator=(const Token& t){
	name = t.name;
	value = t.value;
	info = t.info;
	text_Position = t.text_Position;
	line_Position = t.line_Position;
	list_Position = t.list_Position;
}
virtual bool operator==(Token b){return value == b.value;}
virtual bool operator!=(Token b){return value != b.value;}

size_t printTo(Print& p) const{
	p.print("Token( ");
	p.print(name);
	p.print(" , ");
	p.print(value);
	p.print(" , ");
	p.print(info);
	p.print(" , ");
	p.print(text_Position);
	p.print(" , ");
	p.print(line_Position);
	p.print(" , ");
	p.print(list_Position);
	p.print(" )");
}

String toString(){
	return 	String("Token( ") +
			String(name) +
			String(" , ") +
			String(value) +
			String(" , ") +
			String(info) +
			String(" , ") +
			String(text_Position) +
			String(" , ") +
			String(line_Position) +
			String(" , ") +
			String(list_Position) +
			String(" )");
}
};

}

#endif 
