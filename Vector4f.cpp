
#ifndef Vector4f_cpp
#define Vector4f_cpp

#include "Arduino.h"
#include "Vector3f.h"
#include "Vector4f.h"
/*
    ame::Vector4f *ame::Vector4f::ZERO = new ame::Vector4f(0, 0, 0, 0);
  //  ame::Vector4f *ame::Vector4f::NAN = new ame::Vector4f(Float.NaN, Float.NaN, Float.NaN, Float.NaN);
    ame::Vector4f *ame::Vector4f::UNIT_X = new ame::Vector4f(1, 0, 0, 0);
    ame::Vector4f *ame::Vector4f::UNIT_Y = new ame::Vector4f(0, 1, 0, 0);
    ame::Vector4f *ame::Vector4f::UNIT_Z = new ame::Vector4f(0, 0, 1, 0);
    ame::Vector4f *ame::Vector4f::UNIT_W = new ame::Vector4f(0, 0, 0, 1);
    ame::Vector4f *ame::Vector4f::UNIT_XYZW = new ame::Vector4f(1, 1, 1, 1);
 
    ame::Vector4f::Vector4f() {
        this->x = this->y = this->z = this->w = 0;
    }
	
    ame::Vector4f::Vector4f(float x, float y, float z, float w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
	
    ame::Vector4f ame::Vector4f::set(float xx, float yy, float zz, float ww) {
        this->x = xx;
        this->y = yy;
        this->z = zz;
        this->w = ww;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::set(ame::Vector4f vect) {
        this->x = vect.x;
        this->y = vect.y;
        this->z = vect.z;
        this->w = vect.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::add(ame::Vector4f vec) {
        return ame::Vector4f(this->x + vec.x, this->y + vec.y, this->z + vec.z, this->w + vec.w);
    }
	
    ame::Vector4f ame::Vector4f::add(float addX, float addY, float addZ, float addW) {
        return ame::Vector4f(this->x + addX, this->y + addY, this->z + addZ, this->w + addW);
    }
	
    ame::Vector4f ame::Vector4f::addLocal(ame::Vector4f vec) {
        this->x += vec.x;
        this->y += vec.y;
        this->z += vec.z;
        this->w += vec.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::addLocal(float addX, float addY, float addZ, float addW) {
        this->x += addX;
        this->y += addY;
        this->z += addZ;
        this->w += addW;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::scaleAdd(float scalar, ame::Vector4f add) {
        float xx = this->x * scalar + add.x;
        float xy = this->y * scalar + add.y;
        float xz = this->z * scalar + add.z;
        float xw = this->w * scalar + add.w;
        return ame::Vector4f(xx, xy, xz, xw);
    }
	
    ame::Vector4f ame::Vector4f::scaleAdd(float scalar, ame::Vector4f mult, ame::Vector4f add) {
        float xx = mult.x * scalar + add.x;
        float xy = mult.y * scalar + add.y;
        float xz = mult.z * scalar + add.z;
        float xw = mult.w * scalar + add.w;
        return ame::Vector4f(xx, xy, xz, xw);
    }
	
    ame::Vector4f ame::Vector4f::scaleAddLocal(float scalar, ame::Vector4f add) {
        this->x = this->x * scalar + add.x;
        this->y = this->y * scalar + add.y;
        this->z = this->z * scalar + add.z;
        this->w = this->w * scalar + add.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::scaleAddLocal(float scalar, ame::Vector4f mult, ame::Vector4f add) {
        this->x = mult.x * scalar + add.x;
        this->y = mult.y * scalar + add.y;
        this->z = mult.z * scalar + add.z;
        this->w = mult.w * scalar + add.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    float ame::Vector4f::dot(ame::Vector4f vec) {
        return this->x * vec.x + this->y * vec.y + this->z * vec.z + this->w * vec.w;
    }

    ame::Vector4f ame::Vector4f::project(ame::Vector4f other){
        float n = this->dot(other); // A . B
        float d = other.lengthSquared(); // |B|^2
        return ame::Vector4f(other).multLocal(n/d);
    }
	
    bool ame::Vector4f::isUnitVector(){
        float len = this->length();
        return 0.99f < len && len < 1.01f;
    }
	
    float ame::Vector4f::length() {
        return sqrt(lengthSquared());
    }
	
    float ame::Vector4f::lengthSquared() {
        return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
    }
	
    float ame::Vector4f::distanceSquared(ame::Vector4f v) {
        double dx = this->x - v.x;
        double dy = this->y - v.y;
        double dz = this->z - v.z;
        double dw = this->w - v.w;
        return (float) (dx * dx + dy * dy + dz * dz + dw * dw);
    }
	
    float ame::Vector4f::distance(ame::Vector4f v) {
        return sqrt(distanceSquared(v));
    }
	
    ame::Vector4f ame::Vector4f::mult(float scalar) {
        return ame::Vector4f(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
    }
	
    ame::Vector4f ame::Vector4f::mult(ame::Vector4f vec) {
        float nx = this->x * vec.x;
        float ny = this->y * vec.y;
        float nz = this->z * vec.z;
        float nw = this->w * vec.w;
        return ame::Vector4f(nx, ny, nz ,nw);
    }
	
    ame::Vector4f ame::Vector4f::mult(float xx, float xy, float xz, float xw) {
        return ame::Vector4f(this->x * xx, this->y * xy, this->z * xz, this->w * xw);
	}
	
    ame::Vector4f ame::Vector4f::multLocal(float scalar) {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        this->w *= scalar;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::multLocal(ame::Vector4f vec) {
        x *= vec.x;
        y *= vec.y;
        z *= vec.z;
        w *= vec.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::multLocal(float xx, float xy, float xz, float xw) {
        this->x *= xx;
        this->y *= xy;
        this->z *= xz;
        this->w *= xw;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::divide(float scalar) {
        scalar = 1.0f/scalar;
        return ame::Vector4f(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
    }
	
    ame::Vector4f ame::Vector4f::divideLocal(float scalar) {
        scalar = 1.0f/scalar;
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        this->w *= scalar;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::divide(ame::Vector4f scalar) {
        return ame::Vector4f(this->x / scalar.x, this->y / scalar.y, this->z / scalar.z, this->w / scalar.w);
    }
	
    ame::Vector4f ame::Vector4f::divideLocal(ame::Vector4f scalar) {
        this->x /= scalar.x;
        this->y /= scalar.y;
        this->z /= scalar.z;
        this->w /= scalar.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::negate() {
        return ame::Vector4f(-this->x, -this->y, -this->z, -this->w);
    }
	
    ame::Vector4f ame::Vector4f::negateLocal() {
        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;
        this->w = -this->w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::subtract(ame::Vector4f vec) {
        return ame::Vector4f(this->x - vec.x, this->y - vec.y, this->z - vec.z, this->w - vec.w);
    }
	
    ame::Vector4f ame::Vector4f::subtractLocal(ame::Vector4f vec) {
        this->x -= vec.x;
        this->y -= vec.y;
        this->z -= vec.z;
        this->w -= vec.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::subtract(float subtractX, float subtractY, 
								float subtractZ, float subtractW) {
        return ame::Vector4f(this->x - subtractX, this->y - subtractY, this->z - subtractZ, this->w - subtractW);
    }
	
    ame::Vector4f ame::Vector4f::subtractLocal(float subtractX, float subtractY, 
									float subtractZ, float subtractW) {
        this->x -= subtractX;
        this->y -= subtractY;
        this->z -= subtractZ;
        this->w -= subtractW;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::normalize() {
        float length = this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
        if (length != 1.0f && length != 0.0f){
            length = 1.0f / sqrt(length);
            return ame::Vector4f(this->x * length, this->y * length, this->z * length, this->w * length);
        }
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::normalizeLocal() {
        float length = this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
        if (length != 1.0f && length != 0.0f){
            length = 1.0f / sqrt(length);
            this->x *= length;
            this->y *= length;
            this->z *= length;
            this->w *= length;
        }
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::maxLocal(ame::Vector4f other){
        this->x = other.x > x ? other.x : this->x;
        this->y = other.y > y ? other.y : this->y;
        this->z = other.z > z ? other.z : this->z;
        this->w = other.w > w ? other.w : this->w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::minLocal(ame::Vector4f other){
        this->x = other.x < x ? other.x : this->x;
        this->y = other.y < y ? other.y : this->y;
        this->z = other.z < z ? other.z : this->z;
        this->w = other.w < w ? other.w : this->w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::zero() {
        this->x = this->y = this->z = this->w = 0;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    float ame::Vector4f::angleBetween(ame::Vector4f otherVector) {
        float dotProduct = dot(otherVector);
        float angle = acos(dotProduct);
        return angle;
    }
	
    ame::Vector4f ame::Vector4f::interpolateLocal(ame::Vector4f finalVec, float changeAmnt) {
        this->x=(1-changeAmnt)*this->x + changeAmnt*finalVec.x;
        this->y=(1-changeAmnt)*this->y + changeAmnt*finalVec.y;
        this->z=(1-changeAmnt)*this->z + changeAmnt*finalVec.z;
        this->w=(1-changeAmnt)*this->w + changeAmnt*finalVec.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    ame::Vector4f ame::Vector4f::interpolateLocal(ame::Vector4f beginVec,ame::Vector4f finalVec, 
															float changeAmnt) {
        this->x=(1-changeAmnt)*beginVec.x + changeAmnt*finalVec.x;
        this->y=(1-changeAmnt)*beginVec.y + changeAmnt*finalVec.y;
        this->z=(1-changeAmnt)*beginVec.z + changeAmnt*finalVec.z;
        this->w=(1-changeAmnt)*beginVec.w + changeAmnt*finalVec.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    bool ame::Vector4f::isValidVector(ame::Vector4f vector) {
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
	
	ame::Vector4f *ame::Vector4f::clone() {
        return new ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
    List<float> *ame::Vector4f::toArray(List<float> *list) {
        list->setLValue(0, this->x);
        list->setLValue(1, this->y);
        list->setLValue(2, this->z);
        list->setLValue(3, this->w);
        return list;
    }
	
    bool ame::Vector4f::equals(cppObject *o) {
        if ( o->getClass() != Class<ame::Vector4f>::classType ) {
			return false;
		}

        if (this == o){
			return true;
		}

        ame::Vector4f *comp = (ame::Vector4f*) o;
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
	
    bool ame::Vector4f::isSimilar(ame::Vector4f other, float epsilon) {
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
	
    String ame::Vector4f::toString() {
        return "ame::Vector4f(" + String(this->x) + ", " + String(this->y) + ", " + String(this->z) + ", " + String(this->w) + ")";
    }

    float ame::Vector4f::getX() {
        return this->x;
    }

    ame::Vector4f ame::Vector4f::setX(float xx) {
        this->x = xx;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }

    float ame::Vector4f::getY() {
        return this->y;
    }

    ame::Vector4f ame::Vector4f::setY(float xy) {
        this->y = xy;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }

    float ame::Vector4f::getZ() {
        return this->z;
    }

    ame::Vector4f ame::Vector4f::setZ(float xz) {
        this->z = xz;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }

    float ame::Vector4f::getW() {
        return this->w;
    }
	
	ame::Vector4f ame::Vector4f::setW(float xw) {
        this->w = xw;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
    }
	
	float ame::Vector4f::get(int index) {
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
	
    void ame::Vector4f::set(int index, float value) {
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
	
	
	ame::Vector4f ame::Vector4f::operator=(const ame::Vector4f& a) {
		this->x = a.x;
		this->y = a.y;
		this->z = a.z;
		this->w = a.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator=(const float& a) {
		this->x = a;
		this->y = a;
		this->z = a;
		this->w = a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator=(const float a[4]) {
		this->x = a[0];
		this->y = a[1];
		this->z = a[2];
		this->w = a[3];
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator=(const int& a) {
		this->x = (float)a;
		this->y = (float)a;
		this->z = (float)a;
		this->w = (float)a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator=(const double& a) {
		this->x = (float)a;
		this->y = (float)a;
		this->z = (float)a;
		this->w = (float)a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	bool ame::Vector4f::operator==(const ame::Vector4f& a) {
		if(this->x == a.x && this->y == a.y && this->z == a.z && this->w == a.w){
		return true;
		}
		return false;
	}
	bool ame::Vector4f::operator!=(const ame::Vector4f& a) {
		if(this->x != a.x && this->y != a.y && this->z != a.z && this->w != a.w){
			return true;
		}
		return false;
	}
	ame::Vector4f ame::Vector4f::operator+(const ame::Vector4f& a) {
		return ame::Vector4f(this->x+ a.x ,this->y + a.y ,this->z + a.z ,this->w + a.w);
	}
	ame::Vector4f ame::Vector4f::operator+(const float& a) {
		return ame::Vector4f(this->x+a ,this->y+a ,this->z + a ,this->w + a);
	}
	ame::Vector4f ame::Vector4f::operator+(const int& a) {
		return ame::Vector4f(this->x+(float)a ,this->y+(float)a ,this->z + (float)a ,this->w + (float)a);
	}
	ame::Vector4f ame::Vector4f::operator+(const double& a) {
		return ame::Vector4f(this->x+(float)a ,this->y+(float)a ,this->z + (float)a ,this->w + (float)a);
	}
	ame::Vector4f ame::Vector4f::operator-(const ame::Vector4f& a) {
		return ame::Vector4f(this->x- a.x ,this->y - a.y ,this->z - a.z ,this->w - a.w);
	}
	ame::Vector4f ame::Vector4f::operator-(const float& a) {
		return ame::Vector4f(this->x-a ,this->y-a ,this->z - a ,this->w - a);
	}
	ame::Vector4f ame::Vector4f::operator-(const int& a) {
		return ame::Vector4f(this->x- (float)a ,this->y-(float)a ,this->z - (float)a ,this->w - (float)a);
	}
	ame::Vector4f ame::Vector4f::operator-(const double& a) {
		return ame::Vector4f(this->x- (float)a ,this->y-(float)a ,this->z - (float)a ,this->w - (float)a);
	}
	ame::Vector4f ame::Vector4f::operator*(const ame::Vector4f& a) {
		return ame::Vector4f(this->x* a.x ,this->y * a.y ,this->z * a.z ,this->w * a.w);
	}
	ame::Vector4f ame::Vector4f::operator*(const float& a) {
		return ame::Vector4f(this->x* a ,this->y* a ,this->z * a ,this->w * a);
	}
	ame::Vector4f ame::Vector4f::operator*(const int& a) {
		return ame::Vector4f(this->x*(float)a ,this->y*(float)a ,this->z * (float)a ,this->w * (float)a);
	}
	ame::Vector4f ame::Vector4f::operator*(const double& a) {
		return ame::Vector4f(this->x*(float)a ,this->y*(float)a ,this->z * (float)a ,this->w * (float)a);
	}
	ame::Vector4f ame::Vector4f::operator/(const ame::Vector4f& a) {
		return ame::Vector4f(this->x/ a.x ,this->y / a.y ,this->z / a.z ,this->w / a.w);
	}
	ame::Vector4f ame::Vector4f::operator/(const float& a) {
		return ame::Vector4f(this->x/ a ,this->y/ a ,this->z / a ,this->w / a);
	}
	ame::Vector4f ame::Vector4f::operator/(const int& a) {
		return ame::Vector4f(this->x/(float)a ,this->y/(float)a ,this->z / (float)a ,this->w / (float)a);
	}
	ame::Vector4f ame::Vector4f::operator/(const double& a) {
		return ame::Vector4f(this->x/(float)a ,this->y/(float)a ,this->z / (float)a ,this->w / (float)a);
	}
	
	
	ame::Vector4f ame::Vector4f::operator+=(const ame::Vector4f& a) {
		this->x += a.x;
		this->y += a.y;
		this->z += a.z;
		this->w += a.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator+=(const float& a) {
		this->x += a;
		this->y += a;
		this->z += a;
		this->w += a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator+=(const int& a) {
		this->x += (float)a;
		this->y += (float)a;
		this->z += (float)a;
		this->w += (float)a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator+=(const double& a) {
		this->x += (float)a;
		this->y += (float)a;
		this->z += (float)a;
		this->w += (float)a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator-=(const ame::Vector4f& a) {
		this->x -= a.x;
		this->y -= a.y;
		this->z -= a.z;
		this->w -= a.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator-=(const float& a) {
		this->x -= a;
		this->y -= a;
		this->z -= a;
		this->w -= a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator-=(const int& a) {
		this->x -= (float)a;
		this->y -= (float)a;
		this->z -= (float)a;
		this->w -= (float)a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator-=(const double& a) {
		this->x -= (float)a;
		this->y -= (float)a;
		this->z -= (float)a;
		this->w -= (float)a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator*=(const ame::Vector4f& a) {
		this->x *= a.x;
		this->y *= a.y;
		this->z *= a.z;
		this->w *= a.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator*=(const float& a) {
		this->x *= a;
		this->y *= a;
		this->z *= a;
		this->w *= a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator*=(const int& a) {
		this->x *= (float)a;
		this->y *= (float)a;
		this->z *= (float)a;
		this->w *= (float)a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator*=(const double& a) {
		this->x *= (float)a;
		this->y *= (float)a;
		this->z *= (float)a;
		this->w *= (float)a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator/=(const ame::Vector4f& a) {
		this->x /= a.x;
		this->y /= a.y;
		this->z /= a.z;
		this->w /= a.w;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator/=(const float& a) {
		this->x /= a;
		this->y /= a;
		this->z /= a;
		this->w /= a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator/=(const int& a) {
		this->x /= (float)a;
		this->y /= (float)a;
		this->z /= (float)a;
		this->w /= (float)a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	ame::Vector4f ame::Vector4f::operator/=(const double& a) {
		this->x /= (float)a;
		this->y /= (float)a;
		this->z /= (float)a;
		this->w /= (float)a;
        return ame::Vector4f(this->x, this->y, this->z, this->w);
	}
	*/

#endif 
	
	
