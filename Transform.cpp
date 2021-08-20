
#ifndef Transform_cpp
#define Transform_cpp

#include "Arduino.h"
#include "Transform.h"


    const ame::Transform* ame::Transform::IDENTITY = new ame::Transform();


    ame::Transform::Transform(){
        this->translation = *Vector3f::ZERO;
        // this->rot = *Quaternion::IDENTITY;
    }

    ame::Transform::Transform(const ame::Transform& t){
        this->translation = t.translation;
        this->rot = t.rot;
        this->scale = t.scale;
    }
	
    ame::Transform::Transform(ame::Vector3f translation, ame::Quaternion rot){
        this->translation = translation;
        this->rot = rot;
    }
    
    ame::Transform::Transform(ame::Vector3f translation, ame::Quaternion rot, ame::Vector3f scale){
        this->translation = translation;
        this->rot = rot;
        this->scale = scale;
    }

    ame::Transform::Transform(ame::Vector3f translation){
        this->translation = translation;
        // this->rot = *Quaternion::IDENTITY;
    }

    ame::Transform::Transform(ame::Quaternion rot){
        this->translation = *Vector3f::ZERO;
        this->rot = rot;
    }
	
    ame::Transform ame::Transform::setRotation(ame::Quaternion rot) {
        this->rot = rot;
        return *this;
    }
	
    ame::Quaternion ame::Transform::getRotation() {
        return this->rot;
    }
	
    ame::Transform ame::Transform::setTranslation(float x,float y, float z) {
        this->translation.set(x,y,z);
        return *this;
    }
	
    ame::Transform ame::Transform::setTranslation(ame::Vector3f trans) {
        this->translation = trans;
        return *this;
    }
	
    ame::Vector3f ame::Transform::getTranslation() {
        return this->translation;
    }
	
    ame::Transform ame::Transform::setScale(float x, float y, float z) {
        this->scale.set(x,y,z);
        return *this;
    }
	
    ame::Transform ame::Transform::setScale(ame::Vector3f scale) {
        this->scale = scale;
        return *this;
    }
	
    ame::Transform ame::Transform::setScale(float scale) {
        this->scale = scale;
        return *this;
    }
	
    ame::Vector3f ame::Transform::getScale() {
        return this->scale;
    }
	
    void ame::Transform::interpolateTransforms(ame::Transform t1, ame::Transform t2, float delta) {
        t1.rot.nlerp(t2.rot, delta);
        this->rot.set(t1.rot);
        this->translation.interpolateLocal(t1.translation,t2.translation,delta);
        this->scale.interpolateLocal(t1.scale,t2.scale,delta);
    }
	
    ame::Transform ame::Transform::combineWithParent(ame::Transform parent) {
        
		scale.multLocal(parent.scale);
        
		rot = parent.rot.mult(rot);
        
		translation.multLocal(parent.scale);
        
		parent
            .rot
            .multLocal(translation)
            .addLocal(parent.translation);

        return parent;
    }

    ame::Vector3f ame::Transform::transformVector(ame::Vector3f in, ame::Vector3f store){
		store = rot.mult(store.set(in).multLocal(scale));
        store.addLocal(translation);
        return store;
    }

    ame::Vector3f ame::Transform::transformInverseVector(ame::Vector3f in, ame::Vector3f store){
        store = in.subtract(translation);
        store = rot.inverse().mult(store);
        store.divideLocal(scale);

        return store;
    }

    // Matrix4f ame::Transform::toame::TransformMatrix() {
        // Matrix4f store;
        // store.setTranslation(translation);
        // rot.toame::TransformMatrix(store);
        // store.setScale(scale);
        // return store;
    // }

    // Matrix4f ame::Transform::toame::TransformMatrix(Matrix4f store) {
        // store.setTranslation(translation);
        // rot.toame::TransformMatrix(store);
        // store->setScale(scale);
        // return store;
    // }
    
    // void ame::Transform::fromame::TransformMatrix(Matrix4f mat) {
        // TempVars vars = TempVars.get();
        // translation.set(mat.toTranslationVector(vars.vect1));
        // rot.set(mat.toRotationQuat(vars.quat1));
        // scale.set(mat.toScaleVector(vars.vect2));
        // vars.release();
    // }
    
    // ame::Transform ame::Transform::invert() {
        // ame::Transform t;
        // t.fromame::TransformMatrix(toame::TransformMatrix().invertLocal());
        // return t;
    // }
	
    void ame::Transform::loadIdentity() {
        translation.set(0, 0, 0);
        scale.set(1, 1, 1);
        rot.set(0, 0, 0, 1);
    }
	
    bool ame::Transform::isIdentity() {
        return translation.x == 0.0f && translation.y == 0.0f && translation.z == 0.0f
                && scale.x == 1.0f && scale.y == 1.0f && scale.z == 1.0f
                && rot.w == 1.0f && rot.x == 0.0f && rot.y == 0.0f && rot.z == 0.0f;
    }
    // int ame::Transform::hashCode() {
        // int hash = 7;
        // hash = 89 * hash + rot.hashCode();
        // hash = 89 * hash + translation.hashCode();
        // hash = 89 * hash + scale.hashCode();
        // return hash;
    // }
	
    bool ame::Transform::equal(ame::cppObject *obj) {
        if (obj == nullptr) {
            return false;
        }
        if (this->getClass() != obj->getClass()) {
            return false;
        }
        ame::Transform* other = (ame::Transform*) obj;
        return this->translation.equal(&other->translation)
                && this->scale.equal(&other->scale)
                && this->rot.equal(&other->rot);
    }
	
	String ame::Transform::toString(){
        return String("ame::Transform[ ") + translation.x + ", " + translation.y + ", " + translation.z + "]\n"
                                          + "[ " + rot.x + ", " + rot.y + ", " + rot.z + ", " + rot.w + "]\n"
                                          + "[ " + scale.x + " , " + scale.y + ", " + scale.z + "]";
    }
	
    ame::Transform ame::Transform::set(ame::Transform matrixQuat) {
        this->translation.set(matrixQuat.translation);
        this->rot.set(matrixQuat.rot);
        this->scale.set(matrixQuat.scale);
        return *this;
	}
	
    // void ame::Transform::write(JmeExporter e){
        // OutputCapsule capsule = e.getCapsule(this);
        // capsule.write(rot, "rot", Quaternion.IDENTITY);
        // capsule.write(translation, "translation", Vector3f.ZERO);
        // capsule.write(scale, "scale", Vector3f.UNIT_XYZ);
    // }
	
    // void ame::Transform::read(JmeImporter e){
        // InputCapsule capsule = e.getCapsule(this);
        
        // rot.set((Quaternion)capsule.readSavable("rot", Quaternion.IDENTITY));
        // translation.set((Vector3f)capsule.readSavable("translation", Vector3f.ZERO));
        // scale.set((Vector3f)capsule.readSavable("scale", Vector3f.UNIT_XYZ));
    // }
	
	ame::Transform* ame::Transform::clone() {
		return new ame::Transform(*this);
    }
	ame::cppObjectClass* ame::Transform::getClass(){
		return ame::Class<ame::Transform>::classType;
	}
	bool ame::Transform::instanceof(ame::cppObjectClass* cls){
		return cls == ame::Class<ame::Transform>::classType || ame::cppObject::instanceof(cls);
	}
	
	void ame::Transform::operator=(const ame::Transform& t){
        this->translation = t.translation;
        this->rot = t.rot;
        this->scale = t.scale;
	}
	
	
#endif 