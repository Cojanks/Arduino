#include "LedControl.h"

/*
 LED MATRIX
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 Using MAX72XX LED MAtrix.
 */
LedControl lc=LedControl(12,10,11,1);

unsigned long delaytime=100;

int buttonNormalpin = 9;
int buttonLaughingpin = 8;
int buttonAngrypin = 7;
int buttonNeutralpin = 6;

int currentFace = 10;

int i_normal = 0;
int i_laugh = 0;
int i_angry = 0;

void setup() 
{  
  // Setup Pins
  pinMode(buttonNormalpin, INPUT_PULLUP);  
  pinMode(buttonLaughingpin, INPUT_PULLUP);  
  pinMode(buttonAngrypin, INPUT_PULLUP);  
  pinMode(buttonNeutralpin, INPUT_PULLUP);

  // Setup LEDS 
  lc.shutdown(0,false);
  lc.setIntensity(0,7);
  lc.clearDisplay(0);
}

void loop() 
{
  if (digitalRead(buttonNormalpin) == LOW)
  {
    currentFace = 10;
    i_normal = 0;
  }
  if (digitalRead(buttonLaughingpin) == LOW)
  {
    currentFace = 11;
    i_laugh = 0;
  }
  if (digitalRead(buttonAngrypin) == LOW)
  {
    currentFace = 12;
    i_angry = 0;
  }
  //  TODO:
//  if (digitalRead(buttonNeutralpin) == LOW)
//  {
//    currentFace = 13;
//  }
  
  displayFace(currentFace);
  delay(delaytime);

} // End loop()

//Laughing Face Animation
const uint64_t LAUGHIMAGES[] = {
  0x003c424200666600,
  0x003c7e4200426600,
  0x003c7e4200816600,
  0x003c7e4200008166,
  0x003c427e00008166,
  0x003c42427e008166,
  0x00003c427e008166,
  0x003c42427e008166,
  0x00003c427e008166,
  0x003c42427e008166,
  0x003c427e00008166,
  0x003c7e4200008166,
  0x003c7e4200816600,
  0x003c7e4200426600,
  0x003c7e4200666600,
  0x003c7e4200666600,
  0x003c7e4200666600
};
const int IMAGES_LEN_LAUGH = sizeof(LAUGHIMAGES)/8;
void laughFace(uint64_t image) {
  for(int i = 0; i < 8; i++){
    byte row = (image >> i * 8) & 0xFF;
    for(int p = 0; p < 8; p++){
      lc.setLed(0,i,p, bitRead(row, p));
    }
  }
}

//Laughing Normal/Default Animation
const uint64_t NORMALIMAGES[] = {
  0x003c424200666600,
  0x003c424200666600,
  0x003c424200666600,
  0x003c424200660000,
  0x003c424200660000,
  0x003c424200666600,
  0x003c424200666600,
  0x003c424200664400,
  0x003c424200664400,
  0x0078848400cc8800,
  0x0078848400cc8800,
  0x0078848400cccc00,
  0x0078848400cc4400,
  0x003c424200662200,
  0x001e212100331100,
  0x001e212100331100,
  0x001e212100333300,
  0x001e212100332200,
  0x003c424200664400,
  0x003c424200666600,
  0x003c424200666600,
  0x003c424200666600,
  0x003c424200666600,
  0x003c424200666600,
  0x003c424200666600,
  0x003c424200660600,
  0x003c424200660600,
  0x003c424200660600,
  0x003c424200666600,
  0x003c424200666600,
  0x003c420200664400,
  0x003c020200664400,
  0x003c020200664400,
  0x003c020200664400,
  0x0078040400cc8800,
  0x00f0080800981000,
  0x00e0101000302000,
  0x00c0202000604000,
  0x0080404000c08000,
  0x0000808000800000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000000000,
  0x0000000000808000,
  0x0080000000c04000,
  0x00c0000000602000,
  0x00e0000000301000,
  0x00f0000000988800,
  0x0078808000cc4400,
  0x003c404000662200,
  0x003c424000666600,
  0x003c424200666600,
  0x003c424200666600,
  0x003c424200666600,
  0x003c424200660000,
  0x003c424200660000,
  0x003c424200666600
};
const int IMAGES_LEN_NORMAL = sizeof(NORMALIMAGES)/8;
void normalFace(uint64_t image) {
  for(int i = 0; i < 8; i++){
    byte row = (image >> i * 8) & 0xFF;
    for(int p = 0; p < 8; p++){
      lc.setLed(0,i,p, bitRead(row, p));
    }
  }
}

//Angry Face Animation
const uint64_t ANGRYIMAGES[] = {
  0x00007e0000666600,
  0x00007e0000664200,
  0x0000423c00664200,
  0x0042423c00664200,
  0x0042423c00664200,
  0x00427e3c00664200,
  0x007e423c00664200,
  0x007e423c00664200,
  0x007e423c00664200,
  0x3c42423c00664200,
  0x1e21211e00332100,
  0x1e21211e00332100,
  0x3c42423c00664200,
  0x7884847800cc8400,
  0x7884847800cc8400,
  0x3c42423c00664200,
  0x3c42423c00664200,
  0x3c42423c00006642,
  0x3c4242423c006642,
  0x788484847800cc84,
  0x3c4242423c006642,
  0x1e2121211e003321,
  0x3c4242423c006642,
  0x788484847800cc84,
  0x3c4242423c006642,
  0x1e2121211e003321,
  0x3c4242423c006642,
  0x3c42423c00006642,
  0x3c42423c00664200,
  0x007e423c00664200,
  0x007e423c00664200,
  0x00427e3c00664200,
  0x0042423c00664200,
  0x00007e0000664200,
  0x00007e0000666600,
  0x00007e0000666600,
  0x00007e0000666600,
  0x00007e0000666600
};
const int IMAGES_LEN_ANGRY = sizeof(ANGRYIMAGES)/8;
void angryFace(uint64_t image) {
  for(int i = 0; i < 8; i++){
    byte row = (image >> i * 8) & 0xFF;
    for(int p = 0; p < 8; p++){
      lc.setLed(0,i,p, bitRead(row, p));
    }
  }
}



void displayFace(int faceInt) {
  switch (faceInt) {
  case 10:
    normalFace(NORMALIMAGES[i_normal]);
    if(++i_normal >= IMAGES_LEN_NORMAL ) {
      i_normal = 0;
    }
    break;
  case 11:
    laughFace(LAUGHIMAGES[i_laugh]);
    if(++i_laugh >= IMAGES_LEN_LAUGH ) {
      i_laugh = 0;
    }
    break;
    //  TODO:
    case 12:
    angryFace(ANGRYIMAGES[i_angry]);
    if(++i_angry >= IMAGES_LEN_ANGRY ) {
      i_angry = 0;
    }      
    break;
//    case 13:
//          Bored/Neutral face?
//    break;
  default:
    Serial.println("Default");
    break;
  }
}
