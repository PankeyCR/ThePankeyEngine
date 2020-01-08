
#ifndef Vector2f_cpp
#define Vector2f_cpp

#include "Vector2f.h"

    Vector2f *Vector2f::ZERO = new Vector2f(0.00f, 0.00f);
    Vector2f *Vector2f::UNIT_XY = new Vector2f(1.00f, 1.00f);
	
    Vector2f::Vector2f(float xx, float yy) {
        this->x = xx;
        this->y = yy;
    }

    Vector2f::Vector2f() {
        this->x = this->y = 0;
    }

    Vector2f Vector2f::set(float xx, float yy) {
        this->x = xx;
        this->y = yy;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::set(Vector2f vec) {
        this->x = vec.x;
        this->y = vec.y;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::add(float scalar) {
        return Vector2f(this->x + scalar, this->y + scalar);
    }

    Vector2f Vector2f::add(Vector2f vec) {
        return Vector2f(x + vec.x, y + vec.y);
    }

    Vector2f Vector2f::add(float addX, float addY) {
        float xx = this->x + addX;
        float yy = this->y + addY;
        return Vector2f(xx, yy);
    }

    Vector2f Vector2f::addLocal(Vector2f vec) {
        this->x += vec.x;
        this->y += vec.y;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::addLocal(float addX, float addY) {
        this->x += addX;
        this->y += addY;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::addLocal(float scalar) {
        this->x += scalar;
        this->y += scalar;
        return Vector2f(this->x, this->y);
    }

    float Vector2f::dot(Vector2f vec) {
        return this->x * vec.x + this->y * vec.y;
    }

    Vector3f Vector2f::cross(Vector2f v) {
        return Vector3f(0, 0, determinant(v));
    }

    float Vector2f::determinant(Vector2f v) {
        return (this->x * v.y) - (this->y * v.x);
    }

    float Vector2f::determinant(float XX, float YY) {
        return (this->x * YY) - (this->y * XX);
    }
    
    Vector2f Vector2f::interpolateLocal(Vector2f finalVec, float changeAmnt) {
        this->x = (1 - changeAmnt) * this->x + changeAmnt * finalVec.x;
        this->y = (1 - changeAmnt) * this->y + changeAmnt * finalVec.y;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::interpolateLocal(Vector2f beginVec, Vector2f finalVec,
																float changeAmnt) {
        this->x = (1 - changeAmnt) * beginVec.x + changeAmnt * finalVec.x;
        this->y = (1 - changeAmnt) * beginVec.y + changeAmnt * finalVec.y;
        return Vector2f(this->x, this->y);
    }

    bool Vector2f::isValidVector(Vector2f vector) {
    //  if (Float.isNaN(vector.x) ||
    //      Float.isNaN(vector.y)) return false;
    //  if (Float.isInfinite(vector.x) ||
    //      Float.isInfinite(vector.y)) return false;
      return true;
    }

    float Vector2f::length() {
        return sqrt(lengthSquared());
    }

    float Vector2f::lengthSquared() {
        return this->x * this->x + this->y * this->y;
    }
///////////////////////////////////////////////////////////////////////////////////////////
    float Vector2f::distanceSquared(Vector2f v) {
        double dx = this->x - v.x;
        double dy = this->y - v.y;
        return (float) (dx * dx + dy * dy);
    }

    float Vector2f::distanceSquared(float otherX, float otherY) {
        double dx = this->x - otherX;
        double dy = this->y - otherY;
        return (float) (dx * dx + dy * dy);
    }

    float Vector2f::distance(Vector2f v) {
        return sqrt(distanceSquared(v));
    }

    float Vector2f::distance(float XX, float YY) {
        return sqrt(distanceSquared(XX, YY));
    }

    Vector2f Vector2f::mult(float scalar) {
        return Vector2f(this->x * scalar, this->y * scalar);
    }

    Vector2f Vector2f::mult(Vector2f vec) {
        return Vector2f(this->x * vec.x, this->y * vec.y);
    }

    Vector2f Vector2f::mult(float mulX, float mulY) {
        return Vector2f(this->x * mulX, this->y * mulY);
    }

    Vector2f Vector2f::multLocal(float scalar) {
        this->x *= scalar;
        this->y *= scalar;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::multLocal(Vector2f vec) {
        x *= vec.x;
        y *= vec.y;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::multLocal(float mulX, float mulY) {
        this->x *= mulX;
        this->y *= mulY;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::divide(float scalar) {
        return Vector2f(this->x / scalar, this->y / scalar);
    }

    Vector2f Vector2f::divideLocal(float scalar) {
        this->x /= scalar;
        this->y /= scalar;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::divideLocal(Vector2f vec) {
        this->x /= vec.x;
        this->y /= vec.y;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::divideLocal(float XX, float YY) {
        this->x /= XX;
        this->y /= YY;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::divide(Vector2f vec) {
        return Vector2f(this->x / vec.x, this->y / vec.y);
    }

    Vector2f Vector2f::divide(float XX, float YY) {
        return Vector2f(this->x / XX, this->y / YY);
    }

    Vector2f Vector2f::negate() {
        return Vector2f(-this->x, -this->y);
    }

    Vector2f Vector2f::negateLocal() {
        this->x = -this->x;
        this->y = -this->y;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::subtract(Vector2f vec) {
        return Vector2f(this->x - vec.x , this->y - vec.y);
    }

    Vector2f Vector2f::subtract(float scalar) {
        return Vector2f(this->x - scalar,this->y - scalar);
    }

    Vector2f Vector2f::subtract(float valX, float valY) {
        return Vector2f(this->x - valX, this->y - valY);
    }

    Vector2f Vector2f::subtractLocal(float scalar) {
        this->x -= scalar;
        this->y -= scalar;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::subtractLocal(Vector2f vec) {
        this->x -= vec.x;
        this->y -= vec.y;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::subtractLocal(float valX, float valY) {
        this->x -= valX;
        this->y -= valY;
        return Vector2f(this->x, this->y);
    }

    Vector2f Vector2f::normalize() {
        float lengthN = this->length();
        if (lengthN != 0) {
            return this->divide(lengthN);
        }

        return this->divide(1);
    }

    Vector2f Vector2f::normalizeLocal() {
        float lengthN = this->length();
        if (lengthN != 0) {
            return this->divideLocal(lengthN);
        }

        return this->divideLocal(1);
    }

    float Vector2f::smallestAngleBetween(Vector2f otherVector) {
        float dotProduct = dot(otherVector);
        float angle = acos(dotProduct);
        return angle;
    }

    float Vector2f::angleBetween(Vector2f otherVector) {
        float angle = atan2(otherVector.y, otherVector.x)
                - atan2(this->y, this->x);
        return angle;
    }
    
    float Vector2f::getX() {
        return this->x;
    }

    Vector2f Vector2f::setX(float xx) {
        this->x = xx;
        return Vector2f(this->x, this->y);
    }

    float Vector2f::getY() {
        return this->y;
    }

    Vector2f Vector2f::setY(float yy) {
        this->y = yy;
        return Vector2f(this->x, this->y);
    }

    float Vector2f::getAngle() {
        return atan2(this->y, this->x);
    }

    Vector2f Vector2f::zero() {
        this->x = 0;
		this->y = 0;
        return Vector2f(this->x, this->y);
    }
	
    List<float> *Vector2f::toArray(List<float> *floats) {
		if (floats == nullptr) {
		   return nullptr;
		}
		floats->set(0, this->x);
		floats->set(1, this->y);
		return floats;
	}

    bool Vector2f::equals(cppObject *o) {
        if (!(o->getClassName() =="Vector2f")) {
            return false;
        }

        if (this == o) {
            return true;
        }

        Vector2f *comp = (Vector2f*) o;
        if (this->x !=comp->x){
            return false;
		}
		if (this->y != comp->y){
            return false;
		}
        return true;
    }

    String Vector2f::toString() {
        return "Vector2f(" + String(this->x) + ", " + String(this->y) + ")";
    }

/*
    void readExternal(ObjectInput in) throws IOException,
            ClassNotFoundException {
        x = in.readFloat();
        y = in.readFloat();
    }

    void writeExternal(ObjectOutput out) throws IOException {
        out.writeFloat(x);
        out.writeFloat(y);
    }

    void write(JmeExporter e) throws IOException {
        OutputCapsule capsule = e.getCapsule(this);
        capsule.write(x, "x", 0);
        capsule.write(y, "y", 0);
    }

    void read(JmeImporter e) throws IOException {
        InputCapsule capsule = e.getCapsule(this);
        x = capsule.readFloat("x", 0);
        y = capsule.readFloat("y", 0);
    }
*/
    Vector2f Vector2f::rotateAroundOrigin(float angle, boolean cw) {
        if (cw){
            angle = -angle;
		}
		float rad = (PI/180.0f)*angle;
        float newX = cos(rad) * this->x - sin(rad) * this->y;
        float newY = sin(rad) * this->x + cos(rad) * this->y;
        float xx = newX;
        float yy = newY;
        return Vector2f(xx, yy);
    }
	
    Vector2f Vector2f::rotateAroundOriginLocal(float angle, boolean cw) {
        if (cw){
            angle = -angle;
		}
		float rad = (PI/180.0f)*angle;
        float newX = cos(rad) * this->x - sin(rad) * this->y;
        float newY = sin(rad) * this->x + cos(rad) * this->y;
        this->x = newX;
        this->y = newY;
        return Vector2f(this->x, this->y);
    }
	
	Vector2f Vector2f::rotate(float angle){
		float rad = (PI*angle)/180.0f;
		float coseno = (float)cos(rad);
		float seno = (float)sin(rad);
		return Vector2f((this->x * coseno - this->y * seno),(this->x * seno + this->y * coseno));
    }
	
	Vector2f Vector2f::rotateLocal(float angle){
		float rad = (PI*angle)/180.0f;
		float coseno = (float)cos(rad);
		float seno = (float)sin(rad);
		float xx = this->x * coseno - this->y * seno;
		float yy = this->x * seno + this->y * coseno;
		this->set(xx,yy);
        return Vector2f(this->x, this->y);
    }
	
	String Vector2f::getClassName(){
		return "Vector2f";
	}
	

    Vector2f *Vector2f::clone(){
		Vector2f *v = new Vector2f();
		v->x = this->x;
		v->y = this->y;
		return v;
    }
	
	Vector2f Vector2f::operator=(const Vector2f& a) {
		this->x = a.x;
		this->y = a.y;
        return Vector2f(this->x, this->y);
	}
	Vector2f Vector2f::operator=(const float& a) {
		this->x = a;
		this->y = a;
        return Vector2f(this->x, this->y);
	}
	Vector2f Vector2f::operator=(const float a[2]) {
		this->x = a[0];
		this->y = a[1];
        return Vector2f(this->x, this->y);
	}
	Vector2f Vector2f::operator=(const int& a) {
		this->x = (float)a;
		this->y = (float)a;
        return Vector2f(this->x, this->y);
	}
	Vector2f Vector2f::operator=(const double& a) {
		this->x = (float)a;
		this->y = (float)a;
        return Vector2f(this->x, this->y);
	}
	bool Vector2f::operator==(const Vector2f& a) {
		if(this->x == a.x && this->y == a.y){
		return true;
		}
		return false;
	}
	bool Vector2f::operator!=(const Vector2f& a) {
		if(this->x != a.x && this->y != a.y){
			return true;
		}
		return false;
	}
	Vector2f Vector2f::operator+(const Vector2f& a) {
		return Vector2f(this->x+ a.x ,this->y + a.y);
	}
	Vector2f Vector2f::operator+(const float& a) {
		return Vector2f(this->x+a ,this->y+a);
	}
	Vector2f Vector2f::operator+(const int& a) {
		return Vector2f(this->x+(float)a ,this->y+(float)a);
	}
	Vector2f Vector2f::operator+(const double& a) {
		return Vector2f(this->x+(float)a ,this->y+(float)a);
	}
	Vector2f Vector2f::operator-(const Vector2f& a) {
		return Vector2f(this->x- a.x ,this->y - a.y);
	}
	Vector2f Vector2f::operator-(const float& a) {
		return Vector2f(this->x-a ,this->y-a);
	}
	Vector2f Vector2f::operator-(const int& a) {
		return Vector2f(this->x- (float)a ,this->y-(float)a);
	}
	Vector2f Vector2f::operator-(const double& a) {
		return Vector2f(this->x- (float)a ,this->y-(float)a);
	}
	Vector2f Vector2f::operator*(const Vector2f& a) {
		return Vector2f(this->x* a.x ,this->y * a.y);
	}
	Vector2f Vector2f::operator*(const float& a) {
		return Vector2f(this->x* a ,this->y* a);
	}
	Vector2f Vector2f::operator*(const int& a) {
		return Vector2f(this->x*(float)a ,this->y*(float)a);
	}
	Vector2f Vector2f::operator*(const double& a) {
		return Vector2f(this->x*(float)a ,this->y*(float)a);
	}
	Vector2f Vector2f::operator/(const Vector2f& a) {
		return Vector2f(this->x/ a.x ,this->y / a.y);
	}
	Vector2f Vector2f::operator/(const float& a) {
		return Vector2f(this->x/ a ,this->y/ a);
	}
	Vector2f Vector2f::operator/(const int& a) {
		return Vector2f(this->x/(float)a ,this->y/(float)a);
	}
	Vector2f Vector2f::operator/(const double& a) {
		return Vector2f(this->x/(float)a ,this->y/(float)a);
	}
	
	
	Vector2f Vector2f::operator+=(const Vector2f& a) {
		this->x += a.x;
		this->y += a.y;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator+=(const float& a) {
		this->x += a;
		this->y += a;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator+=(const int& a) {
		this->x += (float)a;
		this->y += (float)a;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator+=(const double& a) {
		this->x += (float)a;
		this->y += (float)a;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator-=(const Vector2f& a) {
		this->x -= a.x;
		this->y -= a.y;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator-=(const float& a) {
		this->x -= a;
		this->y -= a;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator-=(const int& a) {
		this->x -= (float)a;
		this->y -= (float)a;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator-=(const double& a) {
		this->x -= (float)a;
		this->y -= (float)a;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator*=(const Vector2f& a) {
		this->x *= a.x;
		this->y *= a.y;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator*=(const float& a) {
		this->x *= a;
		this->y *= a;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator*=(const int& a) {
		this->x *= (float)a;
		this->y *= (float)a;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator*=(const double& a) {
		this->x *= (float)a;
		this->y *= (float)a;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator/=(const Vector2f& a) {
		this->x /= a.x;
		this->y /= a.y;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator/=(const float& a) {
		this->x /= a;
		this->y /= a;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator/=(const int& a) {
		this->x /= (float)a;
		this->y /= (float)a;
		return Vector2f(this->x,this->y);
	}
	Vector2f Vector2f::operator/=(const double& a) {
		this->x /= (float)a;
		this->y /= (float)a;
		return Vector2f(this->x,this->y);
	}
	
#endif 
