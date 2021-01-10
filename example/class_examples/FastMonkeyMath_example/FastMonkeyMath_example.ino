
#include "FastMonkeyMath.h"
#include "Vector2f.h"
#include "Vector3f.h"

void setup() {
  Serial.begin(9600);
}

void loop(){
  Serial.println("start ");

  int npowertwo = 57;
  float scale = 0.55f;

  Serial.print("nearestPowerOfTwo "+ String(npowertwo) +" ");Serial.println(FastMonkeyMath::nearestPowerOfTwo(npowertwo));
  Serial.print("interpolateLinear "+ String(scale) +" ");Serial.println(FastMonkeyMath::interpolateLinear(scale,0,100));

  Vector3f start(0,0,0);
  Vector3f end(100,100,100);
  Serial.print("interpolateLinear "+ String(scale) +" ");Serial.println(FastMonkeyMath::interpolateLinear(scale,start,end).toString());
  
  Serial.print("extrapolateLinear "+ String(scale) +" ");Serial.println(FastMonkeyMath::extrapolateLinear(scale,0,100));
  Serial.print("extrapolateLinear "+ String(scale) +" ");Serial.println(FastMonkeyMath::extrapolateLinear(scale,start,end).toString());
  Serial.print("acos ");Serial.println(acos(-5));
  Serial.print("acos ");Serial.println(FastMonkeyMath::acos(-5));
  Serial.print("asin ");Serial.println(asin(100));
  Serial.print("asin ");Serial.println(FastMonkeyMath::asin(100));
  Serial.print("invSqrt ");Serial.println(FastMonkeyMath::invSqrt(10));
  Serial.print("log ");Serial.println(log(10));
//  Serial.print("log ");Serial.println(log(10,10));
  Vector2f f0(10,10);
  Vector2f f1(20,20);
  Vector2f f2(30,30);
  Vector2f f3(5,5);
  
  Vector3f c0(5,5,5);
  Vector3f c1(5,5,5);
  Vector3f c2(5,5,5);
  Serial.print("counterClockwise ");Serial.println(FastMonkeyMath::counterClockwise(f0,f1,f2));
  Serial.print("pointInsideTriangle ");Serial.println(FastMonkeyMath::pointInsideTriangle(f0,f1,f2,f3));
  Serial.print("computeNormal ");Serial.println(FastMonkeyMath::computeNormal(c0,c1,c2).toString());
  Serial.print("sphericalToCartesian ");Serial.println(FastMonkeyMath::sphericalToCartesian(c0).toString());
  Serial.print("sphericalToCartesian ");Serial.println(FastMonkeyMath::sphericalToCartesian(c0).toString());
  Serial.print("sphericalToCartesianZ ");Serial.println(FastMonkeyMath::sphericalToCartesianZ(c0).toString());
 // Serial.print("cartesianZToSpherical ");Serial.println(FastMonkeyMath::cartesianZToSpherical(c0).toString());//error, soon will be fix, lol
  Serial.println("end ");
}