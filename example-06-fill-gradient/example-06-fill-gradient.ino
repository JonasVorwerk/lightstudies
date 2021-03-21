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

CRGB leds[NUM_LEDS];

void setup() { 
  //FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.addLeds<LED_TYPE,DATA_PIN,CLOCK_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(64);
  FastLED.clear();
}

void loop() {  

  //FORWARD_HUES, BACKWARD_HUES, SHORTEST_HUES, LONGEST_HUES
  //fill_gradient(leds, startpos, CHSV(50, 255,255) , endpos, CHSV(150,255,255), SHORTEST_HUES);
  fill_gradient(leds, 0, CHSV(50, 255,255) , 22, CHSV(150,255,255), SHORTEST_HUES); // up to 4 CHSV values

  FastLED.show();
  FastLED.delay(1000/FRAMES_PER_SECOND);
  
}


