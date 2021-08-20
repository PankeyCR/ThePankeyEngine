
#ifndef Spatial_h
#define Spatial_h

#include "cppObject.h"
#include "Transform.h"
#include "Vector3f.h"
#include "PrimitiveList.h"
#include "Control.h"
#include "RenderManager.h"

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
		virtual String toString(){return "Spatial";}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			return false;
		}
		
		virtual Spatial* clone(){
			return new Spatial(*this);
		}
		
		virtual void setName(String n){name_m = n;}
		virtual String getName(){return name_m;}
		
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
		String name_m;
};

}

#endif 
