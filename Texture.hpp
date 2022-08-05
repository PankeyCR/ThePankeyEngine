
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Texture)
	#define Texture_hpp
#endif

#ifndef Texture_hpp
#define Texture_hpp
#define Texture_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "ColorRGBA.hpp"

namespace ame{

#ifdef ame_Windows
class Texture{
#endif

#ifdef ame_ArduinoIDE
class Texture : public Printable{
#endif

public:


Texture(){
}
Texture(const Texture& t){
}
virtual ~Texture(){}
virtual void operator=(const Texture& t){
}
virtual bool operator==(Texture b){return false;}
virtual bool operator!=(Texture b){return false;}

#ifdef ame_ArduinoIDE
size_t printTo(Print& p) const{
	size_t i_size = 0;/*
	i_size += p.print("Texture( ");
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
	i_size += p.print(" )");*/
	return i_size;
}
#endif

Note toNote(){
	return 	Note("Texture( ");
}

virtual ColorRGBA getPixelColor(int a_x, int a_y){
	return ColorRGBA::Black;
}
};

}

#endif