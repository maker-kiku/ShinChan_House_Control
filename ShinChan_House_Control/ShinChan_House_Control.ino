#include <Adafruit_NeoPixel.h>

//Neopixel
#define NEO_PIN 13 //네오픽셀 연결 번호

#define LEDNUM 33 //LED 개수

// G R B
// 255 255 0
// 255 99 71

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDNUM, NEO_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);

  strip.begin();
  strip.show();
  strip.setBrightness(50);
  delay(1000);

}

void loop() {
  strip.clear();
  NeopixelFunc();
  strip.show();
  delay(10);
}

void NeopixelFunc() {
  
  for (int i = 0; i < 2; i++) LightON(i);
  for (int i = 2; i < 4; i++) LightON(i);
  for (int i = 4; i < 6; i++) LightON(i);
  for (int i = 6; i < 10; i++) LightON(i);
  for (int i = 10; i < 33; i++) LightON(i);
  
}

void LightON(int i) {
  strip.setPixelColor(i, strip.Color(150, 255, 50));
}

void LightOFF(int i) {
  strip.setPixelColor(i, strip.Color(0, 0, 0));
}
