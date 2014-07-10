#include <Wire.h>

#define RESETpin  5

int LEDvalues[6][16] = {
      {20,  20,  20, 20, 20, 20, 20, 20, 20, 20,  20,  20, 20, 20, 20, 20},
      {40,  40,  40, 40, 40, 40, 40, 40, 40, 40,  40,  40, 40, 40, 40, 40},
      {60,  60,  60, 60, 60, 60, 60, 60, 60, 60,  60,  60, 60, 60, 60, 60},
      {80,  80,  80, 80, 80, 80, 80, 80, 80, 80,  80,  80, 80, 80, 80, 80},
      {100,  100,  100, 100, 100, 100, 100, 100, 100, 100,  100,  100, 100, 100, 100, 100},
      {120,  120,  120, 120, 120, 120, 120, 120, 120, 120,  120,  120, 120, 120, 120, 120},
     };

void setup()
{
  pinMode(RESETpin,   OUTPUT);
  digitalWrite(RESETpin, HIGH);
  
  Wire.begin();
  int LEDbank = 0;
    for (int LEDbankAddress=0x61; LEDbankAddress<0x67; LEDbankAddress++)
   {
      Wire.beginTransmission(LEDbankAddress);
      Wire.write(byte(0b10000000));
      Wire.write(byte(0));
      Wire.write(byte(0));
      for (int i=0; i< 16; i++)
        Wire.write(byte(LEDvalues[LEDbank][i]));
      Wire.write(byte(0xFF));
      Wire.write(byte(0));
      for (int i=0; i< 4; i++)
        Wire.write(byte(0xFF));
      Wire.endTransmission();
      LEDbank++;
   }
}


void loop()
{
  delay(1000);
}
