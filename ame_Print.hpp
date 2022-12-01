
#ifndef ame_Print_hpp
#define ame_Print_hpp

#include "ame_Byte.hpp"
#include "ame_Printable.hpp"
#include "ame_String.hpp"

#ifdef ame_Windows
	#include <string.h>
#endif

#define DEC 10
#define HEX 16
#define OCT 8
#ifdef BIN
#undef BIN
#endif
#define BIN 2

class Print{
  private:
    int write_error;
    size_t printNumber(unsigned long n, int base){
        char buf[8 * sizeof(long) + 1]; // Assumes 8-bit chars plus zero byte.
        char *str = &buf[sizeof(buf) - 1];

        *str = '\0';

        // prevent crash if called with base == 1
        if (base < 2) base = 10;

        do {
            char c = n % base;
            n /= base;

            *--str = c < 10 ? c + '0' : c + 'A' - 10;
        } while(n);

        return write(str);
    }

    size_t printFloat(float number, int digits){
        size_t n = 0;

        //if (isnan(number)) return print("nan");
        //if (isinf(number)) return print("inf");
        if (number > 4294967040.0) return print ("ovf");  // constant determined empirically
        if (number <-4294967040.0) return print ("ovf");  // constant determined empirically

        // Handle negative numbers
        if (number < 0.0){
            n += print('-');
            number = -number;
        }

        // Round correctly so that print(1.999, 2) prints as "2.00"
        double rounding = 0.5;
        for (uint8_t i=0; i<digits; ++i)
        rounding /= 10.0;

        number += rounding;

        // Extract the integer part of the number and print it
        unsigned long int_part = (unsigned long)number;
        double remainder = number - (double)int_part;
        n += print(int_part);

        // Print the decimal point, but only if there are digits beyond
        if (digits > 0) {
            n += print('.');
        }

        // Extract digits from the remainder one at a time
        while (digits-- > 0){
            remainder *= 10.0;
            unsigned int toPrint = (unsigned int)(remainder);
            n += print(toPrint);
            remainder -= toPrint;
        }

        return n;
    }

    protected:
    void setWriteError(int err = 1) { write_error = err; }
  public:
    Print() : write_error(0) {}
    Print(const Print& c_print) : write_error(0) {}

    int getWriteError() { return write_error; }
    void clearWriteError() { setWriteError(0); }

    virtual size_t write(int){return 0;}
    size_t write(const char *str) {
      if (str == NULL) return 0;
      return write((const int *)str, strlen(str));
    }
    virtual size_t write(const int *buffer, size_t size){return 0;}
    size_t write(const char *buffer, size_t size) {
      return write((const int *)buffer, size);
    }

    // default to zero, meaning "a single write may block"
    // should be overriden by subclasses with buffering
    virtual int availableForWrite() { return 0; }

    virtual size_t print(const ame_Byte& a_value){ return 0; }
    virtual size_t print(const bool& a_value){ return 0; }
    virtual size_t print(const float& a_value){ return 0; }
    virtual size_t print(const ame_String &){ return 0; }
    virtual size_t print(const char[]){ return 0; }
    virtual size_t print(char){ return 0; }
    virtual size_t print(unsigned char, int = DEC){ return 0; }
    virtual size_t print(int, int = DEC){ return 0; }
    virtual size_t print(unsigned int, int = DEC){ return 0; }
    virtual size_t print(long, int = DEC){ return 0; }
    virtual size_t print(unsigned long, int = DEC){ return 0; }
    virtual size_t print(double, int = 2){ return 0; }
    virtual size_t print(const Printable&){ return 0; }


    virtual size_t println(const bool& a_value){ return 0; }
    virtual size_t println(const float& a_value){ return 0; }
    virtual size_t println(const ame_String &s){ return 0; }
    virtual size_t println(const char[]){ return 0; }
    virtual size_t println(char){ return 0; }
    virtual size_t println(unsigned char, int = DEC){ return 0; }
    virtual size_t println(int, int = DEC){ return 0; }
    virtual size_t println(unsigned int, int = DEC){ return 0; }
    virtual size_t println(long, int = DEC){ return 0; }
    virtual size_t println(unsigned long, int = DEC){ return 0; }
    virtual size_t println(double, int = 2){ return 0; }
    virtual size_t println(const Printable&){ return 0; }
    virtual size_t println(void){ return 0; }

    virtual void flush() {}
};

#endif
