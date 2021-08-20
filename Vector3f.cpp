
#ifndef Vector3f_cpp
#define Vector3f_cpp

#include "Arduino.h"
#include "Vector3f.h"

const ame::Vector3f* ame::Vector3f::ZERO = new ame::Vector3f(0,0,0);
//const ame::Vector3f* NAN = ame::Vector3f(-1,-1,-1);
const ame::Vector3f* ame::Vector3f::UNIT_X = new ame::Vector3f(1,0,0);
const ame::Vector3f* ame::Vector3f::UNIT_Y = new ame::Vector3f(0,1,0);
const ame::Vector3f* ame::Vector3f::UNIT_Z = new ame::Vector3f(0,0,1);
const ame::Vector3f* ame::Vector3f::UNIT_XYZ = new ame::Vector3f(1,1,1);
const ame::Vector3f* ame::Vector3f::POSITIVE_INFINITY = new ame::Vector3f(1000,1000,1000);
const ame::Vector3f* ame::Vector3f::NEGATIVE_INFINITY = new ame::Vector3f(1000,1000,1000);


    ame::Vector3f::Vector3f() {
        x = 0;
        y = 0;
        z = 0;
    }

    ame::Vector3f::Vector3f(const ame::Vector3f& v) {
        x = v.x;
        y = v.y;
        z = v.z;
    }
	
    ame::Vector3f::Vector3f(float nx,float ny,float nz) {
        x = nx;
        y = ny;
        z = nz;
    }
    
	ame::Vector3f ame::Vector3f::set(float xx, float yy, float zz) {
        this->x = xx;
        this->y = yy;
        this->z = zz;
        return *this;
    }
	ame::Vector3f ame::Vector3f::set(ame::Vector3f vect) {
        this->x = vect.x;
        this->y = vect.y;
        this->z = vect.z;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
	ame::Vector3f ame::Vector3f::add(ame::Vector3f r){
		return ame::Vector3f(this->x + r.getX(), this->y + r.getY(), this->z + r.getZ());
	}
	ame::Vector3f ame::Vector3f::add(ame::Vector3f r,ame::Vector3f a){
		return ame::Vector3f(a.getX() + r.getX(), a.getY() + r.getY(), a.getZ() + r.getZ());
	}
    
	ame::Vector3f ame::Vector3f::add(float r){
		return  ame::Vector3f(this->x + r, this->y + r, this->z + r);
	}
	
	ame::Vector3f ame::Vector3f::add(float xx,float yy,float zz){
		return  ame::Vector3f(this->x + xx, this->y + yy, this->z + zz);
	}
    
	ame::Vector3f ame::Vector3f::addLocal(float r){
		this->x += r;
		this->y += r;
		this->z += r;
        return ame::Vector3f(this->x, this->y, this->z);
	}
    
	ame::Vector3f ame::Vector3f::addLocal(ame::Vector3f r,ame::Vector3f a){
		this->x += ( r.getX() + a.getX() );
		this->y += ( r.getY() + a.getY() );
		this->z += ( r.getZ() + a.getZ() );
        return ame::Vector3f(this->x, this->y, this->z);
	}
    
	ame::Vector3f ame::Vector3f::addLocal(ame::Vector3f r){
		this->x += r.getX();
		this->y += r.getY();
		this->z += r.getZ();
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::addLocal(float xx,float yy,float zz){
		this->x += xx;
		this->y += yy;
		this->z += zz;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::scaleAdd(float scalar, ame::Vector3f add) {
        float xx = this->x * scalar + add.x;
        float yy = this->y * scalar + add.y;
        float zz = this->z * scalar + add.z;
        return ame::Vector3f(xx, yy, zz);
    }
	
	ame::Vector3f ame::Vector3f::scaleAdd(float scalar, ame::Vector3f mult, ame::Vector3f add) {
        float xx = mult.x * scalar + add.x;
        float yy = mult.y * scalar + add.y;
        float zz = mult.z * scalar + add.z;
        return ame::Vector3f(xx, yy, zz);
    }
	
	ame::Vector3f ame::Vector3f::scaleAddLocal(float scalar, ame::Vector3f add) {
        this->x = this->x * scalar + add.x;
        this->y = this->y * scalar + add.y;
        this->z = this->z * scalar + add.z;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
	ame::Vector3f ame::Vector3f::scaleAddLocal(float scalar, ame::Vector3f mult, ame::Vector3f add) {
        this->x = mult.x * scalar + add.x;
        this->y = mult.y * scalar + add.y;
        this->z = mult.z * scalar + add.z;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	float ame::Vector3f::dot(ame::Vector3f r){
		return this->x * r.getX() + this->y * r.getY() + this->z * r.getZ();
	}
	
    ame::Vector3f ame::Vector3f::cross(ame::Vector3f v) {
        return this->cross(v.x, v.y, v.z);
    }
	
    ame::Vector3f ame::Vector3f::cross(float otherX, float otherY, float otherZ) {
        float resX = ((this->y * otherZ) - (this->z * otherY)); 
        float resY = ((this->z * otherX) - (this->x * otherZ));
        float resZ = ((this->x * otherY) - (this->y * otherX));
        return ame::Vector3f(resX, resY, resZ);
    }
	
    ame::Vector3f ame::Vector3f::crossLocal(ame::Vector3f v) {
        return crossLocal(v.x, v.y, v.z);
    }
	
    ame::Vector3f ame::Vector3f::crossLocal(float otherX, float otherY, float otherZ) {
        float tempx = ( y * otherZ ) - ( z * otherY );
        float tempy = ( z * otherX ) - ( x * otherZ );
        this->z = (x * otherY) - (y * otherX);
        this->x = tempx;
        this->y = tempy;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::project(ame::Vector3f other){
        float n = this->dot(other); // A . B
        float d = other.lengthSquared(); // |B|^2
        return ame::Vector3f(other).multLocal(n/d);
    }
	
    ame::Vector3f ame::Vector3f::projectLocal(ame::Vector3f other){
        float n = this->dot(other); // A . B
        float d = other.lengthSquared(); // |B|^2
        return set(other).multLocal(n/d);
    }
	
    boolean ame::Vector3f::isUnitVector(){
        float len = length();
        return 0.99f < len && len < 1.01f;
    }
	
	float ame::Vector3f::length(){
		return (float)sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}
	
	float ame::Vector3f::lengthSquared() {
        return this->x * this->x + this->y * this->y + this->z * this->z;
    }
	
	float ame::Vector3f::distanceSquared(ame::Vector3f v) {
        double dx = this->x - v.x;
        double dy = this->y - v.y;
        double dz = this->z - v.z;
        return (float) (dx * dx + dy * dy + dz * dz);
    }
	
	float ame::Vector3f::distanceSquared(float xx, float yy, float zz) {
        double dx = this->x - xx;
        double dy = this->y - yy;
        double dz = this->z - zz;
        return (float) (dx * dx + dy * dy + dz * dz);
    }
	
	float ame::Vector3f::distance(ame::Vector3f v) {
        return (float)sqrt(distanceSquared(v));
    }
	
	float ame::Vector3f::distance(float xx, float yy, float zz) {
        return (float)sqrt(distanceSquared(xx, yy, zz));
    }
	
    ame::Vector3f ame::Vector3f::multLocal(float scalar) {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::multLocal(ame::Vector3f vec) {
        this->x *= vec.x;
        this->y *= vec.y;
        this->z *= vec.z;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::multLocal(float xx, float yy, float zz) {
        this->x *= xx;
        this->y *= yy;
        this->z *= zz;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::mult(float scalar) {
        return ame::Vector3f(this->x * scalar, this->y * scalar, this->z * scalar);
    }
	
    ame::Vector3f ame::Vector3f::mult(ame::Vector3f vec) {
        return mult(vec.x, vec.y, vec.z);
    }
	
    ame::Vector3f ame::Vector3f::mult(float xx, float yy, float zz) {
        return ame::Vector3f(this->x * xx, this->y * yy, this->z * zz);
    }
	
    ame::Vector3f ame::Vector3f::divide(float scalar) {
        scalar = 1.0f/scalar;
        return ame::Vector3f(this->x * scalar, this->y * scalar, this->z * scalar);
    }
	
    ame::Vector3f ame::Vector3f::divideLocal(float scalar) {
        scalar = 1.00f/scalar;
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::divide(ame::Vector3f scalar) {
        return ame::Vector3f(this->x / scalar.x, this->y / scalar.y, this->z / scalar.z);
    }
	
    ame::Vector3f ame::Vector3f::divideLocal(ame::Vector3f scalar) {
        this->x /= scalar.x;
        this->y /= scalar.y;
        this->z /= scalar.z;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::divide(float xx, float yy, float zz) {
        return ame::Vector3f(this->x / xx, this->y / yy, this->z / zz);
    }
	
    ame::Vector3f ame::Vector3f::divideLocal(float xx, float yy, float zz) {
        this->x /= xx;
        this->y /= yy;
        this->z /= zz;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::negateLocal() {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::subtract(float scalar) {
        return ame::Vector3f(this->x - scalar, this->y - scalar, this->z - scalar);
    }
	
    ame::Vector3f ame::Vector3f::subtract(ame::Vector3f vec) {
        return ame::Vector3f(this->x - vec.x, this->y - vec.y, this->z - vec.z);
    }
	
    ame::Vector3f ame::Vector3f::subtractLocal(float scalar) {
        this->x -= scalar;
        this->y -= scalar;
        this->z -= scalar;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::subtractLocal(ame::Vector3f vec) {
        this->x -= vec.x;
        this->y -= vec.y;
        this->z -= vec.z;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::subtract(float subtractX, float subtractY, float subtractZ) {
        return ame::Vector3f(x - subtractX, y - subtractY, z - subtractZ);
    }
	
    ame::Vector3f ame::Vector3f::subtractLocal(float subtractX, float subtractY, float subtractZ) {
        this->x -= subtractX;
        this->y -= subtractY;
        this->z -= subtractZ;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::normalize() {
        float length = this->x * this->x + this->y * this->y + this->z * this->z;
        if (length != 1.00f && length != 0.00f){
            length = 1.00f / sqrt(length);
            return ame::Vector3f(x * length, y * length, z * length);
        }
        return ame::Vector3f(x,y,z);
    }
	
    ame::Vector3f ame::Vector3f::normalizeLocal() {
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
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::maxLocal(ame::Vector3f other){
        this->x = other.x > x ? other.x : this->x;
        this->y = other.y > y ? other.y : this->y;
        this->z = other.z > z ? other.z : this->z;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::minLocal(ame::Vector3f other){
        this->x = other.x < x ? other.x : this->x;
        this->y = other.y < y ? other.y : this->y;
        this->z = other.z < z ? other.z : this->z;
        return ame::Vector3f(this->x, this->y, this->z);
    }
	
    ame::Vector3f ame::Vector3f::zero() {
        this->x = this->y = this->z = 0;
        return ame::Vector3f(this->x, this->y, this->z);
    }
    
	float ame::Vector3f::angleBetween(ame::Vector3f otherVector) {
        float dotProduct = dot(otherVector);
        //float angle = 0.00f;
        float angle = acos(dotProduct);
      //  float angle = aMath::arccos(dotProduct);//////
        return angle;
    }
    
	ame::Vector3f ame::Vector3f::interpolateLocal(ame::Vector3f finalVec, float changeAmnt) {
        this->x=(1-changeAmnt)*this->x + changeAmnt*finalVec.x;
        this->y=(1-changeAmnt)*this->y + changeAmnt*finalVec.y;
        this->z=(1-changeAmnt)*this->z + changeAmnt*finalVec.z;
        return ame::Vector3f(this->x, this->y, this->z);
    }
    
	ame::Vector3f ame::Vector3f::interpolateLocal(ame::Vector3f beginVec,ame::Vector3f finalVec, float changeAmnt) {
        this->x=(1-changeAmnt)*beginVec.x + changeAmnt*finalVec.x;
        this->y=(1-changeAmnt)*beginVec.y + changeAmnt*finalVec.y;
        this->z=(1-changeAmnt)*beginVec.z + changeAmnt*finalVec.z;
        return ame::Vector3f(this->x, this->y, this->z);
    }
    
	bool ame::Vector3f::isValidVector(ame::Vector3f vector) {
    //  if (Float.isNaN(vector->x) ||
    //      Float.isNaN(vector->y) ||
    //      Float.isNaN(vector->z)) return false;
    //  if (Float.isInfinite(vector->x) ||
    //      Float.isInfinite(vector->y) ||
    //      Float.isInfinite(vector->z)) return false;
      return true;
    }
    
	void ame::Vector3f::generateOrthonormalBasis(ame::Vector3f *u, ame::Vector3f *v, ame::Vector3f *w) {
        w->normalizeLocal();
        generateComplementBasis(u, v, w);
    }
    
	void ame::Vector3f::generateComplementBasis(ame::Vector3f *u, ame::Vector3f *v, ame::Vector3f *w) {
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
    
	ame::Vector3f *ame::Vector3f::clone() {
		return new ame::Vector3f(this->x,this->y,this->z);
    }
    
	boolean ame::Vector3f::equals(cppObject *o) {
        if (this == o) {
			return true; 
		}
		

		if(o->getClass() != Class<ame::Vector3f>::classType) {
			return false;
		}
		

        ame::Vector3f *comp = (ame::Vector3f*)o;
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
    
	float ame::Vector3f::getX(){
		return this->x;
	}
  
	ame::Vector3f ame::Vector3f::setX(float xx){
		this->x = xx;
		return ame::Vector3f(this->x, this->y, this->z);
	}
  
	float ame::Vector3f::getY(){
		return this->y;
	}
  
	ame::Vector3f ame::Vector3f::setY(float yy){
		this->y = yy;
		return ame::Vector3f(this->x, this->y, this->z);
	}
  
	float ame::Vector3f::getZ(){
		return this->z;
	}
  
	ame::Vector3f ame::Vector3f::setZ(float zz){
		this->z = zz;
		return ame::Vector3f(this->x, this->y, this->z);
	}
  
	float ame::Vector3f::get(int index) {
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
  
  void ame::Vector3f::set(int index, float value) {
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
	
    ame::Vector3f ame::Vector3f::rotate(ame::Vector3f axis, float angle){
		float sinAngle = (float)sin(-angle);
		float cosAngle = (float)cos(-angle);

		return 	 ame::Vector3f(x,y,z).cross(axis.mult(sinAngle)).add(           //Rotation on local X
				(ame::Vector3f(x,y,z).mult(cosAngle)).add(                     //Rotation on local Z
				 axis.mult(ame::Vector3f(x,y,z).dot(axis.mult(1 - cosAngle))))); //Rotation on local Y
	} 
  
    ame::Vector3f ame::Vector3f::rotateX(float angle){
		return this->rotate(ame::Vector3f(1,0,0), angle);
	}
  
    ame::Vector3f ame::Vector3f::rotateY(float angle){
		return this->rotate(ame::Vector3f(0,1,0), angle);
	}
  
    ame::Vector3f ame::Vector3f::rotateZ(float angle){
		return this->rotate(ame::Vector3f(0,0,1), angle);
	}
	
    ame::Vector3f ame::Vector3f::rotateLocal(ame::Vector3f axis, float angle){
		float sinAngle = (float)sin(-angle);
		float cosAngle = (float)cos(-angle);

		return this->set(ame::Vector3f(x,y,z).cross(axis.mult(sinAngle)).add(           //Rotation on local X
				(ame::Vector3f(x,y,z).mult(cosAngle)).add(                     //Rotation on local Z
				 axis.mult(ame::Vector3f(x,y,z).dot(axis.mult(1 - cosAngle))))) //Rotation on local Y
			);
	} 
  
    ame::Vector3f ame::Vector3f::rotateLocalX(float angle){
		return this->rotateLocal(ame::Vector3f(1,0,0), angle);
	}
  
    ame::Vector3f ame::Vector3f::rotateLocalY(float angle){
		return this->rotateLocal(ame::Vector3f(0,1,0), angle);
	}
  
    ame::Vector3f ame::Vector3f::rotateLocalZ(float angle){
		return this->rotateLocal(ame::Vector3f(0,0,1), angle);
	}
  
	
	String ame::Vector3f::toString(){
			return "Vector3f(" + (String)x + " " + (String)y + " " + (String)z + ")";
	}
	
	ame::cppObjectClass* ame::Vector3f::getClass(){
		return ame::Class<ame::Vector3f>::classType;
	}
	
	
	void ame::Vector3f::operator=(const ame::Vector3f& a) {
        this->x = a.x;
        this->y = a.y;
        this->z = a.z;
	}
	
	ame::Vector3f ame::Vector3f::operator=(const float& a) {
        this->x = a;
        this->y = a;
        this->z = a;
		return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator=(const int& a) {
        this->x = (float)a;
        this->y = (float)a;
        this->z = (float)a;
		return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator=(const double& a) {
        this->x = (float)a;
        this->y = (float)a;
        this->z = (float)a;
		return ame::Vector3f(this->x, this->y, this->z);
	}
	
	bool ame::Vector3f::operator==(const ame::Vector3f& a) {
		return  ((a.x == this->x) && (a.y == this->y) && (a.z == this->z));
	}
	
	bool ame::Vector3f::operator!=(const ame::Vector3f& a) {
		return  ((a.x != this->x) && (a.y != this->y) && (a.z != this->z));
	}
	
	ame::Vector3f ame::Vector3f::operator+(const ame::Vector3f& a) {
		return ame::Vector3f(this->x + a.x, this->y+ a.y, this->z+ a.z);
	}
	
	ame::Vector3f ame::Vector3f::operator+(const float& a) {
		return ame::Vector3f(this->x + a, this->y+ a, this->z+ a);
	}
	
	ame::Vector3f ame::Vector3f::operator+(const int& a) {
		return ame::Vector3f(this->x + (float)a, this->y+ (float)a, this->z+ (float)a);
	}
	
	ame::Vector3f ame::Vector3f::operator+(const double& a) {
		return ame::Vector3f(this->x + (float)a, this->y+ (float)a, this->z+ (float)a);
	}
	
	ame::Vector3f ame::Vector3f::operator-(const ame::Vector3f& a) {
        return ame::Vector3f(this->x - a.x, this->y - a.y, this->z - a.z);
	}
	
	ame::Vector3f ame::Vector3f::operator-(const float& a) {
        return ame::Vector3f(this->x - a, this->y - a, this->z - a);
	}
	
	ame::Vector3f ame::Vector3f::operator-(const int& a) {
        return ame::Vector3f(this->x - (float)a, this->y - (float)a, this->z - (float)a);
	}
	
	ame::Vector3f ame::Vector3f::operator-(const double& a) {
        return ame::Vector3f(this->x - (float)a, this->y - (float)a, this->z - (float)a);
	}
	
	ame::Vector3f ame::Vector3f::operator*(const ame::Vector3f& a) {
        return ame::Vector3f(this->x * a.x, this->y * a.y, this->z * a.z);
	}
	
	ame::Vector3f ame::Vector3f::operator*(const float& a) {
        return ame::Vector3f(this->x * a, this->y * a, this->z * a);
	}
	
	ame::Vector3f ame::Vector3f::operator*(const int& a) {
        return ame::Vector3f(this->x * (float)a, this->y * (float)a, this->z * (float)a);
	}
	
	ame::Vector3f ame::Vector3f::operator*(const double& a) {
        return ame::Vector3f(this->x * (float)a, this->y * (float)a, this->z * (float)a);
	}
	
	ame::Vector3f ame::Vector3f::operator/(const ame::Vector3f& a) {
        return ame::Vector3f(this->x / a.x, this->y / a.y, this->z / a.z);
	}
	
	ame::Vector3f ame::Vector3f::operator/(const float& a) {
        return ame::Vector3f(this->x / a, this->y / a, this->z / a);
	}
	
	ame::Vector3f ame::Vector3f::operator/(const int& a) {
        return ame::Vector3f(this->x / (float)a, this->y / (float)a, this->z / (float)a);
	}
	
	ame::Vector3f ame::Vector3f::operator/(const double& a) {
        return ame::Vector3f(this->x / (float)a, this->y / (float)a, this->z / (float)a);
	}
	
	
	
	ame::Vector3f ame::Vector3f::operator+=(const ame::Vector3f& a) {
		this->x += a.x;
		this->y += a.y;
		this->z += a.z;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator+=(const float& a) {
		this->x += a;
		this->y += a;
		this->z += a;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator+=(const int& a) {
		this->x += (float)a;
		this->y += (float)a;
		this->z += (float)a;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator+=(const double& a) {
		this->x += (float)a;
		this->y += (float)a;
		this->z += (float)a;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator-=(const ame::Vector3f& a) {
		this->x -= a.x;
		this->y -= a.y;
		this->z -= a.z;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator-=(const float& a) {
		this->x -= a;
		this->y -= a;
		this->z -= a;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator-=(const int& a) {
		this->x -= (float)a;
		this->y -= (float)a;
		this->z -= (float)a;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator-=(const double& a) {
		this->x -= (float)a;
		this->y -= (float)a;
		this->z -= (float)a;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator*=(const ame::Vector3f& a) {
		this->x *= a.x;
		this->y *= a.y;
		this->z *= a.z;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator*=(const float& a) {
		this->x *= a;
		this->y *= a;
		this->z *= a;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator*=(const int& a) {
		this->x *= (float)a;
		this->y *= (float)a;
		this->z *= (float)a;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator*=(const double& a) {
		this->x *= (float)a;
		this->y *= (float)a;
		this->z *= (float)a;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator/=(const ame::Vector3f& a) {
		this->x /= a.x;
		this->y /= a.y;
		this->z /= a.z;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator/=(const float& a) {
		this->x /= a;
		this->y /= a;
		this->z /= a;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator/=(const int& a) {
		this->x /= (float)a;
		this->y /= (float)a;
		this->z /= (float)a;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	ame::Vector3f ame::Vector3f::operator/=(const double& a) {
		this->x /= (float)a;
		this->y /= (float)a;
		this->z /= (float)a;
        return ame::Vector3f(this->x, this->y, this->z);
	}
	
	
	
#endif 
	