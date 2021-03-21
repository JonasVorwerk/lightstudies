//
// Arduino Light Studies examples
// Jonas Vorwerk 2018
// https://jonasvorwerk.nl
//

#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 32 
    
#define DATA_PIN    13
#define CLOCK_PIN   12
#define LED_TYPE    APA102
#define COLOR_ORDER BGR

byte hue = 0;
byte sat = 0;
byte val = 0;

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  //FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.addLeds<LED_TYPE,DATA_PIN,CLOCK_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(64);
  FastLED.clear();
}

void loop() {  

  for(int i = 0; i < NUM_LEDS; i++) {
    
    hue = random(255);
    sat = random(255);
    val = random(255);
    
    leds[i] = CHSV(hue, 255, 255);
  }
  
  FastLED.show();
  delay(250);
  
}
