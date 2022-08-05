
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GuiScene)
	#define GuiScene_hpp
#endif

#ifndef GuiScene_hpp
#define GuiScene_hpp
#define GuiScene_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Vector3f.hpp"

namespace ame{

class GuiState;

class GuiScene{
    public:
		GuiScene(){}
		virtual ~GuiScene(){}

		virtual void attachScene(GuiState* guiState, Vector3f offset){}
		virtual void detachScene(GuiState* guiState){}
		virtual void updateScene(GuiState* guiState, float tpc){}
		
		virtual void operator=(GuiScene g){}
		virtual bool operator==(GuiScene g){return false;}
		virtual bool operator!=(GuiScene g){return true;}
	protected:
};

}

#endif