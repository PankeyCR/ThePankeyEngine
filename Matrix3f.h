
#ifndef Matrix3f_h
#define Matrix3f_h

//#include "Quaternion.h"
#include "Vector3f.h"
#include "List.h"
#include "FastMonkeyMath.h"

//class Quaternion;
//class Matrix4f;

class Matrix3f {
    private:
	
    public:
	
		float m00, m01, m02,
			  m10, m11, m12,
			  m20, m21, m22;
		static Matrix3f *ZERO;
		static Matrix3f *IDENTITY;


		Matrix3f();
		Matrix3f(float m00, float m01, float m02, float m10, float m11,
				float m12, float m20, float m21, float m22);
				
		Matrix3f absolute();
		Matrix3f absoluteLocal();
		
		Matrix3f set(Matrix3f matrix);
		float get(int i, int j);
		List<float> *get(List<float> *data, bool rowMajor);
		
		Matrix3f normalize();            
		Matrix3f normalizeLocal();
		
		Vector3f getColumn(int i);
		Vector3f getRow(int i);
		
		//FloatBuffer toFloatBuffer();
		//FloatBuffer fillFloatBuffer(FloatBuffer fb, boolean columnMajor);
		
		List<float> *fillFloatArray(List<float> *f, bool columnMajor);
		Matrix3f setColumn(int i, Vector3f column);
		Matrix3f setRow(int i, Vector3f row);
		Matrix3f set(int i, int j, float value);
		Matrix3f fromAxes(Vector3f uAxis, Vector3f vAxis, Vector3f wAxis);
		Matrix3f set(List<float> *matrix);
		Matrix3f set(List<float> *matrix, bool rowMajor);        
		//Matrix3f set(Quaternion q);
		void loadIdentity();
		bool isIdentity();
		
		Matrix3f fromAngleAxis(float angle, Vector3f axis);
		Matrix3f fromAngleNormalAxis(float angle, Vector3f axis);
		
		Matrix3f fromAngleAxisLocal(float angle, Vector3f axis);
		Matrix3f fromAngleNormalAxisLocal(float angle, Vector3f axis);
		
		Matrix3f mult(Matrix3f mat);
		Vector3f mult(Vector3f vec);
		
		Matrix3f multLocal(float scale);
		Matrix3f multLocal(Matrix3f mat);
		
		Matrix3f transposeLocal();
		Matrix3f invert();
		Matrix3f invertLocal();
		
		Matrix3f adjoint();
		float determinant();
		Matrix3f zero();
		Matrix3f transpose();
		Matrix3f transposeNew();
		String toString();
		String getClassName();
		bool equals(cppObject *o);
		//void write(JmeExporter e);
		//void read(JmeImporter e);
		
		Matrix3f fromStartEndVectors(Vector3f start, Vector3f end);
		Matrix3f fromStartEndVectorsLocal(Vector3f start, Vector3f end);
		
		Matrix3f scale(Vector3f scale);
		Matrix3f scaleLocal(Vector3f scale);
		
		static bool equalIdentity(Matrix3f mat);
		Matrix3f *clone();
	
		Matrix3f operator=(const Matrix3f& a);
		Matrix3f operator=(const float a[9]);
		bool operator==(const Matrix3f& a);
		bool operator!=(const Matrix3f& a);
		// Quaternion operator+(const Quaternion& a);
		// Quaternion operator+(const float a[4]);
		// Quaternion operator-(const Quaternion& a);
		// Quaternion operator-(const float a[4]);
		Matrix3f operator*(const Matrix3f& mat);
		Matrix3f operator*(const float a[9]);
		// Quaternion operator/(const Quaternion& a);
		// Quaternion operator/(const float [4]);
		
		// Quaternion operator+=(const Quaternion& a);
		// Quaternion operator+=(const float a[4]);
		// Quaternion operator-=(const Quaternion& a);
		// Quaternion operator-=(const float a[4]);
		Matrix3f operator*=(const Matrix3f& mat);
		Matrix3f operator*=(const float a[9]);
		// Quaternion operator/=(const Quaternion& a);
		// Quaternion operator/=(const float [4]);
	
};
#endif 
