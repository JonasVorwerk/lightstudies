//
// Arduino Light Studies examples
// Jonas Vorwerk 2018
// https://jonasvorwerk.nl
//

#include "FastLED.h"

#define NUM_LEDS    41    

#define DATA_PIN    12
#define CLOCK_PIN   13
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

  pulse_sat();

  FastLED.show();
  FastLED.delay(1000/FRAMES_PER_SECOND);
  
}

//functions here

void pulse_hue(){
  for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(beatsin8(40, 64, 255), sat, val); //bpm, lowvalue, highvalue
  }
}

void pulse_sat(){
  for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, beatsin8(40, 64, 255), val); //bpm, lowvalue, highvalue
  }
}

void pulse_val(){
  for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue, sat, beatsin8(40, 64, 255)); //bpm, lowvalue, highvalue
  }
}

