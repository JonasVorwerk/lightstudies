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
#define BRIGHTNESS  32
#define FRAMES_PER_SECOND 30

#define BUTTON_PIN 11

byte hue = 20;
byte sat = 255;
byte val = 255;

CRGB leds[NUM_LEDS];

void setup() { 
  //FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.addLeds<LED_TYPE,DATA_PIN,CLOCK_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();

  pinMode(BUTTON_PIN, INPUT);
}

void loop() {  

  up_down();

  FastLED.show();
  FastLED.delay(1000/FRAMES_PER_SECOND);
  
}

//functions here
void up_down() {

  if(!digitalRead(BUTTON_PIN)){
    for (int i = 0 ; i < NUM_LEDS ; i++) {
      leds[i] += CRGB(5, 5, 5); 
    }
  } else {
    for (int i = 0 ; i < NUM_LEDS ; i++) {
      leds[i] -= CRGB(2, 2, 2);
    }
  }
}

