
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Vector3f)
	#define Vector3f_hpp
#endif

#ifndef Vector3f_hpp
#define Vector3f_hpp
#define Vector3f_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows
    #define _USE_MATH_DEFINES
    #include <cmath>
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "Class.hpp"

namespace ame{

#ifdef ame_Windows
class Vector3f : public cppObject{
#endif

#ifdef ame_ArduinoIDE
class Vector3f : public cppObject , public Printable{
#endif
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

		Vector3f(){
			x = 0;
			y = 0;
			z = 0;
		}
		Vector3f(const Vector3f& v){
			x = v.x;
			y = v.y;
			z = v.z;
		}
		Vector3f(float nx, float ny, float nz){
			x = nx;
			y = ny;
			z = nz;
		}

#ifdef ame_ArduinoIDE
		size_t printTo(Print& p) const{
			p.print(this->x);p.print(',');p.print(this->y);p.print(',');p.print(this->z);
			return 	sizeof(this->x) + sizeof(this->y) + sizeof(this->z);
		}
#endif

		Vector3f set(float xx, float yy, float zz){
			this->x = xx;
			this->y = yy;
			this->z = zz;
			return *this;
		}
		Vector3f set(Vector3f vect){
			this->x = vect.x;
			this->y = vect.y;
			this->z = vect.z;
			return *this;
		}

		Vector3f add(Vector3f r){
			return Vector3f(x + r.getX(), y + r.getY(), z + r.getZ());
		}

		Vector3f add(Vector3f r, Vector3f a){
			return Vector3f(a.getX() + r.getX(), a.getY() + r.getY(), a.getZ() + r.getZ());
		}


		Vector3f add(float r){
			return  Vector3f(this->x + r, this->y + r, this->z + r);
		}

		Vector3f add(float xx,float yy,float zz){
			return  Vector3f(this->x + xx, this->y + yy, this->z + zz);
		}

		Vector3f addLocal(float r){
			this->x += r;
			this->y += r;
			this->z += r;
			return *this;
		}

		Vector3f addLocal(Vector3f r,Vector3f a){
			this->x += ( r.getX() + a.getX() );
			this->y += ( r.getY() + a.getY() );
			this->z += ( r.getZ() + a.getZ() );
			return *this;
		}

		Vector3f addLocal(Vector3f r){
			this->x += r.getX();
			this->y += r.getY();
			this->z += r.getZ();
			return *this;
		}

		Vector3f addLocal(float xx,float yy,float zz){
			this->x += xx;
			this->y += yy;
			this->z += zz;
			return *this;
		}

		Vector3f scaleAdd(float scalar, Vector3f add) {
			float xx = this->x * scalar + add.x;
			float yy = this->y * scalar + add.y;
			float zz = this->z * scalar + add.z;
			return Vector3f(xx, yy, zz);
		}

		Vector3f scaleAdd(float scalar, Vector3f mult, Vector3f add) {
			float xx = mult.x * scalar + add.x;
			float yy = mult.y * scalar + add.y;
			float zz = mult.z * scalar + add.z;
			return Vector3f(xx, yy, zz);
		}

		Vector3f scaleAddLocal(float scalar, Vector3f add) {
			this->x = this->x * scalar + add.x;
			this->y = this->y * scalar + add.y;
			this->z = this->z * scalar + add.z;
			return *this;
		}

		Vector3f scaleAddLocal(float scalar, Vector3f mult, Vector3f add) {
			this->x = mult.x * scalar + add.x;
			this->y = mult.y * scalar + add.y;
			this->z = mult.z * scalar + add.z;
			return *this;
		}
		float dot(Vector3f r){
			return this->x * r.getX() + this->y * r.getY() + this->z * r.getZ();
		}

		Vector3f cross(Vector3f v) {
			return this->cross(v.x, v.y, v.z);
		}

		Vector3f cross(float otherX, float otherY, float otherZ) {
			float resX = ((this->y * otherZ) - (this->z * otherY));
			float resY = ((this->z * otherX) - (this->x * otherZ));
			float resZ = ((this->x * otherY) - (this->y * otherX));
			return Vector3f(resX, resY, resZ);
		}

		Vector3f crossLocal(Vector3f v) {
			return crossLocal(v.x, v.y, v.z);
		}

		Vector3f crossLocal(float otherX, float otherY, float otherZ) {
			float tempx = ( y * otherZ ) - ( z * otherY );
			float tempy = ( z * otherX ) - ( x * otherZ );
			this->z = (x * otherY) - (y * otherX);
			this->x = tempx;
			this->y = tempy;
			return *this;
		}

