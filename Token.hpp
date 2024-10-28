
#ifndef Token_hpp
	#define Token_hpp
	
	#include "pankey.hpp"

	#ifdef pankey_Windows
		#include "pankey_Printable.hpp"
	#endif

	#ifdef pankey_ArduinoIDE
		#include "Arduino.h"
		#include "Printable.h"
	#endif

	#include "Note.hpp"

	namespace pankey{
		
		class Token : public Printable{
			public:
				Note name;
				Note value;
				Note info;
				int text_Position;
				int line_Position;
				int list_Position;

				Token(){
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
				Token(Note a_name, Note a_value, Note a_info, int a_text_position, int a_line_position, int a_list_position){
					name = a_name;
					value = a_value;
					info = a_info;
					text_Position = a_text_position;
					line_Position = a_line_position;
					list_Position = a_list_position;
				}
				Token(Note a_name, Note a_value, Note a_info){
					name = a_name;
					value = a_value;
					info = a_info;
					text_Position = -1;
					line_Position = -1;
					list_Position = -1;
				}
				Token(Note a_name, Note a_value){
					name = a_name;
					value = a_value;
					text_Position = -1;
					line_Position = -1;
					list_Position = -1;
				}
				Token(const Note& a_name){
					name = a_name;
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

				virtual bool valueEqual(Token i_token){return value == i_token.value;}
				virtual bool name_valueEqual(Token i_token){return value == i_token.value;}
				virtual bool equal(Token i_token){return value == i_token.value;}
				virtual bool is(Token i_token){return value == i_token.value;}

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