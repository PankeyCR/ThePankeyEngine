
#define ame_ESP32_LILYGO_CAMERA_PLUS
#define ame_Level_10

#include "Box.h"
#include "Matrix4f.h"
#include "Application.h"
#include "DefaultApplication.h"
#include "ST7789.h"

#define SDCARA_CS 0
#define SNAP_QUALITY 6 // 1-63, 1 is the best

ST7789 tft = ST7789(); // Invoke library, pins defined in User_Setup.h

using namespace ame;

Application* app;
Box mesh;
Matrix4f matrix;
Vector3f vCamera;
float hegth = 240;
float width = 240;
float fTheta = 0;

void setup() {
  Serial.begin(9600);
  app = new DefaultApplication();
  Box mesh;
  float fNear = 0.1f;
  float fFar = 1000.0f;
  float fFov = 90.0f;
  float fAspectRatio = hegth / width;
  float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);

  matrix[0][0] = fAspectRatio * fFovRad;
  matrix[1][1] = fFovRad;
  matrix[2][2] = fFar / (fFar - fNear);
  matrix[3][2] = (-fFar * fNear) / (fFar - fNear);
  matrix[2][3] = 1.0f;
  matrix[3][3] = 0.0f;

  tft.init();
  tft.invertDisplay(true);
  tft.setSwapBytes(true);
  tft.setRotation(0);

}

void loop() {
  app->update();
  float tpc = app->getStateManager()->tpc();
  tft.fillScreen(TFT_BLACK);

  Matrix4f matrixRotZ , matrixRotX;
  fTheta += 1.0f * tpc;

  matrixRotZ[0][0] = cosf(fTheta);
  matrixRotZ[0][1] = sinf(fTheta);
  matrixRotZ[1][0] = -sinf(fTheta);
  matrixRotZ[1][1] = cosf(fTheta);
  matrixRotZ[2][2] = 1;
  matrixRotZ[3][3] = 1;

  matrixRotX[0][0] = 1;
  matrixRotX[1][1] = cosf(fTheta * 0.5f);
  matrixRotX[1][2] = sinf(fTheta * 0.5f);
  matrixRotX[2][1] = -sinf(fTheta * 0.5f);
  matrixRotX[2][2] = cosf(fTheta * 0.5f);
  matrixRotX[3][3] = 1;

  for (int x = 0; x < mesh.triangles.getPosition(); x++) {
    Triangle triangle = mesh.triangles[x];
    Triangle triangleProjected , triangleTranslated , triangleRotatedZ , triangleRotatedZX;

    triangleRotatedZ[0] = matrixRotZ.multMatrixVector(triangle[0]);
    triangleRotatedZ[1] = matrixRotZ.multMatrixVector(triangle[1]);
    triangleRotatedZ[2] = matrixRotZ.multMatrixVector(triangle[2]);


    triangleRotatedZX[0] = matrixRotX.multMatrixVector(triangleRotatedZ[0]);
    triangleRotatedZX[1] = matrixRotX.multMatrixVector(triangleRotatedZ[1]);
    triangleRotatedZX[2] = matrixRotX.multMatrixVector(triangleRotatedZ[2]);

    triangleTranslated = triangleRotatedZX;

    triangleTranslated[0].z = triangleRotatedZX[0].z * 3.0f;
    triangleTranslated[1].z = triangleRotatedZX[1].z * 3.0f;
    triangleTranslated[2].z = triangleRotatedZX[2].z * 3.0f;

    Vector3f normal, line1, line2;
    line1.x = triangleTranslated[1].x - triangleTranslated[0].x;
    line1.y = triangleTranslated[1].y - triangleTranslated[0].y;
    line1.z = triangleTranslated[1].z - triangleTranslated[0].z;

    line2.x = triangleTranslated[2].x - triangleTranslated[0].x;
    line2.y = triangleTranslated[2].y - triangleTranslated[0].y;
    line2.z = triangleTranslated[2].z - triangleTranslated[0].z;

    normal.x = line1.y * line2.z - line1.z * line2.y;
    normal.y = line1.z * line2.x - line1.x * line2.z;
    normal.z = line1.x * line2.y - line1.y * line2.x;
    float l = sqrtf(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
    normal.x /= l; normal.y /= l; normal.z /= l;

    //if (normal.z < 0)
    if (normal.x * (triangleTranslated[0].x - vCamera.x) +
        normal.y * (triangleTranslated[0].y - vCamera.y) +
        normal.z * (triangleTranslated[0].z - vCamera.z) < 0.0f) {

      // Illumination
      Vector3f light_direction = Vector3f(0.0f, 0.0f, -1.0f);
      float l = sqrtf(light_direction.x * light_direction.x + light_direction.y * light_direction.y + light_direction.z * light_direction.z);
      light_direction.x /= l; light_direction.y /= l; light_direction.z /= l;

      triangleProjected[0] = matrix.multMatrixVector(triangleTranslated[0]);
      triangleProjected[1] = matrix.multMatrixVector(triangleTranslated[1]);
      triangleProjected[2] = matrix.multMatrixVector(triangleTranslated[2]);

      triangleProjected[0].x += 2.7f; triangleProjected[0].y += 2.7f;
      triangleProjected[1].x += 2.7f; triangleProjected[1].y += 2.7f;
      triangleProjected[2].x += 2.7f; triangleProjected[2].y += 2.7f;

      triangleProjected[0].x *= 0.2f * width;
      triangleProjected[0].y *= 0.2f * hegth;
      triangleProjected[1].x *= 0.2f * width;
      triangleProjected[1].y *= 0.2f * hegth;
      triangleProjected[2].x *= 0.2f * width;
      triangleProjected[2].y *= 0.2f * hegth;

      tft.drawTriangle(triangleProjected[0].x, triangleProjected[0].y,
                       triangleProjected[1].x, triangleProjected[1].y,
                       triangleProjected[2].x, triangleProjected[2].y,
                       TFT_WHITE);
    }
    //    Serial.print("triangleProjected ");Serial.println(triangleProjected);
  }
  //  Serial.print("matrix ");Serial.println(matrix);
}
