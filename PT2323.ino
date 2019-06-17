// rcl-radio.ru / liman324@yandex.ru
#include <Wire.h>
#include <PT2323.h>
PT2323 rt0;
 
void setup() {
  Wire.begin();
}
 
void loop() {
  rt0.setInput(0); // входы 1...4 (0...3) или 6 моно (4)
  rt0.setMute(0,0,0,0,0,0,0); // MUTE OFF для выходов (0,0,0,0,0,0,0); 
                              // MUTE ON  для выходов (1,1,1,1,1,1,1); 
                              // fl,  fr,  ct,  sub,  sl,  sr, все  выходы mute
  rt0.setFeature(0,0); // дополнительные функции 0...3
                     // 0 - Enhanced Surround Function Active
                     // 1 - Enhanced Surround Function Disabled
                     // 0 - Mixed Channel (0dB) Setup
                     // 1 - Mixed Channel (+6dB) Setup 
  delay(1000);
}
