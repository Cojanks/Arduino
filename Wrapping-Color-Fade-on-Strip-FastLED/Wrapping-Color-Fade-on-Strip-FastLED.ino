#include "FastLED.h"
FASTLED_USING_NAMESPACE

// Instead of a main pixel runner (my term for a pixel that runs down a strip) with a fading tail, the
// runner has a fade up to the 'main' pixel followed by a fade down. 
// This animation will wrap around the strip so if the strip is circular, the runner appears to never stop.
// EX: [0,0,1,2,3,4(main runner),3,2,1,0,0,0,0]

#define DATA_PIN      17
#define NUM_LEDS      100
#define LED_TYPE      WS2812
#define COLOR_ORDER   GRB
CRGB leds[NUM_LEDS];

int delayval = 20; // Speed of Runner
int fadeVal = 10; // This should be (brightestValue / numPixelFace) and should be a whole number. 
int numPixelFade = 20; // The fade on either side of the 'main' pixel
int pixelHue = 20;
int brightestValue = 200;

void setup() {
   FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
}

void loop() {
  for(int i=0;i<NUM_LEDS;i++){
    FastLED.clear();

    // Sets the main pixel
    leds[i] = CHSV(pixelHue,255, brightestValue);
    
    // Once the main pixel is set, you look to the left/right for the fade, starting with the furthest out
    for(int p = numPixelFade; p > 0; p--) {
      // Find the furthest left/right array index of your fade
      int left = i - p; 
      int right = i + p; 

      // Handle Left
      //  If the left most fade indec of the fade does not fall outside of the array:
      if(left >= 0) {
        leds[i-p] = CHSV(pixelHue,255, brightestValue - (fadeVal*p));
      }
      else if(left < 0) { // if the fade needs to wrap from the left to the end of the array:
        leds[NUM_LEDS + left] = CHSV(pixelHue,255, brightestValue - (fadeVal*p));
      }

      // Handle Right
      //  If the right most part of the fade does not fall outside of the array:
      if (right < NUM_LEDS) {
        leds[i + p] = CHSV(pixelHue,255, brightestValue - (fadeVal*p));
      }
      // Else if the right-most fade index extends past the led strip length and needs to wrap to the beginning:
       else if(right >= NUM_LEDS) { 
        leds[right - NUM_LEDS] = CHSV(pixelHue,255, brightestValue - (fadeVal*p));
      }
    }

    FastLED.show();
    delay(delayval);
  }  
}
