#include <Adafruit_NeoPixel.h>

//Neopixel
#define NEO_PIN 12 //네오픽셀 연결 번호

#define LEDNUM 13 //LED 개수

// G R B
// 255 255 0
// 255 99 71

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDNUM, NEO_PIN, NEO_GRB + NEO_KHZ800);
int Led_Count = 0;

void setup() {
  Serial.begin(9600);

  pinMode(2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  strip.begin();
  strip.show();
  strip.setBrightness(50);
  delay(1000);

}

void loop() {
  strip.clear();
  
  if(digitalRead(2) == 0) {
    digitalWrite(LED_BUILTIN, 1);
    if(Led_Count > 10) Led_Count = 0;
    else Led_Count++;
    delay(100);
  }
  
  if(Led_Count == 1) NeopixelFunc(1, 0, 0, 0, 0, 0, 0);
  else if(Led_Count == 2) NeopixelFunc(0, 1, 0, 0, 0, 0, 0);
  else if(Led_Count == 3) NeopixelFunc(0, 0, 1, 0, 0, 0, 0);
  else if(Led_Count == 4) NeopixelFunc(0, 0, 0, 1, 0, 0, 0);
  else if(Led_Count == 5) NeopixelFunc(0, 0, 0, 0, 1, 0, 0);
  else if(Led_Count == 6) NeopixelFunc(0, 0, 0, 0, 0, 1, 0);
  else if(Led_Count == 7) NeopixelFunc(0, 0, 0, 0, 0, 0, 1);
  else if(Led_Count == 8) NeopixelFunc(1, 1, 1, 1, 0, 0, 0);
  else if(Led_Count == 9) NeopixelFunc(0, 0, 1, 1, 0, 0, 0);
  else if(Led_Count == 10) NeopixelFunc(0, 0, 0, 1, 0, 0, 1);
  strip.show();
  
  delay(10);
  digitalWrite(LED_BUILTIN, 0);
}

void NeopixelFunc(bool a, bool b, bool c, bool d, bool e, bool f, bool g) {
  
  for (int i = 0; i < 2; i++) {
    if(a) strip.setPixelColor(i, strip.Color(150, 255, 50)); 
    else strip.setPixelColor(i, strip.Color(0, 0, 0)); 
  } // 1층 화장실
  for (int i = 2; i < 3; i++) {
    if(b) strip.setPixelColor(i, strip.Color(150, 255, 50)); 
    else strip.setPixelColor(i, strip.Color(0, 0, 0)); 
  } // 1층 부엌 
  for (int i = 3; i < 5; i++) {
    if(c) strip.setPixelColor(i, strip.Color(150, 255, 50)); 
    else strip.setPixelColor(i, strip.Color(0, 0, 0)); 
  } // 1층 안방  
  for (int i = 5; i < 8; i++) {
    if(d) strip.setPixelColor(i, strip.Color(150, 255, 50)); 
    else strip.setPixelColor(i, strip.Color(0, 0, 0)); 
  } // 1층 거실 
  for (int i = 8; i < 9; i++) {
    if(e) strip.setPixelColor(i, strip.Color(150, 255, 50)); 
    else strip.setPixelColor(i, strip.Color(0, 0, 0)); 
  } // 1층 복도 
  for (int i = 9; i < 12; i++) {
    if(f) strip.setPixelColor(i, strip.Color(150, 255, 50)); 
    else strip.setPixelColor(i, strip.Color(0, 0, 0)); 
  } // 2층 창고 
  for (int i = 12; i < 14; i++) {
    if(g) strip.setPixelColor(i, strip.Color(150, 255, 50)); 
    else strip.setPixelColor(i, strip.Color(0, 0, 0)); 
  } // 2층 서재  
}
