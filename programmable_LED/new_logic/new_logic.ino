#include <FastLED.h>
#define LED_PIN 5
#define LED_NUM 15
#define LEDS_PER_STEP 3
#define DEFAULT_BRIGHTNESS 1

CRGB leds[LED_NUM];
uint8_t speedValue = 0;

const CRGB colors[] = {
  CRGB::Black,
  CRGB::White,
  CRGB::Red,
  CRGB::Blue,
  CRGB::LawnGreen
};

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(DEFAULT_BRIGHTNESS);  //(0-255)

  Serial.begin(115200);
  Serial.println("Speed LED Controller Ready");

  fill_solid(leds, LED_NUM, CRGB::Black);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    speedValue = Serial.parseInt();
  }
  FastLED.clear();
  Serial.print("Current Speed : ");
  Serial.println(speedValue);

  uint8_t Segments = speedValue;
  uint8_t lightLEDS = Segments * LEDS_PER_STEP;

  for (uint8_t i = 0; i < min(lightLEDS, LED_NUM); i++) {
    uint8_t segment = i / LEDS_PER_STEP; 
    leds[i] = colors[segment + 1];
  }

  FastLED.show();
  delay(50);
}
