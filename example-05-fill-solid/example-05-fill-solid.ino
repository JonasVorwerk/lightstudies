//
// Arduino Light Studies examples
// Jonas Vorwerk 2018
// https://jonasvorwerk.nl
//

#include "FastLED.h"

#define NUM_LEDS 32     

#define DATA_PIN    13
#define CLOCK_PIN   12
#define LED_TYPE    APA102
#define COLOR_ORDER BGR

#define FRAMES_PER_SECOND 30

byte hue = 20;
byte sat = 255;
byte val = 255;

int current_led = 0;

CRGB leds[NUM_LEDS];

void setup() { 
  //FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.addLeds<LED_TYPE,DATA_PIN,CLOCK_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(64);
  FastLED.clear();
}

void loop() {  

  //fill first 10 leds yellow
  fill_solid(leds, 10, CHSV(20, sat, val));
  
  //fill 5 leds red after 10 leds
  fill_solid(leds+10, 5, CHSV(160, sat, val));
  
  FastLED.show();
  FastLED.delay(1000/FRAMES_PER_SECOND);
  
}


