// Becker Bavaria Proffesional C BE1801 KEY tester
// Pinout panel:
//          + SAFE LED . . NC
//        GND SAFE LED . . +12V backlight LED
//                 SDA . . -3.5V LCD negative power supply
//                 SCL . . GND LCD backlight LED
//   INT from Keyboard . . IR or Photodiode
//                 GND . . NC
//   Vref for Keyboard . . NC
//           +5V power . . +12V keyboard backlight LED


#include <Adafruit_PCF8574.h>
#include <Wire.h>


Adafruit_PCF8574 pcf;
long previousMillis = 0;

byte SmallLCD = 0x3D;
byte LongLCD = 0x3C;

byte x = 0b01010101;
byte y = 0b00101010;

long interval = 100;
void setup() {
  while (!Serial) { delay(10); }
  Serial.begin(115200);
  Serial.println("Becker Bavaria Proffesional C BE1801 KEY tester");

  if (!pcf.begin(0x20, &Wire)) {
    Serial.println("Couldn't find PCF8574");
    while (1)
      ;
  }



  pinMode(2, OUTPUT);
  pcf.pinMode(0, OUTPUT);
  pcf.pinMode(1, OUTPUT);
  pcf.pinMode(2, INPUT_PULLUP);
  pcf.pinMode(3, INPUT_PULLUP);
  pcf.pinMode(4, INPUT_PULLUP);
  pcf.pinMode(5, INPUT_PULLUP);
  pcf.pinMode(6, INPUT_PULLUP);
  pcf.pinMode(7, INPUT_PULLUP);


  digitalWrite(2, HIGH);
  pcf.digitalWrite(0, HIGH);
  pcf.digitalWrite(1, HIGH);

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
}

