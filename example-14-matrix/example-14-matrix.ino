//
// Arduino Light Studies examples
// Jonas Vorwerk 2018
// https://jonasvorwerk.nl
//

#include "FastLED.h"

#define NUM_LEDS    32
#define DATA_PIN    13
#define CLOCK_PIN   12
#define LED_TYPE    APA102
#define COLOR_ORDER BGR
#define BRIGHTNESS  64
#define FRAMES_PER_SECOND 30

const uint8_t kMatrixWidth = 8;
const uint8_t kMatrixHeight = 4;
const bool kMatrixSerpentineLayout = false;

byte hue = 20;
byte sat = 255;
byte val = 255;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, 10>(leds, NUM_LEDS);
  //FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLOCK_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();

  Serial.begin(9600);
}

void loop() {

  //while (! Serial);

  EVERY_N_MILLISECONDS(400){
    drawDot(random(kMatrixWidth-1), random(kMatrixHeight-1), random(255));
  }

  fadeToBlackBy(leds, NUM_LEDS, 20);

  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);

}

//draws a dot on a matrix with x position, y position, hue
void drawDot(uint8_t dot_x, uint8_t dot_y, byte hue){

    leds[ XY( dot_x, dot_y) ] = CHSV(hue, sat, val);

}

uint16_t XY( uint8_t x, uint8_t y) {
  uint16_t i;

  if ( kMatrixSerpentineLayout == false) {
    i = (y * kMatrixWidth) + x;
  }

  if ( kMatrixSerpentineLayout == true) {
    if ( y & 0x01) {
      // Odd rows run backwards
      uint8_t reverseX = (kMatrixWidth - 1) - x;
      i = (y * kMatrixWidth) + reverseX;
    } else {
      // Even rows run forwards
      i = (y * kMatrixWidth) + x;
    }
  }

  return i;
}
