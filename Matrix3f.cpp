

#ifndef Matrix3f_cpp
#define Matrix3f_cpp

#include "Matrix3f.h"

    Matrix3f *Matrix3f::ZERO = new Matrix3f(0, 0, 0, 0, 0, 0, 0, 0, 0);
    Matrix3f *Matrix3f::IDENTITY = new Matrix3f();

    Matrix3f::Matrix3f() {
        this->loadIdentity();
    }
	
    Matrix3f::Matrix3f(float m00, float m01, float m02, float m10, float m11,
            float m12, float m20, float m21, float m22) {

        this->m00 = m00;
        this->m01 = m01;
        this->m02 = m02;
        this->m10 = m10;
        this->m11 = m11;
        this->m12 = m12;
        this->m20 = m20;
        this->m21 = m21;
        this->m22 = m22;
    }
	
    Matrix3f Matrix3f::absolute() {
        float mm00 = abs(this->m00);
        float mm01 = abs(this->m01);
        float mm02 = abs(this->m02);
        float mm10 = abs(this->m10);
        float mm11 = abs(this->m11);
        float mm12 = abs(this->m12);
        float mm20 = abs(this->m20);
        float mm21 = abs(this->m21);
        float mm22 = abs(this->m22);
        return Matrix3f(mm00, mm01, mm02, 
						mm10, mm11, mm12, 
						mm20, mm21, mm22);
    }
	
    Matrix3f Matrix3f::absoluteLocal() {
        this->m00 = abs(this->m00);
        this->m01 = abs(this->m01);
        this->m02 = abs(this->m02);
        this->m10 = abs(this->m10);
        this->m11 = abs(this->m11);
        this->m12 = abs(this->m12);
        this->m20 = abs(this->m20);
        this->m21 = abs(this->m21);
        this->m22 = abs(this->m22);
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    Matrix3f Matrix3f::set(Matrix3f matrix) {
		this->m00 = matrix.m00;
		this->m01 = matrix.m01;
		this->m02 = matrix.m02;
		this->m10 = matrix.m10;
		this->m11 = matrix.m11;
		this->m12 = matrix.m12;
		this->m20 = matrix.m20;
		this->m21 = matrix.m21;
		this->m22 = matrix.m22;
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }

    float Matrix3f::get(int i, int j) {
        switch (i) {
            case 0:
                switch (j) {
                    case 0:
                        return m00;
                    case 1:
                        return m01;
                    case 2:
                        return m02;
                }
            case 1:
                switch (j) {
                    case 0:
                        return m10;
                    case 1:
                        return m11;
                    case 2:
                        return m12;
                }
            case 2:
                switch (j) {
                    case 0:
                        return m20;
                    case 1:
                        return m21;
                    case 2:
                        return m22;
                }
        }
    }
	
    List<float> *Matrix3f::get(List<float> *data, bool rowMajor) {
        if (data == nullptr) {
			return nullptr;
		}
        if (data->getSize() < 9) {
			return data;
		}
        if (data->getPosition() == 0) {
            if (rowMajor) {
				data->addLValue( m00);
				data->addLValue( m01);
				data->addLValue( m02);
				data->addLValue( m10);
				data->addLValue( m11);
				data->addLValue( m12);
				data->addLValue( m20);
				data->addLValue( m21);
				data->addLValue( m22);
            } else {
				data->addLValue( m00);
				data->addLValue( m10);
				data->addLValue( m20);
				data->addLValue( m01);
				data->addLValue( m11);
				data->addLValue( m21);
				data->addLValue( m02);
				data->addLValue( m12);
				data->addLValue( m22);
            }
			return data;
		}
        if (data->getPosition() >= 9) {
            if (rowMajor) {
				data->setLValue(0, m00);
				data->setLValue(1, m01);
				data->setLValue(2, m02);
				data->setLValue(3, m10);
				data->setLValue(4, m11);
				data->setLValue(5, m12);
				data->setLValue(6, m20);
				data->setLValue(7, m21);
				data->setLValue(8, m22);
            } else {
				data->setLValue(0, m00);
				data->setLValue(1, m10);
				data->setLValue(2, m20);
				data->setLValue(3, m01);
				data->setLValue(4, m11);
				data->setLValue(5, m21);
				data->setLValue(6, m02);
				data->setLValue(7, m12);
				data->setLValue(8, m22);
            }
        } else if (data->getPosition() >= 16) {
            if (rowMajor) {
				data->setLValue(0, m00);
				data->setLValue(1, m01);
				data->setLValue(2, m02);
				data->setLValue(4, m10);
				data->setLValue(5, m11);
				data->setLValue(6, m12);
				data->setLValue(8, m20);
				data->setLValue(9, m21);
				data->setLValue(10, m22);
            } else {
				data->setLValue(0, m00);
				data->setLValue(1, m10);
				data->setLValue(2, m20);
				data->setLValue(4, m01);
				data->setLValue(5, m11);
				data->setLValue(6, m21);
				data->setLValue(8, m02);
				data->setLValue(9, m12);
				data->setLValue(10, m22);
            }
        }
		return data;
    }
	
    Matrix3f Matrix3f::normalize() {
		Matrix3f store;

        float mag = 1.0f / sqrt(
                m00 * m00
                + m10 * m10
                + m20 * m20);

        store.m00 = m00 * mag;
        store.m10 = m10 * mag;
        store.m20 = m20 * mag;

        mag = 1.0f / sqrt(
                m01 * m01
                + m11 * m11
                + m21 * m21);

        store.m01 = m01 * mag;
        store.m11 = m11 * mag;
        store.m21 = m21 * mag;

        store.m02 = store.m10 * store.m21 - store.m11 * store.m20;
        store.m12 = store.m01 * store.m20 - store.m00 * store.m21;
        store.m22 = store.m00 * store.m11 - store.m01 * store.m10;
        return Matrix3f(store.m00, store.m01, store.m02, 
						store.m10, store.m11, store.m12, 
						store.m20, store.m21, store.m22);
    }
	
    Matrix3f Matrix3f::normalizeLocal() {
		Matrix3f store;
        float mag = 1.0f / sqrt(
                m00 * m00
                + m10 * m10
                + m20 * m20);

        store.m00 = m00 * mag;
        store.m10 = m10 * mag;
        store.m20 = m20 * mag;

        mag = 1.0f / sqrt(
                m01 * m01
                + m11 * m11
                + m21 * m21);

        store.m01 = m01 * mag;
        store.m11 = m11 * mag;
        store.m21 = m21 * mag;

        store.m02 = store.m10 * store.m21 - store.m11 * store.m20;
        store.m12 = store.m01 * store.m20 - store.m00 * store.m21;
        store.m22 = store.m00 * store.m11 - store.m01 * store.m10;
		this->set(store);
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    Vector3f Matrix3f::getColumn(int i) {
		Vector3f store;
        switch (i) {
            case 0:
                store.x = m00;
                store.y = m10;
                store.z = m20;
                break;
            case 1:
                store.x = m01;
                store.y = m11;
                store.z = m21;
                break;
            case 2:
                store.x = m02;
                store.y = m12;
                store.z = m22;
                break;
            default:
			return Vector3f(store.x, store.y, store.z);
        }
        return Vector3f(store.x, store.y, store.z);
    }
	
    Vector3f Matrix3f::getRow(int i) {
		Vector3f store;
        switch (i) {
            case 0:
                store.x = m00;
                store.y = m01;
                store.z = m02;
                break;
            case 1:
                store.x = m10;
                store.y = m11;
                store.z = m12;
                break;
            case 2:
                store.x = m20;
                store.y = m21;
                store.z = m22;
                break;
            default:
				return Vector3f(store.x, store.y, store.z);
        }
        return Vector3f(store.x, store.y, store.z);
    }
	
    // FloatBuffer Matrix3f::toFloatBuffer() {
        // FloatBuffer fb = BufferUtils.createFloatBuffer(9);

        // fb.put(m00).put(m01).put(m02);
        // fb.put(m10).put(m11).put(m12);
        // fb.put(m20).put(m21).put(m22);
        // fb.rewind();
        // return fb;
    // }
	
    // FloatBuffer Matrix3f::fillFloatBuffer(FloatBuffer fb, boolean columnMajor) {
        // TempVars vars = TempVars.get();


        // fillFloatArray(vars.matrixWrite, columnMajor);
        // fb.put(vars.matrixWrite, 0, 9);

        // vars.release();

        // return fb;
    // }

    List<float> *Matrix3f::fillFloatArray(List<float> *f, bool columnMajor) {
        if (f == nullptr) {
			return nullptr;
		}
        if (columnMajor) {
			f->setLValue( 0, m00);
			f->setLValue( 1, m10);
			f->setLValue( 2, m20);
			f->setLValue( 3, m01);
			f->setLValue( 4, m11);
			f->setLValue( 5, m21);
			f->setLValue( 6, m02);
			f->setLValue( 7, m12);
			f->setLValue( 8, m22);
        } else {
			f->setLValue( 0, m00);
			f->setLValue( 1, m01);
			f->setLValue( 2, m02);
			f->setLValue( 3, m10);
			f->setLValue( 4, m11);
			f->setLValue( 5, m12);
			f->setLValue( 6, m20);
			f->setLValue( 7, m21);
			f->setLValue( 8, m22);
        }
		return f;
    }

    Matrix3f Matrix3f::setColumn(int i, Vector3f column) {
        switch (i) {
            case 0:
                this->m00 = column.x;
                this->m10 = column.y;
                this->m20 = column.z;
                break;
            case 1:
                this->m01 = column.x;
                this->m11 = column.y;
                this->m21 = column.z;
                break;
            case 2:
                this->m02 = column.x;
                this->m12 = column.y;
                this->m22 = column.z;
                break;
            default:
				return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
        }
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    Matrix3f Matrix3f::setRow(int i, Vector3f row) {
        switch (i) {
            case 0:
                this->m00 = row.x;
                this->m01 = row.y;
                this->m02 = row.z;
                break;
            case 1:
                this->m10 = row.x;
                this->m11 = row.y;
                this->m12 = row.z;
                break;
            case 2:
                this->m20 = row.x;
                this->m21 = row.y;
                this->m22 = row.z;
                break;
            default:
				return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
        }
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    Matrix3f Matrix3f::set(int i, int j, float value) {
        switch (i) {
            case 0:
                switch (j) {
                    case 0:
                        this->m00 = value;
						return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
                    case 1:
                        this->m01 = value;
						return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
                    case 2:
                        this->m02 = value;
						return Matrix3f(this->m00, this->m01, this->m02, 
							this->m10, this->m11, this->m12, 
							this->m20, this->m21, this->m22);
                }
            case 1:
                switch (j) {
                    case 0:
                        this->m10 = value;
						return Matrix3f(this->m00, this->m01, this->m02, 
							this->m10, this->m11, this->m12, 
							this->m20, this->m21, this->m22);
                    case 1:
                        this->m11 = value;
						return Matrix3f(this->m00, this->m01, this->m02, 
							this->m10, this->m11, this->m12, 
							this->m20, this->m21, this->m22);
                    case 2:
                        this->m12 = value;
						return Matrix3f(this->m00, this->m01, this->m02, 
							this->m10, this->m11, this->m12, 
							this->m20, this->m21, this->m22);
                }
            case 2:
                switch (j) {
                    case 0:
                        this->m20 = value;
						return Matrix3f(this->m00, this->m01, this->m02, 
							this->m10, this->m11, this->m12, 
							this->m20, this->m21, this->m22);
                    case 1:
                        this->m21 = value;
						return Matrix3f(this->m00, this->m01, this->m02, 
							this->m10, this->m11, this->m12, 
							this->m20, this->m21, this->m22);
                    case 2:
                        this->m22 = value;
						return Matrix3f(this->m00, this->m01, this->m02, 
							this->m10, this->m11, this->m12, 
							this->m20, this->m21, this->m22);
                }
        }
    }
	
    // Matrix3f Matrix3f::setLValue(float[3][3] matrix) {
        // if (matrix.length != 3 || matrix[0].length != 3) {
			// return Matrix3f(this);
        // }

        // this->m00 = matrix[0][0];
        // this->m01 = matrix[0][1];
        // this->m02 = matrix[0][2];
        // this->m10 = matrix[1][0];
        // this->m11 = matrix[1][1];
        // this->m12 = matrix[1][2];
        // this->m20 = matrix[2][0];
        // this->m21 = matrix[2][1];
        // this->m22 = matrix[2][2];

        // return Matrix3f(this->m00, this->m01, this->m02, 
						// this->m10, this->m11, this->m12, 
						// this->m20, this->m21, this->m22);
    // }
	
    Matrix3f Matrix3f::fromAxes(Vector3f uAxis, Vector3f vAxis, Vector3f wAxis) {
        this->m00 = uAxis.x;
        this->m10 = uAxis.y;
        this->m20 = uAxis.z;

        this->m01 = vAxis.x;
        this->m11 = vAxis.y;
        this->m21 = vAxis.z;

        this->m02 = wAxis.x;
        this->m12 = wAxis.y;
        this->m22 = wAxis.z;
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    Matrix3f Matrix3f::set(List<float> *matrix) {
        return set(matrix, true);
    }
	
    Matrix3f Matrix3f::set(List<float> *matrix, bool rowMajor) {
        if (matrix->getPosition() >= 9) {
			return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
        }

        if (rowMajor) {
            this->m00 = *matrix->getByPosition(0);
            this->m01 = *matrix->getByPosition(1);
            this->m02 = *matrix->getByPosition(2);
            this->m10 = *matrix->getByPosition(3);
            this->m11 = *matrix->getByPosition(4);
            this->m12 = *matrix->getByPosition(5);
            this->m20 = *matrix->getByPosition(6);
            this->m21 = *matrix->getByPosition(7);
            this->m22 = *matrix->getByPosition(8);
        } else {
            this->m00 = *matrix->getByPosition(0);
            this->m01 = *matrix->getByPosition(3);
            this->m02 = *matrix->getByPosition(6);
            this->m10 = *matrix->getByPosition(1);
            this->m11 = *matrix->getByPosition(4);
            this->m12 = *matrix->getByPosition(7);
            this->m20 = *matrix->getByPosition(2);
            this->m21 = *matrix->getByPosition(5);
            this->m22 = *matrix->getByPosition(8);
        }
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    // Matrix3f Matrix3f::setLValue(Quaternion q) {
		// Matrix3f nm = q.toRotationMatrix(this);
		// this->m00 = nm.m00;
		// this->m01 = nm.m01;
		// this->m02 = nm.m02;
		// this->m10 = nm.m10;
		// this->m11 = nm.m11;
		// this->m12 = nm.m12;
		// this->m20 = nm.m20;
		// this->m21 = nm.m21;
		// this->m22 = nm.m22;
        // return Matrix3f(this->m00, this->m01, this->m02, 
						// this->m10, this->m11, this->m12, 
						// this->m20, this->m21, this->m22);
    // }
	
    void Matrix3f::loadIdentity() {
        this->m01 = this->m02 = this->m10 = this->m12 = this->m20 = this->m21 = 0;
        this->m00 = this->m11 = this->m22 = 1;
    }
	
    bool Matrix3f::isIdentity() {
        return (this->m00 == 1 && this->m01 == 0 && this->m02 == 0)
                && (this->m10 == 0 && this->m11 == 1 && this->m12 == 0)
                && (this->m20 == 0 && this->m21 == 0 && this->m22 == 1);
    }
	
    Matrix3f Matrix3f::fromAngleAxis(float angle, Vector3f axis) {
        Vector3f normAxis = axis.normalize();
        return this->fromAngleNormalAxis(angle, normAxis);
    }
	
    Matrix3f Matrix3f::fromAngleNormalAxis(float angle, Vector3f axis) {
        float fCos = cos(angle);
        float fSin = sin(angle);
        // float fCos = FastMath.cos(angle);
        // float fSin = FastMath.sin(angle);
        float fOneMinusCos = ((float) 1.0f) - fCos;
        float fX2 = axis.x * axis.x;
        float fY2 = axis.y * axis.y;
        float fZ2 = axis.z * axis.z;
        float fXYM = axis.x * axis.y * fOneMinusCos;
        float fXZM = axis.x * axis.z * fOneMinusCos;
        float fYZM = axis.y * axis.z * fOneMinusCos;
        float fXSin = axis.x * fSin;
        float fYSin = axis.y * fSin;
        float fZSin = axis.z * fSin;

        float fm00 = fX2 * fOneMinusCos + fCos;
        float fm01 = fXYM - fZSin;
        float fm02 = fXZM + fYSin;
        float fm10 = fXYM + fZSin;
        float fm11 = fY2 * fOneMinusCos + fCos;
        float fm12 = fYZM - fXSin;
        float fm20 = fXZM - fYSin;
        float fm21 = fYZM + fXSin;
        float fm22 = fZ2 * fOneMinusCos + fCos;
        return Matrix3f(fm00, fm01, fm02, 
						fm10, fm11, fm12, 
						fm20, fm21, fm22);
    }
	
    Matrix3f Matrix3f::fromAngleAxisLocal(float angle, Vector3f axis) {
        Vector3f normAxis = axis.normalize();
        return this->fromAngleNormalAxisLocal(angle, normAxis);
    }
	
    Matrix3f Matrix3f::fromAngleNormalAxisLocal(float angle, Vector3f axis) {
        float fCos = cos(angle);
        float fSin = sin(angle);
        // float fCos = FastMath.cos(angle);
        // float fSin = FastMath.sin(angle);
        float fOneMinusCos = ((float) 1.0f) - fCos;
        float fX2 = axis.x * axis.x;
        float fY2 = axis.y * axis.y;
        float fZ2 = axis.z * axis.z;
        float fXYM = axis.x * axis.y * fOneMinusCos;
        float fXZM = axis.x * axis.z * fOneMinusCos;
        float fYZM = axis.y * axis.z * fOneMinusCos;
        float fXSin = axis.x * fSin;
        float fYSin = axis.y * fSin;
        float fZSin = axis.z * fSin;

        this->m00 = fX2 * fOneMinusCos + fCos;
        this->m01 = fXYM - fZSin;
        this->m02 = fXZM + fYSin;
        this->m10 = fXYM + fZSin;
        this->m11 = fY2 * fOneMinusCos + fCos;
        this->m12 = fYZM - fXSin;
        this->m20 = fXZM - fYSin;
        this->m21 = fYZM + fXSin;
        this->m22 = fZ2 * fOneMinusCos + fCos;
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    Matrix3f Matrix3f::mult(Matrix3f mat) {
		float temp00, temp01, temp02;
        float temp10, temp11, temp12;
        float temp20, temp21, temp22;

        Matrix3f product;
		
        temp00 = m00 * mat.m00 + m01 * mat.m10 + m02 * mat.m20;
        temp01 = m00 * mat.m01 + m01 * mat.m11 + m02 * mat.m21;
        temp02 = m00 * mat.m02 + m01 * mat.m12 + m02 * mat.m22;
        temp10 = m10 * mat.m00 + m11 * mat.m10 + m12 * mat.m20;
        temp11 = m10 * mat.m01 + m11 * mat.m11 + m12 * mat.m21;
        temp12 = m10 * mat.m02 + m11 * mat.m12 + m12 * mat.m22;
        temp20 = m20 * mat.m00 + m21 * mat.m10 + m22 * mat.m20;
        temp21 = m20 * mat.m01 + m21 * mat.m11 + m22 * mat.m21;
        temp22 = m20 * mat.m02 + m21 * mat.m12 + m22 * mat.m22;

        product.m00 = temp00;
        product.m01 = temp01;
        product.m02 = temp02;
        product.m10 = temp10;
        product.m11 = temp11;
        product.m12 = temp12;
        product.m20 = temp20;
        product.m21 = temp21;
        product.m22 = temp22;

        return Matrix3f(product.m00, product.m01, product.m02, 
						product.m10, product.m11, product.m12, 
						product.m20, product.m21, product.m22);
    }
	
    Vector3f Matrix3f::mult(Vector3f vec) {
        float x = vec.x;
        float y = vec.y;
        float z = vec.z;

        float nx = this->m00 * x + this->m01 * y + this->m02 * z;
        float ny = this->m10 * x + this->m11 * y + this->m12 * z;
        float nz = this->m20 * x + this->m21 * y + this->m22 * z;
        return Vector3f(nx , ny , nz);
    }
	
    Matrix3f Matrix3f::multLocal(float scale) {
        this->m00 *= scale;
        this->m01 *= scale;
        this->m02 *= scale;
        this->m10 *= scale;
        this->m11 *= scale;
        this->m12 *= scale;
        this->m20 *= scale;
        this->m21 *= scale;
        this->m22 *= scale;
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    Matrix3f Matrix3f::multLocal(Matrix3f mat) {
		float temp00, temp01, temp02;
        float temp10, temp11, temp12;
        float temp20, temp21, temp22;
		
        temp00 = m00 * mat.m00 + m01 * mat.m10 + m02 * mat.m20;
        temp01 = m00 * mat.m01 + m01 * mat.m11 + m02 * mat.m21;
        temp02 = m00 * mat.m02 + m01 * mat.m12 + m02 * mat.m22;
        temp10 = m10 * mat.m00 + m11 * mat.m10 + m12 * mat.m20;
        temp11 = m10 * mat.m01 + m11 * mat.m11 + m12 * mat.m21;
        temp12 = m10 * mat.m02 + m11 * mat.m12 + m12 * mat.m22;
        temp20 = m20 * mat.m00 + m21 * mat.m10 + m22 * mat.m20;
        temp21 = m20 * mat.m01 + m21 * mat.m11 + m22 * mat.m21;
        temp22 = m20 * mat.m02 + m21 * mat.m12 + m22 * mat.m22;

        this->m00 = temp00;
        this->m01 = temp01;
        this->m02 = temp02;
        this->m10 = temp10;
        this->m11 = temp11;
        this->m12 = temp12;
        this->m20 = temp20;
        this->m21 = temp21;
        this->m22 = temp22;

        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    Matrix3f Matrix3f::transposeLocal() {
        float tmp = m01;
        m01 = m10;
        m10 = tmp;

        tmp = m02;
        m02 = m20;
        m20 = tmp;

        tmp = m12;
        m12 = m21;
        m21 = tmp;

        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    Matrix3f Matrix3f::invert() {
		float det = determinant();
        if (abs(det) <= FLT_EPSILON) {
			return Matrix3f(ZERO->m00, ZERO->m01, ZERO->m02, 
						ZERO->m10, ZERO->m11, ZERO->m12, 
						ZERO->m20, ZERO->m21, ZERO->m22);
        }
		Matrix3f store;
        store.m00 = m11 * m22 - m12 * m21;
        store.m01 = m02 * m21 - m01 * m22;
        store.m02 = m01 * m12 - m02 * m11;
        store.m10 = m12 * m20 - m10 * m22;
        store.m11 = m00 * m22 - m02 * m20;
        store.m12 = m02 * m10 - m00 * m12;
        store.m20 = m10 * m21 - m11 * m20;
        store.m21 = m01 * m20 - m00 * m21;
        store.m22 = m00 * m11 - m01 * m10;

        store.multLocal(1.0f / det);
        return Matrix3f(store.m00, store.m01, store.m02, 
						store.m10, store.m11, store.m12, 
						store.m20, store.m21, store.m22);
    }
	
    Matrix3f Matrix3f::invertLocal() {
        float det = determinant();
        if (abs(det) <= 0.0f) {
            return zero();
        }

        float f00 = m11 * m22 - m12 * m21;
        float f01 = m02 * m21 - m01 * m22;
        float f02 = m01 * m12 - m02 * m11;
        float f10 = m12 * m20 - m10 * m22;
        float f11 = m00 * m22 - m02 * m20;
        float f12 = m02 * m10 - m00 * m12;
        float f20 = m10 * m21 - m11 * m20;
        float f21 = m01 * m20 - m00 * m21;
        float f22 = m00 * m11 - m01 * m10;

        this->m00 = f00;
        this->m01 = f01;
        this->m02 = f02;
        this->m10 = f10;
        this->m11 = f11;
        this->m12 = f12;
        this->m20 = f20;
        this->m21 = f21;
        this->m22 = f22;

        multLocal(1.0f / det);
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    Matrix3f Matrix3f::adjoint() {
        float nm00 = m11 * m22 - m12 * m21;
        float nm01 = m02 * m21 - m01 * m22;
        float nm02 = m01 * m12 - m02 * m11;
        float nm10 = m12 * m20 - m10 * m22;
        float nm11 = m00 * m22 - m02 * m20;
        float nm12 = m02 * m10 - m00 * m12;
        float nm20 = m10 * m21 - m11 * m20;
        float nm21 = m01 * m20 - m00 * m21;
        float nm22 = m00 * m11 - m01 * m10;

        return Matrix3f(nm00,nm01,nm02,nm10,nm11,nm12,nm20,nm21,nm22);
    }
	
    float Matrix3f::determinant() {
        float fCo00 = m11 * m22 - m12 * m21;
        float fCo10 = m12 * m20 - m10 * m22;
        float fCo20 = m10 * m21 - m11 * m20;
        float fDet = m00 * fCo00 + m01 * fCo10 + m02 * fCo20;
        return fDet;
    }
	
    Matrix3f Matrix3f::zero() {
        m00 = m01 = m02 = m10 = m11 = m12 = m20 = m21 = m22 = 0.0f;
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    Matrix3f Matrix3f::transpose() {
        float tm00 = this->m00;
        float tm01 = this->m01;
        float tm02 = this->m02;
        float tm10 = this->m10;
        float tm11 = this->m11;
        float tm12 = this->m12;
        float tm20 = this->m20;
        float tm21 = this->m21;
        float tm22 = this->m22;
		
        float tmp = tm01;
        tm01 = tm10;
        tm10 = tmp;

        tmp = tm02;
        tm02 = tm20;
        tm20 = tmp;

        tmp = tm12;
        tm12 = tm21;
        tm21 = tmp;

        return Matrix3f(tm00, tm01, tm02, 
						tm10, tm11, tm12, 
						tm20, tm21, tm22);
    }
	
    Matrix3f Matrix3f::transposeNew() {
        return Matrix3f(this->m00, this->m10, this->m20, this->m01, this->m11, this->m21, this->m02, this->m12, this->m22);
    }
    
    String Matrix3f::toString() {
		return "Matrix3f "+String(m00), " "+String(m10), " "+
				String(m20), " "+String(m01), " "+String(m11), " "+
				String(m21), " "+String(m02), " "+String(m12), " "+
				String(m22);
    }
	
    cppObjectClass* Matrix3f::getClass(){
		return Class<Matrix3f>::classType;
	}
	
    bool Matrix3f::equals(cppObject *o){
        if (!(o->getClass() == Class<Matrix3f>::classType) || o == nullptr) {
            return false;
        }

        if (this == (Matrix3f*) o) {
            return true;
        }

        Matrix3f *comp = (Matrix3f*) o;
        if (this->m00 != comp->m00) {
            return false;
        }
        if (this->m01 != comp->m01) {
            return false;
        }
        if (this->m02 != comp->m02) {
            return false;
        }

        if (this->m10 != comp->m10) {
            return false;
        }
        if (this->m11 != comp->m11) {
            return false;
        }
        if (this->m12 != comp->m12) {
            return false;
        }

        if (this->m20 != comp->m20) {
            return false;
        }
        if (this->m21 != comp->m21) {
            return false;
        }
        if (this->m22 != comp->m22) {
            return false;
        }

        return true;
    }

    // void Matrix3f::write(JmeExporter e){
        // OutputCapsule cap = e.getCapsule(this);
        // cap.write(m00, "m00", 1);
        // cap.write(m01, "m01", 0);
        // cap.write(m02, "m02", 0);
        // cap.write(m10, "m10", 0);
        // cap.write(m11, "m11", 1);
        // cap.write(m12, "m12", 0);
        // cap.write(m20, "m20", 0);
        // cap.write(m21, "m21", 0);
        // cap.write(m22, "m22", 1);
    // }

    // void Matrix3f::read(JmeImporter e){
        // InputCapsule cap = e.getCapsule(this);
        // m00 = cap.readFloat("m00", 1);
        // m01 = cap.readFloat("m01", 0);
        // m02 = cap.readFloat("m02", 0);
        // m10 = cap.readFloat("m10", 0);
        // m11 = cap.readFloat("m11", 1);
        // m12 = cap.readFloat("m12", 0);
        // m20 = cap.readFloat("m20", 0);
        // m21 = cap.readFloat("m21", 0);
        // m22 = cap.readFloat("m22", 1);
    // }

	
	
    Matrix3f Matrix3f::fromStartEndVectorsLocal(Vector3f start, Vector3f end) {
        Vector3f v = start.cross(end);
        float e, h, f;

        //start.cross(end, v);
        e = start.dot(end);
        f = (e < 0) ? -e : e;

        // if "from" and "to" vectors are nearly parallel
        if (f > 1.0f - ZERO_TOLERANCE) {
            Vector3f u = Vector3f();
            Vector3f x = Vector3f();
            float c1, c2, c3; // coefficients for later use 
            int i, j;

            x.x = (start.x > 0.0) ? start.x : -start.x;
            x.y = (start.y > 0.0) ? start.y : -start.y;
            x.z = (start.z > 0.0) ? start.z : -start.z;

            if (x.x < x.y) {
                if (x.x < x.z) {
                    x.x = 1.0f;
                    x.y = x.z = 0.0f;
                } else {
                    x.z = 1.0f;
                    x.x = x.y = 0.0f;
                }
            } else {
                if (x.y < x.z) {
                    x.y = 1.0f;
                    x.x = x.z = 0.0f;
                } else {
                    x.z = 1.0f;
                    x.x = x.y = 0.0f;
                }
            }

            u.x = x.x - start.x;
            u.y = x.y - start.y;
            u.z = x.z - start.z;
            v.x = x.x - end.x;
            v.y = x.y - end.y;
            v.z = x.z - end.z;

            c1 = 2.0f / u.dot(u);
            c2 = 2.0f / v.dot(v);
            c3 = c1 * c2 * u.dot(v);

            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    float val = -c1 * u.get(i) * u.get(j) - c2 * v.get(i)
                            * v.get(j) + c3 * v.get(i) * u.get(j);
                    set(i, j, val);
                }
                float val = get(i, i);
                set(i, i, val + 1.0f);
            }
        } else {
            // the most common case, unless "start"="end", or "start"=-"end"
            float hvx, hvz, hvxy, hvxz, hvyz;
            h = 1.0f / (1.0f + e);
            hvx = h * v.x;
            hvz = h * v.z;
            hvxy = hvx * v.y;
            hvxz = hvx * v.z;
            hvyz = hvz * v.y;
            set(0, 0, e + hvx * v.x);
            set(0, 1, hvxy - v.z);
            set(0, 2, hvxz + v.y);

            set(1, 0, hvxy + v.z);
            set(1, 1, e + h * v.y * v.y);
            set(1, 2, hvyz - v.x);

            set(2, 0, hvxz - v.y);
            set(2, 1, hvyz + v.x);
            set(2, 2, e + hvz * v.z);
        }
    }
    Matrix3f Matrix3f::fromStartEndVectors(Vector3f start, Vector3f end) {
		Matrix3f store = Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
		store.fromStartEndVectors(start, end);
        return Matrix3f(store.m00, store.m01, store.m02, 
						store.m10, store.m11, store.m12, 
						store.m20, store.m21, store.m22);
	}
	
    Matrix3f Matrix3f::scaleLocal(Vector3f scale) {
        this->m00 *= scale.x;
        this->m10 *= scale.x;
        this->m20 *= scale.x;
        this->m01 *= scale.y;
        this->m11 *= scale.y;
        this->m21 *= scale.y;
        this->m02 *= scale.z;
        this->m12 *= scale.z;
        this->m22 *= scale.z;
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
    Matrix3f Matrix3f::scale(Vector3f scale) {
        float mm00 = this->m00 * scale.x;
        float mm10 = this->m10 * scale.x;
        float mm20 = this->m20 * scale.x;
        float mm01 = this->m01 * scale.y;
        float mm11 = this->m11 * scale.y;
        float mm21 = this->m21 * scale.y;
        float mm02 = this->m02 * scale.z;
        float mm12 = this->m12 * scale.z;
        float mm22 = this->m22 * scale.z;
        return Matrix3f(mm00, mm01, mm02, 
						mm10, mm11, mm12, 
						mm20, mm21, mm22);
    }

    bool Matrix3f::equalIdentity(Matrix3f mat) {
        if (abs(mat.m00 - 1) > 1e-4) {
            return false;
        }
        if (abs(mat.m11 - 1) > 1e-4) {
            return false;
        }
        if (abs(mat.m22 - 1) > 1e-4) {
            return false;
        }

        if (abs(mat.m01) > 1e-4) {
            return false;
        }
        if (abs(mat.m02) > 1e-4) {
            return false;
        }

        if (abs(mat.m10) > 1e-4) {
            return false;
        }
        if (abs(mat.m12) > 1e-4) {
            return false;
        }

        if (abs(mat.m20) > 1e-4) {
            return false;
        }
        if (abs(mat.m21) > 1e-4) {
            return false;
        }

        return true;
    }
	
    Matrix3f *Matrix3f::clone() {
        return new Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
    }
	
	Matrix3f Matrix3f::operator=(const Matrix3f& a) {
		this->m00 = a.m00;
		this->m01 = a.m01;
		this->m02 = a.m02;
		this->m10 = a.m10;
		this->m11 = a.m11;
		this->m12 = a.m12;
		this->m20 = a.m20;
		this->m21 = a.m21;
		this->m22 = a.m22;
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
	}
	Matrix3f Matrix3f::operator=(const float a[9]) {
		this->m00 = a[0];
		this->m01 = a[1];
		this->m02 = a[2];
		this->m10 = a[3];
		this->m11 = a[4];
		this->m12 = a[5];
		this->m20 = a[6];
		this->m21 = a[7];
		this->m22 = a[8];
        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
	}
	bool Matrix3f::operator==(const Matrix3f& a) {
        if (this->m00 != a.m00) {
            return false;
        }
        if (this->m01 != a.m01) {
            return false;
        }
        if (this->m02 != a.m02) {
            return false;
        }

        if (this->m10 != a.m10) {
            return false;
        }
        if (this->m11 != a.m11) {
            return false;
        }
        if (this->m12 != a.m12) {
            return false;
        }

        if (this->m20 != a.m20) {
            return false;
        }
        if (this->m21 != a.m21) {
            return false;
        }
        if (this->m22 != a.m22) {
            return false;
        }

        return true;
	}
	bool Matrix3f::operator!=(const Matrix3f& a) {
        if (this->m00 == a.m00) {
            return false;
        }
        if (this->m01 == a.m01) {
            return false;
        }
        if (this->m02 == a.m02) {
            return false;
        }

        if (this->m10 == a.m10) {
            return false;
        }
        if (this->m11 == a.m11) {
            return false;
        }
        if (this->m12 == a.m12) {
            return false;
        }

        if (this->m20 == a.m20) {
            return false;
        }
        if (this->m21 == a.m21) {
            return false;
        }
        if (this->m22 == a.m22) {
            return false;
        }

        return true;
	}
	// Quaternion Quaternion::operator+(const Quaternion& a) {
		// return Quaternion(this->x+ a.x ,this->y + a.y ,this->z + a.z ,this->w + a.w);
	// }
	// Quaternion Quaternion::operator+(const float a[4]) {
		// return Quaternion(this->x+a[0] ,this->y+a[1] ,this->z + a[2] ,this->w + a[3]);
	// }
	// Quaternion Quaternion::operator-(const Quaternion& a) {
		// return Quaternion(this->x- a.x ,this->y - a.y ,this->z - a.z ,this->w - a.w);
	// }
	// Quaternion Quaternion::operator-(const float a[4]) {
		// return Quaternion(this->x-a[0] ,this->y-a[1] ,this->z - a[2] ,this->w - a[3]);
	// }
	Matrix3f Matrix3f::operator*(const Matrix3f& mat) {
		float temp00, temp01, temp02;
        float temp10, temp11, temp12;
        float temp20, temp21, temp22;

        Matrix3f product;
		
        temp00 = this->m00 * mat.m00 + this->m01 * mat.m10 + this->m02 * mat.m20;
        temp01 = this->m00 * mat.m01 + this->m01 * mat.m11 + this->m02 * mat.m21;
        temp02 = this->m00 * mat.m02 + this->m01 * mat.m12 + this->m02 * mat.m22;
        temp10 = this->m10 * mat.m00 + this->m11 * mat.m10 + this->m12 * mat.m20;
        temp11 = this->m10 * mat.m01 + this->m11 * mat.m11 + this->m12 * mat.m21;
        temp12 = this->m10 * mat.m02 + this->m11 * mat.m12 + this->m12 * mat.m22;
        temp20 = this->m20 * mat.m00 + this->m21 * mat.m10 + this->m22 * mat.m20;
        temp21 = this->m20 * mat.m01 + this->m21 * mat.m11 + this->m22 * mat.m21;
        temp22 = this->m20 * mat.m02 + this->m21 * mat.m12 + this->m22 * mat.m22;

        product.m00 = temp00;
        product.m01 = temp01;
        product.m02 = temp02;
        product.m10 = temp10;
        product.m11 = temp11;
        product.m12 = temp12;
        product.m20 = temp20;
        product.m21 = temp21;
        product.m22 = temp22;

        return Matrix3f(product.m00, product.m01, product.m02, 
						product.m10, product.m11, product.m12, 
						product.m20, product.m21, product.m22);
	}
	Matrix3f Matrix3f::operator*(const float a[9]) {
		float temp00, temp01, temp02;
        float temp10, temp11, temp12;
        float temp20, temp21, temp22;

        Matrix3f product;
        Matrix3f mat;
        mat.m00 = a[0];
        mat.m01 = a[1];
        mat.m02 = a[2];
        mat.m10 = a[3];
        mat.m11 = a[4];
        mat.m12 = a[5];
        mat.m20 = a[6];
        mat.m21 = a[7];
        mat.m22 = a[8];
		
        temp00 = this->m00 * mat.m00 + this->m01 * mat.m10 + this->m02 * mat.m20;
        temp01 = this->m00 * mat.m01 + this->m01 * mat.m11 + this->m02 * mat.m21;
        temp02 = this->m00 * mat.m02 + this->m01 * mat.m12 + this->m02 * mat.m22;
        temp10 = this->m10 * mat.m00 + this->m11 * mat.m10 + this->m12 * mat.m20;
        temp11 = this->m10 * mat.m01 + this->m11 * mat.m11 + this->m12 * mat.m21;
        temp12 = this->m10 * mat.m02 + this->m11 * mat.m12 + this->m12 * mat.m22;
        temp20 = this->m20 * mat.m00 + this->m21 * mat.m10 + this->m22 * mat.m20;
        temp21 = this->m20 * mat.m01 + this->m21 * mat.m11 + this->m22 * mat.m21;
        temp22 = this->m20 * mat.m02 + this->m21 * mat.m12 + this->m22 * mat.m22;

        product.m00 = temp00;
        product.m01 = temp01;
        product.m02 = temp02;
        product.m10 = temp10;
        product.m11 = temp11;
        product.m12 = temp12;
        product.m20 = temp20;
        product.m21 = temp21;
        product.m22 = temp22;

        return Matrix3f(product.m00, product.m01, product.m02, 
						product.m10, product.m11, product.m12, 
						product.m20, product.m21, product.m22);
	}
	// Quaternion Quaternion::operator/(const Quaternion& a) {
		// return Quaternion(this->x/ a.x ,this->y / a.y ,this->z / a.z ,this->w / a.w);
	// }
	// Quaternion Quaternion::operator/(const float a[4]) {
		// return Quaternion(this->x/ a[0] ,this->y/ a[1] ,this->z / a[2] ,this->w / a[3]);
	// }
	
	
	// Quaternion Quaternion::operator+=(const Quaternion& a) {
		// this->x += a.x;
		// this->y += a.y;
		// this->z += a.z;
		// this->w += a.w;
        // return Quaternion(this->x, this->y, this->z, this->w);
	// }
	// Quaternion Quaternion::operator+=(const float a[4]) {
		// this->x += a[0];
		// this->y += a[1];
		// this->z += a[2];
		// this->w += a[3];
        // return Vector4f(this->x, this->y, this->z, this->w);
	// }
	// Quaternion Quaternion::operator-=(const Quaternion& a) {
		// this->x -= a.x;
		// this->y -= a.y;
		// this->z -= a.z;
		// this->w -= a.w;
        // return Quaternion(this->x, this->y, this->z, this->w);
	// }
	// Quaternion Quaternion::operator-=(const float a[4]) {
		// this->x -= a[0];
		// this->y -= a[1];
		// this->z -= a[2];
		// this->w -= a[3];
        // return Quaternion(this->x, this->y, this->z, this->w);
	// }
	
	
	
	Matrix3f Matrix3f::operator*=(const Matrix3f& mat) {
		float temp00, temp01, temp02;
        float temp10, temp11, temp12;
        float temp20, temp21, temp22;
		
        temp00 = m00 * mat.m00 + m01 * mat.m10 + m02 * mat.m20;
        temp01 = m00 * mat.m01 + m01 * mat.m11 + m02 * mat.m21;
        temp02 = m00 * mat.m02 + m01 * mat.m12 + m02 * mat.m22;
        temp10 = m10 * mat.m00 + m11 * mat.m10 + m12 * mat.m20;
        temp11 = m10 * mat.m01 + m11 * mat.m11 + m12 * mat.m21;
        temp12 = m10 * mat.m02 + m11 * mat.m12 + m12 * mat.m22;
        temp20 = m20 * mat.m00 + m21 * mat.m10 + m22 * mat.m20;
        temp21 = m20 * mat.m01 + m21 * mat.m11 + m22 * mat.m21;
        temp22 = m20 * mat.m02 + m21 * mat.m12 + m22 * mat.m22;

        this->m00 = temp00;
        this->m01 = temp01;
        this->m02 = temp02;
        this->m10 = temp10;
        this->m11 = temp11;
        this->m12 = temp12;
        this->m20 = temp20;
        this->m21 = temp21;
        this->m22 = temp22;

        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
	}
	Matrix3f Matrix3f::operator*=(const float a[4]) {
		float temp00, temp01, temp02;
        float temp10, temp11, temp12;
        float temp20, temp21, temp22;
		
        Matrix3f mat;
        mat.m00 = a[0];
        mat.m01 = a[1];
        mat.m02 = a[2];
        mat.m10 = a[3];
        mat.m11 = a[4];
        mat.m12 = a[5];
        mat.m20 = a[6];
        mat.m21 = a[7];
        mat.m22 = a[8];
		
        temp00 = m00 * mat.m00 + m01 * mat.m10 + m02 * mat.m20;
        temp01 = m00 * mat.m01 + m01 * mat.m11 + m02 * mat.m21;
        temp02 = m00 * mat.m02 + m01 * mat.m12 + m02 * mat.m22;
        temp10 = m10 * mat.m00 + m11 * mat.m10 + m12 * mat.m20;
        temp11 = m10 * mat.m01 + m11 * mat.m11 + m12 * mat.m21;
        temp12 = m10 * mat.m02 + m11 * mat.m12 + m12 * mat.m22;
        temp20 = m20 * mat.m00 + m21 * mat.m10 + m22 * mat.m20;
        temp21 = m20 * mat.m01 + m21 * mat.m11 + m22 * mat.m21;
        temp22 = m20 * mat.m02 + m21 * mat.m12 + m22 * mat.m22;

        this->m00 = temp00;
        this->m01 = temp01;
        this->m02 = temp02;
        this->m10 = temp10;
        this->m11 = temp11;
        this->m12 = temp12;
        this->m20 = temp20;
        this->m21 = temp21;
        this->m22 = temp22;

        return Matrix3f(this->m00, this->m01, this->m02, 
						this->m10, this->m11, this->m12, 
						this->m20, this->m21, this->m22);
	}
	
#endif 
	
	