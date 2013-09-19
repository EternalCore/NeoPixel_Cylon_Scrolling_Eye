//NeoPixel LED Digital Strip Cylon Eye v1.10 Created by EternalCore
#include <Adafruit_NeoPixel.h>

//Settings:
#define PIN 6 //The Pin out your Neopixel DIN strip/stick is connected to (Default is 6)
#define TPIXEL 60 //The total amount of pixel's/led's in your connected strip/stick (Default is 60)
int wait_T=40; //This is the delay between moving back and forth and per pixel
int PixelCount=60; //Set this to the AMOUNT of Led's/Pixels you have or want to use on your strip And It can be used to tell where to Stop then return the eye at in the strip
int Pixel_Start_End=0; //Set this to where you want it to Start/End at
boolean UsingBar = false; //Set this to true If you are using the 8x1 Neopixel Bar Or you want to only use 3 leds for the scanner. 

Adafruit_NeoPixel strip = Adafruit_NeoPixel(TPIXEL, PIN, NEO_GRB + NEO_KHZ800); //Standered Strip function

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  //Serial.begin(9600); //Used For pixel Count Debugging
}
void loop() {
  //Example: CylonEyeUp(Center_Dot_Color, Second_Dot_color, Third_Dot_color, wait_T, PixelCount, Pixel_Start_End);
  CylonEyeUp(strip.Color(175,0,0), strip.Color(25,0,0), strip.Color(10,0,0), wait_T, PixelCount, Pixel_Start_End);
  delay(wait_T);
  //Example: CylonEyeDown(Center_Dot_Color, Second_Dot_color, Third_Dot_color, wait_T, PixelCount, Pixel_Start_End);
  CylonEyeDown(strip.Color(175,0,0), strip.Color(25,0,0), strip.Color(10,0,0), wait_T, PixelCount, Pixel_Start_End);
  delay(wait_T);
}

void CylonEyeUp(uint32_t Co, uint32_t Ct, uint32_t Ctt, uint8_t Delay, int TotalPixels, int pStart) {
  for(int i=pStart; i<TotalPixels; i++) {
    if(!UsingBar) { strip.setPixelColor(i+2, Ctt); } //Third Dot Color
    strip.setPixelColor(i+1, Ct);   //Second Dot Color
    strip.setPixelColor(i, Co);     //Center Dot Color
    strip.setPixelColor(i-1, Ct);   //Second Dot Color
    if(!UsingBar) { strip.setPixelColor(i-2, Ctt); } //Third Dot Color

    if(!UsingBar) {
      strip.setPixelColor(i-3, strip.Color(0,0,0)); //Clears the dots after the 3rd color
    } else {
      strip.setPixelColor(i-2, strip.Color(0,0,0)); //Clears the dots after the 2rd color
    }
    strip.show();
    //Serial.println(i); //Used For pixel Count Debugging
    delay(Delay);
  }
}
void CylonEyeDown(uint32_t Co, uint32_t Ct, uint32_t Ctt, uint8_t Delay, int TotalPixels, int pEnd) {
  for(int i=TotalPixels-1; i>pEnd; i--) {
    if(!UsingBar) { strip.setPixelColor(i-2, Ctt); } //Third Dot Color
    strip.setPixelColor(i-1, Ct);   //Second Dot Color
    strip.setPixelColor(i, Co);    //Center Dot Color
    strip.setPixelColor(i+1, Ct);  //Second Dot Color
    if(!UsingBar) { strip.setPixelColor(i+2, Ctt); } //Third Dot Color

    if(!UsingBar) { 
      strip.setPixelColor(i+3, strip.Color(0,0,0)); //Clears the dots after the 3rd color
    } else {
      strip.setPixelColor(i+2, strip.Color(0,0,0)); //Clears the dots after the 2rd color
    }
    strip.show();
    //Serial.println(i); //Used For pixel Count Debugging
    delay(Delay);
  }
}


