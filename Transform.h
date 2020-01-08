
#ifndef Transform_h
#define Transform_h

#include "Arduino.h"
#include "Quaternion.h"
#include "Vector3f.h"
#include "Matrix4f.h"
#include "cppObject.h"

class Transform : public cppObject{
    private: 
    public:	
	/*
		Quaternion rot = Quaternion();
		Vector3f translation = Vector3f();
		Vector3f scale = Vector3f(1, 1, 1);
		
		static Transform *IDENTITY;

		Transform(Vector3f translation, Quaternion rot);
		Transform(Vector3f translation, Quaternion rot, Vector3f scale);
		Transform(Vector3f translation);
		Transform(Quaternion rot);
		Transform(Transform *t);
		Transform();
		Transform setRotation(Quaternion rot);
		Transform setTranslation(Vector3f trans);
		Vector3f getTranslation();
		Transform setScale(Vector3f scale);
		Transform setScale(float scale);
		Vector3f getScale();
		Vector3f getTranslation(Vector3f trans);
		Quaternion getRotation(Quaternion quat);
		Quaternion getRotation();
		Vector3f getScale(Vector3f scale);
		void interpolateTransforms(Transform t1, Transform t2, float delta);
		Transform combineWithParent(Transform parent);
		Transform setTranslation(float x,float y, float z);
		Transform setScale(float x, float y, float z);
		Vector3f transformVector(final Vector3f in, Vector3f store);
		Vector3f transformInverseVector(final Vector3f in, Vector3f store);
		Matrix4f toTransformMatrix();
		Matrix4f toTransformMatrix(Matrix4f store);
		//void fromTransformMatrix(Matrix4f mat);
		//Transform invert();
		void loadIdentity();
		bool isIdentity();
		int hashCode;
		bool equals(Object *obj);
		String toString();
		Transform set(Transform matrixQuat);
	//	void write(JmeExporter e);
	//	void read(JmeImporter e);
		Transform *clone();
		
		*/
};
#endif 
