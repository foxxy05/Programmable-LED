#include <FastLED.h>
#define LED_PIN 12
#define LED 2
#define NUM_LEDS 24

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(128);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Purple;
    FastLED.show();
    delay(50);

    leds[i] = CRGB::Black;  // Red
    FastLED.show();
    delay(50);
  }

  for (int i = NUM_LEDS - 1; i > 0; i--) {
    leds[i] = CRGB::Purple;
    FastLED.show();
    delay(50);

    leds[i] = CRGB::Black;  // Red
    FastLED.show();
    delay(50);
  }
}
