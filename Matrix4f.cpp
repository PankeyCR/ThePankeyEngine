
#ifndef Matrix4f_cpp
#define Matrix4f_cpp

#include "Matrix4f.h"

	Matrix4f *Matrix4f::ZERO = new Matrix4f(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    Matrix4f *Matrix4f::IDENTITY = new Matrix4f();

	Matrix4f::Matrix4f() {
        //this->loadIdentity();
    }

	Matrix4f::Matrix4f(float m00, float m01, float m02, float m03,
            float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23,
            float m30, float m31, float m32, float m33) {

        this->m00 = m00;
        this->m01 = m01;
        this->m02 = m02;
        this->m03 = m03;
        this->m10 = m10;
        this->m11 = m11;
        this->m12 = m12;
        this->m13 = m13;
        this->m20 = m20;
        this->m21 = m21;
        this->m22 = m22;
        this->m23 = m23;
        this->m30 = m30;
        this->m31 = m31;
        this->m32 = m32;
        this->m33 = m33;
    }

	Matrix4f::Matrix4f(List<float> *array) {
		
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////

    Matrix4f Matrix4f::fromFrame(Vector3f location, Vector3f direction, Vector3f up, Vector3f left) {
        // TempVars vars = TempVars.get();
        // try {
            // Vector3f fwdVector = vars.vect1.set(direction);
            // Vector3f leftVector = vars.vect2.set(fwdVector).crossLocal(up);
            // Vector3f upVector = vars.vect3.set(leftVector).crossLocal(fwdVector);

            // m00 = leftVector.x;
            // m01 = leftVector.y;
            // m02 = leftVector.z;
            // m03 = -leftVector.dot(location);

            // m10 = upVector.x;
            // m11 = upVector.y;
            // m12 = upVector.z;
            // m13 = -upVector.dot(location);

            // m20 = -fwdVector.x;
            // m21 = -fwdVector.y;
            // m22 = -fwdVector.z;
            // m23 = fwdVector.dot(location);

            // m30 = 0f;
            // m31 = 0f;
            // m32 = 0f;
            // m33 = 1f;
        // } finally {
            // vars.release();
        // }
        return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
    }
    Matrix4f Matrix4f::fromFrameLocal(Vector3f location, Vector3f direction, Vector3f up, Vector3f left) {
		
        return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
	}
	
	


//////////////////////////////////////////////////////////////////////////////////////////////////////


	List<float> *Matrix4f::get(List<float> *matrix) {
        return this->get(matrix, true);
    }

	List<float> *Matrix4f::get(List<float> *matrix, bool rowMajor) {
        if (matrix == nullptr) {
			return nullptr;
        }
        if (matrix->getPos() == 0) {
			if (rowMajor) {
				matrix->add(m00);
				matrix->add(m01);
				matrix->add(m02);
				matrix->add(m03);
				matrix->add(m10);
				matrix->add(m11);
				matrix->add(m12);
				matrix->add(m13);
				matrix->add(m20);
				matrix->add(m21);
				matrix->add(m22);
				matrix->add(m23);
				matrix->add(m30);
				matrix->add(m31);
				matrix->add(m32);
				matrix->add(m33);
			} else {
				matrix->add(m00);
				matrix->add(m10);
				matrix->add(m20);
				matrix->add(m30);
				matrix->add(m01);
				matrix->add(m11);
				matrix->add(m21);
				matrix->add(m31);
				matrix->add(m02);
				matrix->add(m12);
				matrix->add(m22);
				matrix->add(m32);
				matrix->add(m03);
				matrix->add(m13);
				matrix->add(m23);
				matrix->add(m33);
			}
		}
		return matrix;
    }
	
	// List<float> Matrix4f::get() {
        // return get(true);
    // }

	// List<float> Matrix4f::get(bool rowMajor) {
		// ArrayList<float> matrix();
        // if (rowMajor) {
            // matrix->add(m00);
            // matrix->add(m01);
            // matrix->add(m02);
            // matrix->add(m03);
            // matrix->add(m10);
            // matrix->add(m11);
            // matrix->add(m12);
            // matrix->add(m13);
            // matrix->add(m20);
            // matrix->add(m21);
            // matrix->add(m22);
            // matrix->add(m23);
            // matrix->add(m30);
            // matrix->add(m31);
            // matrix->add(m32);
            // matrix->add(m33);
        // } else {
            // matrix->add(m00);
            // matrix->add(m10);
            // matrix->add(m20);
            // matrix->add(m30);
            // matrix->add(m01);
            // matrix->add(m11);
            // matrix->add(m21);
            // matrix->add(m31);
            // matrix->add(m02);
            // matrix->add(m12);
            // matrix->add(m22);
            // matrix->add(m32);
            // matrix->add(m03);
            // matrix->add(m13);
            // matrix->add(m23);
            // matrix->add(m33);
        // }
		// return ArrayList<float>(&matrix);
    // }

	float Matrix4f::get(int i, int j) {
        switch (i) {
            case 0:
                switch (j) {
                    case 0:
                        return m00;
                    case 1:
                        return m01;
                    case 2:
                        return m02;
                    case 3:
                        return m03;
                }
            case 1:
                switch (j) {
                    case 0:
                        return m10;
                    case 1:
                        return m11;
                    case 2:
                        return m12;
                    case 3:
                        return m13;
                }
            case 2:
                switch (j) {
                    case 0:
                        return m20;
                    case 1:
                        return m21;
                    case 2:
                        return m22;
                    case 3:
                        return m23;
                }
            case 3:
                switch (j) {
                    case 0:
                        return m30;
                    case 1:
                        return m31;
                    case 2:
                        return m32;
                    case 3:
                        return m33;
                }
        }
		return 0.0f;
    }

	// List<float> Matrix4f::getColumn(int i) {
        // return getColumn(i, NULL);
    // }

	List<float> *Matrix4f::getColumn(int i, List<float> *store) {
        if (store == nullptr) {
			return nullptr;
        }
        if (store->getPos() == 0) {
			switch (i) {
				case 0:
					store->add(this->m00);
					store->add(this->m10);
					store->add(this->m20);
					store->add(this->m30);
					break;
				case 1:
					store->add(this->m01);
					store->add(this->m11);
					store->add(this->m21);
					store->add(this->m31);
					break;
				case 2:
					store->add(this->m02);
					store->add(this->m12);
					store->add(this->m22);
					store->add(this->m32);
					break;
				case 3:
					store->add(this->m03);
					store->add(this->m13);
					store->add(this->m23);
					store->add(this->m33);
					break;
				default:
					return nullptr;
			}
		}
        return store;
    }

	Matrix4f Matrix4f::setColumn(int i, List<float> *column) {

        if (column == nullptr) {
			return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
        }
        if (column->getPos() >= 4) {
			
		}
        switch (i) {
            case 0:
                this->m00 = *column->getByPos(0);
                this->m10 = *column->getByPos(1);
                this->m20 = *column->getByPos(2);
                this->m30 = *column->getByPos(3);
                break;
            case 1:
                this->m01 = *column->getByPos(0);
                this->m11 = *column->getByPos(1);
                this->m21 = *column->getByPos(2);
                this->m31 = *column->getByPos(3);
                break;
            case 2:
                this->m02 = *column->getByPos(0);
                this->m12 = *column->getByPos(1);
                this->m22 = *column->getByPos(2);
                this->m32 = *column->getByPos(3);
                break;
            case 3:
                this->m03 = *column->getByPos(0);
                this->m13 = *column->getByPos(1);
                this->m23 = *column->getByPos(2);
                this->m33 = *column->getByPos(3);
                break;
            default:
			return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
        }
        return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
    }

	Matrix4f Matrix4f::set(int i, int j, float value) {
        switch (i) {
            case 0:
                switch (j) {
                    case 0:
                        this->m00 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                    case 1:
                        this->m01 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                    case 2:
                        this->m02 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                    case 3:
                        this->m03 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                }
            case 1:
                switch (j) {
                    case 0:
                        this->m10 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                    case 1:
                        this->m11 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                    case 2:
                        this->m12 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                    case 3:
                        this->m13 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                }
            case 2:
                switch (j) {
                    case 0:
                        this->m20 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                    case 1:
                        this->m21 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                    case 2:
                        this->m22 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                    case 3:
                        this->m23 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                }
            case 3:
                switch (j) {
                    case 0:
                        this->m30 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                    case 1:
                        this->m31 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                    case 2:
                        this->m32 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                    case 3:
                        this->m33 = value;
						return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
                }
        }
        return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
    }

	// Matrix4f Matrix4f::set(float[4][4] matrix) {
        // if (matrix.length != 4 || matrix[0].length != 4) {
			// return;
        // }

        // this->m00 = matrix[0][0];
        // this->m01 = matrix[0][1];
        // this->m02 = matrix[0][2];
        // this->m03 = matrix[0][3];
        // this->m10 = matrix[1][0];
        // this->m11 = matrix[1][1];
        // this->m12 = matrix[1][2];
        // this->m13 = matrix[1][3];
        // this->m20 = matrix[2][0];
        // this->m21 = matrix[2][1];
        // this->m22 = matrix[2][2];
        // this->m23 = matrix[2][3];
        // this->m30 = matrix[3][0];
        // this->m31 = matrix[3][1];
        // this->m32 = matrix[3][2];
        // this->m33 = matrix[3][3];
        // return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						// this->m10, this->m11, this->m12, this->m13, 
						// this->m20, this->m21, this->m22, this->m23, 
						// this->m30, this->m31, this->m32, this->m33);
    // }
    
	Matrix4f Matrix4f::set(float m00, float m01, float m02, float m03,
            float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23,
            float m30, float m31, float m32, float m33) {

        this->m00 = m00;
        this->m01 = m01;
        this->m02 = m02;
        this->m03 = m03;
        this->m10 = m10;
        this->m11 = m11;
        this->m12 = m12;
        this->m13 = m13;
        this->m20 = m20;
        this->m21 = m21;
        this->m22 = m22;
        this->m23 = m23;
        this->m30 = m30;
        this->m31 = m31;
        this->m32 = m32;
        this->m33 = m33;
        return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
    }

	Matrix4f Matrix4f::set(Matrix4f matrix) {
        this->m00 = matrix.m00;
        this->m01 = matrix.m01;
        this->m02 = matrix.m02;
        this->m03 = matrix.m03;
        this->m10 = matrix.m10;
        this->m11 = matrix.m11;
        this->m12 = matrix.m12;
        this->m13 = matrix.m13;
        this->m20 = matrix.m20;
        this->m21 = matrix.m21;
        this->m22 = matrix.m22;
        this->m23 = matrix.m23;
        this->m30 = matrix.m30;
        this->m31 = matrix.m31;
        this->m32 = matrix.m32;
        this->m33 = matrix.m33;
        return Matrix4f(this->m00, this->m01, this->m02, this->m03, 
						this->m10, this->m11, this->m12, this->m13, 
						this->m20, this->m21, this->m22, this->m23, 
						this->m30, this->m31, this->m32, this->m33);
    }
	/////////////////////////////////////////////////////////////////////////////////////////
	/*
	List<float> *Matrix4f::set(List<float> *matrix) {
        return this->set(matrix, true);
    }
	
	List<float> *Matrix4f::set(List<float> *matrix, bool rowMajor) {
        if (matrix == nullptr) {
            return nullptr;
        }
        if (matrix->getPos() < 16) {
            return matrix;
        }

        if (rowMajor) {
            this->m00 = *matrix->getByPos(0);
            this->m01 = *matrix->getByPos(1);
            this->m02 = *matrix->getByPos(2);
            this->m03 = *matrix->getByPos(3);
            this->m10 = *matrix->getByPos(4);
            this->m11 = *matrix->getByPos(5);
            this->m12 = *matrix->getByPos(6);
            this->m13 = *matrix->getByPos(7);
            this->m20 = *matrix->getByPos(8);
            this->m21 = *matrix->getByPos(9);
            this->m22 = *matrix->getByPos(10);
            this->m23 = *matrix->getByPos(11);
            this->m30 = *matrix->getByPos(12);
            this->m31 = *matrix->getByPos(13);
            this->m32 = *matrix->getByPos(14);
            this->m33 = *matrix->getByPos(15);
        } else {
            this->m00 = *matrix->getByPos(0);
            this->m01 = *matrix->getByPos(4);
            this->m02 = *matrix->getByPos(8);
            this->m03 = *matrix->getByPos(12);
            this->m10 = *matrix->getByPos(1);
            this->m11 = *matrix->getByPos(5);
            this->m12 = *matrix->getByPos(9);
            this->m13 = *matrix->getByPos(13);
            this->m20 = *matrix->getByPos(2);
            this->m21 = *matrix->getByPos(6);
            this->m22 = *matrix->getByPos(10);
            this->m23 = *matrix->getByPos(14);
            this->m30 = *matrix->getByPos(3);
            this->m31 = *matrix->getByPos(7);
            this->m32 = *matrix->getByPos(11);
            this->m33 = *matrix->getByPos(15);
        }
        return matrix;
    }

    Matrix4f Matrix4f::transpose() {
        float tmp[16];
        get(tmp, true);
        return Matrix4f(tmp);
    }
	
	Matrix4f Matrix4f::transposeLocal() {
        float tmp = m01;
        m01 = m10;
        m10 = tmp;

        tmp = m02;
        m02 = m20;
        m20 = tmp;

        tmp = m03;
        m03 = m30;
        m30 = tmp;

        tmp = m12;
        m12 = m21;
        m21 = tmp;

        tmp = m13;
        m13 = m31;
        m31 = tmp;

        tmp = m23;
        m23 = m32;
        m32 = tmp;

        return Matrix4f(this);
    }
		
    void Matrix4f::loadIdentity() {
        m01 = m02 = m03 = 0.0f;
        m10 = m12 = m13 = 0.0f;
        m20 = m21 = m23 = 0.0f;
        m30 = m31 = m32 = 0.0f;
        m00 = m11 = m22 = m33 = 1.0f;
    }

    void Matrix4f::fromFrustum(float near, float far, float left, float right, float top, float bottom, bool parallel) {
        loadIdentity();
        if (parallel) {
            // scale
            m00 = 2.0f / (right - left);
            //m11 = 2.0f / (bottom - top);
            m11 = 2.0f / (top - bottom);
            m22 = -2.0f / (far - near);
            m33 = 1f;

            // translation
            m03 = -(right + left) / (right - left);
            //m31 = -(bottom + top) / (bottom - top);
            m13 = -(top + bottom) / (top - bottom);
            m23 = -(far + near) / (far - near);
        } else {
            m00 = (2.0f * near) / (right - left);
            m11 = (2.0f * near) / (top - bottom);
            m32 = -1.0f;
            m33 = -0.0f;

            // A
            m02 = (right + left) / (right - left);

            // B 
            m12 = (top + bottom) / (top - bottom);

            // C
            m22 = -(far + near) / (far - near);

            // D
            m23 = -(2.0f * far * near) / (far - near);
        }
    }
	
	void Matrix4f::fromAngleAxis(float angle, Vector3f axis) {
        Vector3f normAxis = axis.normalize();
        fromAngleNormalAxis(angle, normAxis);
    }
	
	void Matrix4f::fromAngleNormalAxis(float angle, Vector3f axis) {
        zero();
        m33 = 1;

        float fCos = FastMath.cos(angle);
        float fSin = FastMath.sin(angle);
        float fOneMinusCos = ((float) 1.0) - fCos;
        float fX2 = axis.x * axis.x;
        float fY2 = axis.y * axis.y;
        float fZ2 = axis.z * axis.z;
        float fXYM = axis.x * axis.y * fOneMinusCos;
        float fXZM = axis.x * axis.z * fOneMinusCos;
        float fYZM = axis.y * axis.z * fOneMinusCos;
        float fXSin = axis.x * fSin;
        float fYSin = axis.y * fSin;
        float fZSin = axis.z * fSin;

        m00 = fX2 * fOneMinusCos + fCos;
        m01 = fXYM - fZSin;
        m02 = fXZM + fYSin;
        m10 = fXYM + fZSin;
        m11 = fY2 * fOneMinusCos + fCos;
        m12 = fYZM - fXSin;
        m20 = fXZM - fYSin;
        m21 = fYZM + fXSin;
        m22 = fZ2 * fOneMinusCos + fCos;
    }
	
	void Matrix4f::multLocal(float scalar) {
        m00 *= scalar;
        m01 *= scalar;
        m02 *= scalar;
        m03 *= scalar;
        m10 *= scalar;
        m11 *= scalar;
        m12 *= scalar;
        m13 *= scalar;
        m20 *= scalar;
        m21 *= scalar;
        m22 *= scalar;
        m23 *= scalar;
        m30 *= scalar;
        m31 *= scalar;
        m32 *= scalar;
        m33 *= scalar;
    }

    Matrix4f Matrix4f::mult(float scalar) {
        Matrix4f out = new Matrix4f();
        out.set(this);
        out.multLocal(scalar);
        return out;
    }

    Matrix4f Matrix4f::mult(float scalar, Matrix4f store) {
        store.set(this);
        store.multLocal(scalar);
        return store;
    }
	
	Matrix4f Matrix4f::mult(Matrix4f in2) {
        return mult(in2, null);
    }
	
	Matrix4f Matrix4f::mult(Matrix4f in2, Matrix4f store) {
        if (store == null) {
            store = new Matrix4f();
        }

        float temp00, temp01, temp02, temp03;
        float temp10, temp11, temp12, temp13;
        float temp20, temp21, temp22, temp23;
        float temp30, temp31, temp32, temp33;

        temp00 = m00 * in2.m00
                + m01 * in2.m10
                + m02 * in2.m20
                + m03 * in2.m30;
        temp01 = m00 * in2.m01
                + m01 * in2.m11
                + m02 * in2.m21
                + m03 * in2.m31;
        temp02 = m00 * in2.m02
                + m01 * in2.m12
                + m02 * in2.m22
                + m03 * in2.m32;
        temp03 = m00 * in2.m03
                + m01 * in2.m13
                + m02 * in2.m23
                + m03 * in2.m33;

        temp10 = m10 * in2.m00
                + m11 * in2.m10
                + m12 * in2.m20
                + m13 * in2.m30;
        temp11 = m10 * in2.m01
                + m11 * in2.m11
                + m12 * in2.m21
                + m13 * in2.m31;
        temp12 = m10 * in2.m02
                + m11 * in2.m12
                + m12 * in2.m22
                + m13 * in2.m32;
        temp13 = m10 * in2.m03
                + m11 * in2.m13
                + m12 * in2.m23
                + m13 * in2.m33;

        temp20 = m20 * in2.m00
                + m21 * in2.m10
                + m22 * in2.m20
                + m23 * in2.m30;
        temp21 = m20 * in2.m01
                + m21 * in2.m11
                + m22 * in2.m21
                + m23 * in2.m31;
        temp22 = m20 * in2.m02
                + m21 * in2.m12
                + m22 * in2.m22
                + m23 * in2.m32;
        temp23 = m20 * in2.m03
                + m21 * in2.m13
                + m22 * in2.m23
                + m23 * in2.m33;

        temp30 = m30 * in2.m00
                + m31 * in2.m10
                + m32 * in2.m20
                + m33 * in2.m30;
        temp31 = m30 * in2.m01
                + m31 * in2.m11
                + m32 * in2.m21
                + m33 * in2.m31;
        temp32 = m30 * in2.m02
                + m31 * in2.m12
                + m32 * in2.m22
                + m33 * in2.m32;
        temp33 = m30 * in2.m03
                + m31 * in2.m13
                + m32 * in2.m23
                + m33 * in2.m33;

        store.m00 = temp00;
        store.m01 = temp01;
        store.m02 = temp02;
        store.m03 = temp03;
        store.m10 = temp10;
        store.m11 = temp11;
        store.m12 = temp12;
        store.m13 = temp13;
        store.m20 = temp20;
        store.m21 = temp21;
        store.m22 = temp22;
        store.m23 = temp23;
        store.m30 = temp30;
        store.m31 = temp31;
        store.m32 = temp32;
        store.m33 = temp33;

        return store;
    }
	
	Matrix4f Matrix4f::multLocal(Matrix4f in2) {
        return mult(in2, this);
    }
	
	Vector3f Matrix4f::mult(Vector3f vec) {
        return mult(vec, null);
    }
	
	Vector3f Matrix4f::mult(Vector3f vec, Vector3f store) {
        if (store == null) {
            store = new Vector3f();
        }

        float vx = vec.x, vy = vec.y, vz = vec.z;
        store.x = m00 * vx + m01 * vy + m02 * vz + m03;
        store.y = m10 * vx + m11 * vy + m12 * vz + m13;
        store.z = m20 * vx + m21 * vy + m22 * vz + m23;

        return store;
    }
	
	Vector4f Matrix4f::mult(Vector4f vec) {
        return mult(vec, null);
    }
	
	Vector4f Matrix4f::mult(Vector4f vec, Vector4f store) {
        if (null == vec) {
            logger.warning("Source vector is null, null result returned.");
            return null;
        }
        if (store == null) {
            store = new Vector4f();
        }

        float vx = vec.x, vy = vec.y, vz = vec.z, vw = vec.w;
        store.x = m00 * vx + m01 * vy + m02 * vz + m03 * vw;
        store.y = m10 * vx + m11 * vy + m12 * vz + m13 * vw;
        store.z = m20 * vx + m21 * vy + m22 * vz + m23 * vw;
        store.w = m30 * vx + m31 * vy + m32 * vz + m33 * vw;

        return store;
    }
	
	Vector4f Matrix4f::multAcross(Vector4f vec) {
        return multAcross(vec, null);
    }
	
	Vector4f Matrix4f::multAcross(Vector4f vec, Vector4f store) {
        if (null == vec) {
            logger.warning("Source vector is null, null result returned.");
            return null;
        }
        if (store == null) {
            store = new Vector4f();
        }

        float vx = vec.x, vy = vec.y, vz = vec.z, vw = vec.w;
        store.x = m00 * vx + m10 * vy + m20 * vz + m30 * vw;
        store.y = m01 * vx + m11 * vy + m21 * vz + m31 * vw;
        store.z = m02 * vx + m12 * vy + m22 * vz + m32 * vw;
        store.w = m03 * vx + m13 * vy + m23 * vz + m33 * vw;

        return store;
    }
	
	Vector3f Matrix4f::multNormal(Vector3f vec, Vector3f store) {
        if (store == null) {
            store = new Vector3f();
        }

        float vx = vec.x, vy = vec.y, vz = vec.z;
        store.x = m00 * vx + m01 * vy + m02 * vz;
        store.y = m10 * vx + m11 * vy + m12 * vz;
        store.z = m20 * vx + m21 * vy + m22 * vz;

        return store;
    }
	
	Vector3f Matrix4f::multNormalAcross(Vector3f vec, Vector3f store) {
        if (store == null) {
            store = new Vector3f();
        }

        float vx = vec.x, vy = vec.y, vz = vec.z;
        store.x = m00 * vx + m10 * vy + m20 * vz;
        store.y = m01 * vx + m11 * vy + m21 * vz;
        store.z = m02 * vx + m12 * vy + m22 * vz;

        return store;
    }
	
	float Matrix4f::multProj(Vector3f vec, Vector3f store) {
        float vx = vec.x, vy = vec.y, vz = vec.z;
        store.x = m00 * vx + m01 * vy + m02 * vz + m03;
        store.y = m10 * vx + m11 * vy + m12 * vz + m13;
        store.z = m20 * vx + m21 * vy + m22 * vz + m23;
        return m30 * vx + m31 * vy + m32 * vz + m33;
    }
	
	Vector3f Matrix4f::multAcross(Vector3f vec, Vector3f store) {
        if (null == vec) {
            logger.warning("Source vector is null, null result returned.");
            return null;
        }
        if (store == null) {
            store = new Vector3f();
        }

        float vx = vec.x, vy = vec.y, vz = vec.z;
        store.x = m00 * vx + m10 * vy + m20 * vz + m30 * 1;
        store.y = m01 * vx + m11 * vy + m21 * vz + m31 * 1;
        store.z = m02 * vx + m12 * vy + m22 * vz + m32 * 1;

        return store;
    }
	
	Quaternion Matrix4f::mult(Quaternion vec, Quaternion store) {

        if (null == vec) {
            logger.warning("Source vector is null, null result returned.");
            return null;
        }
        if (store == null) {
            store = new Quaternion();
        }

        float x = m00 * vec.x + m10 * vec.y + m20 * vec.z + m30 * vec.w;
        float y = m01 * vec.x + m11 * vec.y + m21 * vec.z + m31 * vec.w;
        float z = m02 * vec.x + m12 * vec.y + m22 * vec.z + m32 * vec.w;
        float w = m03 * vec.x + m13 * vec.y + m23 * vec.z + m33 * vec.w;
        store.x = x;
        store.y = y;
        store.z = z;
        store.w = w;

        return store;
    }
	
	float *Matrix4f::mult(float[] vec4f) {
        if (null == vec4f || vec4f.length != 4) {
            logger.warning("invalid array given, must be nonnull and length 4");
            return null;
        }

        float x = vec4f[0], y = vec4f[1], z = vec4f[2], w = vec4f[3];

        vec4f[0] = m00 * x + m01 * y + m02 * z + m03 * w;
        vec4f[1] = m10 * x + m11 * y + m12 * z + m13 * w;
        vec4f[2] = m20 * x + m21 * y + m22 * z + m23 * w;
        vec4f[3] = m30 * x + m31 * y + m32 * z + m33 * w;

        return vec4f;
    }
	
	float *Matrix4f::multAcross(float[] vec4f) {
        if (null == vec4f || vec4f.length != 4) {
            logger.warning("invalid array given, must be nonnull and length 4");
            return null;
        }

        float x = vec4f[0], y = vec4f[1], z = vec4f[2], w = vec4f[3];

        vec4f[0] = m00 * x + m10 * y + m20 * z + m30 * w;
        vec4f[1] = m01 * x + m11 * y + m21 * z + m31 * w;
        vec4f[2] = m02 * x + m12 * y + m22 * z + m32 * w;
        vec4f[3] = m03 * x + m13 * y + m23 * z + m33 * w;

        return vec4f;
    }
	
	Matrix4f Matrix4f::invert() {
        return invert(null);
    }
	
	Matrix4f Matrix4f::invert(Matrix4f store) {
        if (store == null) {
            store = new Matrix4f();
        }

        float fA0 = m00 * m11 - m01 * m10;
        float fA1 = m00 * m12 - m02 * m10;
        float fA2 = m00 * m13 - m03 * m10;
        float fA3 = m01 * m12 - m02 * m11;
        float fA4 = m01 * m13 - m03 * m11;
        float fA5 = m02 * m13 - m03 * m12;
        float fB0 = m20 * m31 - m21 * m30;
        float fB1 = m20 * m32 - m22 * m30;
        float fB2 = m20 * m33 - m23 * m30;
        float fB3 = m21 * m32 - m22 * m31;
        float fB4 = m21 * m33 - m23 * m31;
        float fB5 = m22 * m33 - m23 * m32;
        float fDet = fA0 * fB5 - fA1 * fB4 + fA2 * fB3 + fA3 * fB2 - fA4 * fB1 + fA5 * fB0;

        if (FastMath.abs(fDet) <= 0f) {
            throw new ArithmeticException("This matrix cannot be inverted");
        }

        store.m00 = +m11 * fB5 - m12 * fB4 + m13 * fB3;
        store.m10 = -m10 * fB5 + m12 * fB2 - m13 * fB1;
        store.m20 = +m10 * fB4 - m11 * fB2 + m13 * fB0;
        store.m30 = -m10 * fB3 + m11 * fB1 - m12 * fB0;
        store.m01 = -m01 * fB5 + m02 * fB4 - m03 * fB3;
        store.m11 = +m00 * fB5 - m02 * fB2 + m03 * fB1;
        store.m21 = -m00 * fB4 + m01 * fB2 - m03 * fB0;
        store.m31 = +m00 * fB3 - m01 * fB1 + m02 * fB0;
        store.m02 = +m31 * fA5 - m32 * fA4 + m33 * fA3;
        store.m12 = -m30 * fA5 + m32 * fA2 - m33 * fA1;
        store.m22 = +m30 * fA4 - m31 * fA2 + m33 * fA0;
        store.m32 = -m30 * fA3 + m31 * fA1 - m32 * fA0;
        store.m03 = -m21 * fA5 + m22 * fA4 - m23 * fA3;
        store.m13 = +m20 * fA5 - m22 * fA2 + m23 * fA1;
        store.m23 = -m20 * fA4 + m21 * fA2 - m23 * fA0;
        store.m33 = +m20 * fA3 - m21 * fA1 + m22 * fA0;

        float fInvDet = 1.0f / fDet;
        store.multLocal(fInvDet);

        return store;
    }
	
	Matrix4f Matrix4f::invertLocal() {

        float fA0 = m00 * m11 - m01 * m10;
        float fA1 = m00 * m12 - m02 * m10;
        float fA2 = m00 * m13 - m03 * m10;
        float fA3 = m01 * m12 - m02 * m11;
        float fA4 = m01 * m13 - m03 * m11;
        float fA5 = m02 * m13 - m03 * m12;
        float fB0 = m20 * m31 - m21 * m30;
        float fB1 = m20 * m32 - m22 * m30;
        float fB2 = m20 * m33 - m23 * m30;
        float fB3 = m21 * m32 - m22 * m31;
        float fB4 = m21 * m33 - m23 * m31;
        float fB5 = m22 * m33 - m23 * m32;
        float fDet = fA0 * fB5 - fA1 * fB4 + fA2 * fB3 + fA3 * fB2 - fA4 * fB1 + fA5 * fB0;

        if (FastMath.abs(fDet) <= 0f) {
            return zero();
        }

        float f00 = +m11 * fB5 - m12 * fB4 + m13 * fB3;
        float f10 = -m10 * fB5 + m12 * fB2 - m13 * fB1;
        float f20 = +m10 * fB4 - m11 * fB2 + m13 * fB0;
        float f30 = -m10 * fB3 + m11 * fB1 - m12 * fB0;
        float f01 = -m01 * fB5 + m02 * fB4 - m03 * fB3;
        float f11 = +m00 * fB5 - m02 * fB2 + m03 * fB1;
        float f21 = -m00 * fB4 + m01 * fB2 - m03 * fB0;
        float f31 = +m00 * fB3 - m01 * fB1 + m02 * fB0;
        float f02 = +m31 * fA5 - m32 * fA4 + m33 * fA3;
        float f12 = -m30 * fA5 + m32 * fA2 - m33 * fA1;
        float f22 = +m30 * fA4 - m31 * fA2 + m33 * fA0;
        float f32 = -m30 * fA3 + m31 * fA1 - m32 * fA0;
        float f03 = -m21 * fA5 + m22 * fA4 - m23 * fA3;
        float f13 = +m20 * fA5 - m22 * fA2 + m23 * fA1;
        float f23 = -m20 * fA4 + m21 * fA2 - m23 * fA0;
        float f33 = +m20 * fA3 - m21 * fA1 + m22 * fA0;

        m00 = f00;
        m01 = f01;
        m02 = f02;
        m03 = f03;
        m10 = f10;
        m11 = f11;
        m12 = f12;
        m13 = f13;
        m20 = f20;
        m21 = f21;
        m22 = f22;
        m23 = f23;
        m30 = f30;
        m31 = f31;
        m32 = f32;
        m33 = f33;

        float fInvDet = 1.0f / fDet;
        multLocal(fInvDet);

        return this;
    }
	
	Matrix4f Matrix4f::adjoint() {
        return adjoint(null);
    }
	
	void Matrix4f::setTransform(Vector3f position, Vector3f scale, Matrix3f rotMat) {
        // Ordering:
        //    1. Scale
        //    2. Rotate
        //    3. Translate

        // Set up final matrix with scale, rotation and translation
        m00 = scale.x * rotMat.m00;
        m01 = scale.y * rotMat.m01;
        m02 = scale.z * rotMat.m02;
        m03 = position.x;
        m10 = scale.x * rotMat.m10;
        m11 = scale.y * rotMat.m11;
        m12 = scale.z * rotMat.m12;
        m13 = position.y;
        m20 = scale.x * rotMat.m20;
        m21 = scale.y * rotMat.m21;
        m22 = scale.z * rotMat.m22;
        m23 = position.z;

        // No projection term
        m30 = 0;
        m31 = 0;
        m32 = 0;
        m33 = 1;
    }
	
	Matrix4f Matrix4f::adjoint(Matrix4f store) {
        if (store == null) {
            store = new Matrix4f();
        }

        float fA0 = m00 * m11 - m01 * m10;
        float fA1 = m00 * m12 - m02 * m10;
        float fA2 = m00 * m13 - m03 * m10;
        float fA3 = m01 * m12 - m02 * m11;
        float fA4 = m01 * m13 - m03 * m11;
        float fA5 = m02 * m13 - m03 * m12;
        float fB0 = m20 * m31 - m21 * m30;
        float fB1 = m20 * m32 - m22 * m30;
        float fB2 = m20 * m33 - m23 * m30;
        float fB3 = m21 * m32 - m22 * m31;
        float fB4 = m21 * m33 - m23 * m31;
        float fB5 = m22 * m33 - m23 * m32;

        store.m00 = +m11 * fB5 - m12 * fB4 + m13 * fB3;
        store.m10 = -m10 * fB5 + m12 * fB2 - m13 * fB1;
        store.m20 = +m10 * fB4 - m11 * fB2 + m13 * fB0;
        store.m30 = -m10 * fB3 + m11 * fB1 - m12 * fB0;
        store.m01 = -m01 * fB5 + m02 * fB4 - m03 * fB3;
        store.m11 = +m00 * fB5 - m02 * fB2 + m03 * fB1;
        store.m21 = -m00 * fB4 + m01 * fB2 - m03 * fB0;
        store.m31 = +m00 * fB3 - m01 * fB1 + m02 * fB0;
        store.m02 = +m31 * fA5 - m32 * fA4 + m33 * fA3;
        store.m12 = -m30 * fA5 + m32 * fA2 - m33 * fA1;
        store.m22 = +m30 * fA4 - m31 * fA2 + m33 * fA0;
        store.m32 = -m30 * fA3 + m31 * fA1 - m32 * fA0;
        store.m03 = -m21 * fA5 + m22 * fA4 - m23 * fA3;
        store.m13 = +m20 * fA5 - m22 * fA2 + m23 * fA1;
        store.m23 = -m20 * fA4 + m21 * fA2 - m23 * fA0;
        store.m33 = +m20 * fA3 - m21 * fA1 + m22 * fA0;

        return store;
    }
	
	float Matrix4f::determinant() {
        float fA0 = m00 * m11 - m01 * m10;
        float fA1 = m00 * m12 - m02 * m10;
        float fA2 = m00 * m13 - m03 * m10;
        float fA3 = m01 * m12 - m02 * m11;
        float fA4 = m01 * m13 - m03 * m11;
        float fA5 = m02 * m13 - m03 * m12;
        float fB0 = m20 * m31 - m21 * m30;
        float fB1 = m20 * m32 - m22 * m30;
        float fB2 = m20 * m33 - m23 * m30;
        float fB3 = m21 * m32 - m22 * m31;
        float fB4 = m21 * m33 - m23 * m31;
        float fB5 = m22 * m33 - m23 * m32;
        float fDet = fA0 * fB5 - fA1 * fB4 + fA2 * fB3 + fA3 * fB2 - fA4 * fB1 + fA5 * fB0;
        return fDet;
    }
	
	Matrix4f Matrix4f::zero() {
        m00 = m01 = m02 = m03 = 0.0f;
        m10 = m11 = m12 = m13 = 0.0f;
        m20 = m21 = m22 = m23 = 0.0f;
        m30 = m31 = m32 = m33 = 0.0f;
        return this;
    }
	
	Matrix4f Matrix4f::add(Matrix4f mat) {
        Matrix4f result = new Matrix4f();
        result.m00 = this.m00 + mat.m00;
        result.m01 = this.m01 + mat.m01;
        result.m02 = this.m02 + mat.m02;
        result.m03 = this.m03 + mat.m03;
        result.m10 = this.m10 + mat.m10;
        result.m11 = this.m11 + mat.m11;
        result.m12 = this.m12 + mat.m12;
        result.m13 = this.m13 + mat.m13;
        result.m20 = this.m20 + mat.m20;
        result.m21 = this.m21 + mat.m21;
        result.m22 = this.m22 + mat.m22;
        result.m23 = this.m23 + mat.m23;
        result.m30 = this.m30 + mat.m30;
        result.m31 = this.m31 + mat.m31;
        result.m32 = this.m32 + mat.m32;
        result.m33 = this.m33 + mat.m33;
        return result;
    }
	
	void Matrix4f::addLocal(Matrix4f mat) {
        m00 += mat.m00;
        m01 += mat.m01;
        m02 += mat.m02;
        m03 += mat.m03;
        m10 += mat.m10;
        m11 += mat.m11;
        m12 += mat.m12;
        m13 += mat.m13;
        m20 += mat.m20;
        m21 += mat.m21;
        m22 += mat.m22;
        m23 += mat.m23;
        m30 += mat.m30;
        m31 += mat.m31;
        m32 += mat.m32;
        m33 += mat.m33;
    }

    Vector3f Matrix4f::toTranslationVector() {
        return new Vector3f(m03, m13, m23);
    }

    void Matrix4f::toTranslationVector(Vector3f vector) {
        vector.set(m03, m13, m23);
    }

    Quaternion Matrix4f::toRotationQuat() {
        Quaternion quat = new Quaternion();
        quat.fromRotationMatrix(toRotationMatrix());
        return quat;
    }

    void Matrix4f::toRotationQuat(Quaternion q) {
        q.fromRotationMatrix(toRotationMatrix());
    }

    Matrix3f Matrix4f::toRotationMatrix() {
        return new Matrix3f(m00, m01, m02, m10, m11, m12, m20, m21, m22);
    }
	
	void Matrix4f::toRotationMatrix(Matrix3f mat) {
        mat.m00 = m00;
        mat.m01 = m01;
        mat.m02 = m02;
        mat.m10 = m10;
        mat.m11 = m11;
        mat.m12 = m12;
        mat.m20 = m20;
        mat.m21 = m21;
        mat.m22 = m22;
	}
	
	Vector3f Matrix4f::toScaleVector() {
		Vector3f result = new Vector3f();
		this.toScaleVector(result);
		return result;
	}
	
	void Matrix4f::toScaleVector(Vector3f vector) {
		float scaleX = (float) Math.sqrt(m00 * m00 + m10 * m10 + m20 * m20);
		float scaleY = (float) Math.sqrt(m01 * m01 + m11 * m11 + m21 * m21);
		float scaleZ = (float) Math.sqrt(m02 * m02 + m12 * m12 + m22 * m22);
		vector.set(scaleX, scaleY, scaleZ);
    }
	
	void Matrix4f::setScale(float x, float y, float z) {
        TempVars vars = TempVars.get();
        vars.vect1.set(m00, m10, m20);
        vars.vect1.normalizeLocal().multLocal(x);
        m00 = vars.vect1.x;
        m10 = vars.vect1.y;
        m20 = vars.vect1.z;

        vars.vect1.set(m01, m11, m21);
        vars.vect1.normalizeLocal().multLocal(y);
        m01 = vars.vect1.x;
        m11 = vars.vect1.y;
        m21 = vars.vect1.z;

        vars.vect1.set(m02, m12, m22);
        vars.vect1.normalizeLocal().multLocal(z);
        m02 = vars.vect1.x;
        m12 = vars.vect1.y;
        m22 = vars.vect1.z;
        vars.release();
    }
	
	void Matrix4f::setScale(Vector3f scale) {
        this.setScale(scale.x, scale.y, scale.z);
    }
	
	void Matrix4f::setTranslation(float[] translation) {
        if (translation.length != 3) {
            throw new IllegalArgumentException(
                    "Translation size must be 3.");
        }
        m03 = translation[0];
        m13 = translation[1];
        m23 = translation[2];
    }
	
	void Matrix4f::setTranslation(float x, float y, float z) {
        m03 = x;
        m13 = y;
        m23 = z;
    }
	
	void Matrix4f::setTranslation(Vector3f translation) {
        m03 = translation.x;
        m13 = translation.y;
        m23 = translation.z;
    }
	
	void Matrix4f::setInverseTranslation(float[] translation) {
        if (translation.length != 3) {
            throw new IllegalArgumentException(
                    "Translation size must be 3.");
        }
        m03 = -translation[0];
        m13 = -translation[1];
        m23 = -translation[2];
    }
	
	void Matrix4f::angleRotation(Vector3f angles) {
        float angle;
        float sr, sp, sy, cr, cp, cy;

        angle = (angles.z * FastMath.DEG_TO_RAD);
        sy = FastMath.sin(angle);
        cy = FastMath.cos(angle);
        angle = (angles.y * FastMath.DEG_TO_RAD);
        sp = FastMath.sin(angle);
        cp = FastMath.cos(angle);
        angle = (angles.x * FastMath.DEG_TO_RAD);
        sr = FastMath.sin(angle);
        cr = FastMath.cos(angle);

        // matrix = (Z * Y) * X
        m00 = cp * cy;
        m10 = cp * sy;
        m20 = -sp;
        m01 = sr * sp * cy + cr * -sy;
        m11 = sr * sp * sy + cr * cy;
        m21 = sr * cp;
        m02 = (cr * sp * cy + -sr * -sy);
        m12 = (cr * sp * sy + -sr * cy);
        m22 = cr * cp;
        m03 = 0.0f;
        m13 = 0.0f;
        m23 = 0.0f;
    }
	
	void Matrix4f::setRotationQuaternion(Quaternion quat) {
        quat.toRotationMatrix(this);
    }
	
	void Matrix4f::setInverseRotationRadians(float[] angles) {
        if (angles.length != 3) {
            throw new IllegalArgumentException(
                    "Angles must be of size 3.");
        }
        double cr = FastMath.cos(angles[0]);
        double sr = FastMath.sin(angles[0]);
        double cp = FastMath.cos(angles[1]);
        double sp = FastMath.sin(angles[1]);
        double cy = FastMath.cos(angles[2]);
        double sy = FastMath.sin(angles[2]);

        m00 = (float) (cp * cy);
        m10 = (float) (cp * sy);
        m20 = (float) (-sp);

        double srsp = sr * sp;
        double crsp = cr * sp;

        m01 = (float) (srsp * cy - cr * sy);
        m11 = (float) (srsp * sy + cr * cy);
        m21 = (float) (sr * cp);

        m02 = (float) (crsp * cy + sr * sy);
        m12 = (float) (crsp * sy - sr * cy);
        m22 = (float) (cr * cp);
    }
	
	void Matrix4f::setInverseRotationDegrees(float[] angles) {
        if (angles.length != 3) {
            throw new IllegalArgumentException(
                    "Angles must be of size 3.");
        }
        float vec[] = new float[3];
        vec[0] = (angles[0] * FastMath.RAD_TO_DEG);
        vec[1] = (angles[1] * FastMath.RAD_TO_DEG);
        vec[2] = (angles[2] * FastMath.RAD_TO_DEG);
        setInverseRotationRadians(vec);
    }

	void Matrix4f::inverseTranslateVect(float[] vec) {
        if (vec.length != 3) {
            throw new IllegalArgumentException(
                    "vec must be of size 3.");
        }

        vec[0] = vec[0] - m03;
        vec[1] = vec[1] - m13;
        vec[2] = vec[2] - m23;
    }
	
    void Matrix4f::inverseTranslateVect(Vector3f data) {
        data.x -= m03;
        data.y -= m13;
        data.z -= m23;
    }
	
    void Matrix4f::translateVect(Vector3f data) {
        data.x += m03;
        data.y += m13;
        data.z += m23;
    }
	
    void Matrix4f::inverseRotateVect(Vector3f vec) {
        float vx = vec.x, vy = vec.y, vz = vec.z;

        vec.x = vx * m00 + vy * m10 + vz * m20;
        vec.y = vx * m01 + vy * m11 + vz * m21;
        vec.z = vx * m02 + vy * m12 + vz * m22;
    }

    void Matrix4f::rotateVect(Vector3f vec) {
        float vx = vec.x, vy = vec.y, vz = vec.z;

        vec.x = vx * m00 + vy * m01 + vz * m02;
        vec.y = vx * m10 + vy * m11 + vz * m12;
        vec.z = vx * m20 + vy * m21 + vz * m22;
    }
	
    String Matrix4f::toString() {
        StringBuilder result = new StringBuilder("Matrix4f\n[\n");
        result.append(" ");
        result.append(m00);
        result.append("  ");
        result.append(m01);
        result.append("  ");
        result.append(m02);
        result.append("  ");
        result.append(m03);
        result.append(" \n");
        result.append(" ");
        result.append(m10);
        result.append("  ");
        result.append(m11);
        result.append("  ");
        result.append(m12);
        result.append("  ");
        result.append(m13);
        result.append(" \n");
        result.append(" ");
        result.append(m20);
        result.append("  ");
        result.append(m21);
        result.append("  ");
        result.append(m22);
        result.append("  ");
        result.append(m23);
        result.append(" \n");
        result.append(" ");
        result.append(m30);
        result.append("  ");
        result.append(m31);
        result.append("  ");
        result.append(m32);
        result.append("  ");
        result.append(m33);
        result.append(" \n]");
        return result.toString();
    }

    bool Matrix4f::equals(Object *o) {
        if (!(o instanceof Matrix4f) || o == null) {
            return false;
        }

        if (this == o) {
            return true;
        }

        Matrix4f comp = (Matrix4f) o;
        if (Float.compare(m00, comp.m00) != 0) {
            return false;
        }
        if (Float.compare(m01, comp.m01) != 0) {
            return false;
        }
        if (Float.compare(m02, comp.m02) != 0) {
            return false;
        }
        if (Float.compare(m03, comp.m03) != 0) {
            return false;
        }

        if (Float.compare(m10, comp.m10) != 0) {
            return false;
        }
        if (Float.compare(m11, comp.m11) != 0) {
            return false;
        }
        if (Float.compare(m12, comp.m12) != 0) {
            return false;
        }
        if (Float.compare(m13, comp.m13) != 0) {
            return false;
        }

        if (Float.compare(m20, comp.m20) != 0) {
            return false;
        }
        if (Float.compare(m21, comp.m21) != 0) {
            return false;
        }
        if (Float.compare(m22, comp.m22) != 0) {
            return false;
        }
        if (Float.compare(m23, comp.m23) != 0) {
            return false;
        }

        if (Float.compare(m30, comp.m30) != 0) {
            return false;
        }
        if (Float.compare(m31, comp.m31) != 0) {
            return false;
        }
        if (Float.compare(m32, comp.m32) != 0) {
            return false;
        }
        if (Float.compare(m33, comp.m33) != 0) {
            return false;
        }

        return true;
    }
	
	
	
	

    // void write(JmeExporter e) throws IOException {
        // OutputCapsule cap = e.getCapsule(this);
        // cap.write(m00, "m00", 1);
        // cap.write(m01, "m01", 0);
        // cap.write(m02, "m02", 0);
        // cap.write(m03, "m03", 0);
        // cap.write(m10, "m10", 0);
        // cap.write(m11, "m11", 1);
        // cap.write(m12, "m12", 0);
        // cap.write(m13, "m13", 0);
        // cap.write(m20, "m20", 0);
        // cap.write(m21, "m21", 0);
        // cap.write(m22, "m22", 1);
        // cap.write(m23, "m23", 0);
        // cap.write(m30, "m30", 0);
        // cap.write(m31, "m31", 0);
        // cap.write(m32, "m32", 0);
        // cap.write(m33, "m33", 1);
    // }

    // void read(JmeImporter e) throws IOException {
        // InputCapsule cap = e.getCapsule(this);
        // m00 = cap.readFloat("m00", 1);
        // m01 = cap.readFloat("m01", 0);
        // m02 = cap.readFloat("m02", 0);
        // m03 = cap.readFloat("m03", 0);
        // m10 = cap.readFloat("m10", 0);
        // m11 = cap.readFloat("m11", 1);
        // m12 = cap.readFloat("m12", 0);
        // m13 = cap.readFloat("m13", 0);
        // m20 = cap.readFloat("m20", 0);
        // m21 = cap.readFloat("m21", 0);
        // m22 = cap.readFloat("m22", 1);
        // m23 = cap.readFloat("m23", 0);
        // m30 = cap.readFloat("m30", 0);
        // m31 = cap.readFloat("m31", 0);
        // m32 = cap.readFloat("m32", 0);
        // m33 = cap.readFloat("m33", 1);
    // }
	
    bool Matrix4f::isIdentity() {
        return (m00 == 1 && m01 == 0 && m02 == 0 && m03 == 0)
                && (m10 == 0 && m11 == 1 && m12 == 0 && m13 == 0)
                && (m20 == 0 && m21 == 0 && m22 == 1 && m23 == 0)
                && (m30 == 0 && m31 == 0 && m32 == 0 && m33 == 1);
    }
	
    void Matrix4f::scale(Vector3f scale) {
        m00 *= scale.getX();
        m10 *= scale.getX();
        m20 *= scale.getX();
        m30 *= scale.getX();
        m01 *= scale.getY();
        m11 *= scale.getY();
        m21 *= scale.getY();
        m31 *= scale.getY();
        m02 *= scale.getZ();
        m12 *= scale.getZ();
        m22 *= scale.getZ();
        m32 *= scale.getZ();
    }

    bool Matrix4f::equalIdentity(Matrix4f mat) {
        if (Math.abs(mat.m00 - 1) > 1e-4) {
            return false;
        }
        if (Math.abs(mat.m11 - 1) > 1e-4) {
            return false;
        }
        if (Math.abs(mat.m22 - 1) > 1e-4) {
            return false;
        }
        if (Math.abs(mat.m33 - 1) > 1e-4) {
            return false;
        }

        if (Math.abs(mat.m01) > 1e-4) {
            return false;
        }
        if (Math.abs(mat.m02) > 1e-4) {
            return false;
        }
        if (Math.abs(mat.m03) > 1e-4) {
            return false;
        }

        if (Math.abs(mat.m10) > 1e-4) {
            return false;
        }
        if (Math.abs(mat.m12) > 1e-4) {
            return false;
        }
        if (Math.abs(mat.m13) > 1e-4) {
            return false;
        }

        if (Math.abs(mat.m20) > 1e-4) {
            return false;
        }
        if (Math.abs(mat.m21) > 1e-4) {
            return false;
        }
        if (Math.abs(mat.m23) > 1e-4) {
            return false;
        }

        if (Math.abs(mat.m30) > 1e-4) {
            return false;
        }
        if (Math.abs(mat.m31) > 1e-4) {
            return false;
        }
        if (Math.abs(mat.m32) > 1e-4) {
            return false;
        }

        return true;
    }

	void Matrix4f::multLocal(Quaternion rotation) {
        Vector3f axis = new Vector3f();
        float angle = rotation.toAngleAxis(axis);
        Matrix4f matrix4f = new Matrix4f();
        matrix4f.fromAngleAxis(angle, axis);
        multLocal(matrix4f);
    }

    Matrix4f *Matrix4f::clone() {
		
    }
*/
	
	
	
#endif 
	
	
	