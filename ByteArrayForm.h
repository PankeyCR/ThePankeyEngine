
#ifndef ByteArrayForm_h
#define ByteArrayForm_h

#include "ByteArray.h"

class ByteArrayForm{
public:
ByteArrayForm(){}
virtual ~ByteArrayForm(){}

virtual void setByteArray(const ByteArray& array){}

virtual ByteArray getByteArray(){return 0;}
};

#endif