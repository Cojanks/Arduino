#include "FastLED.h"
FASTLED_USING_NAMESPACE

#define DATA_PIN      17
#define NUM_LEDS      156
#define LED_TYPE      WS2812
#define COLOR_ORDER   GRB
CRGB leds[NUM_LEDS];


CRGBPalette16 chosenPalette;
TBlendType    chosenBlending;

void setup() {
  delay(3000); // 3 second delay for recovery
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

    // #1-A
//  SetupRedAndBlackPalette();

    // #1-B 
//  SetupBlackAndWhiteStripedPalette()

    // #1-C
  SetupBlackBlueGreenAndWhiteStripedPalette();

  chosenBlending = LINEARBLEND;
}

void loop() {
        // Fill a strip with a gradient. The below will default to taking the 'shortest' path in hue: 50 to 0 -> 255 to 200
        // Starts at 0 and goes to 100 pixels
//      fill_gradient(leds, 0, CHSV(50, 255, 200), 100, CHSV(200, 255, 200));

        // Fill 100 pixels with a gradient. Defaults to taking the shortest
//      fill_gradient(leds, 100, CHSV(50, 255, 200), CHSV(200, 255, 200));

        // Fill 100 pixels with a gradient with 3 anchors, no change in 'direction' in hue value scale
//      fill_gradient(leds, 100, CHSV(50, 255, 200), CHSV(100, 255, 200), CHSV(200, 255, 200));

        //Fill 100 pixels with 3 color anchors that change direction in the hue value scale
//      fill_gradient(leds, 100, CHSV(50, 255, 200), CHSV(180, 255, 200), CHSV(0, 255, 200));

        // 3 color anchors, middle anchor is black (value = 0)
//      fill_gradient(leds, 100, CHSV(100, 255, 200), CHSV(100, 255, 0), CHSV(200, 255, 200));



      // #1-A, #1-B, #1-C: Marching fades. Have some control over the number of runners but only from the palette.
      static uint8_t startIndex = 0;
      startIndex = startIndex + 10; /* motion speed */
      FillLEDsFromCustomPalette( startIndex );
        
  FastLED.show();
  FastLED.delay(10);  
}


void FillLEDsFromCustomPalette( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; i++) {      
        leds[i] = ColorFromPalette( chosenPalette, colorIndex, brightness, chosenBlending);
        colorIndex += 15; //The lower this number, the larger and fewer the runner
    }
}

// #1-A
void SetupRedAndBlackPalette()
{
    CRGB crimsonRed = CHSV(10, 255, 200);
    CRGB black  = CRGB::Black;
    
    chosenPalette = CRGBPalette16(
                                   crimsonRed,  crimsonRed,  black,  black,
                                   black, black, black,  black,
                                   black,  black,  black,  black,
                                   black, black, black,  black );
}

// #1-B
void SetupBlackAndWhiteStripedPalette()
{
    // 'black out' all 16 palette entries...
    fill_solid( chosenPalette, 16, CRGB::Black);
    // and set every fourth one to white.
    chosenPalette[0] = CRGB::White;
    chosenPalette[4] = CRGB::White;
    chosenPalette[8] = CRGB::White;
    chosenPalette[12] = CRGB::White;
    
}

// #1-C
void SetupBlackBlueGreenAndWhiteStripedPalette()
{
    // 'black out' all 16 palette entries...
    fill_solid( chosenPalette, 16, CRGB::Black);
    // The following 2 will blend together
    chosenPalette[0] = CRGB::Red;
    chosenPalette[1] = CRGB::Red;
    // Giant blank/black space
    // Followed by a Blue+Green block of lit pixels that blend together
    chosenPalette[11] = CRGB::Blue;
    chosenPalette[12] = CRGB::Green;
    
}

