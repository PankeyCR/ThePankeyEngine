
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Token)
	#define Token_hpp
#endif

#ifndef Token_hpp
#define Token_hpp
#define Token_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "Note.hpp"

namespace ame{
	
class Token : public Printable{

public:
Note name;
Note value;
Note info;
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
Token(Note n, Note t, Note i, int tP, int lP, int lstP){
	name = n;
	value = t;
	info = i;
	text_Position = tP;
	line_Position = lP;
	list_Position = lstP;
}
Token(Note n, Note t, Note i){
	name = n;
	value = t;
	info = i;
	text_Position = -1;
	line_Position = -1;
	list_Position = -1;
}
Token(Note n, Note t){
	name = n;
	value = t;
	info = "";
	text_Position = -1;
	line_Position = -1;
	list_Position = -1;
}
Token(const Note& n){
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

#ifdef ame_ArduinoIDE
size_t printTo(Print& p) const{
	size_t i_size = 0;
	i_size += p.print("Token( ");
	i_size += p.print(name);
	i_size += p.print(" , ");
	i_size += p.print(value);
	i_size += p.print(" , ");
	i_size += p.print(info);
	i_size += p.print(" , ");
	i_size += p.print(text_Position);
	i_size += p.print(" , ");
	i_size += p.print(line_Position);
	i_size += p.print(" , ");
	i_size += p.print(list_Position);
	i_size += p.print(" )");
	return i_size;
}
#endif

Note toNote(){
	return 	Note("Token( ") +
			Note(name) +
			Note(" , ") +
			Note(value) +
			Note(" , ") +
			Note(info) +
			Note(" , ") +
			Note(text_Position) +
			Note(" , ") +
			Note(line_Position) +
			Note(" , ") +
			Note(list_Position) +
			Note(" )");
}
};

}

#endif