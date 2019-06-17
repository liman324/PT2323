#include <Arduino.h>
#include <Wire.h>
#include "PT2323.h"

PT2323::PT2323(){
	Wire.begin();
}

void PT2323::setInput(int in){
     switch(in){
        case 0: in = 0b11001011;break;
	case 1: in = 0b11001010;break;
	case 2: in = 0b11001001;break;
	case 3: in = 0b11001000;break;
        case 4: in = 0b11000111;break;
        } 
        writeWire(in);}

void PT2323::setMute(int fl, int fr, int ct, int sub, int sl, int sr, int mute){
      if(fl==1){fl = 0b11110001;}else{fl = 0b11110000;}
      if(fr==1){fr = 0b11110011;}else{fr = 0b11110010;}
      if(ct==1){ct = 0b11110101;}else{ct = 0b11110100;}
    if(sub==1){sub = 0b11110111;}else{sub= 0b11110110;}
      if(sl==1){sl = 0b11111001;}else{sl = 0b11111000;}
      if(sr==1){sr = 0b11111011;}else{sr = 0b11111010;} ///
  if(mute==1){mute = 0b11111111;}else{mute=0b11111110;}
      
  writeWire(fl);
  writeWire(fr);
  writeWire(ct);
  writeWire(sub);
  writeWire(sl);
  writeWire(sr);
  writeWire(mute);
}

void PT2323::setFeature(int surr, int mix){
     switch(surr){
        case 0: surr = 0b11010000;break;
	case 1: surr = 0b11010001;break;
        }
     switch(mix){
        case 0: mix = 0b10010000;break;
	case 1: mix = 0b10010001;break;
        } 
        writeWire(surr);
        writeWire(mix);
}

void PT2323::writeWire(char a){
  Wire.beginTransmission(PT2323_address);
  Wire.write (a);
  Wire.endTransmission();
}
