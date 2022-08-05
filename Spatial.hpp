
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Spatial)
	#define Spatial_hpp
#endif

#ifndef Spatial_hpp
#define Spatial_hpp
#define Spatial_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "Transform.hpp"
#include "Vector3f.hpp"
#include "PrimitiveList.hpp"
#include "Control.hpp"
#include "RenderManager.hpp"

namespace ame{

class Node;

class Spatial : public cppObject{	
    public:
		Spatial(){}
		Spatial(const Spatial& s){
			localTransform = s.localTransform;
			worldTransform = s.worldTransform;
			controls = s.controls;
		}
		virtual ~Spatial(){}
		virtual void operator=(const Spatial& s){
			localTransform = s.localTransform;
			worldTransform = s.worldTransform;
			controls = s.controls;
		}
		virtual bool operator==(Spatial b){
			return this->getClass()==b.getClass();
		}
		virtual bool operator!=(Spatial b){
			return this->getClass()!=b.getClass();
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<Spatial>::classType || cppObject::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<Spatial>::classType;}
		virtual Note toNote(){return "Spatial";}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			return false;
		}
		
		virtual Spatial* clone(){
			return new Spatial(*this);
		}
		
		virtual void setName(Note n){name_m = n;}
		virtual Note getName(){return name_m;}
		
		virtual void LogicalUpdate(float tpc){
			for(int x = 0; x < controls.getPosition(); x++){
				Control* control = controls.getByPosition(x);
				control->update(tpc);
			}
		}
		virtual void RenderUpdate(RenderManager* manager){
			for(int x = 0; x < controls.getPosition(); x++){
				Control* control = controls.getByPosition(x);
				control->RenderUpdate(manager);
			}
		}
		virtual void setLocalTranslation(Vector3f v){
			localTransform.setTranslation(v);
		}
		virtual void setLocalTranslation(float x, float y, float z){
			localTransform.setTranslation(x,y,z);
		}
		virtual Vector3f getLocalTranslation(){
			return localTransform.getTranslation();
		}
		virtual Vector3f getWorldTranslation(){
			return worldTransform.getTranslation();
		}
		
	protected:
		Transform localTransform;
		Transform worldTransform;
		PrimitiveList<Control> controls;
		Node* parent;
		Note name_m;
};

}

#endif