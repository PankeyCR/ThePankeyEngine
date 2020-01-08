
#ifndef Vector4f_h
#define Vector4f_h

#include "FastMath.h"
#include "ArrayList.h"
#include "cppObject.h"

class Vector4f : public cppObject{
    private:
	
    public:
        float x;
        float y; 
        float z;
        float w;
		
		static Vector4f *ZERO;
	//	static Vector4f *NAN;
		static Vector4f *UNIT_X;
		static Vector4f *UNIT_Y;
		static Vector4f *UNIT_Z;
		static Vector4f *UNIT_W;
		static Vector4f *UNIT_XYZW;
	
		Vector4f();
		Vector4f(float x, float y, float z, float w);
		
		Vector4f set(float x, float y, float z, float w);
		Vector4f set(Vector4f vect);
		
		Vector4f add(Vector4f vec);
		Vector4f add(float addX, float addY, float addZ, float addW);
		
		Vector4f addLocal(Vector4f vec);
		Vector4f addLocal(float addX, float addY, float addZ, float addW);
		
		Vector4f scaleAdd(float scalar, Vector4f add);
		Vector4f scaleAdd(float scalar, Vector4f mult, Vector4f add);
		
		Vector4f scaleAddLocal(float scalar, Vector4f add);
		Vector4f scaleAddLocal(float scalar, Vector4f mult, Vector4f add);
		
		float dot(Vector4f vec);
		Vector4f project(Vector4f other);
		bool isUnitVector();
		
		float length();
		float lengthSquared();
		
		float distanceSquared(Vector4f v);
		float distance(Vector4f v);
		
		Vector4f mult(float scalar);
		Vector4f mult(Vector4f vec);
		Vector4f mult(float xx, float xy, float xz, float xw);
		
		Vector4f multLocal(float scalar);
		Vector4f multLocal(Vector4f vec);
		Vector4f multLocal(float xx, float xy, float xz, float xw);
		
		Vector4f divide(float scalar);
		Vector4f divide(Vector4f scalar);
		Vector4f divide(float x, float y, float z, float w);
		
		Vector4f divideLocal(float scalar);
		Vector4f divideLocal(Vector4f scalar);
		Vector4f divideLocal(float x, float y, float z, float w);
		
		Vector4f negate();
		Vector4f negateLocal();
		
		Vector4f subtract(Vector4f vec);
		Vector4f subtract(float subtractX, float subtractY, 
							 float subtractZ, float subtractW);
							 
		Vector4f subtractLocal(Vector4f vec);
		Vector4f subtractLocal(float subtractX, 
				float subtractY, float subtractZ, float subtractW);
				
		Vector4f normalize();
		Vector4f normalizeLocal();
		
		Vector4f maxLocal(Vector4f other);
		Vector4f minLocal(Vector4f other);
		
		Vector4f zero();
		float angleBetween(Vector4f otherVector);
		Vector4f interpolateLocal(Vector4f finalVec, float changeAmnt);
		Vector4f interpolateLocal(Vector4f beginVec,
						Vector4f finalVec, float changeAmnt);       
		static bool isValidVector(Vector4f vector);
		Vector4f *clone();
		List<float> *toArray(List<float> *floats);
		
		bool equals(cppObject *o);
		bool isSimilar(Vector4f other, float epsilon);
		String toString();
	//	void write(JmeExporter e);
	//	void read(JmeImporter e);
		float getX();
		Vector4f setX(float x);
		float getY();
		Vector4f setY(float y);
		float getZ();
		Vector4f setZ(float z);
		float getW();
		Vector4f setW(float w);
		float get(int index);
		void set(int index, float value);
		
		Vector4f operator=(const Vector4f& a);
		Vector4f operator=(const float& a);
		Vector4f operator=(const int& a);
		Vector4f operator=(const double& a);
		Vector4f operator=(const float a[4]);
		bool operator==(const Vector4f& a);
		bool operator!=(const Vector4f& a);
		Vector4f operator+(const Vector4f& a);
		Vector4f operator+(const float& a);
		Vector4f operator+(const int& a);
		Vector4f operator+(const double& a);
		Vector4f operator-(const Vector4f& a);
		Vector4f operator-(const float& a);
		Vector4f operator-(const int& a);
		Vector4f operator-(const double& a);
		Vector4f operator*(const Vector4f& a);
		Vector4f operator*(const float& a);
		Vector4f operator*(const int& a);
		Vector4f operator*(const double& a);
		Vector4f operator/(const Vector4f& a);
		Vector4f operator/(const float& a);
		Vector4f operator/(const int& a);
		Vector4f operator/(const double& a);
		
		Vector4f operator+=(const Vector4f& a);
		Vector4f operator+=(const float& a);
		Vector4f operator+=(const int& a);
		Vector4f operator+=(const double& a);
		Vector4f operator-=(const Vector4f& a);
		Vector4f operator-=(const float& a);
		Vector4f operator-=(const int& a);
		Vector4f operator-=(const double& a);
		Vector4f operator*=(const Vector4f& a);
		Vector4f operator*=(const float& a);
		Vector4f operator*=(const int& a);
		Vector4f operator*=(const double& a);
		Vector4f operator/=(const Vector4f& a);
		Vector4f operator/=(const float& a);
		Vector4f operator/=(const int& a);
		Vector4f operator/=(const double& a);
		
		
};


#endif 
