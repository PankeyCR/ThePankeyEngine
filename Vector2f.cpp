
#ifndef Vector2f_cpp
#define Vector2f_cpp

#include "Vector2f.h"

    ame::Vector2f *ame::Vector2f::ZERO = new ame::Vector2f(0.00f, 0.00f);
    ame::Vector2f *ame::Vector2f::UNIT_XY = new ame::Vector2f(1.00f, 1.00f);
	
    ame::Vector2f::Vector2f(float xx, float yy) {
        this->x = xx;
        this->y = yy;
    }

    ame::Vector2f::Vector2f() {
        this->x = this->y = 0;
    }

    ame::Vector2f::Vector2f(const ame::Vector2f& v) {
        this->x = v.x;
        this->y = v.y;
    }

    ame::Vector2f ame::Vector2f::set(float xx, float yy) {
        this->x = xx;
        this->y = yy;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::set(ame::Vector2f vec) {
        this->x = vec.x;
        this->y = vec.y;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::add(float scalar) {
        return ame::Vector2f(this->x + scalar, this->y + scalar);
    }

    ame::Vector2f ame::Vector2f::add(ame::Vector2f vec) {
        return ame::Vector2f(x + vec.x, y + vec.y);
    }

    ame::Vector2f ame::Vector2f::add(float addX, float addY) {
        float xx = this->x + addX;
        float yy = this->y + addY;
        return ame::Vector2f(xx, yy);
    }

    ame::Vector2f ame::Vector2f::addLocal(ame::Vector2f vec) {
        this->x += vec.x;
        this->y += vec.y;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::addLocal(float addX, float addY) {
        this->x += addX;
        this->y += addY;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::addLocal(float scalar) {
        this->x += scalar;
        this->y += scalar;
        return ame::Vector2f(this->x, this->y);
    }

    float ame::Vector2f::dot(ame::Vector2f vec) {
        return this->x * vec.x + this->y * vec.y;
    }

    ame::Vector3f ame::Vector2f::cross(ame::Vector2f v) {
        return Vector3f(0, 0, determinant(v));
    }

    float ame::Vector2f::determinant(ame::Vector2f v) {
        return (this->x * v.y) - (this->y * v.x);
    }

    float ame::Vector2f::determinant(float XX, float YY) {
        return (this->x * YY) - (this->y * XX);
    }
    
    ame::Vector2f ame::Vector2f::interpolateLocal(ame::Vector2f finalVec, float changeAmnt) {
        this->x = (1 - changeAmnt) * this->x + changeAmnt * finalVec.x;
        this->y = (1 - changeAmnt) * this->y + changeAmnt * finalVec.y;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::interpolateLocal(ame::Vector2f beginVec, ame::Vector2f finalVec,
																float changeAmnt) {
        this->x = (1 - changeAmnt) * beginVec.x + changeAmnt * finalVec.x;
        this->y = (1 - changeAmnt) * beginVec.y + changeAmnt * finalVec.y;
        return ame::Vector2f(this->x, this->y);
    }

    bool ame::Vector2f::isValidVector(ame::Vector2f vector) {
    //  if (Float.isNaN(vector.x) ||
    //      Float.isNaN(vector.y)) return false;
    //  if (Float.isInfinite(vector.x) ||
    //      Float.isInfinite(vector.y)) return false;
      return true;
    }

    float ame::Vector2f::length() {
        return sqrt(lengthSquared());
    }

    float ame::Vector2f::lengthSquared() {
        return this->x * this->x + this->y * this->y;
    }
///////////////////////////////////////////////////////////////////////////////////////////
    float ame::Vector2f::distanceSquared(ame::Vector2f v) {
        double dx = this->x - v.x;
        double dy = this->y - v.y;
        return (float) (dx * dx + dy * dy);
    }

    float ame::Vector2f::distanceSquared(float otherX, float otherY) {
        double dx = this->x - otherX;
        double dy = this->y - otherY;
        return (float) (dx * dx + dy * dy);
    }

    float ame::Vector2f::distance(ame::Vector2f v) {
        return sqrt(distanceSquared(v));
    }

    float ame::Vector2f::distance(float XX, float YY) {
        return sqrt(distanceSquared(XX, YY));
    }

    ame::Vector2f ame::Vector2f::mult(float scalar) {
        return ame::Vector2f(this->x * scalar, this->y * scalar);
    }

    ame::Vector2f ame::Vector2f::mult(ame::Vector2f vec) {
        return ame::Vector2f(this->x * vec.x, this->y * vec.y);
    }

    ame::Vector2f ame::Vector2f::mult(float mulX, float mulY) {
        return ame::Vector2f(this->x * mulX, this->y * mulY);
    }

    ame::Vector2f ame::Vector2f::multLocal(float scalar) {
        this->x *= scalar;
        this->y *= scalar;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::multLocal(ame::Vector2f vec) {
        x *= vec.x;
        y *= vec.y;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::multLocal(float mulX, float mulY) {
        this->x *= mulX;
        this->y *= mulY;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::divide(float scalar) {
        return ame::Vector2f(this->x / scalar, this->y / scalar);
    }

    ame::Vector2f ame::Vector2f::divideLocal(float scalar) {
        this->x /= scalar;
        this->y /= scalar;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::divideLocal(ame::Vector2f vec) {
        this->x /= vec.x;
        this->y /= vec.y;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::divideLocal(float XX, float YY) {
        this->x /= XX;
        this->y /= YY;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::divide(ame::Vector2f vec) {
        return ame::Vector2f(this->x / vec.x, this->y / vec.y);
    }

    ame::Vector2f ame::Vector2f::divide(float XX, float YY) {
        return ame::Vector2f(this->x / XX, this->y / YY);
    }

    ame::Vector2f ame::Vector2f::negate() {
        return ame::Vector2f(-this->x, -this->y);
    }

    ame::Vector2f ame::Vector2f::negateLocal() {
        this->x = -this->x;
        this->y = -this->y;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::subtract(ame::Vector2f vec) {
        return ame::Vector2f(this->x - vec.x , this->y - vec.y);
    }

    ame::Vector2f ame::Vector2f::subtract(float scalar) {
        return ame::Vector2f(this->x - scalar,this->y - scalar);
    }

    ame::Vector2f ame::Vector2f::subtract(float valX, float valY) {
        return ame::Vector2f(this->x - valX, this->y - valY);
    }

    ame::Vector2f ame::Vector2f::subtractLocal(float scalar) {
        this->x -= scalar;
        this->y -= scalar;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::subtractLocal(ame::Vector2f vec) {
        this->x -= vec.x;
        this->y -= vec.y;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::subtractLocal(float valX, float valY) {
        this->x -= valX;
        this->y -= valY;
        return ame::Vector2f(this->x, this->y);
    }

    ame::Vector2f ame::Vector2f::normalize() {
        float lengthN = this->length();
        if (lengthN != 0) {
            return this->divide(lengthN);
        }

        return this->divide(1);
    }

    ame::Vector2f ame::Vector2f::normalizeLocal() {
        float lengthN = this->length();
        if (lengthN != 0) {
            return this->divideLocal(lengthN);
        }

        return this->divideLocal(1);
    }

    float ame::Vector2f::smallestAngleBetween(ame::Vector2f otherVector) {
        float dotProduct = dot(otherVector);
        float angle = acos(dotProduct);
        return angle;
    }

    float ame::Vector2f::angleBetween(ame::Vector2f otherVector) {
        float angle = atan2(otherVector.y, otherVector.x)
                - atan2(this->y, this->x);
        return angle;
    }
    
    float ame::Vector2f::getX() {
        return this->x;
    }

    ame::Vector2f ame::Vector2f::setX(float xx) {
        this->x = xx;
        return ame::Vector2f(this->x, this->y);
    }

    float ame::Vector2f::getY() {
        return this->y;
    }

    ame::Vector2f ame::Vector2f::setY(float yy) {
        this->y = yy;
        return ame::Vector2f(this->x, this->y);
    }

    float ame::Vector2f::getAngle() {
        return atan2(this->y, this->x);
    }

    ame::Vector2f ame::Vector2f::zero() {
        this->x = 0;
		this->y = 0;
        return ame::Vector2f(this->x, this->y);
    }
	
    ame::List<float> *ame::Vector2f::toArray(ame::List<float> *floats) {
		if (floats == nullptr) {
		   return nullptr;
		}
		floats->setLValue(0, this->x);
		floats->setLValue(1, this->y);
		return floats;
	}

    bool ame::Vector2f::equals(ame::cppObject *o) {
        if (!(o->getClass() == ame::Class<ame::Vector2f>::classType)) {
            return false;
        }

        if (this == o) {
            return true;
        }

        ame::Vector2f *comp = (ame::Vector2f*) o;
        if (this->x !=comp->x){
            return false;
		}
		if (this->y != comp->y){
            return false;
		}
        return true;
    }

    String ame::Vector2f::toString() {
        return "Vector2f(" + String(this->x) + ", " + String(this->y) + ")";
    }


    // void readExternal(ObjectInput in) throws IOException,
            // ClassNotFoundException {
        // x = in.readFloat();
        // y = in.readFloat();
    // }

    // void writeExternal(ObjectOutput out) throws IOException {
        // out.writeFloat(x);
        // out.writeFloat(y);
    // }

    // void write(JmeExporter e) throws IOException {
        // OutputCapsule capsule = e.getCapsule(this);
        // capsule.write(x, "x", 0);
        // capsule.write(y, "y", 0);
    // }

    // void read(JmeImporter e) throws IOException {
        // InputCapsule capsule = e.getCapsule(this);
        // x = capsule.readFloat("x", 0);
        // y = capsule.readFloat("y", 0);
    // }

    ame::Vector2f ame::Vector2f::rotateAroundOrigin(float angle, boolean cw) {
        if (cw){
            angle = -angle;
		}
		float rad = (PI/180.0f)*angle;
        float newX = cos(rad) * this->x - sin(rad) * this->y;
        float newY = sin(rad) * this->x + cos(rad) * this->y;
        float xx = newX;
        float yy = newY;
        return ame::Vector2f(xx, yy);
    }
	
    ame::Vector2f ame::Vector2f::rotateAroundOriginLocal(float angle, boolean cw) {
        if (cw){
            angle = -angle;
		}
		float rad = (PI/180.0f)*angle;
        float newX = cos(rad) * this->x - sin(rad) * this->y;
        float newY = sin(rad) * this->x + cos(rad) * this->y;
        this->x = newX;
        this->y = newY;
        return ame::Vector2f(this->x, this->y);
    }
	
	ame::Vector2f ame::Vector2f::rotate(float angle){
		float rad = (PI*angle)/180.0f;
		float coseno = (float)cos(rad);
		float seno = (float)sin(rad);
		return ame::Vector2f((this->x * coseno - this->y * seno),(this->x * seno + this->y * coseno));
    }
	
	ame::Vector2f ame::Vector2f::rotateLocal(float angle){
		float rad = (PI*angle)/180.0f;
		float coseno = (float)cos(rad);
		float seno = (float)sin(rad);
		float xx = this->x * coseno - this->y * seno;
		float yy = this->x * seno + this->y * coseno;
		this->set(xx,yy);
        return ame::Vector2f(this->x, this->y);
    }
	
	ame::cppObjectClass* ame::Vector2f::getClass(){
		return ame::Class<ame::Vector2f>::classType;
	}
	

    ame::Vector2f *ame::Vector2f::clone(){
		ame::Vector2f *v = new ame::Vector2f();
		v->x = this->x;
		v->y = this->y;
		return v;
    }
	
	ame::Vector2f ame::Vector2f::operator=(const ame::Vector2f& a) {
		this->x = a.x;
		this->y = a.y;
        return ame::Vector2f(this->x, this->y);
	}
	ame::Vector2f ame::Vector2f::operator=(const float& a) {
		this->x = a;
		this->y = a;
        return ame::Vector2f(this->x, this->y);
	}
	ame::Vector2f ame::Vector2f::operator=(const float a[2]) {
		this->x = a[0];
		this->y = a[1];
        return ame::Vector2f(this->x, this->y);
	}
	ame::Vector2f ame::Vector2f::operator=(const int& a) {
		this->x = (float)a;
		this->y = (float)a;
        return ame::Vector2f(this->x, this->y);
	}
	ame::Vector2f ame::Vector2f::operator=(const double& a) {
		this->x = (float)a;
		this->y = (float)a;
        return ame::Vector2f(this->x, this->y);
	}
	bool ame::Vector2f::operator==(const ame::Vector2f& a) {
		if(this->x == a.x && this->y == a.y){
		return true;
		}
		return false;
	}
	bool ame::Vector2f::operator!=(const ame::Vector2f& a) {
		if(this->x != a.x && this->y != a.y){
			return true;
		}
		return false;
	}
	ame::Vector2f ame::Vector2f::operator+(const ame::Vector2f& a) {
		return ame::Vector2f(this->x+ a.x ,this->y + a.y);
	}
	ame::Vector2f ame::Vector2f::operator+(const float& a) {
		return ame::Vector2f(this->x+a ,this->y+a);
	}
	ame::Vector2f ame::Vector2f::operator+(const int& a) {
		return ame::Vector2f(this->x+(float)a ,this->y+(float)a);
	}
	ame::Vector2f ame::Vector2f::operator+(const double& a) {
		return ame::Vector2f(this->x+(float)a ,this->y+(float)a);
	}
	ame::Vector2f ame::Vector2f::operator-(const ame::Vector2f& a) {
		return ame::Vector2f(this->x- a.x ,this->y - a.y);
	}
	ame::Vector2f ame::Vector2f::operator-(const float& a) {
		return ame::Vector2f(this->x-a ,this->y-a);
	}
	ame::Vector2f ame::Vector2f::operator-(const int& a) {
		return ame::Vector2f(this->x- (float)a ,this->y-(float)a);
	}
	ame::Vector2f ame::Vector2f::operator-(const double& a) {
		return ame::Vector2f(this->x- (float)a ,this->y-(float)a);
	}
	ame::Vector2f ame::Vector2f::operator*(const ame::Vector2f& a) {
		return ame::Vector2f(this->x* a.x ,this->y * a.y);
	}
	ame::Vector2f ame::Vector2f::operator*(const float& a) {
		return ame::Vector2f(this->x* a ,this->y* a);
	}
	ame::Vector2f ame::Vector2f::operator*(const int& a) {
		return ame::Vector2f(this->x*(float)a ,this->y*(float)a);
	}
	ame::Vector2f ame::Vector2f::operator*(const double& a) {
		return ame::Vector2f(this->x*(float)a ,this->y*(float)a);
	}
	ame::Vector2f ame::Vector2f::operator/(const ame::Vector2f& a) {
		return ame::Vector2f(this->x/ a.x ,this->y / a.y);
	}
	ame::Vector2f ame::Vector2f::operator/(const float& a) {
		return ame::Vector2f(this->x/ a ,this->y/ a);
	}
	ame::Vector2f ame::Vector2f::operator/(const int& a) {
		return ame::Vector2f(this->x/(float)a ,this->y/(float)a);
	}
	ame::Vector2f ame::Vector2f::operator/(const double& a) {
		return ame::Vector2f(this->x/(float)a ,this->y/(float)a);
	}
	
	
	ame::Vector2f ame::Vector2f::operator+=(const ame::Vector2f& a) {
		this->x += a.x;
		this->y += a.y;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator+=(const float& a) {
		this->x += a;
		this->y += a;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator+=(const int& a) {
		this->x += (float)a;
		this->y += (float)a;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator+=(const double& a) {
		this->x += (float)a;
		this->y += (float)a;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator-=(const ame::Vector2f& a) {
		this->x -= a.x;
		this->y -= a.y;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator-=(const float& a) {
		this->x -= a;
		this->y -= a;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator-=(const int& a) {
		this->x -= (float)a;
		this->y -= (float)a;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator-=(const double& a) {
		this->x -= (float)a;
		this->y -= (float)a;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator*=(const ame::Vector2f& a) {
		this->x *= a.x;
		this->y *= a.y;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator*=(const float& a) {
		this->x *= a;
		this->y *= a;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator*=(const int& a) {
		this->x *= (float)a;
		this->y *= (float)a;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator*=(const double& a) {
		this->x *= (float)a;
		this->y *= (float)a;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator/=(const ame::Vector2f& a) {
		this->x /= a.x;
		this->y /= a.y;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator/=(const float& a) {
		this->x /= a;
		this->y /= a;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator/=(const int& a) {
		this->x /= (float)a;
		this->y /= (float)a;
		return ame::Vector2f(this->x,this->y);
	}
	ame::Vector2f ame::Vector2f::operator/=(const double& a) {
		this->x /= (float)a;
		this->y /= (float)a;
		return ame::Vector2f(this->x,this->y);
	}

#endif 
