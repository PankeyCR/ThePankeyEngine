
#ifndef Logic_h
#define Logic_h

#include "ByteArray.h"

namespace ame{

class Logic{
public:
Logic(){}
~Logic(){}

virtual ByteArray logic(const ByteArray& array){
	return array;
}

protected:
};

}

#endif