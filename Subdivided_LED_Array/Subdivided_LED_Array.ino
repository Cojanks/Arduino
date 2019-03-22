#include "FastLED.h"
FASTLED_USING_NAMESPACE

#define DATA_PIN      17
#define NUM_LEDS      156
#define LED_TYPE      WS2812
#define COLOR_ORDER   GRB
CRGBArray<NUM_LEDS> leds;
uint8_t max_bright = 190;  
CRGBPalette16 currentPalette;

int brightnessVal = 250;

int numStripSections = 3;
int numLEDSInStrip = 52;
int activeStrip = 0;

void setup() {
//  Serial.begin(9600);
  delay(3000); // 3 second delay for recovery
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  currentPalette = PartyColors_p;
  FastLED.setBrightness(max_bright);
}

uint8_t gHue = 250;

void loop() {
  EVERY_N_MILLISECONDS(1000) {                           
      incrimentActiveStrip();
      stripSwitch(activeStrip);
  }

} 

void incrimentActiveStrip() {
  if (activeStrip >= numStripSections) {
      activeStrip = 1;                                       
    } else {
      activeStrip++;
    }
}

void stripSwitch(int StripToTurnOn) {
  FastLED.clear();
  leds((numLEDSInStrip*activeStrip) - numLEDSInStrip, (numLEDSInStrip*activeStrip)) = CRGB::DarkTurquoise;
  FastLED.show();
}

       



