#include <Wire.h>
#include "rgb_lcd.h"
#include "grove_two_rgb_led_matrix.h"

rgb_lcd lcd;

const int TouchPin=2;


#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
#define SERIAL SerialUSB
#else
#define SERIAL Serial
#endif


#define DISPLAY_COLOR    0X11


GroveTwoRGBLedMatrixClass matrix;

void setup() {
    lcd.begin(16, 2);
    pinMode(TouchPin, INPUT);
    Wire.begin();
    
}

uint64_t pic[1] = {0x2345654354345676};

uint8_t pic8[] = {0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
                0xaa,0xaa,0xaa,0x55,0x55,0xaa,0xaa,0xaa,
                0xaa,0xaa,0x55,0xaa,0xaa,0x55,0xaa,0xaa,
                0x55,0xaa,0x55,0xaa,0xaa,0x55,0xaa,0x55,
                0x55,0xaa,0x55,0xaa,0xaa,0x55,0xaa,0x55,
                0x55,0xaa,0x55,0xaa,0xaa,0x55,0xaa,0x55,
                0xaa,0x55,0xaa,0x55,0x55,0xaa,0x55,0xaa,
                0xaa,0xaa,0x55,0x55,0x55,0x55,0xaa,0xaa,};

void loop() {
    int sensorValue = digitalRead(TouchPin);
    if(sensorValue==1)
    {
      matrix.displayEmoji(0 ,2000,true);
      lcd.setRGB(255, 255, 0006);
      lcd.print("Have a good time");
      lcd.setCursor(0,1);
      lcd.print("tonight!");
      delay(4000);
      lcd.clear();
      lcd.print("Happy New Year!!");
      delay(4000);
      lcd.clear();
      
    }
    else
    {
      lcd.setRGB(000, 000, 255);
      matrix.displayFrames(pic8,2000,true,1);
      delay(500);
      
//      matrix.clear();
    }
    
} 
