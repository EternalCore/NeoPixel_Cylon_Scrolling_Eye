//NeoPixel LED Digital Strip Cylon Eye v1.03 Created by EternalCore
#include <Adafruit_NeoPixel.h>

//Settings:
#define PIN 6 //The Pin out your Neopixel DIN strip/stick is connected to (Default is 6)
#define TPIXEL 60 //The total amount of pixel's/led's in your connected strip/stick (Default is 60)
int wait_T=40; //This is the delay between moving back and forth and per pixel
int refresh=400;
int PixelCount=60; //Set this to the AMOUNT of Led's/Pixels you have or want to use on your strip And It can be used to tell where to Stop then return the eye at in the strip
int Pixel_Start_End=0; //Set this to where you want it to Start/End at
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)
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
  //CylonEyeDown(strip.Color(175,0,0), strip.Color(25,0,0), strip.Color(10,0,0), wait_T, PixelCount, Pixel_Start_End);
  //delay(wait_T);
  CylonEyeClear(wait_T,PixelCount, Pixel_Start_End);
  delay(refresh);
}
void CylonEyeClear(uint8_t Delay, int TotalPixels, int pStart) {
  for(int i=pStart; i<TotalPixels; i++) {
    strip.setPixelColor(i, strip.Color(0,0,0)); //Clears the dots
     strip.show();
    //Serial.println(i); //Used For pixel Count Debugging
    //delay(Delay);
  }
}
void CylonEyeUp(uint32_t Co, uint32_t Ct, uint32_t Ctt, uint8_t Delay, int TotalPixels, int pStart) {
  for(int i=pStart; i<TotalPixels; i++) {
   // strip.setPixelColor(i+2, Ctt);  //Third Dot Color
    strip.setPixelColor(i+1, Ct);   //Second Dot Color
    strip.setPixelColor(i, Co);     //Center Dot Color
    strip.setPixelColor(i-1, Ct);   //Second Dot Color
    //strip.setPixelColor(i-2, Ctt);  //Third Dot Color

    strip.setPixelColor(i-3, strip.Color(0,0,0)); //Clears the dots after the 3rd color
    strip.show();
    //Serial.println(i); //Used For pixel Count Debugging
    delay(Delay);

  }
}
void CylonEyeDown(uint32_t Co, uint32_t Ct, uint32_t Ctt, uint8_t Delay, int TotalPixels, int pEnd) {
  for(int i=TotalPixels-1; i>pEnd; i--) {
    strip.setPixelColor(i-2, Ctt);  //Third Dot Color
    strip.setPixelColor(i-1, Ct);   //Second Dot Color
    strip.setPixelColor(i, Co);    //Center Dot Color
    strip.setPixelColor(i+1, Ct);  //Second Dot Color
    strip.setPixelColor(i+2, Ctt); //Third Dot Color

    strip.setPixelColor(i+3, strip.Color(0,0,0)); //Clears the dots after the 3rd color
    strip.show();
    //Serial.println(i); //Used For pixel Count Debugging
    delay(Delay);
  }
}


