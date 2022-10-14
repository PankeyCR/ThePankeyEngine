
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Vector4f)
	#define Vector4f_hpp
#endif

#ifndef Vector4f_hpp
#define Vector4f_hpp
#define Vector4f_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

// #include "FastMonkeyMath.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "cppObject.hpp"
#include "Class.hpp"

namespace ame{

class Vector4f : public cppObject , public Printable{
    private:
	
    public:
        float x;
        float y; 
        float z;
        float w;
		
		const static Vector4f *ZERO;
	//	const static Vector4f *NAN;
		const static Vector4f *UNIT_X;
		const static Vector4f *UNIT_Y;
		const static Vector4f *UNIT_Z;
		const static Vector4f *UNIT_W;
		const static Vector4f *UNIT_XYZW;
	
		Vector4f(){
			this->x = this->y = this->z = this->w = 0;
		}
		
		Vector4f(const Vector4f& vec){
			this->x = vec.x;
			this->y = vec.y;
			this->z = vec.z;
			this->w = vec.w;
		}
		
		Vector4f(float xx, float yy, float zz, float ww){
			this->x = xx;
			this->y = yy;
			this->z = zz;
			this->w = ww;
		}

		size_t printTo(Print& p) const{
			p.print(this->x);p.print(',');p.print(this->y);p.print(',');p.print(this->z);p.print(',');p.print(this->w);
			return 	sizeof(this->x) + sizeof(this->y) + sizeof(this->z) + sizeof(this->w);
		}
		
		Vector4f set(float xx, float yy, float zz, float ww){
			this->x = xx;
			this->y = yy;
			this->z = zz;
			this->w = ww;
			return *this;
		}
		
		Vector4f set(Vector4f vect){
			this->x = vect.x;
			this->y = vect.y;
			this->z = vect.z;
			this->w = vect.w;
			return *this;
		}
		
		Vector4f add(Vector4f vec){
			return Vector4f(this->x + vec.x, this->y + vec.y, this->z + vec.z, this->w + vec.w);
		}
		
		Vector4f add(float addX, float addY, float addZ, float addW){
			return Vector4f(this->x + addX, this->y + addY, this->z + addZ, this->w + addW);
		}
		
		Vector4f addLocal(Vector4f vec){
			this->x += vec.x;
			this->y += vec.y;
			this->z += vec.z;
			this->w += vec.w;
			return *this;
		}
		
		Vector4f addLocal(float addX, float addY, float addZ, float addW){
			this->x += addX;
			this->y += addY;
			this->z += addZ;
			this->w += addW;
			return *this;
		}
		
		Vector4f scaleAdd(float scalar, Vector4f add){
			float xx = this->x * scalar + add.x;
			float xy = this->y * scalar + add.y;
			float xz = this->z * scalar + add.z;
			float xw = this->w * scalar + add.w;
			return Vector4f(xx, xy, xz, xw);
		}
		
		Vector4f scaleAdd(float scalar, Vector4f mult, Vector4f add){
			float xx = mult.x * scalar + add.x;
			float xy = mult.y * scalar + add.y;
			float xz = mult.z * scalar + add.z;
			float xw = mult.w * scalar + add.w;
			return Vector4f(xx, xy, xz, xw);
		}
		
		Vector4f scaleAddLocal(float scalar, Vector4f add){
			this->x = this->x * scalar + add.x;
			this->y = this->y * scalar + add.y;
			this->z = this->z * scalar + add.z;
			this->w = this->w * scalar + add.w;
			return *this;
		}
		
		Vector4f scaleAddLocal(float scalar, Vector4f mult, Vector4f add){
			this->x = mult.x * scalar + add.x;
			this->y = mult.y * scalar + add.y;
			this->z = mult.z * scalar + add.z;
			this->w = mult.w * scalar + add.w;
			return *this;
		}
		
		float dot(Vector4f vec){
			return this->x * vec.x + this->y * vec.y + this->z * vec.z + this->w * vec.w;
		}
		
		Vector4f project(Vector4f other){
			float n = this->dot(other); // A . B
			float d = other.lengthSquared(); // |B|^2
			Vector4f v = Vector4f(other);
			return v.multLocal(n/d);
		}
		
