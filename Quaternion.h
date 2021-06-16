
#ifndef Quaternion_h
#define Quaternion_h

#include "FastMonkeyMath.h"
#include "cppObject.h"
#include "List.h"
#include "Matrix3f.h"
#include "Matrix4f.h"


class Quaternion : public cppObject{	
    private:
		
    public:
		const static Quaternion* IDENTITY;
    	const static Quaternion* DIRECTION_Z;
    	const static Quaternion* ZERO;
	
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        float w = 1.0f;
		
		Quaternion();
		Quaternion(const Quaternion& q);
		Quaternion(float x, float y, float z, float w);
		Quaternion(List<float> *angles);
		
		float getX();
		float getY();
		float getZ();
		float getW();
		
		Quaternion set(float x, float y, float z, float w);
		Quaternion set(Quaternion q);
		
		void loadIdentity();
		bool isIdentity();
		
		Quaternion fromAngles(List<float> *angles);
		Quaternion fromAngles(float xAngle, float yAngle, float zAngle);
		
		Quaternion fromAnglesLocal(List<float> *angles);
		Quaternion fromAnglesLocal(float xAngle, float yAngle, float zAngle);
		
		List<float> *toAngles(List<float> *angles);
		
		Quaternion fromRotationMatrix(Matrix3f matrix);
		Quaternion fromRotationMatrix(float m00, float m01, float m02,
            float m10, float m11, float m12, float m20, float m21, float m22);
		
		Quaternion fromRotationMatrixLocal(Matrix3f matrix);
		Quaternion fromRotationMatrixLocal(float m00, float m01, float m02,
            float m10, float m11, float m12, float m20, float m21, float m22);
		
		Matrix3f toRotationMatrix3f();
		
		Matrix4f toTransformMatrix4f();
		Matrix4f toRotationMatrix4f();
		
		Vector3f getRotationColumn(int i);
		
		Quaternion fromAngleAxis(float angle, Vector3f axis);
		Quaternion fromAngleNormalAxis(float angle, Vector3f axis);
		
		Quaternion fromAngleAxisLocal(float angle, Vector3f axis);
		Quaternion fromAngleNormalAxisLocal(float angle, Vector3f axis);
		
		float toAngleAxis();
		Vector3f toVector3fAxis();
		
		Quaternion slerp(Quaternion q1, Quaternion q2, float t);
		Quaternion slerpLocal(Quaternion q1, Quaternion q2, float t);
		
		Quaternion slerp(Quaternion q2, float changeAmnt);
		Quaternion slerpLocal(Quaternion q2, float changeAmnt);
		
		Quaternion nlerp(Quaternion q2, float blend);
		Quaternion nlerpLocal(Quaternion q2, float blend);
		
		Quaternion add(Quaternion q);
		Quaternion add(float qx, float qy, float qz, float qw);
		
		Quaternion addLocal(Quaternion q);
		Quaternion addLocal(float qx, float qy, float qz, float qw);
		
		Quaternion subtract(Quaternion q);
		Quaternion subtract(float qx, float qy, float qz, float qw);
		
		Quaternion subtractLocal(Quaternion q);
		Quaternion subtractLocal(float qx, float qy, float qz, float qw);
		
		Quaternion mult(Quaternion q);
		Quaternion mult(float qx, float qy, float qz, float qw);
		
		Quaternion apply(Matrix3f matrix);
		Quaternion applyLocal(Matrix3f matrix);
		
		Quaternion fromAxes(List<Vector3f> *axis);
		Quaternion fromAxes(Vector3f xAxis, Vector3f yAxis, Vector3f zAxis);
		
		Quaternion fromAxesLocal(List<Vector3f> *axis);
		Quaternion fromAxesLocal(Vector3f xAxis, Vector3f yAxis, Vector3f zAxis);
		
		List<Vector3f> *toAxes(List<Vector3f> *axis);
		
		Vector3f mult(Vector3f v);
		
		Vector3f multLocal(Vector3f v);
		
		Quaternion multLocal(Quaternion q);
		Quaternion multLocal(float qx, float qy, float qz, float qw);
		
		Quaternion mult(float scalar);
		
		Quaternion multLocal(float scalar);
		
		float dot(Quaternion q);
		float norm();
		Quaternion normalize();
		Quaternion normalizeLocal();
		Quaternion inverse();
		Quaternion inverseLocal();
		Quaternion negate();
		Quaternion negateLocal();
		
		bool isSimilar(Quaternion other, float epsilon);
	//	void readExternal(ObjectInput in);
	//	void writeExternal(ObjectOutput out);
		void lookAt(Vector3f direction, Vector3f up);
	//	void write(JmeExporter e);
	//	void read(JmeImporter e);
		Quaternion opposite();
		Quaternion opposite(Quaternion store);
		Quaternion oppositeLocal();
		
		String toString();
		cppObjectClass* getClass();
		bool equals(cppObject *o);
		Quaternion* clone();
		
		
		void operator=(const Quaternion& a);
		Quaternion operator=(const float a[4]);
		Quaternion operator=(const int& a);
		bool operator==(const Quaternion& a);
		bool operator!=(const Quaternion& a);
		Quaternion operator+(const Quaternion& a);
		Quaternion operator+(const float a[4]);
		Quaternion operator-(const Quaternion& a);
		Quaternion operator-(const float a[4]);
		Quaternion operator*(const Quaternion& a);
		Quaternion operator*(const float a[4]);
		// Quaternion operator/(const Quaternion& a);
		// Quaternion operator/(const float [4]);
		Quaternion operator/(const int a);
		
		Quaternion operator+=(const Quaternion& a);
		Quaternion operator+=(const float a[4]);
		Quaternion operator-=(const Quaternion& a);
		Quaternion operator-=(const float a[4]);
		Quaternion operator*=(const Quaternion& q);
		Quaternion operator*=(const float a[4]);
		// Quaternion operator/=(const Quaternion& a);
		// Quaternion operator/=(const float [4]);
		
};
#endif 