void loop() {
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
  analogWrite(11, 127);
  ////////////////////////////////////////////////////////////////////////
  if (millis() - previousMillis > interval) {
    if (pcf.digitalRead(2) == 0) {
      previousMillis = millis();
      Serial.println("Button on TONE pressed!");
      Wire.beginTransmission(SmallLCD);  //1
      Wire.write(0xE1);
      Wire.write(0x02);
      Wire.write(0b00000001);
      Wire.write(0b00000001);
      Wire.write(0b01111111);
      Wire.write(0b00000001);
      Wire.write(0b00000001);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //2
      Wire.write(0xE0);
      Wire.write(0x24);
      Wire.write(0b00111110);
      Wire.write(0b01000001);
      Wire.write(0b01000001);
      Wire.endTransmission();
      Wire.beginTransmission(SmallLCD);
      Wire.write(0xE1);
      Wire.write(0x00);
      Wire.write(0b01000001);
      Wire.write(0b00111110);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //3
      Wire.write(0xE0);
      Wire.write(0x08);
      Wire.write(0b01111111);
      Wire.write(0b00000100);
      Wire.write(0b00001000);
      Wire.write(0b00010000);
      Wire.write(0b01111111);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //4
      Wire.write(0xE0);
      Wire.write(0x0D);
      Wire.write(0b01111111);
      Wire.write(0b01001001);
      Wire.write(0b01001001);
      Wire.write(0b01001001);
      Wire.write(0b01000001);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //5
      Wire.write(0xE0);
      Wire.write(0x13);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();
    }
    if (pcf.digitalRead(4) == 0) {
      previousMillis = millis();
      Serial.println("Button on * pressed!");
      Wire.beginTransmission(SmallLCD);  //1
      Wire.write(0xE1);
      Wire.write(0x07);
      Wire.write(0b00101010);
      Wire.write(0b00011100);
      Wire.write(0b01111111);
      Wire.write(0b00011100);
      Wire.write(0b00101010);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //2
      Wire.write(0xE1);
      Wire.write(0x0D);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();
    }
    if (pcf.digitalRead(5) == 0) {
      previousMillis = millis();
      Serial.println("Button on SC pressed!");
      Wire.beginTransmission(SmallLCD);  //1
      Wire.write(0xE1);
      Wire.write(0x07);
      Wire.write(0b00110010);
      Wire.write(0b01001001);
      Wire.write(0b01001001);
      Wire.write(0b01001001);
      Wire.write(0b00100110);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //2
      Wire.write(0xE1);
      Wire.write(0x0D);
      Wire.write(0b00111110);
      Wire.write(0b01000001);
      Wire.write(0b01000001);
      Wire.write(0b01000001);
      Wire.write(0b00100010);
      Wire.endTransmission();
    }
    if (pcf.digitalRead(6) == 0) {
      previousMillis = millis();
      Serial.println("Button on > pressed!");
      Wire.beginTransmission(SmallLCD);  //1
      Wire.write(0xE1);
      Wire.write(0x07);
      Wire.write(0b01000001);
      Wire.write(0b00100010);
      Wire.write(0b00010100);
      Wire.write(0b00001000);
      Wire.write(0b00000000);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //2
      Wire.write(0xE1);
      Wire.write(0x0D);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();
    }
    if (pcf.digitalRead(7) == 0) {
      previousMillis = millis();
      Serial.println("Button on < pressed!");
      Wire.beginTransmission(SmallLCD);  //1
      Wire.write(0xE1);
      Wire.write(0x07);
      Wire.write(0b00000000);
      Wire.write(0b00001000);
      Wire.write(0b00010100);
      Wire.write(0b00100010);
      Wire.write(0b01000001);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //2
      Wire.write(0xE1);
      Wire.write(0x0D);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();
    }
  }  ////////////////////////////////////////////////////////////////////////



  if (millis() - previousMillis > interval) {




    pcf.digitalWrite(0, LOW);

    if (pcf.digitalRead(2) == 0) {
      previousMillis = millis();
      Serial.println("Button on EJECT pressed!");
      Wire.beginTransmission(SmallLCD);  //1
      Wire.write(0xE1);
      Wire.write(0x02);
      Wire.write(0b01111111);
      Wire.write(0b01001001);
      Wire.write(0b01001001);
      Wire.write(0b01001001);
      Wire.write(0b01000001);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //2
      Wire.write(0xE0);
      Wire.write(0x24);
      Wire.write(0b00111111);
      Wire.write(0b01000000);
      Wire.write(0b01000000);
      Wire.endTransmission();
      Wire.beginTransmission(SmallLCD);
      Wire.write(0xE1);
      Wire.write(0x00);
      Wire.write(0b01000000);
      Wire.write(0b00110000);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //3
      Wire.write(0xE0);
      Wire.write(0x08);
      Wire.write(0b01111111);
      Wire.write(0b01001001);
      Wire.write(0b01001001);
      Wire.write(0b01001001);
      Wire.write(0b01000001);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //4
      Wire.write(0xE0);
      Wire.write(0x0D);
      Wire.write(0b00111110);
      Wire.write(0b01000001);
      Wire.write(0b01000001);
      Wire.write(0b01000001);
      Wire.write(0b00100010);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //5
      Wire.write(0xE0);
      Wire.write(0x13);
      Wire.write(0b00000001);
      Wire.write(0b00000001);
      Wire.write(0b01111111);
      Wire.write(0b00000001);
      Wire.write(0b00000001);
      Wire.endTransmission();
    }
    if (pcf.digitalRead(3) == 0) {
      previousMillis = millis();
      Serial.println("Button on TP pressed!");
      Wire.beginTransmission(SmallLCD);  //1
      Wire.write(0xE1);
      Wire.write(0x02);
      Wire.write(0b00000001);
      Wire.write(0b00000001);
      Wire.write(0b01111111);
      Wire.write(0b00000001);
      Wire.write(0b00000001);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //2
      Wire.write(0xE0);
      Wire.write(0x24);
      Wire.write(0b01111111);
      Wire.write(0b00001001);
      Wire.write(0b00001001);
      Wire.endTransmission();
      Wire.beginTransmission(SmallLCD);
      Wire.write(0xE1);
      Wire.write(0x00);
      Wire.write(0b00001001);
      Wire.write(0b00000110);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //3
      Wire.write(0xE0);
      Wire.write(0x08);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //4
      Wire.write(0xE0);
      Wire.write(0x0D);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //5
      Wire.write(0xE0);
      Wire.write(0x13);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();
    }
    if (pcf.digitalRead(4) == 0) {
      previousMillis = millis();
      Serial.println("Button on REG pressed!");
      Wire.beginTransmission(SmallLCD);  //1
      Wire.write(0xE1);
      Wire.write(0x02);
      Wire.write(0b01111111);
      Wire.write(0b00001001);
      Wire.write(0b00001001);
      Wire.write(0b00001001);
      Wire.write(0b01110110);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //2
      Wire.write(0xE0);
      Wire.write(0x24);
      Wire.write(0b01111111);
      Wire.write(0b01001001);
      Wire.write(0b01001001);
      Wire.endTransmission();
      Wire.beginTransmission(SmallLCD);
      Wire.write(0xE1);
      Wire.write(0x00);
      Wire.write(0b01001001);
      Wire.write(0b01000001);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //3
      Wire.write(0xE0);
      Wire.write(0x08);
      Wire.write(0b00111110);
      Wire.write(0b01000001);
      Wire.write(0b01010001);
      Wire.write(0b01010001);
      Wire.write(0b00110010);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //4
      Wire.write(0xE0);
      Wire.write(0x0D);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //5
      Wire.write(0xE0);
      Wire.write(0x13);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();
    }
    if (pcf.digitalRead(5) == 0) {
      previousMillis = millis();
      Serial.println("Button on FM pressed!");

      Wire.beginTransmission(SmallLCD);  //1
      Wire.write(0xE1);
      Wire.write(0x02);
      Wire.write(0b01111111);
      Wire.write(0b00001001);
      Wire.write(0b00001001);
      Wire.write(0b00001001);
      Wire.write(0b00000001);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //2
      Wire.write(0xE0);
      Wire.write(0x24);
      Wire.write(0b01111111);
      Wire.write(0b00000010);
      Wire.write(0b00000100);
      Wire.endTransmission();
      Wire.beginTransmission(SmallLCD);
      Wire.write(0xE1);
      Wire.write(0x00);
      Wire.write(0b00000010);
      Wire.write(0b01111111);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //3
      Wire.write(0xE0);
      Wire.write(0x08);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //4
      Wire.write(0xE0);
      Wire.write(0x0D);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //5
      Wire.write(0xE0);
      Wire.write(0x13);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();
    }
    if (pcf.digitalRead(6) == 0) {
      previousMillis = millis();
      Serial.println("Button on AM pressed!");

      Wire.beginTransmission(SmallLCD);  //1
      Wire.write(0xE1);
      Wire.write(0x02);
      Wire.write(0b01111100);
      Wire.write(0b00001010);
      Wire.write(0b00001001);
      Wire.write(0b00001010);
      Wire.write(0b01111100);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //2
      Wire.write(0xE0);
      Wire.write(0x24);
      Wire.write(0b01111111);
      Wire.write(0b00000010);
      Wire.write(0b00000100);
      Wire.endTransmission();
      Wire.beginTransmission(SmallLCD);
      Wire.write(0xE1);
      Wire.write(0x00);
      Wire.write(0b00000010);
      Wire.write(0b01111111);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //3
      Wire.write(0xE0);
      Wire.write(0x08);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //4
      Wire.write(0xE0);
      Wire.write(0x0D);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //5
      Wire.write(0xE0);
      Wire.write(0x13);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();
    }
    if (pcf.digitalRead(7) == 0) {
      previousMillis = millis();
      Serial.println("Button on MODE pressed!");
      Wire.beginTransmission(SmallLCD);  //1
      Wire.write(0xE1);
      Wire.write(0x02);
      Wire.write(0b01111111);
      Wire.write(0b00000010);
      Wire.write(0b00000100);
      Wire.write(0b00000010);
      Wire.write(0b01111111);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //2
      Wire.write(0xE0);
      Wire.write(0x24);
      Wire.write(0b00111110);
      Wire.write(0b01000001);
      Wire.write(0b01000001);
      Wire.endTransmission();
      Wire.beginTransmission(SmallLCD);
      Wire.write(0xE1);
      Wire.write(0x00);
      Wire.write(0b01000001);
      Wire.write(0b00111110);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //3
      Wire.write(0xE0);
      Wire.write(0x08);
      Wire.write(0b01111111);
      Wire.write(0b01000001);
      Wire.write(0b01000001);
      Wire.write(0b01000001);
      Wire.write(0b00111110);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //4
      Wire.write(0xE0);
      Wire.write(0x0D);
      Wire.write(0b01111111);
      Wire.write(0b01001001);
      Wire.write(0b01001001);
      Wire.write(0b01001001);
      Wire.write(0b01000001);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //5
      Wire.write(0xE0);
      Wire.write(0x13);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();
    }

    pcf.digitalWrite(0, HIGH);

    ////////////////////////////////////////////////////////////////////////

    pcf.digitalWrite(1, LOW);

    if (pcf.digitalRead(2) == 0) {
      previousMillis = millis();
      Serial.println("Button on 3 pressed!");
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
    }
    if (pcf.digitalRead(3) == 0) {
      previousMillis = millis();
      Serial.println("Button on 4 pressed!");
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
    }
    if (pcf.digitalRead(4) == 0) {
      previousMillis = millis();
      Serial.println("Button on 5 pressed!");
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
    }
    if (pcf.digitalRead(5) == 0) {
      previousMillis = millis();
      Serial.println("Button on 8 pressed!");
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
    }
    if (pcf.digitalRead(6) == 0) {
      previousMillis = millis();
      Serial.println("Button on 9 pressed!");
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
    }
    if (pcf.digitalRead(7) == 0) {
      previousMillis = millis();
      Serial.println("Button on 10 pressed!");
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
    }

    pcf.digitalWrite(1, HIGH);

    ////////////////////////////////////////////////////////////////////////

    digitalWrite(2, LOW);


    if (pcf.digitalRead(2) == 0) {
      previousMillis = millis();
      Serial.println("Button on 1 pressed!");
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
    }
    if (pcf.digitalRead(6) == 0) {
      previousMillis = millis();
      Serial.println("Button on 2 pressed!");
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
    }
    if (pcf.digitalRead(3) == 0) {
      previousMillis = millis();
      Serial.println("Button on TA pressed!");
      Wire.beginTransmission(SmallLCD);  //1
      Wire.write(0xE1);
      Wire.write(0x02);
      Wire.write(0b00000001);
      Wire.write(0b00000001);
      Wire.write(0b01111111);
      Wire.write(0b00000001);
      Wire.write(0b00000001);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //2
      Wire.write(0xE0);
      Wire.write(0x24);
      Wire.write(0b01111100);
      Wire.write(0b00001010);
      Wire.write(0b00001001);
      Wire.endTransmission();
      Wire.beginTransmission(SmallLCD);
      Wire.write(0xE1);
      Wire.write(0x00);
      Wire.write(0b00001010);
      Wire.write(0b01111100);
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //3
      Wire.write(0xE0);
      Wire.write(0x08);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //4
      Wire.write(0xE0);
      Wire.write(0x0D);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();

      Wire.beginTransmission(SmallLCD);  //5
      Wire.write(0xE0);
      Wire.write(0x13);
      for (uint8_t p = 0; p < 5; p++) {
        Wire.write(0x00);
      }
      Wire.endTransmission();
    }
    if (pcf.digitalRead(4) == 0) {
      previousMillis = millis();
      Serial.println("Button on 6 pressed!");
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
    }
    if (pcf.digitalRead(5) == 0) {
      previousMillis = millis();
      Serial.println("Button on 7 pressed!");

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
    }

    digitalWrite(2, HIGH);
  }
  ////////////////////////////////////////////////////////////////////////


  if (millis() - previousMillis > interval * 10) {

    Wire.beginTransmission(LongLCD);
    Wire.write(0xE0);
    Wire.write(0x08);
    for (uint8_t p = 0; p < 30; p++) {
      Wire.write(0xFF);
    }
    Wire.endTransmission();

    Wire.beginTransmission(LongLCD);
    Wire.write(0xE0);
    Wire.write(0x26);
    for (uint8_t p = 0; p < 5; p++) {
      Wire.write(0xFF);
    }
    Wire.endTransmission();

    Wire.beginTransmission(LongLCD);
    Wire.write(0xE1);
    Wire.write(0x03);
    for (uint8_t p = 0; p < 30; p++) {
      Wire.write(0xFF);
    }
    Wire.endTransmission();

    Wire.beginTransmission(LongLCD);
    Wire.write(0xE1);
    Wire.write(0x21);
    for (uint8_t p = 0; p < 10; p++) {
      Wire.write(0xFF);
    }
    Wire.endTransmission();


    Wire.beginTransmission(LongLCD);
    Wire.write(0xE3);
    Wire.write(0x03);
    for (uint8_t p = 0; p < 30; p++) {
      Wire.write(0xFF);
    }
    Wire.endTransmission();

    Wire.beginTransmission(LongLCD);
    Wire.write(0xE3);
    Wire.write(0x21);
    for (uint8_t p = 0; p < 5; p++) {
      Wire.write(0xFF);
    }
    Wire.endTransmission();

    Wire.beginTransmission(LongLCD);
    Wire.write(0xE2);
    Wire.write(0x03);
    for (uint8_t p = 0; p < 30; p++) {
      Wire.write(0xFF);
    }
    Wire.endTransmission();

    Wire.beginTransmission(LongLCD);
    Wire.write(0xE2);
    Wire.write(0x21);
    for (uint8_t p = 0; p < 10; p++) {
      Wire.write(0xFF);
    }
    Wire.endTransmission();
  }
}