		Vector3f project(Vector3f other){
			float n = this->dot(other); // A . B
			float d = other.lengthSquared(); // |B|^2
			return Vector3f(other).multLocal(n/d);
		}

		Vector3f projectLocal(Vector3f other){
			float n = this->dot(other); // A . B
			float d = other.lengthSquared(); // |B|^2
			return set(other).multLocal(n/d);
		}

		bool isUnitVector(){
			float len = length();
			return 0.99f < len && len < 1.01f;
		}

		float length(){
			return (float)sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
		}

		float lengthSquared() {
			return this->x * this->x + this->y * this->y + this->z * this->z;
		}

		float distanceSquared(Vector3f v) {
			double dx = this->x - v.x;
			double dy = this->y - v.y;
			double dz = this->z - v.z;
			return (float) (dx * dx + dy * dy + dz * dz);
		}

		float distanceSquared(float xx, float yy, float zz) {
			double dx = this->x - xx;
			double dy = this->y - yy;
			double dz = this->z - zz;
			return (float) (dx * dx + dy * dy + dz * dz);
		}

		float distance(Vector3f v) {
			return (float)sqrt(distanceSquared(v));
		}

		float distance(float xx, float yy, float zz) {
			return (float)sqrt(distanceSquared(xx, yy, zz));
		}

		Vector3f multLocal(float scalar) {
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			return *this;
		}

		Vector3f multLocal(Vector3f vec) {
			this->x *= vec.x;
			this->y *= vec.y;
			this->z *= vec.z;
			return *this;
		}

		Vector3f multLocal(float xx, float yy, float zz) {
			this->x *= xx;
			this->y *= yy;
			this->z *= zz;
			return *this;
		}

		Vector3f mult(float scalar) {
			return Vector3f(this->x * scalar, this->y * scalar, this->z * scalar);
		}

		Vector3f mult(Vector3f vec) {
			return mult(vec.x, vec.y, vec.z);
		}

		Vector3f mult(float xx, float yy, float zz) {
			return Vector3f(this->x * xx, this->y * yy, this->z * zz);
		}

		Vector3f divide(float scalar) {
			scalar = 1.0f/scalar;
			return Vector3f(this->x * scalar, this->y * scalar, this->z * scalar);
		}

		Vector3f divideLocal(float scalar) {
			scalar = 1.00f/scalar;
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			return *this;
		}

		Vector3f divide(Vector3f scalar) {
			return Vector3f(this->x / scalar.x, this->y / scalar.y, this->z / scalar.z);
		}

		Vector3f divideLocal(Vector3f scalar) {
			this->x /= scalar.x;
			this->y /= scalar.y;
			this->z /= scalar.z;
			return *this;
		}

		Vector3f divide(float xx, float yy, float zz) {
			return Vector3f(this->x / xx, this->y / yy, this->z / zz);
		}

		Vector3f divideLocal(float xx, float yy, float zz) {
			this->x /= xx;
			this->y /= yy;
			this->z /= zz;
			return *this;
		}

		Vector3f negateLocal() {
			this->x = -this->x;
			this->y = -this->y;
			this->z = -this->z;
			return *this;
		}

		Vector3f subtract(float scalar) {
			return Vector3f(this->x - scalar, this->y - scalar, this->z - scalar);
		}

		Vector3f subtract(Vector3f vec) {
			return Vector3f(this->x - vec.x, this->y - vec.y, this->z - vec.z);
		}

		Vector3f subtractLocal(float scalar) {
			this->x -= scalar;
			this->y -= scalar;
			this->z -= scalar;
			return *this;
		}

		Vector3f subtractLocal(Vector3f vec) {
			this->x -= vec.x;
			this->y -= vec.y;
			this->z -= vec.z;
			return *this;
		}

		Vector3f subtract(float subtractX, float subtractY, float subtractZ) {
			return Vector3f(x - subtractX, y - subtractY, z - subtractZ);
		}

		Vector3f subtractLocal(float subtractX, float subtractY, float subtractZ) {
			this->x -= subtractX;
			this->y -= subtractY;
			this->z -= subtractZ;
			return *this;
		}

		Vector3f normalize() {
			float length = this->x * this->x + this->y * this->y + this->z * this->z;
			if (length != 1.00f && length != 0.00f){
				length = 1.00f / sqrt(length);
				return Vector3f(x * length, y * length, z * length);
			}
			return Vector3f(x,y,z);
		}

