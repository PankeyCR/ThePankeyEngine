
#ifndef Vector3f_h
#define Vector3f_h

#include "Arduino.h"
#include "cppObject.h"

namespace ame{

class Vector3f : public cppObject{
    private:
	
    public:
		const static Vector3f* ZERO;
		// const static Vector3f* NAN;
		const static Vector3f* UNIT_X;
		const static Vector3f* UNIT_Y;
		const static Vector3f* UNIT_Z;
		const static Vector3f* UNIT_XYZ;
		const static Vector3f* POSITIVE_INFINITY;
		const static Vector3f* NEGATIVE_INFINITY;
		
        float x;
        float y; 
        float z;  
		
		Vector3f();
		Vector3f(const Vector3f& v);
		Vector3f(float nx, float ny, float nz); 
		
		Vector3f set(float xx, float yy, float zz);
		Vector3f set(Vector3f vect);
		
		Vector3f add(float r);
		Vector3f add(Vector3f r,Vector3f a);
		Vector3f add(Vector3f r);
		Vector3f add(float xx,float yy,float zz);
		
		Vector3f addLocal(float r);
		Vector3f addLocal(Vector3f r,Vector3f a);
		Vector3f addLocal(Vector3f r);
		Vector3f addLocal(float xx,float yy,float zz);
		
		Vector3f scaleAdd(float scalar, Vector3f add);
		Vector3f scaleAdd(float scalar, Vector3f mult, Vector3f add);
		
		Vector3f scaleAddLocal(float scalar, Vector3f add);
		Vector3f scaleAddLocal(float scalar, Vector3f mult, Vector3f add);
		
		float dot(Vector3f r);
		
		Vector3f cross(Vector3f v);
		Vector3f cross(float otherX, float otherY, float otherZ);
		
		Vector3f crossLocal(Vector3f v);
		Vector3f crossLocal(float otherX, float otherY, float otherZ);
		
		Vector3f project(Vector3f other);
		Vector3f projectLocal(Vector3f other);
		
		boolean isUnitVector();
		
		float length();
		float lengthSquared();
		
		float distanceSquared(Vector3f v);
		float distanceSquared(float xx, float yy, float zz);
		float distance(Vector3f v);
		float distance(float xx, float yy, float zz);
		
		Vector3f multLocal(float scalar);
		Vector3f multLocal(Vector3f vec);
		Vector3f multLocal(float xx, float yy, float zz);
		
		Vector3f mult(float scalar);
		Vector3f mult(Vector3f vec);
		Vector3f mult(float xx, float yy, float zz);
		
		Vector3f divide(float scalar);
		Vector3f divide(Vector3f scalar);
		Vector3f divide(float xx, float yy, float zz);
		
		Vector3f divideLocal(float scalar);
		Vector3f divideLocal(Vector3f scalar);
		Vector3f divideLocal(float xx, float yy, float zz);
		
		Vector3f negateLocal();
		
		Vector3f subtract(float scalar);
		Vector3f subtract(Vector3f vec);
		Vector3f subtract(float subtractX, float subtractY, float subtractZ);
		
		Vector3f subtractLocal(float scalar);
		Vector3f subtractLocal(Vector3f vec);
		Vector3f subtractLocal(float subtractX, float subtractY, float subtractZ);
		
		Vector3f normalize();
		Vector3f normalizeLocal();
		
		Vector3f maxLocal(Vector3f other);
		Vector3f minLocal(Vector3f other);
		
		Vector3f zero();
		
		float angleBetween(Vector3f otherVector);
		Vector3f interpolateLocal(Vector3f finalVec, float changeAmnt);
		Vector3f interpolateLocal(Vector3f beginVec,Vector3f finalVec, float changeAmnt);
		static bool isValidVector(Vector3f vector);
		static void generateOrthonormalBasis(Vector3f *u, Vector3f *v, Vector3f *w);
		static void generateComplementBasis(Vector3f *u, Vector3f *v, Vector3f *w);
		
		Vector3f *clone();
		boolean equals(cppObject *o);
		
		float getX();
		Vector3f setX(float xx);
		float getY();
		Vector3f setY(float yy);
		float getZ();
		Vector3f setZ(float zz);
		float get(int index);
		void set(int index, float value);
		
		Vector3f rotate(Vector3f axis, float angle);
		Vector3f rotateX(float angle);
		Vector3f rotateY(float angle);
		Vector3f rotateZ(float angle);
		
		Vector3f rotateLocal(Vector3f axis, float angle);
		Vector3f rotateLocalX(float angle);
		Vector3f rotateLocalY(float angle);
		Vector3f rotateLocalZ(float angle);
		
		String toString();
		cppObjectClass* getClass();
		
		void operator=(const Vector3f& a);
		Vector3f operator=(const float& a);
		Vector3f operator=(const int& a);
		Vector3f operator=(const double& a);
		bool operator==(const Vector3f& a);
		bool operator!=(const Vector3f& a);
		Vector3f operator+(const Vector3f& a);
		Vector3f operator+(const float& a);
		Vector3f operator+(const int& a);
		Vector3f operator+(const double& a);
		Vector3f operator-(const Vector3f& a);
		Vector3f operator-(const float& a);
		Vector3f operator-(const int& a);
		Vector3f operator-(const double& a);
		Vector3f operator*(const Vector3f& a);
		Vector3f operator*(const float& a);
		Vector3f operator*(const int& a);
		Vector3f operator*(const double& a);
		Vector3f operator/(const Vector3f& a);
		Vector3f operator/(const float& a);
		Vector3f operator/(const int& a);
		Vector3f operator/(const double& a);
		
		Vector3f operator+=(const Vector3f& a);
		Vector3f operator+=(const float& a);
		Vector3f operator+=(const int& a);
		Vector3f operator+=(const double& a);
		Vector3f operator-=(const Vector3f& a);
		Vector3f operator-=(const float& a);
		Vector3f operator-=(const int& a);
		Vector3f operator-=(const double& a);
		Vector3f operator*=(const Vector3f& a);
		Vector3f operator*=(const float& a);
		Vector3f operator*=(const int& a);
		Vector3f operator*=(const double& a);
		Vector3f operator/=(const Vector3f& a);
		Vector3f operator/=(const float& a);
		Vector3f operator/=(const int& a);
		Vector3f operator/=(const double& a);
};

}


#endif 
