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
}

void loop() {  

  blink_every_time();

  FastLED.show();
  FastLED.delay(1000/FRAMES_PER_SECOND);
  
}

//functions here
void blink_every_time() {

  //do something every 1 second time 
//  EVERY_N_SECONDS(1){
//    hue = random(255);
//    for (int i = 0 ; i < NUM_LEDS ; i++) {
//        leds[i] = CHSV(hue, sat, val);
//    }
//  }

  //do something every 500 miliseconds
    EVERY_N_MILLISECONDS(500){
      for (int i = 0 ; i < NUM_LEDS ; i++) {
          leds[i] = CHSV(random(255), sat, val);
      }
    }
  
  //random time 
  //  EVERY_N_SECONDS_I(timer, random8( 5, 30)){
  //    timer.setPeriod( random8( 5, 30) );
  //    leds[0] = CHSV(hue, sat, 255);
  //  }

  //fadeout
  fadeToBlackBy(leds, NUM_LEDS, 20);
}
