
#ifndef Transform_hpp
#define Transform_hpp

#include "Quaternion.hpp"
#include "Vector3f.hpp"
#include "Matrix4f.hpp"
#include "cppObject.hpp"
#include "cppObjectClass.hpp"

namespace higgs{

class Transform : public cppObject{
    public:
		const static Transform *IDENTITY;

		Transform(){
			this->translation = *Vector3f::ZERO;
			// this->rot = *Quaternion::IDENTITY;
		}

		Transform(const Transform& t){
			this->translation = t.translation;
			this->rot = t.rot;
			this->scale = t.scale;
		}
		
		Transform(Vector3f translation, Quaternion rot){
			this->translation = translation;
			this->rot = rot;
		}
		
		Transform(Vector3f translation, Quaternion rot, Vector3f scale){
			this->translation = translation;
			this->rot = rot;
			this->scale = scale;
		}

		Transform(Vector3f translation){
			this->translation = translation;
			// this->rot = *Quaternion::IDENTITY;
		}

		Transform(Quaternion rot){
			this->translation = *Vector3f::ZERO;
			this->rot = rot;
		}
		
		
		Transform setRotation(Quaternion rot){
			this->rot = rot;
			return *this;
		}
		
		Quaternion getRotation(){
			return this->rot;
		}
		
		
		Transform setTranslation(float x,float y, float z){
			this->translation.set(x,y,z);
			return *this;
		}
		
		Transform setTranslation(Vector3f trans){
			this->translation = trans;
			return *this;
		}
		
		Vector3f getTranslation(){
			return this->translation;
		}
		
		
		Transform setScale(float x, float y, float z){
			this->scale.set(x,y,z);
			return *this;
		}
		
		Transform setScale(Vector3f scale){
			this->scale = scale;
			return *this;
		}
		
		Transform setScale(float scale){
			this->scale = scale;
			return *this;
		}
		
		Vector3f getScale(){
			return this->scale;
		}
		
		
		void interpolateTransforms(Transform t1, Transform t2, float delta){
			t1.rot.nlerp(t2.rot, delta);
			this->rot.set(t1.rot);
			this->translation.interpolateLocal(t1.translation,t2.translation,delta);
			this->scale.interpolateLocal(t1.scale,t2.scale,delta);
		}
		
		Transform combineWithParent(Transform parent){
			
			scale.multLocal(parent.scale);
			
			rot = parent.rot.mult(rot);
			
			translation.multLocal(parent.scale);
			
			parent
				.rot
				.multLocal(translation)
				.addLocal(parent.translation);

			return parent;
		}

		Vector3f transformVector(Vector3f in, Vector3f store){
			store = rot.mult(store.set(in).multLocal(scale));
			store.addLocal(translation);
			return store;
		}

		Vector3f transformInverseVector(Vector3f in, Vector3f store){
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
		// Matrix4f toTransformMatrix();
		// Matrix4f toTransformMatrix(Matrix4f store);
		//void fromTransformMatrix(Matrix4f mat);
		
		// Transform invert();
		void loadIdentity(){
			translation.set(0, 0, 0);
			scale.set(1, 1, 1);
			rot.set(0, 0, 0, 1);
		}
		
		bool isIdentity(){
			return translation.x == 0.0f && translation.y == 0.0f && translation.z == 0.0f
					&& scale.x == 1.0f && scale.y == 1.0f && scale.z == 1.0f
					&& rot.w == 1.0f && rot.x == 0.0f && rot.y == 0.0f && rot.z == 0.0f;
		}
		// int ame::Transform::hashCode() {
			// int hash = 7;
			// hash = 89 * hash + rot.hppashCode();
			// hash = 89 * hash + translation.hppashCode();
			// hash = 89 * hash + scale.hppashCode();
			// return hash;
		// }
		bool equal(cppObject* obj){
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
		
		Note toNote(){
			return Note("ame::Transform[ ") + translation.x + ", " + translation.y + ", " + translation.z + "]\n"
											  + "[ " + rot.x + ", " + rot.y + ", " + rot.z + ", " + rot.w + "]\n"
											  + "[ " + scale.x + " , " + scale.y + ", " + scale.z + "]";
		}
		
		Transform set(Transform matrixQuat){
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
	//	void write(JmeExporter e);
	//	void read(JmeImporter e);
		Transform* clone(){
			return new Transform(*this);
		}
		
		bool instanceof(cppObjectClass* cls){
			return cls == Class<Transform>::classType || cppObject::instanceof(cls);
		}
		
		cppObjectClass* getClass(){
			return Class<Transform>::classType;
		}
		
		
		virtual void operator=(const Transform& t){
			this->translation = t.translation;
			this->rot = t.rot;
			this->scale = t.scale;
		}
		// virtual void operator=(const Vector3f& t);
		// virtual void operator=(const Quaternion& t);
	protected:
		Quaternion rot;
		Vector3f translation;
		Vector3f scale = *Vector3f::UNIT_XYZ;
};

}

const ame::Transform* ame::Transform::IDENTITY = new ame::Transform();

#endif