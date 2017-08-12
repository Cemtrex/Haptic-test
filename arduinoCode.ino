#include <Wire.h>
#include "Adafruit_DRV2605.h"
#define BAUD 9600

Adafruit_DRV2605 drv;

void setup() {
  Serial.begin(BAUD);
  Serial.println("DRV test");
  drv.begin();
    
  // I2C trigger by sending 'go' command 
  drv.setMode(DRV2605_MODE_INTTRIG); // default, internal trigger when sending GO command

  drv.selectLibrary(1);
  //drv.setWaveform(0, 84);  // ramp up medium 1, see datasheet part 11.2
  drv.setWaveform(1, 1);  // strong click 100%, see datasheet part 11.2
  //drv.setWaveform(2, 0);  // end of waveforms
}

void loop(){
  String input;
  //If any input is detected in arduino
  if(Serial.available() > 0){
    //read the whole string until '\n' delimiter is read
    input = Serial.readStringUntil('\n');
    if (input.equals("Start")){
      drv.go();
      Serial.println("Vibrate");
    } 
  }
}

