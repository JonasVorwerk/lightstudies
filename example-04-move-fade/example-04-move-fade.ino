//
// Arduino Light Studies examples
// Jonas Vorwerk 2018
// https://jonasvorwerk.nl
//

#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 22     

#define DATA_PIN    13
#define CLOCK_PIN   12
#define LED_TYPE    APA102
#define COLOR_ORDER BGR

byte hue = 20;
byte sat = 255;
byte val = 255;

int current_led = 0;

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  //FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.addLeds<LED_TYPE,DATA_PIN,CLOCK_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(32);
  FastLED.clear();
}

void loop() {  

  fadeToBlackBy(leds, NUM_LEDS, 20);

  leds[current_led] = CHSV(hue, sat, val);

  if(current_led > NUM_LEDS-1) {
    current_led = 10;
  } else {
    current_led++;
  }
  
  FastLED.show();
  delay(100);

  //FastLED.clear();
}

