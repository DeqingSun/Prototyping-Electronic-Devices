#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, 13, NEO_RGB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
  pixels.setPixelColor(0, pixels.Color(31, 0, 0));
  pixels.show();
  delay(333);
  pixels.setPixelColor(0, pixels.Color(0, 31, 0));
  pixels.show();
  delay(333);
  pixels.setPixelColor(0, pixels.Color(0, 0, 31));
  pixels.show();
  delay(333);
}
