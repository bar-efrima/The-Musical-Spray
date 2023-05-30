#include <Adafruit_CircuitPlayground.h>
#include "pitches.h" //musical notes libary

int value;
int modeP =0;
int melody[] = { 
NOTE_B3, NOTE_G3, NOTE_A3, NOTE_D4, NOTE_G2, NOTE_B2, NOTE_A2, NOTE_C2,NOTE_DS4, NOTE_FS4 , NOTE_GS4, NOTE_AS4, NOTE_G5, NOTE_B5, NOTE_A5, NOTE_C5 };
int sensorA1;
int sensorA2;
int sensorA3;
int sensorA4;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  pinMode(A5, INPUT); //for button state
}

void loop() { 
  //Turning the 3 neo-pixels ON when the area is dark
  value = CircuitPlayground.lightSensor(); 
  if(value <10){
     CircuitPlayground.setPixelColor(1 , 255 , 0 , 0);
     CircuitPlayground.setPixelColor(5 , 255 , 0 , 0);
     CircuitPlayground.setPixelColor(8 , 255 , 0 , 0);
  }else{
    CircuitPlayground.setPixelColor(1 , 0 , 0 , 0);
    CircuitPlayground.setPixelColor(5 , 0 , 0 , 0);
    CircuitPlayground.setPixelColor(8 , 0 , 0 , 0);
  }
   delay(100);
  int buttonState = CircuitPlayground.readCap(A5);
  digitalWrite(A0,HIGH);
  sensorA1 = CircuitPlayground.readCap(A1);
  sensorA2 = CircuitPlayground.readCap(A2);
  sensorA3 = CircuitPlayground.readCap(A3);
  sensorA4 = CircuitPlayground.readCap(A4);
  
  //Pressing the button- Switching between 5 modes of different music notes(mode 1 = turn off)
  if(buttonState>1000){
    modeP = modeP +1;      
  }
  if(modeP==0){
    CircuitPlayground.setPixelColor (0 , 0 , 0 , 0);
  }
  if(modeP==1){
   play(modeP,melody);
   CircuitPlayground.setPixelColor (0 , 0 , 0 , 255);
  }
  if(modeP==2){
    CircuitPlayground.setPixelColor (0 , 0 , 255 , 0);
    play(modeP,melody);
  }
  if(modeP==3){
    CircuitPlayground.setPixelColor (0 , 255 , 0 , 0);
    play(modeP,melody);
  }
  if(modeP==4){
    CircuitPlayground.setPixelColor (0 , 255 , 255 , 255);
    play(modeP,melody);
  }
  if(modeP==5){
    modeP = 0;
  } 
} 
//Giving each electric port a musical note when being touched 
void play(int modeP, int melody[] ){ 
      if(sensorA1 > 900){
         CircuitPlayground.playTone(melody[(modeP*4)-4], 350);      
      }if(sensorA2 > 900){
          CircuitPlayground.playTone(melody[(modeP*4)-3], 225);
      }if(sensorA3 > 900){
          CircuitPlayground.playTone(melody[(modeP*4)-2], 350);     
      }if(sensorA4 > 900){
        CircuitPlayground.playTone(melody[(modeP*4)-1], 350);  
      }
}
