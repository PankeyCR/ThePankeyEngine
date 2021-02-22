

#ifndef Token_h
#define Token_h

class Token{
public:
String name;
String type;
String info;
int text_Position;
int line_Position;
int list_Position;

Token(){
	name = "";
	type = "";
	info = "";
	text_Position = -1;
	line_Position = -1;
	list_Position = -1;
}
Token(const Token& t){
	name = t.name;
	type = t.type;
	info = t.info;
	text_Position = t.text_Position;
	line_Position = t.line_Position;
	list_Position = t.list_Position;
}
Token(String n, String t, String i, int tP, int lP, int lstP){
	name = n;
	type = t;
	info = i;
	text_Position = tP;
	line_Position = lP;
	list_Position = lstP;
}
Token(String n, String t, String i){
	name = n;
	type = t;
	info = i;
	text_Position = -1;
	line_Position = -1;
	list_Position = -1;
}
Token(String n, String t){
	name = n;
	type = t;
	info = "";
	text_Position = -1;
	line_Position = -1;
	list_Position = -1;
}
virtual ~Token(){}
virtual void operator=(const Token& t){
	name = t.name;
	type = t.type;
	info = t.info;
	text_Position = t.text_Position;
	line_Position = t.line_Position;
	list_Position = t.list_Position;
}
virtual void operator=(Token t){
	name = t.name;
	type = t.type;
	info = t.info;
	text_Position = t.text_Position;
	line_Position = t.line_Position;
	list_Position = t.list_Position;
}
virtual bool operator==(Token b){return type == b.type;}
virtual bool operator!=(Token b){return type != b.type;}
};

#endif 
