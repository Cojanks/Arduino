#include "FastLED.h"
FASTLED_USING_NAMESPACE

#define DATA_PIN      17
#define NUM_LEDS      156
#define LED_TYPE      WS2812
#define COLOR_ORDER   GRB
CRGB leds[NUM_LEDS];
uint8_t max_bright = 220;  
CRGBPalette16 currentPalette;

int brightnessVal = 250;

void setup() {
//  Serial.begin(9600);
  delay(3000); // 3 second delay for recovery
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  currentPalette = PartyColors_p;
  FastLED.setBrightness(max_bright);
}

uint8_t gHue = 50;


void loop() {
//
  EVERY_N_MILLISECONDS(20) {                                        // FastLED based non-blocking delay to update/display the sequence.
//   gHue++;
   sinelon_pixels();                                               // You don't really need the EVERY_N_MILLISECONDS in this routine.
  }
//
//    EVERY_N_MILLISECONDS(100) {                                    
//   gHue++;
//  }


  FastLED.show();

} // loop()



void sinelon_pixels() {

  fadeToBlackBy( leds, NUM_LEDS, 220);
  
  int pos1 = millis()/60;     //speed. Increase to go slower                         
  // int pos1 =  beatsin8(10,0,NUM_LEDS-7);                 // Back and forth a la sinelon.
  

  for (uint8_t i = 0; i<156; i++) { // The num max num here is the length of the total animation. 
                              //So 52 out of an array of 156 will mean that the animation is 1/3 the length of the array
    int thisbright = cubicwave8((i*5));    // number has to do with number of runners ? for an array of 156, 5 means 3 runners?          
    thisbright = thisbright*thisbright/255;             // Increase the brightness drop (see gamma correction).
    leds[(i+pos1)%NUM_LEDS] = ColorFromPalette( currentPalette, gHue, thisbright, LINEARBLEND);    
  }
  
} // sinelon_pixels()


