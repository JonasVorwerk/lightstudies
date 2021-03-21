//
// Arduino Light Studies examples
// Jonas Vorwerk 2018
// https://jonasvorwerk.nl
//

#include "FastLED.h"

#define NUM_LEDS    22     
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

  Serial.begin(9600);
}

void loop() {  

  EVERY_N_MILLISECONDS( 20 ) { 
    hue++;
  } 

  //confetti();
  //twodots;
  bpmdot();

  FastLED.show();
  FastLED.delay(1000/FRAMES_PER_SECOND);
  
}

void confetti() {
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( hue + random8(64), 200, 255);
}

void twodots(){
  for(int i = 0; i < NUM_LEDS-1; i++) { 
    leds[i] = CRGB::Red; 
    leds[i+1] = CRGB::Red;
    FastLED.delay(100); 
    leds[i] = CRGB::Black; 
    leds[i+1] = CRGB::Black;
  }
}

int dot;
void bpmdot(){
  dot = beatsin16(10, 0, NUM_LEDS);
  leds[dot] = CHSV(hue, 200, 255);
  
  fadeToBlackBy(leds, NUM_LEDS, 64);
}
