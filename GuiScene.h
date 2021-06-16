

#ifndef GuiScene_h
#define GuiScene_h

#include "Vector3f.h"

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

#endif 
