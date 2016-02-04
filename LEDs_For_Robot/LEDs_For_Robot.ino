//The best library for cross-chipset compatibility
#include "FastLED.h"
//Timer Library
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



#define FORWARD 0
#define BACKWARD 1
#define SLOW 250
#define MEDIUM 50
#define FAST 5

boolean direction = FORWARD;

//Delay for each cycle of random colors.
int dly = 10; //Adjust to your liking, Default: 10
int tdly = 250;
int pdly = 100;
int greenDLY = 50;

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
  //scamTheGreen();
  }
 //Run Function 2: 15sec  
 if(cycle > 15 && cycle <= 30){
    randAllColor();
    pulseLeds();
    scamTheGreen();
  }
   if(cycle > 30 && cycle <= 45){
    randColor();
    pulseLeds();
    scamTheGreen();
  }
  if(cycle > 45 && cycle <= 60){
    randAllColor();
    //scamTheGreen();
  }
 //Run Function 3: 15sec
 // if(cycle > 30 && cycle <= 45){
   // tjColors();
 // }
  //Reset cycle
  if(cycle > 60){
 
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
 
 
  void scamTheGreen(){
   d = 0;
 while( d < NUM_LEDS ){  
    leds[d].setRGB(0,255,0);
    d++;
    //FastLED.show();
  }
    FastLED.show();
   delay(greenDLY);
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
   
 // Changes all LEDS to given color
void allColor(CRGB c){
  for(int i=0; i<NUM_LEDS; i++){
    leds[i] = c;
  }
  FastLED.show();
}

void allRandom(){
  for(int i=0; i<NUM_LEDS; i++){
    leds[i] = randomColor();
  }
  FastLED.show(); 
}

// Random disolve colors
void disolve(int simultaneous, int cycles, int speed){
  for(int i=0; i<cycles; i++){
    for(int j=0; j<simultaneous; j++){
      int idx = random(NUM_LEDS);
      leds[idx] = CRGB::Black;
    }
    FastLED.show();
    delay(speed);
  }

  allColor(CRGB::Black);
}

// Flashes given color
// If c==NULL, random color flash
void flash(CRGB c, int count, int speed){
  for(int i=0; i<count; i++){
    if(c){
      allColor(c);
    }
    else{
      allColor(randomColor());
    }
    delay(speed);
    allColor(CRGB::Black);
    delay(speed);
  }
}

// Wipes color from end to end
void colorWipe(CRGB c, int speed, int direction){
  for(int i=0; i<NUM_LEDS; i++){
    if(direction == FORWARD){
      leds[i] = c;
    }
    else{
      leds[NUM_LEDS-1-i] = c;
    }
    FastLED.show();
    delay(speed);
  }
}

// Rainbow colors that slowly cycle across LEDs
void rainbow(int cycles, int speed){ // TODO direction
  if(cycles == 0){
    for(int i=0; i< NUM_LEDS; i++) {
      leds[i] = Wheel(((i * 256 / NUM_LEDS)) & 255);
    }
    FastLED.show();
  }
  else{
    for(int j=0; j<256*cycles; j++) {
      for(int i=0; i< NUM_LEDS; i++) {
        leds[i] = Wheel(((i * 256 / NUM_LEDS) + j) & 255);
      }
      FastLED.show();
      delay(speed);
    }
  }
}

// Theater-style crawling lights
void theaterChase(CRGB c, int cycles, int speed){ // TODO direction

  for (int j=0; j<cycles; j++) {  
    for (int q=0; q < 3; q++) {
      for (int i=0; i < NUM_LEDS; i=i+3) {
        int pos = i+q;
        leds[pos] = c;    //turn every third pixel on
      }
      FastLED.show();

      delay(speed);

      for (int i=0; i < NUM_LEDS; i=i+3) {
        leds[i+q] = CRGB::Black;        //turn every third pixel off
      }
    }
  }
}

// Theater-style crawling lights with rainbow effect
void theaterChaseRainbow(int cycles, int speed){ // TODO direction, duration
  for (int j=0; j < 256 * cycles; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < NUM_LEDS; i=i+3) {
        int pos = i+q;
        leds[pos] = Wheel( (i+j) % 255);    //turn every third pixel on
      }
      FastLED.show();

      delay(speed);

      for (int i=0; i < NUM_LEDS; i=i+3) {
        leds[i+q] = CRGB::Black;  //turn every third pixel off
      }
    }
  }
}

// Random flashes of lightning
void lightning(CRGB c, int simultaneous, int cycles, int speed){
  int flashes[simultaneous];

  for(int i=0; i<cycles; i++){
    for(int j=0; j<simultaneous; j++){
      int idx = random(NUM_LEDS);
      flashes[j] = idx;
      leds[idx] = c ? c : randomColor();
    }
    FastLED.show();
    delay(speed);
    for(int s=0; s<simultaneous; s++){
      leds[flashes[s]] = CRGB::Black;
    }
    delay(speed);
  }
}

// Sliding bar across LEDs
void cylon(CRGB c, int width, int speed){
  // First slide the leds in one direction
  for(int i = 0; i <= NUM_LEDS-width; i++) {
    for(int j=0; j<width; j++){
      leds[i+j] = c;
    }

    FastLED.show();

    // now that we've shown the leds, reset to black for next loop
    for(int j=0; j<5; j++){
      leds[i+j] = CRGB::Black;
    }
    delay(speed);
  }

  // Now go in the other direction.  
  for(int i = NUM_LEDS-width; i >= 0; i--) {
    for(int j=0; j<width; j++){
      leds[i+j] = c;
    }
    FastLED.show();
    for(int j=0; j<width; j++){
      leds[i+j] = CRGB::Black;
    }

    delay(speed);
  }
}

// Display alternating stripes
void stripes(CRGB c1, CRGB c2, int width){
  for(int i=0; i<NUM_LEDS; i++){
    if(i % (width * 2) < width){
      leds[i] = c1;
    }
    else{
      leds[i] = c2;
    } 
  }
  FastLED.show();
}

// Theater-style crawling of stripes
void stripesChase(CRGB c1, CRGB c2, int width, int cycles, int speed){ // TODO direction

}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
CRGB Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return CRGB(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return CRGB(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return CRGB(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

CRGB randomColor(){
  return Wheel(random(256)); 
}




//Seconds Incrementer  
void incCycle() 
{
  cycle++;
}

  
  
  
  

  
  


