#include "FastLED.h"
FASTLED_USING_NAMESPACE

#define DATA_PIN      17
#define NUM_LEDS      156
#define LED_TYPE      WS2812
#define COLOR_ORDER   GRB
CRGB leds[NUM_LEDS];

int delayval = 50; // Speed of Runner
int fadeVal = 10; // This should be brightestValue / numPixelFace and should be a whole number. 
//int numPixelFade = 20; The fade on either side
int pixelHue = 130;
int brightestValue = 200;

void setup() {
   FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
}

void loop() {
  for(int i=0;i<NUM_LEDS;i++){
    FastLED.clear();


    leds[i] = CHSV(pixelHue,255, brightestValue);
    
    for(int p = numPixelFade; p > 0; p--) {
      int left = i - p; 
      int right = i + p; 

      if(left >= 0) {
//        leds.setPixelColor(i-p, pixels.Color(0,200 - (fadeVal*p),200 - (fadeVal*p)));
        leds[i-p] = CHSV(pixelHue,255, brightestValue - (fadeVal*p));
      }
      else if(left < 0) {
//        leds.setPixelColor(NUM_LEDS + left, pixels.Color(0,200 - (fadeVal*p),200 - (fadeVal*p)));
        leds[NUM_LEDS + left] = CHSV(pixelHue,255, brightestValue - (fadeVal*p));
      }
      if (right < NUM_LEDS) {
//        leds.setPixelColor(i + p, pixels.Color(0,200 - (fadeVal*p),200 - (fadeVal*p)));]
        leds[i + p] = CHSV(pixelHue,255, brightestValue - (fadeVal*p));
      }
       else if(right >= NUM_LEDS) {
//        leds.setPixelColor(right - NUM_LEDS, pixels.Color(0,200 - (fadeVal*p),200 - (fadeVal*p)));
        leds[right - NUM_LEDS] = CHSV(pixelHue,255, brightestValue - (fadeVal*p));
      }
    }

    FastLED.show();
    delay(delayval);
  }  
}
