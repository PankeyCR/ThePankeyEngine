
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef ByteArrayForm_hpp
#define ByteArrayForm_hpp

#include "ByteArray.hpp"

namespace ame{
	
class ByteArrayForm{
public:
ByteArrayForm(){}
virtual ~ByteArrayForm(){}

virtual void setByteArray(const ByteArray& array){}

virtual ByteArray getByteArray(){return 0;}
};

}

#endif

#endif
