
#ifndef Texture_hpp
#define Texture_hpp

#include "higgs_Enviroment.hpp"

#ifdef higgs_Windows
	#include "higgs_Printable.hpp"
	#include "higgs_Print.hpp"
#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "ColorRGBA.hpp"
#include "Array2D.hpp"
#include "Font.hpp"

namespace higgs{

class Texture{

public:
	Texture(){}
	Texture(int a_width, int a_height){}
	Texture(const Texture& t){
		
	}
	virtual ~Texture(){}
	
	virtual ColorRGBA getColor(int x, int y){return ColorRGBA();}
	
	
	virtual void operator=(const Texture& t){
	}
	virtual bool operator==(Texture b){return false;}
	virtual bool operator!=(Texture b){return false;}

protected:
	Array2D<ColorRGBA> screen;
};

}

#endif