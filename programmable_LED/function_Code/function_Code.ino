#include <FastLED.h>

#define LED_PIN 12
#define LED_NUM 15

int speed = 0;
CRGB leds[LED_NUM];

void speedOne();
void speedTwo();
void speedThree();
void speedFour();
void speedFive();
void speedElse();

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(64);
  FastLED.clear();
  FastLED.show();

  Serial.begin(9600);
  Serial.print("GANPATI BAPPA MORYA!!!");

  FastLED.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Current Speed : ");
  Serial.println(speed);

  if (Serial.available()) {
    speed = Serial.parseInt();
  }

  if (speed == 1) {
    speedOne();
  } else if (speed == 2) {
    speedTwo();
  } else if (speed == 3) {
    speedThree();
  } else if (speed == 4) {
    speedFour();
  } else if (speed == 5) {
    speedFive();
  } else {
    speedElse();
  }

  FastLED.show();
  delay(50);
}

void speedOne() {
  leds[0] = CRGB::White;
  leds[1] = CRGB::White;
  leds[2] = CRGB::White;

  for (int i = 3; i < LED_NUM; i++) {
    leds[i] = CRGB::Black;
  }
}

void speedTwo() {
  // speedOne();
  leds[3] = CRGB::Yellow;
  leds[4] = CRGB::Yellow;
  leds[5] = CRGB::Yellow;

  for (int i = 6; i < LED_NUM; i++) {
    leds[i] = CRGB::Black;
  }
}

void speedThree() {
  speedTwo();
  leds[6] = CRGB::Red;
  leds[7] = CRGB::Red;
  leds[8] = CRGB::Red;

  for (int i = 9; i < LED_NUM; i++) {
    leds[i] = CRGB::Black;
  }
}

void speedFour() {
  speedThree();
  leds[9] = CRGB::Blue;
  leds[10] = CRGB::Blue;
  leds[11] = CRGB::Blue;

  for (int i = 12; i < LED_NUM; i++) {
    leds[i] = CRGB::Black;
  }
}

void speedFive() {
  speedFour();
  leds[12] = CRGB::Green;
  leds[13] = CRGB::Green;
  leds[14] = CRGB::Green;
}

void speedElse() {
  for (int i = 0; i < LED_NUM; i++) {
    leds[i] = CRGB::Black;
  }
}
