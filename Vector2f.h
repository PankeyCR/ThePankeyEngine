
#ifndef Vector2f_h
#define Vector2f_h

#include "Arduino.h"
#include "Vector3f.h"
#include "List.h"
#include "cppObject.h"

namespace ame{
	
class Vector2f : public cppObject{
    private:
	
    public:
 
    static Vector2f *ZERO;
    static Vector2f *UNIT_XY;
    
    float x;
    float y;

    Vector2f(float xx, float yy);
    Vector2f();
    Vector2f(const Vector2f& v);
	
    Vector2f set(float x, float y);
    Vector2f set(Vector2f vec);
	
    Vector2f add(float scalar);
    Vector2f add(Vector2f vec);
    Vector2f add(float addX, float addY);
	
    Vector2f addLocal(Vector2f vec);
    Vector2f addLocal(float addX, float addY);
    Vector2f addLocal(float scalar);
	
    float dot(Vector2f vec);
    Vector3f cross(Vector2f v);
    float determinant(Vector2f v);
    float determinant(float XX, float YY);
    Vector2f interpolateLocal(Vector2f finalVec, float changeAmnt);
    Vector2f interpolateLocal(Vector2f beginVec, Vector2f finalVec,
            float changeAmnt);
    static bool isValidVector(Vector2f vector);
    float length();
    float lengthSquared();
    float distanceSquared(Vector2f v);
    float distanceSquared(float otherX, float otherY);
    float distance(Vector2f v);
    float distance(float XX, float YY);
	
    Vector2f mult(float scalar);
    Vector2f mult(Vector2f vec);
    Vector2f mult(float mulX, float mulY);
	
    Vector2f multLocal(float scalar);
    Vector2f multLocal(Vector2f vec);
    Vector2f multLocal(float mulX, float mulY);
	
    Vector2f divide(float scalar);
    Vector2f divide(float XX, float YY);
    Vector2f divide(Vector2f vec);
	
    Vector2f divideLocal(float scalar);
    Vector2f divideLocal(Vector2f vec);
    Vector2f divideLocal(float XX, float YY);
	
    Vector2f negate();
    Vector2f negateLocal();
	
    Vector2f subtract(Vector2f vec);
    Vector2f subtract(float scalar);
    Vector2f subtract(float valX, float valY);
	
    Vector2f subtractLocal(float scalar);
    Vector2f subtractLocal(Vector2f vec);
    Vector2f subtractLocal(float valX, float valY);
	
    Vector2f normalize();
    Vector2f normalizeLocal();
	
    float smallestAngleBetween(Vector2f otherVector);
    float angleBetween(Vector2f otherVector);
    float getX();
    Vector2f setX(float xx);
    float getY();
    Vector2f setY(float yy);
    float getAngle();
    Vector2f zero();
    Vector2f *clone();
    List<float> *toArray(List<float> *floats);
    bool equals(cppObject *o);
    String toString();
    //void readExternal(ObjectInput in);
    //void writeExternal(ObjectOutput out);
   // void write(JmeExporter e);
  //  void read(JmeImporter e);
    Vector2f rotateAroundOrigin(float angle, bool cw);
    Vector2f rotateAroundOriginLocal(float angle, bool cw);
	Vector2f rotate(float angle);
	Vector2f rotateLocal(float angle);
	cppObjectClass* getClass();
	
	Vector2f operator=(const Vector2f& a);
	Vector2f operator=(const float& a);
	Vector2f operator=(const float a[2]);
	Vector2f operator=(const int& a);
	Vector2f operator=(const double& a);
	bool operator==(const Vector2f& a);
	bool operator!=(const Vector2f& a);
	Vector2f operator+(const Vector2f& a);
	Vector2f operator+(const float& a);
	Vector2f operator+(const int& a);
	Vector2f operator+(const double& a);
	Vector2f operator-(const Vector2f& a);
	Vector2f operator-(const float& a);
	Vector2f operator-(const int& a);
	Vector2f operator-(const double& a);
	Vector2f operator*(const Vector2f& a);
	Vector2f operator*(const float& a);
	Vector2f operator*(const int& a);
	Vector2f operator*(const double& a);
	Vector2f operator/(const Vector2f& a);
	Vector2f operator/(const float& a);
	Vector2f operator/(const int& a);
	Vector2f operator/(const double& a);
	
	Vector2f operator+=(const Vector2f& a);
	Vector2f operator+=(const float& a);
	Vector2f operator+=(const int& a);
	Vector2f operator+=(const double& a);
	Vector2f operator-=(const Vector2f& a);
	Vector2f operator-=(const float& a);
	Vector2f operator-=(const int& a);
	Vector2f operator-=(const double& a);
	Vector2f operator*=(const Vector2f& a);
	Vector2f operator*=(const float& a);
	Vector2f operator*=(const int& a);
	Vector2f operator*=(const double& a);
	Vector2f operator/=(const Vector2f& a);
	Vector2f operator/=(const float& a);
	Vector2f operator/=(const int& a);
	Vector2f operator/=(const double& a);
};

}


#endif
