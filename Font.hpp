
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Font)
	#define Font_hpp
#endif

#ifndef Font_hpp
#define Font_hpp
#define Font_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows
	#include "ame_Printable.hpp"
	#include "ame_Print.hpp"
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "ColorRGBA.hpp"

namespace ame{

class Font{

public:
	Font(){}
	Font(int a_width, int a_height){}
	Font(const Font& t){
		
	}
	virtual ~Font(){}
	
	
	
	virtual void operator=(const Font& t){
	}
	virtual bool operator==(Font b){return false;}
	virtual bool operator!=(Font b){return false;}

protected:
};

}

#endif