		Vector3f normalizeLocal() {
			// NOTE: this implementation is more optimized
			// than the old jme normalize as this method
			// is commonly used.
			float length = x * x + y * y + z * z;
			if (length != 1.0f && length != 0.0f){
				length = 1.0f / (float)sqrt(length);
				this->x *= length;
				this->y *= length;
				this->z *= length;
			}
			return *this;
		}

		Vector3f maxLocal(Vector3f other){
			this->x = other.x > x ? other.x : this->x;
			this->y = other.y > y ? other.y : this->y;
			this->z = other.z > z ? other.z : this->z;
			return *this;
		}

		Vector3f minLocal(Vector3f other){
			this->x = other.x < x ? other.x : this->x;
			this->y = other.y < y ? other.y : this->y;
			this->z = other.z < z ? other.z : this->z;
			return *this;
		}

		Vector3f zero() {
			this->x = this->y = this->z = 0;
			return *this;
		}

		float angleBetween(Vector3f otherVector) {
			float dotProduct = dot(otherVector);
			//float angle = 0.00f;
			float angle = acos(dotProduct);
		  //  float angle = aMath::arccos(dotProduct);//////
			return angle;
		}

		Vector3f interpolateLocal(Vector3f finalVec, float changeAmnt) {
			this->x=(1-changeAmnt)*this->x + changeAmnt*finalVec.x;
			this->y=(1-changeAmnt)*this->y + changeAmnt*finalVec.y;
			this->z=(1-changeAmnt)*this->z + changeAmnt*finalVec.z;
			return *this;
		}

		Vector3f interpolateLocal(Vector3f beginVec,Vector3f finalVec, float changeAmnt) {
			this->x=(1-changeAmnt)*beginVec.x + changeAmnt*finalVec.x;
			this->y=(1-changeAmnt)*beginVec.y + changeAmnt*finalVec.y;
			this->z=(1-changeAmnt)*beginVec.z + changeAmnt*finalVec.z;
			return *this;
		}

		bool isValidVector(Vector3f vector) {
		//  if (Float.isNaN(vector->x) ||
		//      Float.isNaN(vector->y) ||
		//      Float.isNaN(vector->z)) return false;
		//  if (Float.isInfinite(vector->x) ||
		//      Float.isInfinite(vector->y) ||
		//      Float.isInfinite(vector->z)) return false;
		  return true;
		}

		void generateOrthonormalBasis(Vector3f *u, Vector3f *v, Vector3f *w) {
			w->normalizeLocal();
			generateComplementBasis(u, v, w);
		}

		void generateComplementBasis(Vector3f *u, Vector3f *v, Vector3f *w) {
			float fInvLength;

			if (abs(w->x) >= abs(w->y)) {
				// w.x or w.z is the largest magnitude component, swap them
				fInvLength = 0;
		   //     fInvLength = aMath::invSqrt(w->x * w->x + w->z * w->z);
		 //       fInvLength = aMath::invSqrt(w->x * w->x + w->z * w->z);/////////////////////////////
				u->x = -w->z * fInvLength;
				u->y = 0.0f;
				u->z = +w->x * fInvLength;
				v->x = w->y * u->z;
				v->y = w->z * u->x - w->x * u->z;
				v->z = -w->y * u->x;
			} else {
				// w.y or w.z is the largest magnitude component, swap them
				fInvLength = 0;
		 //       fInvLength = aMath::invSqrt(w->y * w->y + w->z * w->z);
	   //         fInvLength = aMath::invSqrt(w->y * w->y + w->z * w->z);////////////////////////////////////
				u->x = 0.0f;
				u->y = +w->z * fInvLength;
				u->z = -w->y * fInvLength;
				v->x = w->y * u->z - w->z * u->y;
				v->y = -w->x * u->z;
				v->z = w->x * u->y;
			}
		}

		Vector3f *clone() {
			return new Vector3f(this->x,this->y,this->z);
		}

		bool equals(cppObject *o) {
			if (this == o) {
				return true;
			}


			if(o->getClass() != Class<Vector3f>::classType) {
				return false;
			}


			Vector3f *comp = (Vector3f*)o;
			if (comp->x != 0) {
				return false;
			}
			if (comp->y != 0) {
				return false;
			}
			if (comp->z != 0) {
				return false;
			}
			return true;
		}

