//The best library for cross-chipset compatibility
#include "FastLED.h"
#include "Timer.h"

// How many leds in your strip?
#define NUM_LEDS 7

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN

//Data
#define DATA_PIN 2
//Clock
#define CLOCK_PIN 3

//Delay for each cycle of random colors.
int dly = 10; //Adjust to your liking, Default: 10
int tdly = 250;
int pdly = 100;
//Brightness
int brightness = 255;
//Seconds Count
int cycle = 0;
//Used in While loop
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;
//Create timer
Timer t;
//Random Number
int rnum = 0;
//pulse
int pled = 0;
int pled1 = 0;
int pled2 = 0;
int pled3 = 0;
int pled4 = 0;





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
        //Test Lights
        testRed();
        testGreen();
        testBlue();
        
        //Increment Seconds Count
        t.every(1000,incCycle);
        //Serial
        Serial.begin(9600);
        


}


void loop()
{

//Update seconds count	
  t.update();

 //Run Function 1: 15sec 
  if(cycle <= 15){
  randColor();
  }
 //Run Function 2: 15sec  
 if(cycle > 15 && cycle <= 30){
    randAllColor();
  }
 //Run Function 3: 15sec
 // if(cycle > 30 && cycle <= 45){
   // tjColors();
 // }
  //Reset cycle
  if(cycle > 30){
 
  cycle = 0;
    
  }
  
  
 
  
  }
  
  
void randColor(){
  //Randomly Flashes Color on Each LED
  //While Loop
  a = 0;
 while(a < NUM_LEDS){
 	leds[a] = CHSV( random(50,256), 255, brightness);
 	//Wait
 	delay(dly);
 	//Write to LED Strip
 	FastLED.show();
 	a++;
 }
 
}



void randAllColor(){
  //Randomly Flashes Color on Each LED
  //While Loop
  rnum = random(50,256);
  b = 0;
 while(b < NUM_LEDS){
 	leds[b] = CHSV(rnum,255,brightness);
 	//Wait
 	delay(dly);
 	//Write to LED Strip
 	FastLED.show();
 	b++;
 }
 pulseLeds();
}

/*
void tjColors(){
  f = 0;
  while(f < NUM_LEDS){
    leds[f] = CHSV(64,255,brightness);
    FastLED.show();
    f++;
    leds[f] = CHSV(32,255,brightness);
    FastLED.show();
    f++;
    leds[f] = CHSV(224,255,brightness);
    FastLED.show();
    f++;
    leds[f] = CHSV(192,255,brightness);
    FastLED.show();
    f++;
  }
}
*/

 void testRed(){
 c = 0;
 while(c < NUM_LEDS){
    leds[c].setRGB(255,0,0);
    //FastLED.show();
    c++;

 }
    FastLED.show();
   delay(tdly);
 }
 
 
 void testGreen(){
   d = 0;
 while( d < NUM_LEDS ){  
    leds[d].setRGB(0,255,0);
    d++;
    //FastLED.show();
  }
    FastLED.show();
   delay(tdly);
 }
 
 
 void testBlue(){
   e = 0;
 while( e < NUM_LEDS ){  
    leds[e].setRGB(0,0,255);
    e++;
    //FastLED.show();
  }
    FastLED.show();
   delay(tdly);
 }
 
 void pulseLeds(){
   pled = brightness;
   FastLED.setBrightness(pled);
   FastLED.show();
   delay(pdly);
   pled1 = pled-(pled/4);
   FastLED.setBrightness(pled1);
   FastLED.show();
   delay(pdly);
   pled2 = pled1-(pled1/4);
   FastLED.setBrightness(pled2);
   FastLED.show();
   delay(pdly);
   pled3 = pled2-(pled2/4);
   FastLED.setBrightness(pled3);
   FastLED.show();
   delay(pdly);
   pled4 = pled3-(pled3/4);
   FastLED.setBrightness(pled4);
   FastLED.show();
   delay(pdly);
   FastLED.setBrightness(pled3);
   FastLED.show();
   delay(pdly);
   FastLED.setBrightness(pled2);
   FastLED.show();
   delay(pdly);
   FastLED.setBrightness(pled1);
   FastLED.show();
   delay(pdly);
   FastLED.setBrightness(pled);
   FastLED.show();
   delay(pdly);
   
   
 }
   
   
 
 

  
  
//Seconds Incrementer  
void incCycle() 
{
  cycle++;
}

  
  
  
  

  
  


