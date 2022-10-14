
#ifndef ViewPort_hpp
#define ViewPort_hpp
#define ViewPort_AVAILABLE

#include "cppObject.hpp"
#include "Texture.hpp"
#include "Node.hpp"

namespace ame{

class ViewPort : public cppObject{
    public:
		ViewPort(){}
		virtual ~ViewPort(){}
    
	protected:
		Texture m_screen;
		Node* m_space = nullptr;
};

}

#endif
