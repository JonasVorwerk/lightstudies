//
// Arduino Light Studies examples
// Jonas Vorwerk 2018
// https://jonasvorwerk.nl
//

#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 30

// which cable goes in what pin?
#define DATA_PIN 12
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
}

void loop() { 

  // All differtent methods to define a color to one led

  leds[0] = 0xFF44DD;
  FastLED.show();
  delay(500);

  leds[0] = CRGB::Red;
  FastLED.show();
  delay(500);

  leds[0].r = 255; 
  leds[0].g = 68; 
  leds[0].b = 221;
  FastLED.show();
  delay(500);

  leds[0].setRGB(20, 255, 221); //RGB
  FastLED.show();
  delay(500);

  leds[0] = CRGB( 255, 68, 221); //RGB
  FastLED.show();
  delay(500);
  
  leds[0] = CHSV(20, 255, 255); //HUE SAT VAL
  FastLED.show();
  delay(500);

}
