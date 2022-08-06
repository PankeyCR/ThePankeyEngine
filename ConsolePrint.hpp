
#ifndef ConsolePrint_hpp
#define ConsolePrint_hpp
#define ConsolePrint_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows
	#include <stdio.h>
	#include "ame_Print.hpp"
	#include "ame_Printable.hpp"
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "ame_String.hpp"

namespace ame{

class ConsolePrint : public Print{
    public:
	ConsolePrint(){}
	ConsolePrint(const ConsolePrint& c_cp){}
		virtual ~ConsolePrint(){}


    size_t print(const bool& a_value){
        printf ("%bd", a_value);
        return sizeof(a_value);
    }

    size_t print(const ame_String& a_value){
        printf ("%sd", a_value);
        return sizeof(a_value);
    }
/*
    size_t print(const char[] a_value){
        printf ("%s", a_value);
        return sizeof(a_value);
    }
*/
    size_t print(char a_value){
        printf ("%s", a_value);
        return sizeof(a_value);
    }

    size_t print(unsigned char a_value, int = DEC){
        printf ("%sd", a_value);
        return sizeof(a_value);
    }

    size_t print(int a_value, int = DEC){
        printf ("%id", a_value);
        return sizeof(a_value);
    }

    size_t print(unsigned int a_value, int a_dec = DEC){
        printf ("%sd", a_value);
        return sizeof(a_value);
    }

    size_t print(long a_value, int a_dec = DEC){
        printf ("%sd", a_value);
        return sizeof(a_value);
    }

    size_t print(unsigned long a_value, int a_dec= DEC){
        printf ("%ld", a_value);
        return sizeof(a_value);
    }

    size_t print(double a_value, int a_dec = 2){
        printf ("%sd", a_value);
        return sizeof(a_value);
    }

    size_t print(const Printable& a_value){
        a_value.printTo(*this);
        return sizeof(a_value);
    }


    size_t println(const bool& a_value){
        printf ("%bd \n", a_value);
        return sizeof(a_value);
    }

    size_t println(const ame_String& a_value){
        printf ("%sd \n", a_value);
        return sizeof(a_value);
    }
/*
    size_t println(const char[] a_value){
        printf ("%s \n", a_value);
        return sizeof(a_value);
    }
*/
    size_t println(char a_value){
        printf ("%s \n", a_value);
        return sizeof(a_value);
    }

    size_t println(unsigned char a_value, int a_dec = DEC){
        printf ("%sd", a_value);
        return sizeof(a_value);
    }

    size_t println(int a_value, int a_dec = DEC){
        printf ("%id \n", a_value);
        return sizeof(a_value);
    }

    size_t println(unsigned int a_value, int a_dec = DEC){
        printf ("%sd", a_value);
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
        printf ("%ld \n", a_value);
        return sizeof(a_value);
    }

    size_t println(const Printable& a_value){
        a_value.printTo(*this);
        return sizeof(a_value);
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
