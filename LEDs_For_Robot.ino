//The best library for cross-chipset compatibility
#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 7

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN

//Data
#define DATA_PIN 2
//Clock
#define CLOCK_PIN 3

//Brightness
int brightness = 100;




// Define the array of leds
CRGB leds[NUM_LEDS];

//Check Examples/FastLED/Multiple/ArrayOfLedArrays for multiple Arrays.

void setup()
{
	// Uncomment/edit one of the following lines for your leds arrangement or chipset.
	// FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
	// FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);

	// FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<P9813, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<APA102, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<DOTSTAR, RGB>(leds, NUM_LEDS);

	FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
	// FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      
        //Is The Brightness Too High: If so, FIX
        if(brightness > 255){
          brightness = 255;
        }
        //Set Brightness
        FastLED.setBrightness(brightness);
        //Serial.begin(9600);
        


}


void loop()
{
  
  delay(1);
 //Increase Cycle Counter 
  cycle = cycle++;
 //Run Function 1: 15sec 
  if(cycle <= 15000){
  randColor();
  }
 //Run Function 2: 15sec  
  if(cycle > 15000 && cycle <= 30000){
  }
 //Reset Cycle Count at End of Functions: After 30sec
  if(cycle > 30000){
    cycle = 0;
  }
  
  }
  
  
void randColor(){
  //Randomly Flashes Color on Each LED
  //For Loop :) , ... I finnaly understand them.
    for(int i = 0; i < NUM_LEDS; i++){
     //Write random R,G,B Values between 50 and 255
    leds[i] = CHSV( random(50,256), random(50,256), random(50,256));
    //Wait
    delay(10);
    //Write to LED Strip
    FastLED.show();
  }
  
}
  
  
  
  

  
  


