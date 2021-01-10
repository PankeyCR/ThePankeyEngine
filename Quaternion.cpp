

#ifndef Quaternion_cpp
#define Quaternion_cpp

#include "Quaternion.h"


    Quaternion *Quaternion::IDENTITY = new Quaternion();
    Quaternion *Quaternion::DIRECTION_Z = new Quaternion();
    Quaternion *Quaternion::ZERO = new Quaternion(0, 0, 0, 0);
    
    //static {
    //   DIRECTION_Z.fromAxes(Vector3f.UNIT_X, Vector3f.UNIT_Y, Vector3f.UNIT_Z);
    //}
	
    Quaternion::Quaternion() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->w = 1;
    }
	
    Quaternion::Quaternion(float x, float y, float z, float w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    float Quaternion::getX() {
        return this->x;
    }

    float Quaternion::getY() {
        return this->y;
    }

    float Quaternion::getZ() {
        return this->z;
    }

    float Quaternion::getW() {
        return this->w;
    }
	
	Quaternion Quaternion::set(float x, float y, float z, float w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
	Quaternion Quaternion::set(Quaternion q) {
        this->x = q.x;
        this->y = q.y;
        this->z = q.z;
        this->w = q.w;
		return Quaternion(this->x, this->y, this->z, this->w);
    }

    Quaternion::Quaternion(List<float> *angles) {
        this->fromAngles(angles);
    }
	
    void Quaternion::loadIdentity() {
        this->x = this->y = this->z = 0;
        this->w = 1;
    }
	
    bool Quaternion::isIdentity() {
        if (this->x == 0 && this->y == 0 && this->z == 0 && this->w == 1) {
            return true;
        } else {
            return false;
        }
    }
	
    Quaternion Quaternion::fromAngles(List<float> *angles) {
        if (angles->getPosition() != 3) {
            //throw new IllegalArgumentException(
            //        "Angles array must have three elements");
			return Quaternion(this->x, this->y, this->z, this->w);
        }

        return this->fromAngles(*angles->getByPosition(0), *angles->getByPosition(1), *angles->getByPosition(2));
    }
	
    Quaternion Quaternion::fromAngles(float xAngle, float yAngle, float zAngle) {
        float angle;
        float sinY, sinZ, sinX, cosY, cosZ, cosX;
        angle = zAngle * 0.5f;
        sinZ = sin(angle);
        cosZ = cos(angle);
        //sinZ = FastMonkeyMath.sin(angle);
        //cosZ = FastMonkeyMath.cos(angle);
        angle = yAngle * 0.5f;
        sinY = sin(angle);
        cosY = cos(angle);
        angle = xAngle * 0.5f;
        sinX = sin(angle);
        cosX = cos(angle);

        // variables used to reduce multiplication calls.
        float cosYXcosZ = cosY * cosZ;
        float sinYXsinZ = sinY * sinZ;
        float cosYXsinZ = cosY * sinZ;
        float sinYXcosZ = sinY * cosZ;

        float cw = (cosYXcosZ * cosX - sinYXsinZ * sinX);
        float cx = (cosYXcosZ * sinX + sinYXsinZ * cosX);
        float cy = (sinYXcosZ * cosX + cosYXsinZ * sinX);
        float cz = (cosYXsinZ * cosX - sinYXcosZ * sinX);

		Quaternion rtq = Quaternion(cx, cy, cz, cw);
        rtq.normalizeLocal();
		return Quaternion(rtq.x, rtq.y, rtq.z, rtq.w);
    }
	
    Quaternion Quaternion::fromAnglesLocal(List<float> *angles) {
        if (angles->getPosition() != 3) {
            //throw new IllegalArgumentException(
            //        "Angles array must have three elements");
			return Quaternion(this->x, this->y, this->z, this->w);
        }

        return this->fromAnglesLocal(*angles->getByPosition(0), *angles->getByPosition(1), *angles->getByPosition(2));
    }
	
    Quaternion Quaternion::fromAnglesLocal(float xAngle, float yAngle, float zAngle) {
        float angle;
        float sinY, sinZ, sinX, cosY, cosZ, cosX;
        angle = zAngle * 0.5f;
        sinZ = sin(angle);
        cosZ = cos(angle);
        //sinZ = FastMonkeyMath.sin(angle);
        //cosZ = FastMonkeyMath.cos(angle);
        angle = yAngle * 0.5f;
        sinY = sin(angle);
        cosY = cos(angle);
        angle = xAngle * 0.5f;
        sinX = sin(angle);
        cosX = cos(angle);

        // variables used to reduce multiplication calls.
        float cosYXcosZ = cosY * cosZ;
        float sinYXsinZ = sinY * sinZ;
        float cosYXsinZ = cosY * sinZ;
        float sinYXcosZ = sinY * cosZ;

        this->w = (cosYXcosZ * cosX - sinYXsinZ * sinX);
        this->x = (cosYXcosZ * sinX + sinYXsinZ * cosX);
        this->y = (sinYXcosZ * cosX + cosYXsinZ * sinX);
        this->z = (cosYXsinZ * cosX - sinYXcosZ * sinX);

        this->normalizeLocal();
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    List<float> *Quaternion::toAngles(List<float> *angles) {
        if (angles == nullptr) {
            return nullptr;
            //angles = new float[3];
        } else if (angles->getPosition() < 3) {
            //throw new IllegalArgumentException("Angles array must have three elements");
        }

        float sqw = this->w * this->w;
        float sqx = this->x * this->x;
        float sqy = this->y * this->y;
        float sqz = this->z * this->z;
        float unit = sqx + sqy + sqz + sqw; // if normalized is one, otherwise
        // is correction factor
        float test = x * y + z * w;
        if (test > 0.499 * unit) { // singularity at north pole
            //angles[1] = 2 * FastMonkeyMath.atan2(x, w);
            angles->setLValue(1, 2.0f * atan2(x, w) );
            angles->setLValue(2, HALF_PI );
            angles->setLValue(0, 0.0f );
        } else if (test < -0.499f * unit) { // singularity at south pole
            //angles[1] = -2 * FastMonkeyMath.atan2(x, w);
            angles->setLValue(1, -2.0f * atan2(x, w) );
            angles->setLValue(2, -HALF_PI );
            angles->setLValue(0, 0.0f );
        } else {
            angles->setLValue(1, atan2(2 * this->y * this->w - 2 * this->x * this->z, sqx - sqy - sqz + sqw) ); // yaw or heading
            angles->setLValue(2, asin(2 * test / unit) );
            angles->setLValue(0, atan2(2 * this->x * this->w - 2 * this->y * this->z, -sqx + sqy - sqz + sqw) );
        }
        return angles;
    }
	
    Quaternion Quaternion::fromRotationMatrix(Matrix3f matrix) {
        return this->fromRotationMatrix(matrix.m00, matrix.m01, matrix.m02, matrix.m10,
                matrix.m11, matrix.m12, matrix.m20, matrix.m21, matrix.m22);
    }

    Quaternion Quaternion::fromRotationMatrix(float m00, float m01, float m02,
            float m10, float m11, float m12, float m20, float m21, float m22) {
        // first normalize the forward (F), up (U) and side (S) vectors of the rotation matrix
        // so that the scale does not affect the rotation
        float lengthSquared = m00 * m00 + m10 * m10 + m20 * m20;
        if (lengthSquared != 1.0f && lengthSquared != 0.0f) {
            lengthSquared = 1.0f / sqrt(lengthSquared);
            m00 *= lengthSquared;
            m10 *= lengthSquared;
            m20 *= lengthSquared;
        }
        lengthSquared = m01 * m01 + m11 * m11 + m21 * m21;
        if (lengthSquared != 1.0f && lengthSquared != 0.0f) {
            lengthSquared = 1.0f / sqrt(lengthSquared);
            m01 *= lengthSquared;
            m11 *= lengthSquared;
            m21 *= lengthSquared;
        }
        lengthSquared = m02 * m02 + m12 * m12 + m22 * m22;
        if (lengthSquared != 1.0f && lengthSquared != 0.0f) {
            lengthSquared = 1.0f / sqrt(lengthSquared);
            m02 *= lengthSquared;
            m12 *= lengthSquared;
            m22 *= lengthSquared;
        }

        // Use the Graphics Gems code, from 
        // ftp://ftp.cis.upenn.edu/pub/graphics/shoemake/quatut.ps.Z
        // *NOT* the "Matrix and Quaternions FAQ", which has errors!

        // the trace is the sum of the diagonal elements; see
        // http://mathworld.wolfram.com/MatrixTrace.html
        float t = m00 + m11 + m22;
		float cx,cy,cz,cw;
        // we protect the division by s by ensuring that s>=1
        if (t >= 0) { // |w| >= .5
            float s = sqrt(t + 1); // |s|>=1 ...
            cw = 0.5f * s;
            s = 0.5f / s;                 // so this division isn't bad
            cx = (m21 - m12) * s;
            cy = (m02 - m20) * s;
            cz = (m10 - m01) * s;
        } else if ((m00 > m11) && (m00 > m22)) {
            float s = sqrt(1.0f + m00 - m11 - m22); // |s|>=1
            cx = s * 0.5f; // |x| >= .5
            s = 0.5f / s;
            cy = (m10 + m01) * s;
            cz = (m02 + m20) * s;
            cw = (m21 - m12) * s;
        } else if (m11 > m22) {
            float s = sqrt(1.0f + m11 - m00 - m22); // |s|>=1
            cy = s * 0.5f; // |y| >= .5
            s = 0.5f / s;
            cx = (m10 + m01) * s;
            cz = (m21 + m12) * s;
            cw = (m02 - m20) * s;
        } else {
            float s = sqrt(1.0f + m22 - m00 - m11); // |s|>=1
            cz = s * 0.5f; // |z| >= .5
            s = 0.5f / s;
            cx = (m02 + m20) * s;
            cy = (m21 + m12) * s;
            cw = (m10 - m01) * s;
        }

		return Quaternion(cx, cy, cz, cw);
    }
	
    Quaternion Quaternion::fromRotationMatrixLocal(Matrix3f matrix) {
        return this->fromRotationMatrixLocal(matrix.m00, matrix.m01, matrix.m02, matrix.m10,
                matrix.m11, matrix.m12, matrix.m20, matrix.m21, matrix.m22);
    }

    Quaternion Quaternion::fromRotationMatrixLocal(float m00, float m01, float m02,
            float m10, float m11, float m12, float m20, float m21, float m22) {
        // first normalize the forward (F), up (U) and side (S) vectors of the rotation matrix
        // so that the scale does not affect the rotation
        float lengthSquared = m00 * m00 + m10 * m10 + m20 * m20;
        if (lengthSquared != 1.0f && lengthSquared != 0.0f) {
            lengthSquared = 1.0f / sqrt(lengthSquared);
            m00 *= lengthSquared;
            m10 *= lengthSquared;
            m20 *= lengthSquared;
        }
        lengthSquared = m01 * m01 + m11 * m11 + m21 * m21;
        if (lengthSquared != 1.0f && lengthSquared != 0.0f) {
            lengthSquared = 1.0f / sqrt(lengthSquared);
            m01 *= lengthSquared;
            m11 *= lengthSquared;
            m21 *= lengthSquared;
        }
        lengthSquared = m02 * m02 + m12 * m12 + m22 * m22;
        if (lengthSquared != 1.0f && lengthSquared != 0.0f) {
            lengthSquared = 1.0f / sqrt(lengthSquared);
            m02 *= lengthSquared;
            m12 *= lengthSquared;
            m22 *= lengthSquared;
        }

        // Use the Graphics Gems code, from 
        // ftp://ftp.cis.upenn.edu/pub/graphics/shoemake/quatut.ps.Z
        // *NOT* the "Matrix and Quaternions FAQ", which has errors!

        // the trace is the sum of the diagonal elements; see
        // http://mathworld.wolfram.com/MatrixTrace.html
        float t = m00 + m11 + m22;

        // we protect the division by s by ensuring that s>=1
        if (t >= 0) { // |w| >= .5
            float s = sqrt(t + 1); // |s|>=1 ...
            this->w = 0.5f * s;
            s = 0.5f / s;                 // so this division isn't bad
            this->x = (m21 - m12) * s;
            this->y = (m02 - m20) * s;
            this->z = (m10 - m01) * s;
        } else if ((m00 > m11) && (m00 > m22)) {
            float s = sqrt(1.0f + m00 - m11 - m22); // |s|>=1
            this->x = s * 0.5f; // |x| >= .5
            s = 0.5f / s;
            this->y = (m10 + m01) * s;
            this->z = (m02 + m20) * s;
            this->w = (m21 - m12) * s;
        } else if (m11 > m22) {
            float s = sqrt(1.0f + m11 - m00 - m22); // |s|>=1
            this->y = s * 0.5f; // |y| >= .5
            s = 0.5f / s;
            this->x = (m10 + m01) * s;
            this->z = (m21 + m12) * s;
            this->w = (m02 - m20) * s;
        } else {
            float s = sqrt(1.0f + m22 - m00 - m11); // |s|>=1
            this->z = s * 0.5f; // |z| >= .5
            s = 0.5f / s;
            this->x = (m02 + m20) * s;
            this->y = (m21 + m12) * s;
            this->w = (m10 - m01) * s;
        }

		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    Matrix3f Quaternion::toRotationMatrix3f() {

        float normm = norm();
        // we explicitly test norm against one here, saving a division
        // at the cost of a test and branch.  Is it worth it?
        float s = (normm == 1.0f) ? 2.0f : (normm > 0.0f) ? 2.0f / normm : 0.0f;

        // compute xs/ys/zs first to save 6 multiplications, since xs/ys/zs
        // will be used 2-4 times each.
        float xs = this->x * s;
        float ys = this->y * s;
        float zs = this->z * s;
        float xx = this->x * xs;
        float xy = this->x * ys;
        float xz = this->x * zs;
        float xw = this->w * xs;
        float yy = this->y * ys;
        float yz = this->y * zs;
        float yw = this->w * ys;
        float zz = this->z * zs;
        float zw = this->w * zs;
		Matrix3f result;
        // using s=2/norm (instead of 1/norm) saves 9 multiplications by 2 here
        result.m00 = 1 - (yy + zz);
        result.m01 = (xy - zw);
        result.m02 = (xz + yw);
        result.m10 = (xy + zw);
        result.m11 = 1 - (xx + zz);
        result.m12 = (yz - xw);
        result.m20 = (xz - yw);
        result.m21 = (yz + xw);
        result.m22 = 1 - (xx + yy);

        return Matrix3f(result.m00, result.m01, result.m02, result.m10, result.m11,
            result.m12, result.m20, result.m21, result.m22);
    }
	
    Matrix4f Quaternion::toTransformMatrix4f() {

		Matrix4f store;
        float normm = norm();
        // we explicitly test norm against one here, saving a division
        // at the cost of a test and branch.  Is it worth it?
        float s = (normm == 1.0f) ? 2.0f : (normm > 0.0f) ? 2.0f / normm : 0.0f;

        // compute xs/ys/zs first to save 6 multiplications, since xs/ys/zs
        // will be used 2-4 times each.
        float xs = x * s;
        float ys = y * s;
        float zs = z * s;
        float xx = x * xs;
        float xy = x * ys;
        float xz = x * zs;
        float xw = w * xs;
        float yy = y * ys;
        float yz = y * zs;
        float yw = w * ys;
        float zz = z * zs;
        float zw = w * zs;
        // using s=2/norm (instead of 1/norm) saves 9 multiplications by 2 here
        store.m00 = 1 - (yy + zz);
        store.m01 = (xy - zw);
        store.m02 = (xz + yw);
        store.m10 = (xy + zw);
        store.m11 = 1 - (xx + zz);
        store.m12 = (yz - xw);
        store.m20 = (xz - yw);
        store.m21 = (yz + xw);
        store.m22 = 1 - (xx + yy);

        return Matrix4f(store.m00, store.m01, store.m02, store.m03, 
						store.m10, store.m11, store.m12, store.m13, 
						store.m20, store.m21, store.m22, store.m23, 
						store.m30, store.m31, store.m32, store.m33);
    }
	
    Matrix4f Quaternion::toRotationMatrix4f() {
		 Matrix4f store;
        // TempVars tempv = TempVars.get();
        // Vector3f originalScale = tempv.vect1;

        // result.toScaleVector(originalScale);
        // result.setScale(1, 1, 1);
        // float normm = norm();
        ////we explicitly test norm against one here, saving a division
        ////at the cost of a test and branch.  Is it worth it?
        // float s = (normm == 1f) ? 2f : (normm > 0f) ? 2f / normm : 0;

        ////compute xs/ys/zs first to save 6 multiplications, since xs/ys/zs
        ////will be used 2-4 times each.
        // float xs = x * s;
        // float ys = y * s;
        // float zs = z * s;
        // float xx = x * xs;
        // float xy = x * ys;
        // float xz = x * zs;
        // float xw = w * xs;
        // float yy = y * ys;
        // float yz = y * zs;
        // float yw = w * ys;
        // float zz = z * zs;
        // float zw = w * zs;

        ////using s=2/norm (instead of 1/norm) saves 9 multiplications by 2 here
        // result.m00 = 1 - (yy + zz);
        // result.m01 = (xy - zw);
        // result.m02 = (xz + yw);
        // result.m10 = (xy + zw);
        // result.m11 = 1 - (xx + zz);
        // result.m12 = (yz - xw);
        // result.m20 = (xz - yw);
        // result.m21 = (yz + xw);
        // result.m22 = 1 - (xx + yy);

        // result.setScale(originalScale);

        // tempv.release();

        return Matrix4f(store.m00, store.m01, store.m02, store.m03, 
						store.m10, store.m11, store.m12, store.m13, 
						store.m20, store.m21, store.m22, store.m23, 
						store.m30, store.m31, store.m32, store.m33);
    }
	
    Vector3f Quaternion::getRotationColumn(int i) {
        Vector3f store;

        float normm = norm();
        if (normm != 1.0f) {
            normm = FastMonkeyMath::invSqrt(normm);
        }

        float xx = x * x * normm;
        float xy = x * y * normm;
        float xz = x * z * normm;
        float xw = x * w * normm;
        float yy = y * y * normm;
        float yz = y * z * normm;
        float yw = y * w * normm;
        float zz = z * z * normm;
        float zw = z * w * normm;

        switch (i) {
            case 0:
                store.x = 1 - 2 * (yy + zz);
                store.y = 2 * (xy + zw);
                store.z = 2 * (xz - yw);
                break;
            case 1:
                store.x = 2 * (xy - zw);
                store.y = 1 - 2 * (xx + zz);
                store.z = 2 * (yz + xw);
                break;
            case 2:
                store.x = 2 * (xz + yw);
                store.y = 2 * (yz - xw);
                store.z = 1 - 2 * (xx + yy);
                break;
            default:
				return Vector3f(store.x, store.y, store.z);
                //logger.warning("Invalid column index.");
                //throw new IllegalArgumentException("Invalid column index. " + i);
        }

        return Vector3f(store.x, store.y, store.z);
    }

    Quaternion Quaternion::fromAngleAxis(float angle, Vector3f axis) {
        Vector3f normAxis = axis.normalize();
		return this->fromAngleNormalAxis(angle, normAxis);
    }
    
    Quaternion Quaternion::fromAngleNormalAxis(float angle, Vector3f axis) {
        if (axis.x == 0 && axis.y == 0 && axis.z == 0) {
            //this->loadIdentity();
			return Quaternion(0, 0, 0, 1);
        } else {
            float halfAngle = 0.5f * angle;
            float sinn = sin(halfAngle);
            float sw = cos(halfAngle);
            float sx = sinn * axis.x;
            float sy = sinn * axis.y;
            float sz = sinn * axis.z;
			return Quaternion(sx, sy, sz, sw);
        }
    }

    Quaternion Quaternion::fromAngleAxisLocal(float angle, Vector3f axis) {
        Vector3f normAxis = axis.normalize();
		return this->fromAngleNormalAxisLocal(angle, normAxis);
    }
    
    Quaternion Quaternion::fromAngleNormalAxisLocal(float angle, Vector3f axis) {
        if (axis.x == 0 && axis.y == 0 && axis.z == 0) {
            this->loadIdentity();
        } else {
            float halfAngle = 0.5f * angle;
            float sinn = sin(halfAngle);
            this->w = cos(halfAngle);
            this->x = sinn * axis.x;
            this->y = sinn * axis.y;
            this->z = sinn * axis.z;
        }
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    float Quaternion::toAngleAxis() {
        float sqrLength = this->x * this->x + this->y * this->y + this->z * this->z;
        float angle;
        if (sqrLength == 0.0f) {
            angle = 0.0f;
        } else {
            angle = (2.0f * acos(w));
        }

        return angle;
    }
	
    Vector3f Quaternion::toVector3fAxis() {
		Vector3f axisStore;
        float sqrLength = this->x * this->x + this->y * this->y + this->z * this->z;
        if (sqrLength == 0.0f) {
                axisStore.x = 1.0f;
                axisStore.y = 0.0f;
                axisStore.z = 0.0f;
        } else {
                float invLength = (1.0f / sqrt(sqrLength));
                axisStore.x = this->x * invLength;
                axisStore.y = this->y * invLength;
                axisStore.z = this->z * invLength;
        }

        return axisStore;
    }
	
    Quaternion Quaternion::slerp(Quaternion q1, Quaternion q2, float t) {
        // Create a local quaternion to store the interpolated quaternion
        if (q1.x == q2.x && q1.y == q2.y && q1.z == q2.z && q1.w == q2.w) {
            this->set(q1);
			return Quaternion(this->x, this->y, this->z, this->w);
        }

        float result = (q1.x * q2.x) + (q1.y * q2.y) + (q1.z * q2.z)
                + (q1.w * q2.w);

        if (result < 0.0f) {
            // Negate the second quaternion and the result of the dot product
            q2.x = -q2.x;
            q2.y = -q2.y;
            q2.z = -q2.z;
            q2.w = -q2.w;
            result = -result;
        }

        // Set the first and second scale for the interpolation
        float scale0 = 1 - t;
        float scale1 = t;

        // Check if the angle between the 2 quaternions was big enough to
        // warrant such calculations
        if ((1 - result) > 0.1f) {// Get the angle between the 2 quaternions,
            // and then store the sin() of that angle
            float theta = acos(result);
            float invSinTheta = 1.0f / sin(theta);

            // Calculate the scale for q1 and q2, according to the angle and
            // its sine
            scale0 = sin((1 - t) * theta) * invSinTheta;
            scale1 = sin((t * theta)) * invSinTheta;
        }

        // Calculate the x, y, z and w values for the quaternion by using a
        // special
        // form of linear interpolation for quaternions.
        float tx = (scale0 * q1.x) + (scale1 * q2.x);
        float ty = (scale0 * q1.y) + (scale1 * q2.y);
        float tz = (scale0 * q1.z) + (scale1 * q2.z);
        float tw = (scale0 * q1.w) + (scale1 * q2.w);

        // Return the interpolated quaternion
		return Quaternion(tx, ty, tz, tw);
    }
	
    Quaternion Quaternion::slerpLocal(Quaternion q1, Quaternion q2, float t) {
        // Create a local quaternion to store the interpolated quaternion
        if (q1.x == q2.x && q1.y == q2.y && q1.z == q2.z && q1.w == q2.w) {
            this->set(q1);
			return Quaternion(this->x, this->y, this->z, this->w);
        }

        float result = (q1.x * q2.x) + (q1.y * q2.y) + (q1.z * q2.z)
                + (q1.w * q2.w);

        if (result < 0.0f) {
            // Negate the second quaternion and the result of the dot product
            q2.x = -q2.x;
            q2.y = -q2.y;
            q2.z = -q2.z;
            q2.w = -q2.w;
            result = -result;
        }

        // Set the first and second scale for the interpolation
        float scale0 = 1 - t;
        float scale1 = t;

        // Check if the angle between the 2 quaternions was big enough to
        // warrant such calculations
        if ((1 - result) > 0.1f) {// Get the angle between the 2 quaternions,
            // and then store the sin() of that angle
            float theta = acos(result);
            float invSinTheta = 1.0f / sin(theta);

            // Calculate the scale for q1 and q2, according to the angle and
            // its sine
            scale0 = sin((1 - t) * theta) * invSinTheta;
            scale1 = sin((t * theta)) * invSinTheta;
        }

        // Calculate the x, y, z and w values for the quaternion by using a
        // special
        // form of linear interpolation for quaternions.
        this->x = (scale0 * q1.x) + (scale1 * q2.x);
        this->y = (scale0 * q1.y) + (scale1 * q2.y);
        this->z = (scale0 * q1.z) + (scale1 * q2.z);
        this->w = (scale0 * q1.w) + (scale1 * q2.w);

        // Return the interpolated quaternion
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    Quaternion Quaternion::slerp(Quaternion q2, float changeAmnt) {
        if (this->x == q2.x && this->y == q2.y && this->z == q2.z
                && this->w == q2.w) {
			return Quaternion(this->x, this->y, this->z, this->w);
        }

        float result = (this->x * q2.x) + (this->y * q2.y) + (this->z * q2.z)
                + (this->w * q2.w);

        if (result < 0.0f) {
            // Negate the second quaternion and the result of the dot product
            q2.x = -q2.x;
            q2.y = -q2.y;
            q2.z = -q2.z;
            q2.w = -q2.w;
            result = -result;
        }

        // Set the first and second scale for the interpolation
        float scale0 = 1 - changeAmnt;
        float scale1 = changeAmnt;

        // Check if the angle between the 2 quaternions was big enough to
        // warrant such calculations
        if ((1 - result) > 0.1f) {
            // Get the angle between the 2 quaternions, and then store the sin()
            // of that angle
            float theta = acos(result);
            float invSinTheta = 1.0f / sin(theta);

            // Calculate the scale for q1 and q2, according to the angle and
            // its sine
            scale0 = sin((1 - changeAmnt) * theta) * invSinTheta;
            scale1 = sin((changeAmnt * theta)) * invSinTheta;
        }

        // Calculate the x, y, z and w values for the quaternion by using a
        // special
        // form of linear interpolation for quaternions.
        float ex = (scale0 * this->x) + (scale1 * q2.x);
        float ey = (scale0 * this->y) + (scale1 * q2.y);
        float ez = (scale0 * this->z) + (scale1 * q2.z);
        float ew = (scale0 * this->w) + (scale1 * q2.w);
		return Quaternion(ex, ey, ez, ew);
    }
	
    Quaternion Quaternion::slerpLocal(Quaternion q2, float changeAmnt) {
        if (this->x == q2.x && this->y == q2.y && this->z == q2.z
                && this->w == q2.w) {
			return Quaternion(this->x, this->y, this->z, this->w);
        }

        float result = (this->x * q2.x) + (this->y * q2.y) + (this->z * q2.z)
                + (this->w * q2.w);

        if (result < 0.0f) {
            // Negate the second quaternion and the result of the dot product
            q2.x = -q2.x;
            q2.y = -q2.y;
            q2.z = -q2.z;
            q2.w = -q2.w;
            result = -result;
        }

        // Set the first and second scale for the interpolation
        float scale0 = 1 - changeAmnt;
        float scale1 = changeAmnt;

        // Check if the angle between the 2 quaternions was big enough to
        // warrant such calculations
        if ((1 - result) > 0.1f) {
            // Get the angle between the 2 quaternions, and then store the sin()
            // of that angle
            float theta = acos(result);
            float invSinTheta = 1.0f / sin(theta);

            // Calculate the scale for q1 and q2, according to the angle and
            // its sine
            scale0 = sin((1 - changeAmnt) * theta) * invSinTheta;
            scale1 = sin((changeAmnt * theta)) * invSinTheta;
        }

        // Calculate the x, y, z and w values for the quaternion by using a
        // special
        // form of linear interpolation for quaternions.
        this->x = (scale0 * this->x) + (scale1 * q2.x);
        this->y = (scale0 * this->y) + (scale1 * q2.y);
        this->z = (scale0 * this->z) + (scale1 * q2.z);
        this->w = (scale0 * this->w) + (scale1 * q2.w);
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    Quaternion Quaternion::nlerpLocal(Quaternion q2, float blend) {
        float d = dot(q2);
        float blendI = 1.0f - blend;
		Quaternion p;
        if (d < 0.0f) {
            p.x = blendI * this->x - blend * q2.x;
            p.y = blendI * this->y - blend * q2.y;
            p.z = blendI * this->z - blend * q2.z;
            p.w = blendI * this->w - blend * q2.w;
        } else {
            p.x = blendI * this->x + blend * q2.x;
            p.y = blendI * this->y + blend * q2.y;
            p.z = blendI * this->z + blend * q2.z;
            p.w = blendI * this->w + blend * q2.w;
        }
        return p.normalizeLocal();
    }
	
    Quaternion Quaternion::nlerp(Quaternion q2, float blend) {
        float d = dot(q2);
        float blendI = 1.0f - blend;
        if (d < 0.0f) {
            this->x = blendI * this->x - blend * q2.x;
            this->y = blendI * this->y - blend * q2.y;
            this->z = blendI * this->z - blend * q2.z;
            this->w = blendI * this->w - blend * q2.w;
        } else {
            this->x = blendI * this->x + blend * q2.x;
            this->y = blendI * this->y + blend * q2.y;
            this->z = blendI * this->z + blend * q2.z;
            this->w = blendI * this->w + blend * q2.w;
        }
        return this->normalizeLocal();
    }
	
    Quaternion Quaternion::add(Quaternion q) {
        return Quaternion(this->x + q.x, this->y + q.y, this->z + q.z, this->w + q.w);
    }
	
    Quaternion Quaternion::add(float qx, float qy, float qz, float qw) {
        return  Quaternion(this->x + qx, this->y + qy, this->z + qz, this->w + qw);
    }
	
    Quaternion Quaternion::addLocal(Quaternion q) {
        this->x += q.x;
        this->y += q.y;
        this->z += q.z;
        this->w += q.w;
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    Quaternion Quaternion::addLocal(float qx, float qy, float qz, float qw) {
        this->x += qx;
        this->y += qy;
        this->z += qz;
        this->w += qw;
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    Quaternion Quaternion::subtract(Quaternion q) {
        return Quaternion(this->x - q.x, this->y - q.y, this->z - q.z, this->w - q.w);
    }
	
    Quaternion Quaternion::subtract(float qx, float qy, float qz, float qw) {
        return Quaternion(this->x - qx, this->y - qy, this->z - qz, this->w - qw);
    }
	
    Quaternion Quaternion::subtractLocal(Quaternion q) {
        this->x -= q.x;
        this->y -= q.y;
        this->z -= q.z;
        this->w -= q.w;
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    Quaternion Quaternion::subtractLocal(float qx, float qy, float qz, float qw) {
        this->x -= qx;
        this->y -= qy;
        this->z -= qz;
        this->w -= qw;
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    Quaternion Quaternion::mult(Quaternion q) {
		Quaternion res;
        float qw = q.w, qx = q.x, qy = q.y, qz = q.z;
        res.x = this->x * qw + this->y * qz - this->z * qy + this->w * qx;
        res.y = -this->x * qz + this->y * qw + this->z * qx + this->w * qy;
        res.z = this->x * qy - this->y * qx + this->z * qw + this->w * qz;
        res.w = -this->x * qx - this->y * qy - this->z * qz + this->w * qw;
		return Quaternion(res.x, res.y, res.z, res.w);
    }
	
    Quaternion Quaternion::mult(float qx, float qy, float qz, float qw) {
		Quaternion res;
        res.x = this->x * qw + this->y * qz - this->z * qy + this->w * qx;
        res.y = -this->x * qz + this->y * qw + this->z * qx + this->w * qy;
        res.z = this->x * qy - this->y * qx + this->z * qw + this->w * qz;
        res.w = -this->x * qx - this->y * qy - this->z * qz + this->w * qw;
		return Quaternion(res.x, res.y, res.z, res.w);
    }
	
    Quaternion Quaternion::apply(Matrix3f matrix) {
        float oldX = this->x, oldY = this->y, oldZ = this->z, oldW = this->w;
        Quaternion temp = this->fromRotationMatrix(matrix);

        float ox = oldX * temp.w + oldY * temp.z - oldZ * temp.y + oldW * temp.x;
        float oy = -oldX * temp.z + oldY * temp.w + oldZ * temp.x + oldW * temp.y;
        float oz = oldX * temp.y - oldY * temp.x + oldZ * temp.w + oldW * temp.z;
        float ow = -oldX * temp.x - oldY * temp.y - oldZ * temp.z + oldW * temp.w;
		return Quaternion(ox, oy, oz, ow);
    }
	
    Quaternion Quaternion::applyLocal(Matrix3f matrix) {
        float oldX = this->x, oldY = this->y, oldZ = this->z, oldW = this->w;
        this->fromRotationMatrixLocal(matrix);
        float tempX = this->x, tempY = this->y, tempZ = this->z, tempW = this->w;

        this->x = oldX * tempW + oldY * tempZ - oldZ * tempY + oldW * tempX;
        this->y = -oldX * tempZ + oldY * tempW + oldZ * tempX + oldW * tempY;
        this->z = oldX * tempY - oldY * tempX + oldZ * tempW + oldW * tempZ;
        this->w = -oldX * tempX - oldY * tempY - oldZ * tempZ + oldW * tempW;
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    Quaternion Quaternion::fromAxes(List<Vector3f> *axis) {
        if (axis->getPosition() < 3) {
            //throw new IllegalArgumentException(
            //        "Axis array must have three elements");
			return Quaternion(this->x, this->y, this->z, this->w);
        }
        return this->fromAxes(*axis->getByPosition(0), *axis->getByPosition(1), *axis->getByPosition(2));
    }
	
    Quaternion Quaternion::fromAxes(Vector3f xAxis, Vector3f yAxis, Vector3f zAxis) {
        return this->fromRotationMatrix(xAxis.x, yAxis.x, zAxis.x, xAxis.y, yAxis.y,
                zAxis.y, xAxis.z, yAxis.z, zAxis.z);
    }
	
    Quaternion Quaternion::fromAxesLocal(List<Vector3f> *axis) {
        if (axis->getPosition() < 3) {
            //throw new IllegalArgumentException(
            //        "Axis array must have three elements");
			return Quaternion(this->x, this->y, this->z, this->w);
        }
        return this->fromAxesLocal(*axis->getByPosition(0), *axis->getByPosition(1), *axis->getByPosition(2));
    }
	
    Quaternion Quaternion::fromAxesLocal(Vector3f xAxis, Vector3f yAxis, Vector3f zAxis) {
        return this->fromRotationMatrixLocal(xAxis.x, yAxis.x, zAxis.x, xAxis.y, yAxis.y,
                zAxis.y, xAxis.z, yAxis.z, zAxis.z);
    }

    List<Vector3f> *Quaternion::toAxes(List<Vector3f> *axis) {
        Matrix3f tempMat = this->toRotationMatrix3f();
		if(axis->getPosition() >= 3){
			axis->setLValue( 0, tempMat.getColumn(0) );
			axis->setLValue( 1, tempMat.getColumn(1) );
			axis->setLValue( 2, tempMat.getColumn(2) );
		}
		if(axis->getPosition() == 0){
			axis->addLValue( tempMat.getColumn(0) );
			axis->addLValue( tempMat.getColumn(1) );
			axis->addLValue( tempMat.getColumn(2) );
		}
        //axis[0] = tempMat.getColumn(0, axis->getByPosition(0));
        //axis[1] = tempMat.getColumn(1, axis->getByPosition(1));
        //axis[2] = tempMat.getColumn(2, axis->getByPosition(2));
		return axis;
    }
	
    Vector3f Quaternion::mult(Vector3f v) {
        Vector3f store;
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            store.set(0, 0, 0);
        } else {
            float vx = v.x, vy = v.y, vz = v.z;
            store.x = w * w * vx + 2 * y * w * vz - 2 * z * w * vy + x * x
                    * vx + 2 * y * x * vy + 2 * z * x * vz - z * z * vx - y
                    * y * vx;
            store.y = 2 * x * y * vx + y * y * vy + 2 * z * y * vz + 2 * w
                    * z * vx - z * z * vy + w * w * vy - 2 * x * w * vz - x
                    * x * vy;
            store.z = 2 * x * z * vx + 2 * y * z * vy + z * z * vz - 2 * w
                    * y * vx - y * y * vz + 2 * w * x * vy - x * x * vz + w
                    * w * vz;
        }
        return Vector3f(store.x, store.y, store.z);
    }
	
    // Vector3f Quaternion::multLocal(Vector3f v) {
        // float tempX, tempY;
        // tempX = w * w * v.x + 2 * y * w * v.z - 2 * z * w * v.y + x * x * v.x
                // + 2 * y * x * v.y + 2 * z * x * v.z - z * z * v.x - y * y * v.x;
        // tempY = 2 * x * y * v.x + y * y * v.y + 2 * z * y * v.z + 2 * w * z
                // * v.x - z * z * v.y + w * w * v.y - 2 * x * w * v.z - x * x
                // * v.y;
        // v.z = 2 * x * z * v.x + 2 * y * z * v.y + z * z * v.z - 2 * w * y * v.x
                // - y * y * v.z + 2 * w * x * v.y - x * x * v.z + w * w * v.z;
        // v.x = tempX;
        // v.y = tempY;
        // return Vector3f(v.x, v.y, v.z);
    // }

    Quaternion Quaternion::multLocal(Quaternion q) {
        float x1 = this->x * q.w + this->y * q.z - this->z * q.y + this->w * q.x;
        float y1 = -this->x * q.z + this->y * q.w + this->z * q.x + this->w * q.y;
        float z1 = this->x * q.y - this->y * q.x + this->z * q.w + this->w * q.z;
        this->w = -this->x * q.x - this->y * q.y - this->z * q.z + this->w * q.w;
        this->x = x1;
        this->y = y1;
        this->z = z1;
		return Quaternion(this->x, this->y, this->z, this->w);
    }

    Quaternion Quaternion::multLocal(float qx, float qy, float qz, float qw) {
        float x1 = this->x * qw + this->y * qz - this->z * qy + this->w * qx;
        float y1 = -this->x * qz + this->y * qw + this->z * qx + this->w * qy;
        float z1 = this->x * qy - this->y * qx + this->z * qw + this->w * qz;
        this->w = -this->x * qx - this->y * qy - this->z * qz + this->w * qw;
        this->x = x1;
        this->y = y1;
        this->z = z1;
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    Quaternion Quaternion::mult(float scalar) {
        return Quaternion(scalar * this->x, scalar * this->y, scalar * this->z, scalar * this->w);
    }
    Quaternion Quaternion::multLocal(float scalar) {
        this->w *= scalar;
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    float Quaternion::dot(Quaternion q) {
        return this->w * q.w + this->x * q.x + this->y * q.y + this->z * q.z;
    }
	
    float Quaternion::norm() {
        return this->w * this->w + this->x * this->x + this->y * this->y + this->z * this->z;
    }

//    @Deprecated
//    public void normalize() {
//        float n = FastMonkeyMath.invSqrt(norm());
//        x *= n;
//        y *= n;
//        z *= n;
//        w *= n;
//    }

    Quaternion Quaternion::normalize() {
        float n = FastMonkeyMath::invSqrt(norm());
        float nx = this->x * n;
        float ny = this->y * n;
        float nz = this->z * n;
        float nw = this->w * n;
		return Quaternion(nx, ny, nz, nw);
    }

    Quaternion Quaternion::normalizeLocal() {
        float n = FastMonkeyMath::invSqrt(norm());
        this->x *= n;
        this->y *= n;
        this->z *= n;
        this->w *= n;
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    Quaternion Quaternion::inverse() {
        float nor = this->norm();
        if (nor > 0.0) {
            float invNorm = 1.0f / nor;
            return Quaternion(-this->x * invNorm, -this->y * invNorm, -this->z * invNorm, this->w
                    * invNorm);
        }
        // return an invalid result to flag the error
        return nullptr;
    }
	
    Quaternion Quaternion::inverseLocal() {
        float nor = this->norm();
        if (nor > 0.0) {
            float invNorm = 1.0f / nor;
            this->x *= -invNorm;
            this->y *= -invNorm;
            this->z *= -invNorm;
            this->w *= invNorm;
        }
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    Quaternion Quaternion::negate() {
		return Quaternion(-this->x, -this->y, -this->z, -this->w);
    }
	
    Quaternion Quaternion::negateLocal() {
        this->x *= -1;
        this->y *= -1;
        this->z *= -1;
        this->w *= -1;
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
    String Quaternion::toString() {
        return "Quaternion(" + String(this->x) + ", " + String(this->y) + ", " + String(this->z) + ", " + String(this->w) + ")";
    }
	
    String Quaternion::getClassName() {
        return "Quaternion";
    }
	
    bool Quaternion::equals(cppObject *o) {

        if (this == o || (o->getClassName() == "Quaternion")) {
            return true;
        }

        Quaternion *comp = (Quaternion*) o;
        if (this->x != comp->x) {
            return false;
        }
        if (this->y != comp->y) {
            return false;
        }
        if (this->z != comp->z) {
            return false;
        }
        if (this->w != comp->w) {
            return false;
        }
        return true;
    }
	
    bool Quaternion::isSimilar(Quaternion other, float epsilon) {
        // if (abs(other.x - x) > epsilon)) {
        //if (Float.compare(Math.abs(other.x - x), epsilon) > 0) {
            // return false;
        // }
        // if (Float.compare(Math.abs(other.y - y), epsilon) > 0) {
            // return false;
        // }
        // if (Float.compare(Math.abs(other.z - z), epsilon) > 0) {
            // return false;
        // }
        // if (Float.compare(Math.abs(other.w - w), epsilon) > 0) {
            // return false;
        // }
        return true;
    }	
	
    // void Quaternion::readExternal(ObjectInput in){
        // x = in.readFloat();
        // y = in.readFloat();
        // z = in.readFloat();
        // w = in.readFloat();
    // }

    // void Quaternion::writeExternal(ObjectOutput out){
        // out.writeFloat(x);
        // out.writeFloat(y);
        // out.writeFloat(z);
        // out.writeFloat(w);
    // }
	
	
	
    void Quaternion::lookAt(Vector3f direction, Vector3f up) {
        // TempVars vars = TempVars.get();
        // vars.vect3.set(direction).normalizeLocal();
        // vars.vect1.set(up).crossLocal(direction).normalizeLocal();
        // vars.vect2.set(direction).crossLocal(vars.vect1).normalizeLocal();
        // fromAxes(vars.vect1, vars.vect2, vars.vect3);
        // vars.release();
    }

    // void Quaternion::write(JmeExporter e) throws IOException {
        // OutputCapsule cap = e.getCapsule(this);
        // cap.write(x, "x", 0);
        // cap.write(y, "y", 0);
        // cap.write(z, "z", 0);
        // cap.write(w, "w", 1);
    // }

    // void Quaternion::read(JmeImporter e) throws IOException {
        // InputCapsule cap = e.getCapsule(this);
        // x = cap.readFloat("x", 0);
        // y = cap.readFloat("y", 0);
        // z = cap.readFloat("z", 0);
        // w = cap.readFloat("w", 1);
    // }
	
	
    Quaternion Quaternion::opposite() {
        Quaternion store;

        Vector3f axis = toVector3fAxis();
        float angle = toAngleAxis();

        store.fromAngleAxis(PI + angle, axis);
		return Quaternion(store.x, store.y, store.z, store.w);
    }
	
    Quaternion Quaternion::oppositeLocal() {
        Quaternion store;

        Vector3f axis = toVector3fAxis();
        float angle = toAngleAxis();

        store.fromAngleAxis(PI + angle, axis);
        this->x = store.x;
        this->y = store.y;
        this->z = store.z;
        this->w = store.w;
		return Quaternion(this->x, this->y, this->z, this->w);
    }
	
	Quaternion *Quaternion::clone() {
		return new Quaternion(this->x, this->y, this->z, this->w);
    }

	
	
	Quaternion Quaternion::operator=(const Quaternion& a) {
		this->x = a.x;
		this->y = a.y;
		this->z = a.z;
		this->w = a.w;
        return Quaternion(this->x, this->y, this->z, this->w);
	}
	
	Quaternion Quaternion::operator=(const float a[4]) {
		this->x = a[0];
		this->y = a[1];
		this->z = a[2];
		this->w = a[3];
        return Quaternion(this->x, this->y, this->z, this->w);
	}
	
	Quaternion Quaternion::operator=(const int& a) {
		this->x = (float)a;
		this->y = (float)a;
		this->z = (float)a;
		this->w = (float)a;
        return Quaternion(this->x, this->y, this->z, this->w);
	}
	
	bool Quaternion::operator==(const Quaternion& a) {
		if(this->x == a.x && this->y == a.y && this->z == a.z && this->w == a.w){
		return true;
		}
		return false;
	}
	bool Quaternion::operator!=(const Quaternion& a) {
		if(this->x != a.x && this->y != a.y && this->z != a.z && this->w != a.w){
			return true;
		}
		return false;
	}
	Quaternion Quaternion::operator+(const Quaternion& a) {
		return Quaternion(this->x+ a.x ,this->y + a.y ,this->z + a.z ,this->w + a.w);
	}
	Quaternion Quaternion::operator+(const float a[4]) {
		return Quaternion(this->x+a[0] ,this->y+a[1] ,this->z + a[2] ,this->w + a[3]);
	}
	Quaternion Quaternion::operator-(const Quaternion& a) {
		return Quaternion(this->x- a.x ,this->y - a.y ,this->z - a.z ,this->w - a.w);
	}
	Quaternion Quaternion::operator-(const float a[4]) {
		return Quaternion(this->x-a[0] ,this->y-a[1] ,this->z - a[2] ,this->w - a[3]);
	}
	Quaternion Quaternion::operator*(const Quaternion& a) {
        float xx = this->x * a.w + this->y * a.z - this->z * a.y + this->w * a.x;
        float xy = -this->x * a.z + this->y * a.w  + this->z * a.x + this->w * a.y;
        float xz = this->x * a.y - this->y * a.x + this->z * a.w  + this->w * a.z;
        float xw = -this->x * a.x - this->y * a.y - this->z * a.z + this->w * a.w ;
		return Quaternion(xx, xy, xz, xw);
	}
	Quaternion Quaternion::operator*(const float a[4]) {
        float xx = this->x * a[3] + this->y * a[2] - this->z * a[1] + this->w * a[0];
        float xy = -this->x * a[2] + this->y * a[3] + this->z * a[0] + this->w * a[1];
        float xz = this->x * a[1] - this->y * a[0] + this->z * a[3] + this->w * a[2];
        float xw = -this->x * a[0] - this->y * a[1] - this->z * a[2] + this->w * a[3];
		return Quaternion(xx, xy, xz, xw);
	}
	// Quaternion Quaternion::operator/(const Quaternion& a) {
		// return Quaternion(this->x/ a.x ,this->y / a.y ,this->z / a.z ,this->w / a.w);
	// }
	// Quaternion Quaternion::operator/(const float a[4]) {
		// return Quaternion(this->x/ a[0] ,this->y/ a[1] ,this->z / a[2] ,this->w / a[3]);
	// }
	Quaternion Quaternion::operator/(const int a) {
		return Quaternion(this->x/ a ,this->y/ a ,this->z / a ,this->w / a);
	}
	
	
	Quaternion Quaternion::operator+=(const Quaternion& a) {
		this->x += a.x;
		this->y += a.y;
		this->z += a.z;
		this->w += a.w;
        return Quaternion(this->x, this->y, this->z, this->w);
	}
	Quaternion Quaternion::operator+=(const float a[4]) {
		this->x += a[0];
		this->y += a[1];
		this->z += a[2];
		this->w += a[3];
        return Quaternion(this->x, this->y, this->z, this->w);
	}
	Quaternion Quaternion::operator-=(const Quaternion& a) {
		this->x -= a.x;
		this->y -= a.y;
		this->z -= a.z;
		this->w -= a.w;
        return Quaternion(this->x, this->y, this->z, this->w);
	}
	Quaternion Quaternion::operator-=(const float a[4]) {
		this->x -= a[0];
		this->y -= a[1];
		this->z -= a[2];
		this->w -= a[3];
        return Quaternion(this->x, this->y, this->z, this->w);
	}
	Quaternion Quaternion::operator*=(const Quaternion& q) {
        float x1 = this->x * q.w + this->y * q.z - this->z * q.y + this->w * q.x;
        float y1 = -this->x * q.z + this->y * q.w + this->z * q.x + this->w * q.y;
        float z1 = this->x * q.y - this->y * q.x + this->z * q.w + this->w * q.z;
        this->w = -this->x * q.x - this->y * q.y - this->z * q.z + this->w * q.w;
        this->x = x1;
        this->y = y1;
        this->z = z1;
		return Quaternion(this->x, this->y, this->z, this->w);
	}
	Quaternion Quaternion::operator*=(const float a[4]) {
        float x1 = this->x * a[3] + this->y * a[2] - this->z * a[1] + this->w * a[0];
        float y1 = -this->x * a[2] + this->y * a[3] + this->z * a[0] + this->w * a[1];
        float z1 = this->x * a[1] - this->y *a[0] + this->z * a[3] + this->w * a[2];
        this->w = -this->x * a[0] - this->y * a[1] - this->z * a[2] + this->w * a[3];
        this->x = x1;
        this->y = y1;
        this->z = z1;
		return Quaternion(this->x, this->y, this->z, this->w);
	}
	// Quaternion Quaternion::operator/=(const Quaternion& a) {
		// this->x /= a.x;
		// this->y /= a.y;
		// this->z /= a.z;
		// this->w /= a.w;
        // return Quaternion(this->x, this->y, this->z, this->w);
	// }
	// Quaternion Quaternion::operator/=(const float a[4]) {
		// this->x /= a;
		// this->y /= a;
		// this->z /= a;
		// this->w /= a;
        // return Quaternion(this->x, this->y, this->z, this->w);
	// }
	
	
#endif 

	
	