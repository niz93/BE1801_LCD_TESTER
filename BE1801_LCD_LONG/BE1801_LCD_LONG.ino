// Becker Bavaria Proffesional C BE1801 LCD tester
// Pinout panel:
//          + SAFE LED . . NC
//        GND SAFE LED . . +12V backlight LED
//                 SDA . . -3.5V LCD negative power supply
//                 SCL . . GND LCD backlight LED
//   INT from Keyboard . . IR or Photodiode
//                 GND . . NC
//   Vref for Keyboard . . NC
//           +5V power . . +12V keyboard backlight LED

#include <Wire.h>

byte SmallLCD = 0x3D;
byte LongLCD = 0x3C;

byte x = 0;
byte y = 0;
byte z = 0;
short time = 400;


void setup() {
  Wire.begin();

  //////////////////////////////////////////////////////////////////////// initialization LCD
  Wire.beginTransmission(LongLCD);
  Wire.write(0xD5);
  Wire.write(0xFC);
  Wire.write(0xF0);
  Wire.write(0x60);
  Wire.endTransmission();

  Wire.beginTransmission(SmallLCD);
  Wire.write(0xD5);
  Wire.write(0xFC);
  Wire.write(0xF0);
  Wire.write(0x60);
  Wire.endTransmission();
  ////////////////////////////////////////////////////////////////////////
  analogWrite(11, 127);  //negative power supply for LCD see scheme
  ////////////////////////////////////////////////////////////////////////
}




void loop() {



  z++;
  if (z > 7) { z = 0; }

  if (z == 0) {
    x = 0b00000000;
    y = 0b00000000;
  }

  if (z == 1) {
    x = 0b01111111;
    y = 0b01111111;
  }

  if (z == 2) {
    x = 0b01010101;
    y = 0b00101010;
  }

  if (z == 3) {
    x = 0b00101010;
    y = 0b01010101;
  }

  if (z == 4) {
    x = 0b01111111;
    y = 0b00000000;
  }

  if (z == 5) {
    x = 0b00000000;
    y = 0b01111111;
  }

  if (z == 6) {
    x = 0b01010101;
    y = 0b01010101;
  }

  if (z == 7) {
    x = 0b00101010;
    y = 0b00101010;
  }


  //////////////////////////////////////////////////////////////////////// Long LCD wave

  Wire.beginTransmission(LongLCD);  //1
  Wire.write(0xE3);
  Wire.write(0x21);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //2
  Wire.write(0xE3);
  Wire.write(0x1C);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();


  Wire.beginTransmission(LongLCD);  //3
  Wire.write(0xE3);
  Wire.write(0x17);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //4
  Wire.write(0xE3);
  Wire.write(0x12);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //5
  Wire.write(0xE3);
  Wire.write(0x0D);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //6
  Wire.write(0xE3);
  Wire.write(0x08);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //7
  Wire.write(0xE3);
  Wire.write(0x03);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //8
  Wire.write(0xE2);
  Wire.write(0x26);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //9
  Wire.write(0xE2);
  Wire.write(0x21);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //10
  Wire.write(0xE2);
  Wire.write(0x1C);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //11
  Wire.write(0xE2);
  Wire.write(0x17);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //12
  Wire.write(0xE2);
  Wire.write(0x12);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //13
  Wire.write(0xE2);
  Wire.write(0x0D);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //14
  Wire.write(0xE2);
  Wire.write(0x08);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //15
  Wire.write(0xE2);
  Wire.write(0x03);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //16
  Wire.write(0xE1);
  Wire.write(0x26);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //17
  Wire.write(0xE1);
  Wire.write(0x21);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //18
  Wire.write(0xE1);
  Wire.write(0x1C);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //19
  Wire.write(0xE1);
  Wire.write(0x17);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //20
  Wire.write(0xE1);
  Wire.write(0x12);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //21
  Wire.write(0xE1);
  Wire.write(0x0D);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //22
  Wire.write(0xE1);
  Wire.write(0x08);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //23
  Wire.write(0xE1);
  Wire.write(0x03);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //24
  Wire.write(0xE0);
  Wire.write(0x26);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //25
  Wire.write(0xE0);
  Wire.write(0x21);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //26
  Wire.write(0xE0);
  Wire.write(0x1C);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //27
  Wire.write(0xE0);
  Wire.write(0x17);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //28
  Wire.write(0xE0);
  Wire.write(0x12);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //29
  Wire.write(0xE0);
  Wire.write(0x0D);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(LongLCD);  //30
  Wire.write(0xE0);
  Wire.write(0x08);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  //////////////////////////////////////////////////////////////////////// Small LCD wave 1 stroke

  Wire.beginTransmission(SmallLCD);  //1
  Wire.write(0xE1);
  Wire.write(0x02);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(SmallLCD);  //2
  Wire.write(0xE0);
  Wire.write(0x24);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();
  Wire.beginTransmission(SmallLCD);
  Wire.write(0xE1);
  Wire.write(0x00);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(SmallLCD);  //3
  Wire.write(0xE0);
  Wire.write(0x08);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(SmallLCD);  //4
  Wire.write(0xE0);
  Wire.write(0x0D);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(SmallLCD);  //5
  Wire.write(0xE0);
  Wire.write(0x13);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(SmallLCD);  //6
  Wire.write(0xE0);
  Wire.write(0x19);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(SmallLCD);  //7
  Wire.write(0xE0);
  Wire.write(0x1F);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(SmallLCD);  //8
  Wire.write(0xE2);
  Wire.write(0x0E);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  //////////////////////////////////////////////////////////////////////// Small LCD wave 2 stroke
  Wire.beginTransmission(SmallLCD);  //1
  Wire.write(0xE1);
  Wire.write(0x07);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  Wire.beginTransmission(SmallLCD);  //2
  Wire.write(0xE1);
  Wire.write(0x0D);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();


  Wire.beginTransmission(SmallLCD);  //3
  Wire.write(0xE1);
  Wire.write(0x13);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();


  Wire.beginTransmission(SmallLCD);  //4
  Wire.write(0xE1);
  Wire.write(0x19);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();



  Wire.beginTransmission(SmallLCD);  //5
  Wire.write(0xE1);
  Wire.write(0x1F);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();


  Wire.beginTransmission(SmallLCD);  //6
  Wire.write(0xE1);
  Wire.write(0x25);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();


  Wire.beginTransmission(SmallLCD);  //7
  Wire.write(0xE2);
  Wire.write(0x03);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();


  Wire.beginTransmission(SmallLCD);  //8
  Wire.write(0xE2);
  Wire.write(0x09);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.write(y);
  Wire.write(x);
  Wire.endTransmission();

  digitalWrite(LED_BUILTIN, LOW);
  delay(time);
  digitalWrite(LED_BUILTIN, HIGH);
}