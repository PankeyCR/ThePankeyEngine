
#ifndef Transform_cpp
#define Transform_cpp

#include "Arduino.h"
#include "Transform.h"


    const Transform* Transform::IDENTITY = new Transform();


    Transform::Transform(){
        this->translation = *Vector3f::ZERO;
        // this->rot = *Quaternion::IDENTITY;
    }

    Transform::Transform(const Transform& t){
        this->translation = t.translation;
        this->rot = t.rot;
        this->scale = t.scale;
    }
	
    Transform::Transform(Vector3f translation, Quaternion rot){
        this->translation = translation;
        this->rot = rot;
    }
    
    Transform::Transform(Vector3f translation, Quaternion rot, Vector3f scale){
        this->translation = translation;
        this->rot = rot;
        this->scale = scale;
    }

    Transform::Transform(Vector3f translation){
        this->translation = translation;
        // this->rot = *Quaternion::IDENTITY;
    }

    Transform::Transform(Quaternion rot){
        this->translation = *Vector3f::ZERO;
        this->rot = rot;
    }
	
    Transform Transform::setRotation(Quaternion rot) {
        this->rot = rot;
        return *this;
    }
	
    Quaternion Transform::getRotation() {
        return this->rot;
    }
	
    Transform Transform::setTranslation(float x,float y, float z) {
        this->translation.set(x,y,z);
        return *this;
    }
	
    Transform Transform::setTranslation(Vector3f trans) {
        this->translation = trans;
        return *this;
    }
	
    Vector3f Transform::getTranslation() {
        return this->translation;
    }
	
    Transform Transform::setScale(float x, float y, float z) {
        this->scale.set(x,y,z);
        return *this;
    }
	
    Transform Transform::setScale(Vector3f scale) {
        this->scale = scale;
        return *this;
    }
	
    Transform Transform::setScale(float scale) {
        this->scale = scale;
        return *this;
    }
	
    Vector3f Transform::getScale() {
        return this->scale;
    }
	
    void Transform::interpolateTransforms(Transform t1, Transform t2, float delta) {
        t1.rot.nlerp(t2.rot, delta);
        this->rot.set(t1.rot);
        this->translation.interpolateLocal(t1.translation,t2.translation,delta);
        this->scale.interpolateLocal(t1.scale,t2.scale,delta);
    }
	
    Transform Transform::combineWithParent(Transform parent) {
        
		scale.multLocal(parent.scale);
        
		rot = parent.rot.mult(rot);
        
		translation.multLocal(parent.scale);
        
		parent
            .rot
            .multLocal(translation)
            .addLocal(parent.translation);

        return parent;
    }

    Vector3f Transform::transformVector(Vector3f in, Vector3f store){
		store = rot.mult(store.set(in).multLocal(scale));
        store.addLocal(translation);
        return store;
    }

    Vector3f Transform::transformInverseVector(Vector3f in, Vector3f store){
        store = in.subtract(translation);
        store = rot.inverse().mult(store);
        store.divideLocal(scale);

        return store;
    }

    // Matrix4f Transform::toTransformMatrix() {
        // Matrix4f store;
        // store.setTranslation(translation);
        // rot.toTransformMatrix(store);
        // store.setScale(scale);
        // return store;
    // }

    // Matrix4f Transform::toTransformMatrix(Matrix4f store) {
        // store.setTranslation(translation);
        // rot.toTransformMatrix(store);
        // store->setScale(scale);
        // return store;
    // }
    
    // void Transform::fromTransformMatrix(Matrix4f mat) {
        // TempVars vars = TempVars.get();
        // translation.set(mat.toTranslationVector(vars.vect1));
        // rot.set(mat.toRotationQuat(vars.quat1));
        // scale.set(mat.toScaleVector(vars.vect2));
        // vars.release();
    // }
    
    // Transform Transform::invert() {
        // Transform t;
        // t.fromTransformMatrix(toTransformMatrix().invertLocal());
        // return t;
    // }
	
    void Transform::loadIdentity() {
        translation.set(0, 0, 0);
        scale.set(1, 1, 1);
        rot.set(0, 0, 0, 1);
    }
	
    bool Transform::isIdentity() {
        return translation.x == 0.0f && translation.y == 0.0f && translation.z == 0.0f
                && scale.x == 1.0f && scale.y == 1.0f && scale.z == 1.0f
                && rot.w == 1.0f && rot.x == 0.0f && rot.y == 0.0f && rot.z == 0.0f;
    }
    // int Transform::hashCode() {
        // int hash = 7;
        // hash = 89 * hash + rot.hashCode();
        // hash = 89 * hash + translation.hashCode();
        // hash = 89 * hash + scale.hashCode();
        // return hash;
    // }
	
    bool Transform::equal(cppObject *obj) {
        if (obj == nullptr) {
            return false;
        }
        if (this->getClass() != obj->getClass()) {
            return false;
        }
        Transform* other = (Transform*) obj;
        return this->translation.equal(&other->translation)
                && this->scale.equal(&other->scale)
                && this->rot.equal(&other->rot);
    }
	
	String Transform::toString(){
        return String("Transform[ ") + translation.x + ", " + translation.y + ", " + translation.z + "]\n"
                                          + "[ " + rot.x + ", " + rot.y + ", " + rot.z + ", " + rot.w + "]\n"
                                          + "[ " + scale.x + " , " + scale.y + ", " + scale.z + "]";
    }
	
    Transform Transform::set(Transform matrixQuat) {
        this->translation.set(matrixQuat.translation);
        this->rot.set(matrixQuat.rot);
        this->scale.set(matrixQuat.scale);
        return *this;
	}
	/*
    void Transform::write(JmeExporter e){
        OutputCapsule capsule = e.getCapsule(this);
        capsule.write(rot, "rot", Quaternion.IDENTITY);
        capsule.write(translation, "translation", Vector3f.ZERO);
        capsule.write(scale, "scale", Vector3f.UNIT_XYZ);
    }
	
    void Transform::read(JmeImporter e){
        InputCapsule capsule = e.getCapsule(this);
        
        rot.set((Quaternion)capsule.readSavable("rot", Quaternion.IDENTITY));
        translation.set((Vector3f)capsule.readSavable("translation", Vector3f.ZERO));
        scale.set((Vector3f)capsule.readSavable("scale", Vector3f.UNIT_XYZ));
    }*/
	
	Transform* Transform::clone() {
		return new Transform(*this);
    }
	cppObjectClass* Transform::getClass(){
		return Class<Transform>::classType;
	}
	bool Transform::instanceof(cppObjectClass* cls){
		return cls == Class<Transform>::classType || cppObject::instanceof(cls);
	}
	
	void Transform::operator=(const Transform& t){
        this->translation = t.translation;
        this->rot = t.rot;
        this->scale = t.scale;
	}
	
#endif 