
#ifndef Transform_h
#define Transform_h

#include "Arduino.h"
#include "Quaternion.h"
#include "Vector3f.h"
#include "Matrix4f.h"
#include "cppObject.h"
#include "cppObjectClass.h"

class Transform : public cppObject{
    public:
		const static Transform *IDENTITY;

		Transform();
		Transform(const Transform& t);
		Transform(Vector3f translation, Quaternion rot);
		Transform(Vector3f translation, Quaternion rot, Vector3f scale);
		Transform(Vector3f translation);
		Transform(Quaternion rot);
		
		Transform setRotation(Quaternion rot);
		Quaternion getRotation();
		
		Transform setTranslation(float x,float y, float z);
		Transform setTranslation(Vector3f trans);
		Vector3f getTranslation();
		
		Transform setScale(float x, float y, float z);
		Transform setScale(Vector3f scale);
		Transform setScale(float scale);
		Vector3f getScale();
		
		void interpolateTransforms(Transform t1, Transform t2, float delta);
		Transform combineWithParent(Transform parent);
		Vector3f transformVector(Vector3f in, Vector3f store);
		Vector3f transformInverseVector(Vector3f in, Vector3f store);
		
		// Matrix4f toTransformMatrix();
		// Matrix4f toTransformMatrix(Matrix4f store);
		//void fromTransformMatrix(Matrix4f mat);
		
		// Transform invert();
		void loadIdentity();
		bool isIdentity();
		bool equal(cppObject* obj);
		String toString();
		Transform set(Transform matrixQuat);
	//	void write(JmeExporter e);
	//	void read(JmeImporter e);
		Transform* clone();
		bool instanceof(cppObjectClass* cls);
		cppObjectClass* getClass();
		
		virtual void operator=(const Transform& t);
		// virtual void operator=(const Vector3f& t);
		// virtual void operator=(const Quaternion& t);
	protected:
		Quaternion rot;
		Vector3f translation;
		Vector3f scale = *Vector3f::UNIT_XYZ;
};
#endif 
