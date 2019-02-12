#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            17
#define NUMPIXELS      156

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 20;
int fadeVal = 10;
int numPixelFade = 20;

void setup() {
  pixels.begin();
}

void loop() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels.clear();

    pixels.setPixelColor(i, pixels.Color(0,200,200));

    for(int p = numPixelFade; p > 0; p--) {
      int left = i - p; 
      int right = i + p; 

      if(left >= 0) {
        pixels.setPixelColor(i-p, pixels.Color(0,200 - (fadeVal*p),200 - (fadeVal*p)));
      }
      else if(left < 0) {
        pixels.setPixelColor(NUMPIXELS + left, pixels.Color(0,200 - (fadeVal*p),200 - (fadeVal*p)));
      }
      if (right < NUMPIXELS) {
        pixels.setPixelColor(i + p, pixels.Color(0,200 - (fadeVal*p),200 - (fadeVal*p)));
      }
       else if(right >= NUMPIXELS) {
        pixels.setPixelColor(right - NUMPIXELS, pixels.Color(0,200 - (fadeVal*p),200 - (fadeVal*p)));
      }
    }

    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval);
  }  
}
