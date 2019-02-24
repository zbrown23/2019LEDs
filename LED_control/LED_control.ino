/*
 * LED Animations
 * 1. DARC SIDE Colors
 * 2. Chase up Elevator
 * 3. Pulsing Red
 * 4. Pulsing Blue
 * 5. Solid Red
 * 6. Solid Blue
 */

//includes
#include <Wire.h>
#include <FastLED.h>

//Changeable variables
#define DATA_PIN 3
#define BRIGHTNESS 100
#define FRAMES_PER_SECOND  30
int fadeAmount = 5;
int wait = 50;
const int leftBottom = 37;
const int rightBottom = 37;
const int frontBottom = 0;
const int leftElevator = 0;
const int rightElevator = 0;

//definitions so the code knows what it's doing
//#define STRAND_LENGTH leftBottom+rightBottom+frontBottom+leftElevator+rightElevator
#define STRAND_LENGTH 37
int brightness = BRIGHTNESS;
CRGB leds[STRAND_LENGTH];

void setup() {
  //setup code
  Wire.begin(8);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, STRAND_LENGTH).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
}

void loop() {
     
     coralRain(0,30,true,4);
     //FastLED.delay(1000/FRAMES_PER_SECOND);
}

void coralRain(int startIndex, int endIndex, bool reverse, int rainFrequency) {
  if(reverse) {
    for(int i = floor((endIndex - 1)/rainFrequency); i >=startIndex; i--) {
      for(int b = 0; b < rainFrequency; b++) {
        leds[i + ((endIndex-startIndex)/rainFrequency)*b].setRGB( 250, 75, 90);
          fadeToBlackBy(leds, endIndex - startIndex, 300);
      }
      FastLED.show();
      FastLED.delay(wait);
    }
  }
  else {
  }
}

void CoralChaseBackForth() {
        for(int dot = 0; dot < STRAND_LENGTH; dot++) { 
            leds[dot].setRGB( 250, 75, 90);
            fadeToBlackBy(leds, STRAND_LENGTH, 300);
            FastLED.show();
            FastLED.delay(wait);
  }
        for(int dot = STRAND_LENGTH - 1; dot >= 0; dot--) {
            leds[dot+0].setRGB( 250, 75, 90);
            fadeToBlackBy(leds, STRAND_LENGTH, 300);
            FastLED.show();
            FastLED.delay(wait);
        }
}

void colorWipeRed() {
  for(int i=0; i<STRAND_LENGTH; i++) {
    leds[i].setRGB(128, 0, 0);
    FastLED.show();
    FastLED.delay(wait);
  }
}

void colorWipeBlue() {
  for(int i=0, j=0; i<STRAND_LENGTH; i++) {
    leds[i].setRGB(0, 0, 128);
    FastLED.show();
    FastLED.delay(wait);
  }
}

void colorWipeCoral() {
  for(int i=0; i<STRAND_LENGTH; i++) {
    leds[i].setRGB(200, 75, 90);
    FastLED.show();
    FastLED.delay(wait);
  }
}

void colorWipeBlack() {
  for(int i=0; i<STRAND_LENGTH; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
    FastLED.delay(wait);
  }
}

void elevatorChaseRed() {
  for(int dot = 0; dot < STRAND_LENGTH; dot+2) { 
            leds[dot].setRGB(128, 0, 0);
            FastLED.show();
        leds[dot] = CRGB::Black;
            FastLED.delay(wait);
  }
}

void pulseRed() {

 }
