
#ifndef Matrix4f_h
#define Matrix4f_h

#include "FastMonkeyMath.h"
#include "Vector3f.h"
//#include "Quaternion.h"
#include "List.h"
#include "Matrix3f.h"
#include "Vector4f.h"


//class Matrix3f;
//class Quaternion;

namespace ame{

class Matrix4f {
    private:
	
    public:

    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
    static Matrix4f *ZERO;
    static Matrix4f *IDENTITY;
	
    Matrix4f();
    Matrix4f(float m00, float m01, float m02, float m03,
            float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23,
            float m30, float m31, float m32, float m33);
    Matrix4f(List<float> *array);
	
    Matrix4f fromFrame(Vector3f location, Vector3f direction, Vector3f up, Vector3f left);
    Matrix4f fromFrameLocal(Vector3f location, Vector3f direction, Vector3f up, Vector3f left);
	
    List<float> *get(List<float> *matrix);
    List<float> *get(List<float> *matrix, bool rowMajor);
	
    float get(int i, int j);
	
    //List<float> *getColumn(int i);
    List<float> *getColumn(int i, List<float> *store);
	
    Matrix4f setColumn(int i, List<float> *column);
	
    Matrix4f set(int i, int j, float value);
	
    Matrix4f set(float m00, float m01, float m02, float m03,
            float m10, float m11, float m12, float m13,
            float m20, float m21, float m22, float m23,
            float m30, float m31, float m32, float m33);
			
    //Matrix4f set(float[4][4] matrix);
    Matrix4f set(Matrix4f matrix);
	/*
    List<float> *set(List<float> *matrix);
    List<float> *set(List<float> *matrix, bool rowMajor);
	
    Matrix4f transpose();
    Matrix4f transposeLocal();
	
    void loadIdentity();
	
    void fromFrustum(float near, float far, float left, float right, float top, float bottom, 
						bool parallel);
						
    void fromAngleAxis(float angle, Vector3f axis);
    void fromAngleNormalAxis(float angle, Vector3f axis);
	
    void multLocal(float scalar);
    Matrix4f mult(float scalar);
    Matrix4f mult(float scalar, Matrix4f store);
    Matrix4f mult(Matrix4f in2);
    Matrix4f mult(Matrix4f in2, Matrix4f store);
    Matrix4f multLocal(Matrix4f in2);
    Vector3f mult(Vector3f vec);
    Vector3f mult(Vector3f vec, Vector3f store);
    Vector4f mult(Vector4f vec);
    Vector4f mult(Vector4f vec, Vector4f store);
    Vector4f multAcross(Vector4f vec);
    Vector4f multAcross(Vector4f vec, Vector4f store);
    Vector3f multNormal(Vector3f vec, Vector3f store);
    Vector3f multNormalAcross(Vector3f vec, Vector3f store);
    float multProj(Vector3f vec, Vector3f store);
    Vector3f multAcross(Vector3f vec, Vector3f store);
    Quaternion mult(Quaternion vec, Quaternion store);
    List<float> mult(List<float> vec4f);
    List<float> multAcross(List<float> vec4f);
    Matrix4f invert();
    Matrix4f invert(Matrix4f store);
    Matrix4f invertLocal();
    Matrix4f adjoint();
    void setTransform(Vector3f position, Vector3f scale, Matrix3f rotMat);
    Matrix4f adjoint(Matrix4f store);
    float determinant();
    Matrix4f zero();
    Matrix4f add(Matrix4f mat);
    void addLocal(Matrix4f mat);
    Vector3f toTranslationVector();
    void toTranslationVector(Vector3f vector);
    Quaternion toRotationQuat();
    void toRotationQuat(Quaternion q);
    Matrix3f toRotationMatrix();
    void toRotationMatrix(Matrix3f mat);
	Vector3f toScaleVector();
	void toScaleVector(Vector3f vector);
    void setScale(float x, float y, float z);
    void setScale(Vector3f scale);
    void setTranslation(List<float> translation);
    void setTranslation(float x, float y, float z);
    void setTranslation(Vector3f translation);
    void setInverseTranslation(List<float> translation);
    void angleRotation(Vector3f angles);
    void setRotationQuaternion(Quaternion quat);
    void setInverseRotationRadians(List<float> angles);
    void setInverseRotationDegrees(List<float> angles);
    void inverseTranslateVect(List<float> vec);
    void inverseTranslateVect(Vector3f data);
    void translateVect(Vector3f data);
    void inverseRotateVect(Vector3f vec);
    void rotateVect(Vector3f vec);
    String toString();
    String getClassName();
    bool equals(cppObject *o);
   // void write(JmeExporter e);
   // void read(JmeImporter e);
    bool isIdentity();
    void scale(Vector3f scale);
    static bool equalIdentity(Matrix4f mat);
    void multLocal(Quaternion rotation);
    Matrix4f *clone();
	*/
	
};

}

#endif 
