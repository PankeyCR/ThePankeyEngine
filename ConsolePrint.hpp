
#ifndef ConsolePrint_hpp
#define ConsolePrint_hpp

#if pankey_Enviroment == pankey_Windows_Enviroment
	#include <stdio.h>
	#include "pankey_Print.hpp"
	#include "pankey_Printable.hpp"
#endif

#if pankey_IDE == pankey_Arduino_IDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "pankey_String.hpp"

namespace pankey{

class ConsolePrint : public Print{
    public:
	ConsolePrint(){}
	ConsolePrint(const ConsolePrint& c_cp){}
		virtual ~ConsolePrint(){}


    size_t print(const bool& a_value){
        printf ("%s", a_value ? "true" : "false");
        return sizeof(a_value);
    }

    size_t print(const pankey_String& a_value){
        printf ("%s", a_value.c_str());
        return sizeof(a_value);
    }
    size_t print(char a_value){
        printf ("%c", a_value);
        return sizeof(a_value);
    }

    size_t print(const char* a_value){
        printf ("%s", a_value);
        return sizeof(a_value);
    }

    size_t print(unsigned char a_value, int = DEC){
        printf ("%c", a_value);
        return sizeof(a_value);
    }

    size_t print(int a_value, int = DEC){
        printf ("%i", a_value);
        return sizeof(a_value);
    }

    size_t print(unsigned int a_value, int a_dec = DEC){
        printf ("%i", a_value);
        return sizeof(a_value);
    }

    size_t print(long a_value, int a_dec = DEC){
        printf ("%ld", a_value);
        return sizeof(a_value);
    }

    size_t print(unsigned long a_value, int a_dec= DEC){
        printf ("%ld", a_value);
        return sizeof(a_value);
    }

    size_t print(double a_value, int a_dec = 2){
        printf ("%f", a_value);
        return sizeof(a_value);
    }

    size_t print(const Printable& a_value){
        a_value.printTo(*this);
        return sizeof(a_value);
    }


    size_t println(const bool& a_value){
        printf ("%s \n", a_value ? "true" : "false");
        return sizeof(a_value);
    }

    size_t println(const pankey_String& a_value){
        printf ("%s \n", a_value.c_str());
        return sizeof(a_value);
    }

    size_t println(const char* a_value){
        printf ("%s \n", a_value);
        return sizeof(a_value);
    }

    size_t println(char a_value){
        printf ("%c \n", a_value);
        return sizeof(a_value);
    }

    size_t println(unsigned char a_value, int a_dec = DEC){
        printf ("%c\n", a_value);
        return sizeof(a_value);
    }

    size_t println(int a_value, int a_dec = DEC){
        printf ("%i \n", a_value);
        return sizeof(a_value);
    }

    size_t println(unsigned int a_value, int a_dec = DEC){
        printf ("%i", a_value);
        return sizeof(a_value);
    }

    size_t println(long a_value, int a_dec = DEC){
        printf ("%ld \n", a_value);
        return sizeof(a_value);
    }

    size_t println(unsigned long a_value, int a_dec = DEC){
        printf ("%ld \n", a_value);
        return sizeof(a_value);
    }

    size_t println(double a_value, int a_dec = 2){
        printf ("%f \n", a_value);
        return sizeof(a_value);
    }

    size_t println(const Printable& a_value){
        size_t i_size = a_value.printTo(*this);
        printf ("%s \n", "");
        return i_size + sizeof('\n');
    }

    size_t println(void){
        printf ("%s \n", "");
        return sizeof("\n");
    }

    size_t print(const float& a_value){
        printf ("%f", a_value);
        return sizeof(a_value);
    }
    size_t println(const float& a_value){
        printf ("%f \n", a_value);
        return sizeof(a_value);
    }

	protected:

};

extern ConsolePrint PConsole;

}

#endif
