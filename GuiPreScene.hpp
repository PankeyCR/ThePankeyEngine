
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GuiPreScene)
	#define GuiPreScene_hpp
#endif

#ifndef GuiPreScene_hpp
#define GuiPreScene_hpp
#define GuiPreScene_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class GuiState;

class GuiPreScene{
    public:
		GuiPreScene(){}
		virtual ~GuiPreScene(){}

		virtual void initialize(GuiState* guiState){}
		
		virtual void operator=(GuiPreScene g){}
		virtual bool operator==(GuiPreScene g){return false;}
		virtual bool operator!=(GuiPreScene g){return true;}
	protected:
};

}

#endif