		bool isUnitVector(){
			float len = this->length();
			return 0.99f < len && len < 1.01f;
		}
		
		float length(){
			return sqrt(lengthSquared());
		}
		
		float lengthSquared(){
			return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
		}
		
		float distanceSquared(Vector4f v){
			double dx = this->x - v.x;
			double dy = this->y - v.y;
			double dz = this->z - v.z;
			double dw = this->w - v.w;
			return (float) (dx * dx + dy * dy + dz * dz + dw * dw);
		}
		
		float distance(Vector4f v){
			return sqrt(distanceSquared(v));
		}
		
		Vector4f mult(float scalar){
			return Vector4f(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
		}
		
		Vector4f mult(Vector4f vec){
			float nx = this->x * vec.x;
			float ny = this->y * vec.y;
			float nz = this->z * vec.z;
			float nw = this->w * vec.w;
			return Vector4f(nx, ny, nz ,nw);
		}
		
		Vector4f mult(float xx, float xy, float xz, float xw){
			return Vector4f(this->x * xx, this->y * xy, this->z * xz, this->w * xw);
		}
		
		Vector4f multLocal(float scalar){
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			this->w *= scalar;
			return *this;
		}
		
		Vector4f multLocal(Vector4f vec){
			x *= vec.x;
			y *= vec.y;
			z *= vec.z;
			w *= vec.w;
			return *this;
		}
		Vector4f multLocal(float xx, float xy, float xz, float xw){
			this->x *= xx;
			this->y *= xy;
			this->z *= xz;
			this->w *= xw;
			return *this;
		}
		
		Vector4f divide(float scalar){
			scalar = 1.0f/scalar;
			return Vector4f(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
		}
		
		Vector4f divideLocal(float scalar){
			scalar = 1.0f/scalar;
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			this->w *= scalar;
			return *this;
		}
		
		Vector4f divide(Vector4f scalar){
			return Vector4f(this->x / scalar.x, this->y / scalar.y, this->z / scalar.z, this->w / scalar.w);
		}
		
		Vector4f divideLocal(Vector4f scalar){
			this->x /= scalar.x;
			this->y /= scalar.y;
			this->z /= scalar.z;
			this->w /= scalar.w;
			return *this;
		}
		
		Vector4f divide(float xx, float yy, float zz, float ww){
			float tx = this->x / xx;
			float ty = this->y / yy;
			float tz = this->z / zz;
			float tw = this->w / ww;
			return Vector4f(tx, ty, tz, tw);
		}
		
		Vector4f divideLocal(float xx, float yy, float zz, float ww){
			this->x /= xx;
			this->y /= yy;
			this->z /= zz;
			this->w /= ww;
			return *this;
		}
		
		Vector4f negate(){
			return Vector4f(-this->x, -this->y, -this->z, -this->w);
		}
		
		Vector4f negateLocal(){
			this->x = -this->x;
			this->y = -this->y;
			this->z = -this->z;
			this->w = -this->w;
			return *this;
		}
		
		Vector4f subtract(Vector4f vec){
			return Vector4f(this->x - vec.x, this->y - vec.y, this->z - vec.z, this->w - vec.w);
		}
							 
		Vector4f subtractLocal(Vector4f vec){
			this->x -= vec.x;
			this->y -= vec.y;
			this->z -= vec.z;
			this->w -= vec.w;
			return *this;
		}
		
		Vector4f subtract(float subtractX, float subtractY, 
							 float subtractZ, float subtractW){
			return ame::Vector4f(this->x - subtractX, this->y - subtractY, this->z - subtractZ, this->w - subtractW);
		}
		
		Vector4f subtractLocal(float subtractX, 
				float subtractY, float subtractZ, float subtractW){
			this->x -= subtractX;
			this->y -= subtractY;
			this->z -= subtractZ;
			this->w -= subtractW;
			return *this;
		}
				
		Vector4f normalize(){
			float length = this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
			if (length != 1.0f && length != 0.0f){
				length = 1.0f / sqrt(length);
				return Vector4f(this->x * length, this->y * length, this->z * length, this->w * length);
			}
			return *this;
		}
		
		Vector4f normalizeLocal(){
			float length = this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
			if (length != 1.0f && length != 0.0f){
				length = 1.0f / sqrt(length);
				this->x *= length;
				this->y *= length;
				this->z *= length;
				this->w *= length;
			}
			return *this;
		}
		
		Vector4f maxLocal(Vector4f other){
			this->x = other.x > x ? other.x : this->x;
			this->y = other.y > y ? other.y : this->y;
			this->z = other.z > z ? other.z : this->z;
			this->w = other.w > w ? other.w : this->w;
			return *this;
		}
		
		Vector4f minLocal(Vector4f other){
			this->x = other.x < x ? other.x : this->x;
			this->y = other.y < y ? other.y : this->y;
			this->z = other.z < z ? other.z : this->z;
			this->w = other.w < w ? other.w : this->w;
			return *this;
		}
		
		Vector4f zero(){
			this->x = this->y = this->z = this->w = 0;
			return *this;
		}
		
		float angleBetween(Vector4f otherVector){
			float dotProduct = dot(otherVector);
			float angle = acos(dotProduct);
			return angle;
		}
		
		Vector4f interpolateLocal(Vector4f finalVec, float changeAmnt){
			this->x=(1-changeAmnt)*this->x + changeAmnt*finalVec.x;
			this->y=(1-changeAmnt)*this->y + changeAmnt*finalVec.y;
			this->z=(1-changeAmnt)*this->z + changeAmnt*finalVec.z;
			this->w=(1-changeAmnt)*this->w + changeAmnt*finalVec.w;
			return *this;
		}
		
		Vector4f interpolateLocal(Vector4f beginVec,
						Vector4f finalVec, float changeAmnt){
			this->x=(1-changeAmnt)*beginVec.x + changeAmnt*finalVec.x;
			this->y=(1-changeAmnt)*beginVec.y + changeAmnt*finalVec.y;
			this->z=(1-changeAmnt)*beginVec.z + changeAmnt*finalVec.z;
			this->w=(1-changeAmnt)*beginVec.w + changeAmnt*finalVec.w;
			return *this;
		}
		
		static bool isValidVector(Vector4f vector){
	  ///   if (Float.isNaN(vector.x) ||
		//      Float.isNaN(vector.y) ||
	  //        Float.isNaN(vector.z)||
	  //        Float.isNaN(vector.w)) return false;
	  //    if (Float.isInfinite(vector.x) ||
	  //        Float.isInfinite(vector.y) ||
	   //       Float.isInfinite(vector.z) ||
	   //       Float.isInfinite(vector.w)) return false;
		  return true;
		}
		
		#if defined(LinkedList_AVAILABLE)
		
		LinkedList<float> toArray(){
			LinkedList<float> list;
			list.addLValue(this->x);
			list.addLValue(this->y);
			list.addLValue(this->z);
			list.addLValue(this->w);
			return list;
		}
		
		#endif
		
		bool isSimilar(Vector4f other, float epsilon){
			if (abs(other.x - this->x) > epsilon){
				return false;
			}
			if (abs(other.y - this->y) > epsilon){
				return false;
			}
			if (abs(other.z - this->z) > epsilon){
				return false;
			}
			if (abs(other.w - this->w) > epsilon){
				return false;
			}
			return true;
		}
		
	//	void write(JmeExporter e);
	//	void read(JmeImporter e);
		float getX(){
			return this->x;
		}
		
		Vector4f setX(float xx){
			this->x = xx;
			return *this;
		}
		
		float getY(){
			return this->y;
		}
		
		Vector4f setY(float xy){
			this->y = xy;
			return *this;
		}
		
		float getZ(){
			return this->z;
		}
		
		Vector4f setZ(float xz){
			this->z = xz;
			return *this;
		}
		
		float getW(){
			return this->w;
		}
		
		Vector4f setW(float xw){
			this->w = xw;
			return *this;
		}
		float get(int index){
			switch (index) {
				case 0:
					return x;
				case 1:
					return y;
				case 2:
					return z;
				case 3:
					return w;
			}		
		}
		
		void set(int index, float value){
			switch (index) {
				case 0:
					x = value;
					return;
				case 1:
					y = value;
					return;
				case 2:
					z = value;
					return;
				case 3:
					w = value;
				  return;
			}
		}
		
		Vector4f *clone(){
			return new Vector4f(this->x, this->y, this->z, this->w);
		}
		bool equals(cppObject *a_obj){
			if ( a_obj->getClass() != Class<Vector4f>::classType ) {
				return false;
			}

			if (this == a_obj){
				return true;
			}

			Vector4f *comp = (Vector4f*) a_obj;
			if (comp->x != this->x){
				return false;
			}
			if (comp->y != this->y){
				return false;
			}
			if (comp->z != this->z){
				return false;
			}
			if (comp->w != this->w){
				return false;
			}
			return true;
		}
		Note toNote(){
			return Note("Vector4f(") + Note(this->x) + Note(", ") + Note(this->y) + Note(", ") + Note(this->z) + Note(", ") + Note(this->w) + Note(")");
		}
		
		Vector4f operator=(const Vector4f& a){
			this->x = a.x;
			this->y = a.y;
			this->z = a.z;
			this->w = a.w;
			return *this;
		}
		
		Vector4f operator=(const float& a){
			this->x = a;
			this->y = a;
			this->z = a;
			this->w = a;
			return *this;
		}
		
		Vector4f operator=(const int& a){
			this->x = (float)a;
			this->y = (float)a;
			this->z = (float)a;
			this->w = (float)a;
			return *this;
		}
		
		Vector4f operator=(const double& a){
			this->x = (float)a;
			this->y = (float)a;
			this->z = (float)a;
			this->w = (float)a;
			return *this;
		}
		
		Vector4f operator=(const float a[4]){
			this->x = a[0];
			this->y = a[1];
			this->z = a[2];
			this->w = a[3];
			return *this;
		}
		
		bool operator==(const Vector4f& a){
			if(this->x == a.x && this->y == a.y && this->z == a.z && this->w == a.w){
				return true;
			}
			return false;
		}
		
		bool operator!=(const Vector4f& a){
			if(this->x != a.x && this->y != a.y && this->z != a.z && this->w != a.w){
				return true;
			}
			return false;
		}
		
		Vector4f operator+(const Vector4f& a){
			return Vector4f(this->x+ a.x ,this->y + a.y ,this->z + a.z ,this->w + a.w);
		}
		
		Vector4f operator+(const float& a){
			return Vector4f(this->x+a ,this->y+a ,this->z + a ,this->w + a);
		}
		Vector4f operator+(const int& a){
			return Vector4f(this->x+(float)a ,this->y+(float)a ,this->z + (float)a ,this->w + (float)a);
		}
		
		Vector4f operator+(const double& a){
			return Vector4f(this->x+(float)a ,this->y+(float)a ,this->z + (float)a ,this->w + (float)a);
		}
		
		Vector4f operator-(const Vector4f& a){
			return Vector4f(this->x- a.x ,this->y - a.y ,this->z - a.z ,this->w - a.w);
		}
		
		Vector4f operator-(const float& a){
			return Vector4f(this->x-a ,this->y-a ,this->z - a ,this->w - a);
		}
		
		Vector4f operator-(const int& a){
			return Vector4f(this->x- (float)a ,this->y-(float)a ,this->z - (float)a ,this->w - (float)a);
		}
		
		Vector4f operator-(const double& a){
			return Vector4f(this->x- (float)a ,this->y-(float)a ,this->z - (float)a ,this->w - (float)a);
		}
		
		Vector4f operator*(const Vector4f& a){
			return Vector4f(this->x* a.x ,this->y * a.y ,this->z * a.z ,this->w * a.w);
		}
		
		Vector4f operator*(const float& a){
			return Vector4f(this->x* a ,this->y* a ,this->z * a ,this->w * a);
		}
		
		Vector4f operator*(const int& a){
			return Vector4f(this->x*(float)a ,this->y*(float)a ,this->z * (float)a ,this->w * (float)a);
		}
		
		Vector4f operator*(const double& a){
			return Vector4f(this->x*(float)a ,this->y*(float)a ,this->z * (float)a ,this->w * (float)a);
		}
		
		Vector4f operator/(const Vector4f& a){
			return Vector4f(this->x/ a.x ,this->y / a.y ,this->z / a.z ,this->w / a.w);
		}
		
		Vector4f operator/(const float& a){
			return Vector4f(this->x/ a ,this->y/ a ,this->z / a ,this->w / a);
		}
		
		Vector4f operator/(const int& a){
			return Vector4f(this->x/(float)a ,this->y/(float)a ,this->z / (float)a ,this->w / (float)a);
		}
		
		Vector4f operator/(const double& a){
			return Vector4f(this->x/(float)a ,this->y/(float)a ,this->z / (float)a ,this->w / (float)a);
		}
		
		Vector4f operator+=(const Vector4f& a){
			this->x += a.x;
			this->y += a.y;
			this->z += a.z;
			this->w += a.w;
			return *this;
		}
		
		Vector4f operator+=(const float& a){
			this->x += a;
			this->y += a;
			this->z += a;
			this->w += a;
			return *this;
		}
		
		Vector4f operator+=(const int& a){
			this->x += (float)a;
			this->y += (float)a;
			this->z += (float)a;
			this->w += (float)a;
			return *this;
		}
		
		Vector4f operator+=(const double& a){
			this->x += (float)a;
			this->y += (float)a;
			this->z += (float)a;
			this->w += (float)a;
			return *this;
		}
		
		Vector4f operator-=(const Vector4f& a){
			this->x -= a.x;
			this->y -= a.y;
			this->z -= a.z;
			this->w -= a.w;
			return *this;
		}
		
		Vector4f operator-=(const float& a){
			this->x -= a;
			this->y -= a;
			this->z -= a;
			this->w -= a;
			return *this;
		}
		
		Vector4f operator-=(const int& a){
			this->x -= (float)a;
			this->y -= (float)a;
			this->z -= (float)a;
			this->w -= (float)a;
			return *this;
		}
		
		Vector4f operator-=(const double& a){
			this->x -= (float)a;
			this->y -= (float)a;
			this->z -= (float)a;
			this->w -= (float)a;
			return *this;
		}
		
		Vector4f operator*=(const Vector4f& a){
			this->x *= a.x;
			this->y *= a.y;
			this->z *= a.z;
			this->w *= a.w;
			return *this;
		}
		
		Vector4f operator*=(const float& a){
			this->x *= a;
			this->y *= a;
			this->z *= a;
			this->w *= a;
			return *this;
		}
		
		Vector4f operator*=(const int& a){
			this->x *= (float)a;
			this->y *= (float)a;
			this->z *= (float)a;
			this->w *= (float)a;
			return *this;
		}
		
		Vector4f operator*=(const double& a){
			this->x *= (float)a;
			this->y *= (float)a;
			this->z *= (float)a;
			this->w *= (float)a;
			return *this;
		}
		
		Vector4f operator/=(const Vector4f& a){
			this->x /= a.x;
			this->y /= a.y;
			this->z /= a.z;
			this->w /= a.w;
			return *this;
		}
		
		Vector4f operator/=(const float& a){
			this->x /= a;
			this->y /= a;
			this->z /= a;
			this->w /= a;
			return *this;
		}
		
		Vector4f operator/=(const int& a){
			this->x /= (float)a;
			this->y /= (float)a;
			this->z /= (float)a;
			this->w /= (float)a;
			return *this;
		}
		
		Vector4f operator/=(const double& a){
			this->x /= (float)a;
			this->y /= (float)a;
			this->z /= (float)a;
			this->w /= (float)a;
			return *this;
		}

		virtual cppObjectClass* getClass(){
			return Class<Vector4f>::getClass();
		}

		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<Vector4f>::getClass();
		}
};

const Vector4f *Vector4f::ZERO = new Vector4f(0, 0, 0, 0);
// const Vector4f *Vector4f::NAN = new Vector4f(Float.NaN, Float.NaN, Float.NaN, Float.NaN);
const Vector4f *Vector4f::UNIT_X = new Vector4f(1, 0, 0, 0);
const Vector4f *Vector4f::UNIT_Y = new Vector4f(0, 1, 0, 0);
const Vector4f *Vector4f::UNIT_Z = new Vector4f(0, 0, 1, 0);
const Vector4f *Vector4f::UNIT_W = new Vector4f(0, 0, 0, 1);
const Vector4f *Vector4f::UNIT_XYZW = new Vector4f(1, 1, 1, 1);

}

#endif