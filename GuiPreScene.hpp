
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef GuiPreScene_hpp
#define GuiPreScene_hpp

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

#endif 
