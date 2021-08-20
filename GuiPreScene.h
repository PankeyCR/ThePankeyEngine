

#ifndef GuiPreScene_h
#define GuiPreScene_h

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
