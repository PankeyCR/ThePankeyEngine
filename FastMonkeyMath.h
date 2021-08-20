
#ifndef FastMonkeyMath_h
#define FastMonkeyMath_h

#include "Vector3f.h"
#include "Vector2f.h"
#include "RealRandom.h"

#define DBL_EPSILON 2.220446049250313e-16f
#define FLT_EPSILON 1.1920928955078125e-7f
#define ZERO_TOLERANCE 0.0001f
#define ONE_THIRD 0.3333333333333f
#define QUARTER_PI 0.25f * PI
#define INV_PI 1.0f / PI
#define INV_TWO_PI 1.0f / TWO_PI

namespace ame{

class FastMonkeyMath{
	private:
		static RealRandom *realRandom;
		static int randomSize;
		
		// FastMonkeyMath();
    public:
	
	
    static float Random();
    static void setRandomSize(int size);

    static bool isPowerOfTwo(int number);
    static int nearestPowerOfTwo(int number);
    static float interpolateLinear(float scale, float startValue, float endValue);
    static Vector3f interpolateLinear(float scale, 
									  Vector3f startValue, 
								      Vector3f endValue); 
    static float extrapolateLinear(float scale, float startValue, float endValue);
    static Vector3f extrapolateLinear(float scale, 
								      Vector3f startValue, 
									  Vector3f endValue);
    static float interpolateCatmullRom(float u, float T, 
									   float p0, float p1, 
									   float p2, float p3);
    static Vector3f interpolateCatmullRom(float u, float T, 
										  Vector3f p0, Vector3f p1, 
										  Vector3f p2, Vector3f p3);      
    static float interpolateBezier(float u, float p0, float p1, float p2, float p3);     
    static Vector3f interpolateBezier(float u, 
									  Vector3f p0, Vector3f p1, 
									  Vector3f p2, Vector3f p3);

    static float getCatmullRomP1toP2Length(Vector3f p0, Vector3f p1, Vector3f p2, Vector3f p3, 
										   float startRange, float endRange, float curveTension);
    static float getBezierP1toP2Length(Vector3f p0, Vector3f p1, Vector3f p2, Vector3f p3);
    static float acos(float fValue);
    static float asin(float fValue);
    // static float atan(float fValue);
    // static float atan2(float fY, float fX);
    // static float ceil(float fValue);
    // static float cos(float v);
    // static float sin(float v);
    // static float exp(float fValue);
    // static float abs(float fValue);
    // static float floor(float fValue);
    static float invSqrt(float fValue);
    static float fastInvSqrt(float x);
    static float intBitsToFloat(int x);
    static float floatToIntBits(float x);
    //static float log(float fValue);
    //static float log(float value, float base);
    //static float pow(float fBase, float fExponent);
    static float sqr(float fValue);
    // static float sqrt(float fValue);
    // static float tan(float fValue);
    static int sign(int iValue);
    //static float sign(float fValue);
    static int counterClockwise(Vector2f p0, Vector2f p1, Vector2f p2);
    static int pointInsideTriangle(Vector2f t0, Vector2f t1, Vector2f t2, Vector2f p);
    static Vector3f computeNormal(Vector3f v1, Vector3f v2, Vector3f v3);
    static float determinant(double m00, double m01, double m02,
            double m03, double m10, double m11, double m12, double m13,
            double m20, double m21, double m22, double m23, double m30,
            double m31, double m32, double m33);
    // static float nextRandomFloat();
    // static int nextRandomInt(int min, int max);
    // static int nextRandomInt();
    static Vector3f sphericalToCartesian(Vector3f sphereCoords);
    static Vector3f cartesianToSpherical(Vector3f cartCoords);
    static Vector3f sphericalToCartesianZ(Vector3f sphereCoords);
    static Vector3f cartesianZToSpherical(Vector3f cartCoords);
    static float normalize(float val, float min, float max);
    static float copysign(float x, float y);
    static float clamp(float input, float min, float max);
    static float saturate(float input);
    static bool approximateEquals(float a, float b);
    static float convertHalfToFloat(short half);
	static short convertFloatToHalf(float flt);
};

}

#endif 
