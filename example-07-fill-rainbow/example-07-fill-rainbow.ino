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

CRGB leds[NUM_LEDS];

void setup() { 
  //FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.addLeds<LED_TYPE,DATA_PIN,CLOCK_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(64);
  FastLED.clear();
}

void loop() {  

  fill_rainbow(leds, NUM_LEDS, 0, 5);            // Use FastLED's fill_rainbow routine.

  FastLED.show();
  FastLED.delay(1000/FRAMES_PER_SECOND);
  
}


