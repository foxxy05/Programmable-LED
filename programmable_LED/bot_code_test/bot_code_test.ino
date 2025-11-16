#include <FastLED.h>

#define LED_PIN 12
#define LED_NUM 15

int speed = 0;
CRGB leds[LED_NUM];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(128);
  FastLED.clear();
  FastLED.show();

  Serial.begin(9600);
  Serial.print("GANPATI BAPPA MORYA!!!");

  FastLED.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Current Speed : ");
  Serial.println(speed);

  if (Serial.available()) {
    speed = Serial.parseInt();
  }

  if (speed == 1) {
    leds[0] = CRGB::White;
    leds[1] = CRGB::White;
    leds[2] = CRGB::White;

    for(int i = 3; i < LED_NUM; i++){
      leds[i] = CRGB::Black;
    }
    FastLED.show();
  }

  else if (speed == 2) {
    leds[3] = CRGB::Yellow;
    leds[4] = CRGB::Yellow;
    leds[5] = CRGB::Yellow;

    for(int i = 6; i < LED_NUM; i++){
      leds[i] = CRGB::Black;
    }
    FastLED.show();
  }

  else if (speed == 3) {
    leds[6] = CRGB::Orange;
    leds[7] = CRGB::Orange;
    leds[8] = CRGB::Orange;

    for(int i = 9; i < LED_NUM; i++){
      leds[i] = CRGB::Black;
    }
    FastLED.show();
  }

  else if (speed == 4) {
    leds[9] = CRGB::Red;
    leds[10] = CRGB::Red;
    leds[11] = CRGB::Red;

    for(int i = 12; i < LED_NUM; i++){
      leds[i] = CRGB::Black;
    }
    FastLED.show();
  }

  else if (speed == 5) {
    leds[12] = CRGB::Blue;
    leds[13] = CRGB::Blue;
    leds[14] = CRGB::Blue;
    FastLED.show();
  }

  else {
    for(int i = 0; i < LED_NUM; i++){
      leds[i] = CRGB::Black;
    }
    FastLED.show();
  }

  delay(100);
}
