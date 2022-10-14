
#ifndef SimpleApplication_hpp
#define SimpleApplication_hpp
#define SimpleApplication_AVAILABLE

#include "DefaultApplication.hpp"
#include "Node.hpp"
#include "RenderStateManager.hpp"

namespace ame{

class SimpleApplication : public DefaultApplication{
    public:
		SimpleApplication(){
			this->states = new RenderStateManager();
			this->settings = new DefaultSettings();
			this->states->setApplication(this);
			this->rootNode = new Node();
			this->guiNode = new Node();
		}
		virtual ~SimpleApplication(){}
		
		virtual void update(){
			this->states->update();
			if(memory != nullptr){
				memory->update(this->states->tpc());
			}
		}
		
		virtual Node* getRootNode(){
			return this->rootNode;
		}
		virtual Node* getGuiNode(){
			return this->guiNode;
		}
		
		//cppObject part
		virtual cppObjectClass* getClass(){
			return Class<SimpleApplication>::classType;
		}

		virtual bool instanceof(cppObjectClass* cls){
			return cls == ame::Class<SimpleApplication>::classType || ame::Application::instanceof(cls);
		}
		
	protected:
		Node* rootNode = nullptr;
		Node* guiNode = nullptr;
};

}

#endif