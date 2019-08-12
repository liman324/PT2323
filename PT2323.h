//  PT2323
#ifndef  PT2323_H
#define  PT2323_H

#define  PT2323_address 0b1001010 // адрес

#include <Arduino.h>
class  PT2323
{
  public:
     PT2323();
        void setInput(int in); // входы 1...4 (in = 0...3), 6 моно входов (in = 4)
        void setMute(int fl, int fr, int ct, int sub, int sl, int sr, int mute); 
        // MUTE OFF для выходов (0,0,0,0,0,0,0); 
        // MUTE ON  для выходов (1,1,1,1,1,1,1); 
        // fl,  fr,  ct,  sub,  sl,  sr, все  выходы mute
        void setFeature(int surr, int mix); // дополнительные функции 0...1, 0...1
               // 0 - Enhanced Surround Function Active
               // 1 - Enhanced Surround Function Disabled
               // 0 - Mixed Channel (0dB) Setup
               // 1 - Mixed Channel (+6dB) Setup 
  private:
	void writeWire(char a);
};
	
#endif // PT2323_H
