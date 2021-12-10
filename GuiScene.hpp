
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef GuiScene_hpp
#define GuiScene_hpp

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

#endif 
