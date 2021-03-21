//
// Arduino Light Studies examples
// Jonas Vorwerk 2018
// https://jonasvorwerk.nl
//

#include "FastLED.h"

#define DATA_PIN    13
#define CLOCK_PIN   12
#define LED_TYPE    APA102
#define COLOR_ORDER BGR
#define BRIGHTNESS  128
#define FRAMES_PER_SECOND 30

const uint8_t kMatrixWidth = 8;
const uint8_t kMatrixHeight = 5;
const bool kMatrixSerpentineLayout = false;

#define NUM_LEDS  kMatrixWidth * kMatrixHeight

byte hue = 20;
byte sat = 255;
byte val = 255;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS);     //Adafruit Uno Neopixel shield
  //FastLED.addLeds<NEOPIXEL, 10>(leds, NUM_LEDS);  //Adafruit Feather Neopixel shield
  //FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLOCK_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();

  Serial.begin(9600);
}

void loop() {

  //only run is serial output is open
  //while (! Serial);

  EVERY_N_MILLISECONDS(200){
    drawCircle(1, random(kMatrixWidth-1), random(kMatrixHeight-1), random(255), 15);
    //drawCircle(1, random(kMatrixWidth-1), random(kMatrixHeight-1), random(255), random(2,15));
  }

  fadeToBlackBy(leds, NUM_LEDS, 20);

  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);

}

//draws a circle on a matrix with radius, x position, y position, hue, amount of steps
void drawCircle(uint8_t radius, uint8_t dot_x, uint8_t dot_y, byte hue, byte steps){

    float theta = 0;
    leds[ XY( dot_x, dot_y) ] = CHSV(hue, sat, val);

    while (theta <= 360) {
  
      float x = dot_x + radius * cos(theta);
      float y = dot_y + radius * sin(theta);
      theta += 360 / steps;

      //round the x,y positions to hole led pixels
      x = (int)round(x);
      y = (int)round(y);
  
      //check if x, y values fit onto the matrix, if no then don't show them to avoid errors
      if (x >= 0 &&  x < kMatrixWidth && y >= 0 && y < kMatrixHeight) {
        leds[ XY(x, y) ] = CHSV(hue, sat, val/2);
      }
    }
}

uint16_t XY( uint8_t x, uint8_t y) {
  uint16_t i;

  if (kMatrixSerpentineLayout == false) {
    i = (y * kMatrixWidth) + x;
  }

  if (kMatrixSerpentineLayout == true) {
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