		float getX(){
			return this->x;
		}

		Vector3f setX(float xx){
			this->x = xx;
			return *this;
		}

		float getY(){
			return this->y;
		}

		Vector3f setY(float yy){
			this->y = yy;
			return *this;
		}

		float getZ(){
			return this->z;
		}

		Vector3f setZ(float zz){
			this->z = zz;
			return *this;
		}

		float get(int index) {
			switch (index) {
				case 0:
					return this->x;
				case 1:
					return this->y;
				case 2:
					return this->z;
			}
			return 0;
		}

	  void set(int index, float value) {
			switch (index) {
				case 0:
					this->x = value;
					return;
				case 1:
					this->y = value;
					return;
				case 2:
					this->z = value;
					return;
			}
		}

		Vector3f rotate(Vector3f axis, float angle){
			float sinAngle = (float)sin(-angle);
			float cosAngle = (float)cos(-angle);

			return 	 Vector3f(x,y,z).cross(axis.mult(sinAngle)).add(           //Rotation on local X
					(Vector3f(x,y,z).mult(cosAngle)).add(                     //Rotation on local Z
					 axis.mult(Vector3f(x,y,z).dot(axis.mult(1 - cosAngle))))); //Rotation on local Y
		}

		Vector3f rotateX(float angle){
			return this->rotate(Vector3f(1,0,0), angle);
		}

		Vector3f rotateY(float angle){
			return this->rotate(Vector3f(0,1,0), angle);
		}

		Vector3f rotateZ(float angle){
			return this->rotate(Vector3f(0,0,1), angle);
		}

		Vector3f rotateLocal(Vector3f axis, float angle){
			float sinAngle = (float)sin(-angle);
			float cosAngle = (float)cos(-angle);

			return this->set(Vector3f(x,y,z).cross(axis.mult(sinAngle)).add(           //Rotation on local X
					(Vector3f(x,y,z).mult(cosAngle)).add(                     //Rotation on local Z
					 axis.mult(Vector3f(x,y,z).dot(axis.mult(1 - cosAngle))))) //Rotation on local Y
				);
		}

		Vector3f rotateLocalX(float angle){
			return this->rotateLocal(Vector3f(1,0,0), angle);
		}

		Vector3f rotateLocalY(float angle){
			return this->rotateLocal(Vector3f(0,1,0), angle);
		}

		Vector3f rotateLocalZ(float angle){
			return this->rotateLocal(Vector3f(0,0,1), angle);
		}

		Note toNote(){
			return Note("Vector3f(") + Note(x) + Note(" ") + Note(y) + Note(" ") + Note(z) + Note(")");
		}

		ame::cppObjectClass* getClass(){
			return ame::Class<Vector3f>::classType;
		}


		void operator=(const Vector3f& a) {
			this->x = a.x;
			this->y = a.y;
			this->z = a.z;
		}

		Vector3f operator=(const float& a) {
			this->x = a;
			this->y = a;
			this->z = a;
			return *this;
		}

		Vector3f operator=(const int& a) {
			this->x = (float)a;
			this->y = (float)a;
			this->z = (float)a;
			return *this;
		}

		Vector3f operator=(const double& a) {
			this->x = (float)a;
			this->y = (float)a;
			this->z = (float)a;
			return *this;
		}

		bool operator==(const Vector3f& a) {
			return  ((a.x == this->x) && (a.y == this->y) && (a.z == this->z));
		}

		bool operator!=(const Vector3f& a) {
			return  ((a.x != this->x) && (a.y != this->y) && (a.z != this->z));
		}

		Vector3f operator+(const Vector3f& a) {
			return Vector3f(this->x + a.x, this->y+ a.y, this->z+ a.z);
		}

		Vector3f operator+(const float& a) {
			return Vector3f(this->x + a, this->y+ a, this->z+ a);
		}

		Vector3f operator+(const int& a) {
			return Vector3f(this->x + (float)a, this->y+ (float)a, this->z+ (float)a);
		}

		Vector3f operator+(const double& a) {
			return Vector3f(this->x + (float)a, this->y+ (float)a, this->z+ (float)a);
		}

		Vector3f operator-(const Vector3f& a) {
			return Vector3f(this->x - a.x, this->y - a.y, this->z - a.z);
		}

		Vector3f operator-(const float& a) {
			return Vector3f(this->x - a, this->y - a, this->z - a);
		}

		Vector3f operator-(const int& a) {
			return Vector3f(this->x - (float)a, this->y - (float)a, this->z - (float)a);
		}

