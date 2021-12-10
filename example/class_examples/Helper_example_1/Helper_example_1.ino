
#include "Helper.hpp"
#include "Vector2f.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("similar Vector2f: ");Serial.println(similar(Vector2f(2.9f, 2.9f), Vector2f(3,3), Vector2f(0.5f,0.5f)));
  Serial.print("similar float: ");Serial.println(similar(2.3f, 3.4f, 0.5f));
}
