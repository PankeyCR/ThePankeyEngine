

#ifndef GuiState_h
#define GuiState_h

#include "AppState.h"
#include "Arduino.h"
#include "List.h"
#include "Map.h"
#include "PrimitiveList.h"
#include "PrimitiveMap.h"
#include "Panel.h"
#include "GuiScene.h"
#include "GuiPreScene.h"
#include "Annotation.h"
#include "SerialMessageControlledState.h"
#include "SimpleApplication.h"

#ifdef GuiStateLogApp
	#include "Logger.h"
	#define GuiStateLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define GuiStateLog(name,method,type,mns)
#endif

namespace ame{

class GuiState : public SerialMessageControlledState{
    public:
		GuiState(){
			init = new PrimitiveList<GuiPreScene>();
			panels = new PrimitiveMap<String,Panel>();
			scenes = new PrimitiveMap<String,GuiScene>();
			activePanels = new PrimitiveMap<String,Panel>();
			activeScenes = new PrimitiveMap<String,GuiScene>();
		}
		virtual ~GuiState(){
			delete init;
			delete panels;
			delete scenes;
			delete activePanels;
			delete activeScenes;
		}

		bool instanceof(cppObjectClass* cls){
			return cls == Class<GuiState>::classType || SerialMessageControlledState::instanceof(cls);
		}
		cppObjectClass* getClass(){return Class<GuiState>::classType;}
		
		virtual bool invoke(String method){
			GuiStateLog("GuiState", "invoke",  "println", "invoke method without parameters");
			return annotation1.invoke(this,method);
		}
		virtual bool invoke(String method, String parameter1){
			GuiStateLog("GuiState", "invoke",  "println", "invoke method with 1 parameter");
			return annotation2.invoke(this,method,parameter1);
		}
		virtual bool invoke(String method, String parameter1, String parameter2){
			GuiStateLog("GuiState", "invoke",  "println", "invoke method with 1 parameter");
			return annotation3.invoke(this,method,parameter1,parameter2);
		}
		
		virtual void initialize(Application* app) {
			if(app->instanceof("SimpleApplication")){
				guiNode = ((SimpleApplication*)app)->getGuiNode();
				rootNode = ((SimpleApplication*)app)->getRootNode();
			}
			for(int x=0; x < init->getPosition(); x++){
				GuiPreScene* prescene = init->getByPosition(x);
				prescene->initialize(this);
			}
		}
		
		virtual void update(float tpc){
			for(int x = 0; x < this->activeScenes->getPosition(); x++){
				GuiScene* scene = this->activeScenes->getByPosition(x);
				scene->updateScene(this, tpc);
			}
		}
    
		void addPreScene(GuiPreScene* prescene){
			this->init->addPointer(prescene);
		}
		
		void addPanel(String name, Panel* panel){
			this->panels->addPointer(name,panel);
		}
		
		Panel* getPanel(String name){
			return this->panels->getByLValue(name);
		}
		
		void removePanel(String name){
			this->panels->removeDeleteByLValue(name);
		}

		void addScene(String name, GuiScene* scene) {
			this->scenes->addPointer(name, scene);
		}

		GuiScene* getScene(String name) {
			return this->scenes->getByLValue(name);
		}
		
		void removeScene(String name){
			this->scenes->removeDeleteByLValue(name);
		}

		void attach(String name) {
			if(this->guiNode == nullptr){
				return;
			}
			Panel* panel = this->panels->getByLValue(name);
			if(panel != nullptr){
				this->activePanels->addPointer(name, panel);
				this->guiNode->attachChild(panel);
				return;
			}
			GuiScene* scene = this->scenes->getByLValue(name);
			if(scene != nullptr){
				scene->attachScene(this, *Vector3f::ZERO);
				this->activeScenes->addPointer(name, scene);
			}
		}

		void attach(String name, Vector3f position) {
			if(this->guiNode == nullptr){
				return;
			}
			Panel* panel = this->panels->getByLValue(name);
			if(panel != nullptr){
				panel->setLocalTranslation(position);
				this->activePanels->addPointer(name, panel);
				this->guiNode->attachChild(panel);
				return;
			}
			GuiScene* scene = this->scenes->getByLValue(name);
			if(scene != nullptr){
				scene->attachScene(this, position);
				this->activeScenes->addPointer(name, scene);
			}
		}

		void detach(String name) {
			if(this->guiNode == nullptr){
				return;
			}
			Panel* panel = this->activePanels->getByLValue(name);
			if(panel != nullptr){
				this->activePanels->removeByLValue(name);
				this->guiNode->detachChildByPointer(panel);
				return;
			}
			GuiScene* scene = this->activeScenes->getByLValue(name);
			if(scene != nullptr){
				this->activeScenes->removeByLValue(name);
				scene->detachScene(this);
			}
		}

		void detachAll() {
			for(int x = 0; x < this->activePanels->getPosition(); x++){
				Panel* panel = this->activePanels->getByPosition(x);
				this->guiNode->detachChildByPointer(panel);
			}
			this->activePanels->resetDeleteKey();
			for(int x = 0; x < this->activeScenes->getPosition(); x++){
				GuiScene* scene = this->activeScenes->getByPosition(x);
				scene->detachScene(this);
			}
			this->activeScenes->resetDeleteKey();
		}

		void detachAllPanels() {
			for(int x = 0; x < this->activePanels->getPosition(); x++){
				Panel* panel = this->activePanels->getByPosition(x);
				this->guiNode->detachChildByPointer(panel);
			}
			this->activePanels->resetDeleteKey();
		}

		void detachAllScenes() {
			for(int x = 0; x < this->activeScenes->getPosition(); x++){
				GuiScene* scene = this->activeScenes->getByPosition(x);
				scene->detachScene(this);
			}
			this->activeScenes->resetDeleteKey();
		}
		
	protected:
		Annotation<String,bool,GuiState> annotation1;
		Annotation<String,bool,GuiState,String> annotation2;
		Annotation<String,bool,GuiState,String,String> annotation3;
		
		Node* guiNode = nullptr;
		Node* rootNode = nullptr;
		List<GuiPreScene>* init;
		Map<String,Panel>* panels;
		Map<String,GuiScene>* scenes;
		Map<String,Panel>* activePanels;
		Map<String,GuiScene>* activeScenes;
};

#endif 