		Vector3f operator-(const double& a) {
			return Vector3f(this->x - (float)a, this->y - (float)a, this->z - (float)a);
		}

		Vector3f operator*(const Vector3f& a) {
			return Vector3f(this->x * a.x, this->y * a.y, this->z * a.z);
		}

		Vector3f operator*(const float& a) {
			return Vector3f(this->x * a, this->y * a, this->z * a);
		}

		Vector3f operator*(const int& a) {
			return Vector3f(this->x * (float)a, this->y * (float)a, this->z * (float)a);
		}

		Vector3f operator*(const double& a) {
			return Vector3f(this->x * (float)a, this->y * (float)a, this->z * (float)a);
		}

		Vector3f operator/(const Vector3f& a) {
			return Vector3f(this->x / a.x, this->y / a.y, this->z / a.z);
		}

		Vector3f operator/(const float& a) {
			return Vector3f(this->x / a, this->y / a, this->z / a);
		}

		Vector3f operator/(const int& a) {
			return Vector3f(this->x / (float)a, this->y / (float)a, this->z / (float)a);
		}

		Vector3f operator/(const double& a) {
			return Vector3f(this->x / (float)a, this->y / (float)a, this->z / (float)a);
		}



		Vector3f operator+=(const Vector3f& a) {
			this->x += a.x;
			this->y += a.y;
			this->z += a.z;
			return *this;
		}

		Vector3f operator+=(const float& a) {
			this->x += a;
			this->y += a;
			this->z += a;
			return *this;
		}

		Vector3f operator+=(const int& a) {
			this->x += (float)a;
			this->y += (float)a;
			this->z += (float)a;
			return *this;
		}

		Vector3f operator+=(const double& a) {
			this->x += (float)a;
			this->y += (float)a;
			this->z += (float)a;
			return *this;
		}

		Vector3f operator-=(const Vector3f& a) {
			this->x -= a.x;
			this->y -= a.y;
			this->z -= a.z;
			return *this;
		}

		Vector3f operator-=(const float& a) {
			this->x -= a;
			this->y -= a;
			this->z -= a;
			return *this;
		}

		Vector3f operator-=(const int& a) {
			this->x -= (float)a;
			this->y -= (float)a;
			this->z -= (float)a;
			return *this;
		}

		Vector3f operator-=(const double& a) {
			this->x -= (float)a;
			this->y -= (float)a;
			this->z -= (float)a;
			return *this;
		}

		Vector3f operator*=(const Vector3f& a) {
			this->x *= a.x;
			this->y *= a.y;
			this->z *= a.z;
			return *this;
		}

		Vector3f operator*=(const float& a) {
			this->x *= a;
			this->y *= a;
			this->z *= a;
			return *this;
		}

		Vector3f operator*=(const int& a) {
			this->x *= (float)a;
			this->y *= (float)a;
			this->z *= (float)a;
			return *this;
		}

		Vector3f operator*=(const double& a) {
			this->x *= (float)a;
			this->y *= (float)a;
			this->z *= (float)a;
			return *this;
		}

		Vector3f operator/=(const Vector3f& a) {
			this->x /= a.x;
			this->y /= a.y;
			this->z /= a.z;
			return *this;
		}

		Vector3f operator/=(const float& a) {
			this->x /= a;
			this->y /= a;
			this->z /= a;
			return *this;
		}

		Vector3f operator/=(const int& a) {
			this->x /= (float)a;
			this->y /= (float)a;
			this->z /= (float)a;
			return *this;
		}

		Vector3f operator/=(const double& a) {
			this->x /= (float)a;
			this->y /= (float)a;
			this->z /= (float)a;
			return *this;
		}
};

const Vector3f* Vector3f::ZERO = new Vector3f(0,0,0);
// const Vector3f* NAN = Vector3f(-1,-1,-1);
const Vector3f* Vector3f::UNIT_X = new Vector3f(1,0,0);
const Vector3f* Vector3f::UNIT_Y = new Vector3f(0,1,0);
const Vector3f* Vector3f::UNIT_Z = new Vector3f(0,0,1);
const Vector3f* Vector3f::UNIT_XYZ = new Vector3f(1,1,1);
const Vector3f* Vector3f::POSITIVE_INFINITY = new Vector3f(1000,1000,1000);
const Vector3f* Vector3f::NEGATIVE_INFINITY = new Vector3f(1000,1000,1000);

}

#endif