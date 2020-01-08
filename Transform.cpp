
#include "Arduino.h"
#include "Transform.h"
/*

    static Transform *IDENTITY = new Transform();


    Transform::Transform(Vector3f translation, Quaternion rot){
        this->translation = translation;
        this->rot = rot;
    }
    
    Transform::Transform(Vector3f translation, Quaternion rot, Vector3f scale){
        this(translation, rot);
        this.scale = scale;
    }

    Transform::Transform(Vector3f translation){
        this(translation, *Quaternion::IDENTITY);
    }

    Transform::Transform(Quaternion rot){
        this(*Vector3f->ZERO, rot);
    }

    Transform::Transform(){
        this(*Vector3f->ZERO, *Quaternion->IDENTITY);
    }

    Transform::Transform(Transform *t){
        this(t->translation, t->rot);
    }
	
    Transform Transform::setRotation(Quaternion rot) {
        this->rot = rot;
        return Transform(this);
    }
	
    Transform Transform::setTranslation(Vector3f trans) {
        this->translation = trans;
        return Transform(this);
    }
	
    Vector3f Transform::getTranslation() {
        return translation;
    }
	
    Transform Transform::setScale(Vector3f scale) {
        this->scale = scale;
        return Transform(this);
    }
	
    Transform Transform::setScale(float scale) {
        this->scale = scale;
        return Transform(this);
    }
	
    Vector3f Transform::getScale() {
        return scale;
    }
	
    Vector3f Transform::getTranslation(Vector3f *trans) {
        if (trans== NULL){
			trans=new Vector3f();
		}
        trans->set(this->translation);
        return Vector3f(trans);
    }
	
    Quaternion Transform::getRotation(Quaternion *quat) {
        if (quat== NULL){
			quat=new Quaternion();
		}
        quat->set(this->rot);
        return Quaternion(quat);
    }
	
    Quaternion Transform::getRotation() {
        return rot;
    }
	
    Vector3f Transform::getScale(Vector3f *scale) {
        if (scale== NULL){
			scale = new Vector3f();
		}
        scale->set(this->scale);
        return Vector3f(scale);
    }
	
    void Transform::interpolateTransforms(Transform t1, Transform t2, float delta) {
        t1.rot.nlerp(t2.rot, delta);
        this->rot.set(t1.rot);
        this->translation.interpolateLocal(t1.translation,t2.translation,delta);
        this->scale.interpolateLocal(t1.scale,t2.scale,delta);
    }
	
    Transform Transform::combineWithParent(Transform parent) {
        
		scale.multLocal(parent.scale);
        
		parent.rot.mult(rot, rot);
        
		translation.multLocal(parent.scale);
        
		parent
            .rot
            .multLocal(translation)
            .addLocal(parent.translation);

        return Transform(this);
    }
	
    Transform Transform::setTranslation(float x,float y, float z) {
        translation.set(x,y,z);
        return Transform(this);
    }
	
    Transform Transform::setScale(float x, float y, float z) {
        scale.set(x,y,z);
        return Transform(this);
    }

    Vector3f Transform::transformVector(final Vector3f in, Vector3f store){
        if (store == null)
            store = new Vector3f();

        return rot.mult(store.set(in).multLocal(scale), store).addLocal(translation);
    }

    Vector3f Transform::transformInverseVector(final Vector3f in, Vector3f store){
        if (store == null)
            store = new Vector3f();
		
        in.subtract(translation, store);
        rot.inverse().mult(store, store);
        store.divideLocal(scale);

        return store;
    }

    Matrix4f Transform::toTransformMatrix() {
        Matrix4f store();
        store.setTranslation(translation);
        rot.toTransformMatrix(store);
        store.setScale(scale);
        return Matrix4f(store);
    }

    Matrix4f Transform::toTransformMatrix(Matrix4f *store) {
        if (store == NULL) {
            store = new Matrix4f();
        }
        store->setTranslation(translation);
        rot.toTransformMatrix(store);
        store->setScale(scale);
        return Matrix4f(store);
    }
    
   /* void Transform::fromTransformMatrix(Matrix4f mat) {
        TempVars vars = TempVars.get();
        translation.set(mat.toTranslationVector(vars.vect1));
        rot.set(mat.toRotationQuat(vars.quat1));
        scale.set(mat.toScaleVector(vars.vect2));
        vars.release();
    }
    
    Transform Transform::invert() {
        Transform t = new Transform();
        t.fromTransformMatrix(toTransformMatrix().invertLocal());
        return t;
    }*/
	/*
    void Transform::loadIdentity() {
        translation.set(0, 0, 0);
        scale.set(1, 1, 1);
        rot.set(0, 0, 0, 1);
    }
	
    bool Transform::isIdentity() {
        return translation.x == 0f && translation.y == 0f && translation.z == 0f
                && scale.x == 1f && scale.y == 1f && scale.z == 1f
                && rot.w == 1f && rot.x == 0f && rot.y == 0f && rot.z == 0f;
    }
	*/
  /*  int Transform::hashCode() {
        int hash = 7;
        hash = 89 * hash + rot.hashCode();
        hash = 89 * hash + translation.hashCode();
        hash = 89 * hash + scale.hashCode();
        return hash;
    }*/
	/*
    bool equals(cppObject *obj) {
        if (obj == NULL) {
            return false;
        }
        if (getClassName() != obj->getClassName()) {
            return false;
        }
        Transform *other = (*Transform) obj;
        return this->translation.equals(&other->translation)
                && this->scale.equals(&other->scale)
                && this->rot.equals(&other->rot);
    }
	
	String Transform::toString(){
        return getClassName() + "[ " + translation.x + ", " + translation.y + ", " + translation.z + "]\n"
                                          + "[ " + rot.x + ", " + rot.y + ", " + rot.z + ", " + rot.w + "]\n"
                                          + "[ " + scale.x + " , " + scale.y + ", " + scale.z + "]";
    }
	
    Transform Transform::set(Transform matrixQuat) {
        this->translation.set(matrixQuat.translation);
        this->rot.set(matrixQuat.rot);
        this->scale.set(matrixQuat.scale);
        return 
	}
	*/
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
	/*
	Transform *Transform::clone() {
		return new Transform(this);
    }
	
	*/
	