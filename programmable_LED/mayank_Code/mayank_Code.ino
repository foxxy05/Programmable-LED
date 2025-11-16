#include <FastLED.h>
#define LED_PIN 12
#define LED_NUM 15

int speedValue = 0;
CRGB leds[LED_NUM];


void speed(int color_No, int LED);
const CRGB color[] = {
  CRGB::Black,
  CRGB::Purple,
  CRGB::White,
  CRGB::Red,
  // CRGB::Blue,
  // CRGB::Green
};

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
  Serial.print("Current Speed : ");
  Serial.println(speedValue);

  if (Serial.available()) {
    speedValue = Serial.parseInt();
  }

  if (speedValue == 1) {
    speed(1, 0);
  }

  else if (speedValue == 2) {
    speed(1, 0);
    speed(2, 3);
  }

  else if (speedValue == 3) {
    speed(1, 0);
    speed(2, 3);
    speed(3, 6);
  }

  else if (speedValue == 4) {
    speed(1, 0);
    speed(2, 3);
    speed(3, 6);
    speed(4, 9);
  }

  else if (speedValue == 5) {
    speed(1, 0);
    speed(2, 3);
    speed(3, 6);
    speed(4, 9);
    speed(5, 12);
  }

  else {
    for (int i = 0; i < LED_NUM; i++) {
      leds[i] = color[0];
    }
  }

  FastLED.show();
  delay(50);
}

void speed(int color_No, int LED) {
  for (int i = LED; i < LED + 3; i++) {
    leds[i] = color[color_No];
  }

  for (int i = LED + 3; i < LED_NUM; i++) {
    leds[i] = color[0];
  }
}
