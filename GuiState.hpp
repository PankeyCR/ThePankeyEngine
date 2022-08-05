
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GuiState)
	#define GuiState_hpp
#endif

#ifndef GuiState_hpp
#define GuiState_hpp
#define GuiState_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "AppState.hpp"
#include "List.hpp"
#include "Map.hpp"
#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"
#include "Panel.hpp"
#include "GuiScene.hpp"
#include "GuiPreScene.hpp"
#include "Annotation.hpp"
#include "SerialMessageControlledState.hpp"
#include "SimpleApplication.hpp"

#ifdef GuiStateLogApp
	#include "Logger.hpp"
	#define GuiStateLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define GuiStateLog(name,method,type,mns)
#endif

namespace ame{

class GuiState : public SerialMessageControlledState{
    public:
		GuiState(){
			init = new PrimitiveList<GuiPreScene>();
			panels = new PrimitiveMap<Note,Panel>();
			scenes = new PrimitiveMap<Note,GuiScene>();
			activePanels = new PrimitiveMap<Note,Panel>();
			activeScenes = new PrimitiveMap<Note,GuiScene>();
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
		
		virtual bool invoke(Note method){
			GuiStateLog("GuiState", "invoke",  "println", "invoke method without parameters");
			return annotation1.invoke(this,method);
		}
		virtual bool invoke(Note method, Note parameter1){
			GuiStateLog("GuiState", "invoke",  "println", "invoke method with 1 parameter");
			return annotation2.invoke(this,method,parameter1);
		}
		virtual bool invoke(Note method, Note parameter1, Note parameter2){
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
		
		void addPanel(Note name, Panel* panel){
			this->panels->addPointer(name,panel);
		}
		
		Panel* getPanel(Note name){
			return this->panels->getByLValue(name);
		}
		
		void removePanel(Note name){
			this->panels->removeDeleteByLValue(name);
		}

		void addScene(Note name, GuiScene* scene) {
			this->scenes->addPointer(name, scene);
		}

		GuiScene* getScene(Note name) {
			return this->scenes->getByLValue(name);
		}
		
		void removeScene(Note name){
			this->scenes->removeDeleteByLValue(name);
		}

		void attach(Note name) {
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

		void attach(Note name, Vector3f position) {
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

		void detach(Note name) {
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
		Annotation<Note,bool,GuiState> annotation1;
		Annotation<Note,bool,GuiState,Note> annotation2;
		Annotation<Note,bool,GuiState,Note,Note> annotation3;
		
		Node* guiNode = nullptr;
		Node* rootNode = nullptr;
		List<GuiPreScene>* init;
		Map<Note,Panel>* panels;
		Map<Note,GuiScene>* scenes;
		Map<Note,Panel>* activePanels;
		Map<Note,GuiScene>* activeScenes;
};

#endif