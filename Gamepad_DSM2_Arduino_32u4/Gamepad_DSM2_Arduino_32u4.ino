// Simple gamepad example that demonstraits how to read five Arduino
// digital pins and map them to the Arduino Joystick library.
//
// The digital pins 2 - 6 are grounded when they are pressed.
// Pin 2 = UP
// Pin 3 = RIGHT
// Pin 4 = DOWN
// Pin 5 = LEFT
// Pin 6 = FIRE
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Matthew Heironimus
// 2016-11-24
//--------------------------------------------------------------------

#include <Joystick.h>
#include <Wire.h>
String throttle;
char inByte[6];
int i = 0;
String stringa;
String throttle_2;
char dati[24];
char dati2[24];
String ch, ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8;
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                   1, 0,                  // Button Count, Hat Switch Count
                   true, true, false,     // X and Y, but no Z Axis
                   true, true, false,   // No Rx, Ry, or Rz
                   false, false,          // No rudder or throttle
                   false, false, false);  // No accelerator, brake, or steering

void setup() {
  Serial1.begin(19200);
  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(-1023, 1023);
  Joystick.setYAxisRange(-1023, 1023);
  Joystick.setRxAxisRange(-1023, 1023);
  Joystick.setRyAxisRange(-1023, 1023);
  Wire.begin();
}

// Last state of the buttons
int lastButtonState[5] = {0, 0, 0, 0, 0};

void loop() {

  i = 0;
  byte x = 1;
  Wire.beginTransmission(8);
  Wire.write(x);
  Wire.endTransmission(8);
  //delay(5);

  Wire.requestFrom(8, 24);    // request 6 bytes from slave device #8
  i = 0;
  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    //Serial1.print(c);         // print the character
    stringa += (c);
    //dati[i] = c;
    i++;
  }

  x = 2;
  int n = 0;
  Wire.beginTransmission(8);
  Wire.write(x);
  Wire.endTransmission(8);
  //delay(5);
  Wire.requestFrom(8, 1);    // request 6 bytes from slave device #8
  while (Wire.available()) { // slave may send less than requested
    n = Wire.read(); // receive a byte as character
    //Serial1.print("n = ");         // print the character
    //Serial1.println(n);         // print the character

  }

  x = 3;
  Wire.beginTransmission(8);
  Wire.write(x);
  Wire.endTransmission(8);
  //delay(5);
  Wire.requestFrom(8, n);    // request 6 bytes from slave device #8
  i = 0;
  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    //Serial1.print(c);         // print the character
    stringa += (c);
    //dati[i] = c;
    i++;
  }

  int index1;
  int index2;
  //if (stringa.charAt(0) == "$"){

  index1 = stringa.indexOf(",");

  stringa.remove(0, (index1 + 1));
  index1 = stringa.indexOf(",");
  ch1 = stringa.substring(0, index1);

  stringa.remove(0, (index1 + 1));
  index1 = stringa.indexOf(",");
  ch2 = stringa.substring(0, index1);

  stringa.remove(0, (index1 + 1));
  index1 = stringa.indexOf(",");
  ch3 = stringa.substring(0, index1);

  stringa.remove(0, (index1 + 1));
  index1 = stringa.indexOf(",");
  ch4 = stringa.substring(0, index1);

  stringa.remove(0, (index1 + 1));
  index1 = stringa.indexOf(",");
  ch5 = stringa.substring(0, index1);

  stringa.remove(0, (index1 + 1));
  index1 = stringa.indexOf(",");
  ch6 = stringa.substring(0, index1);

  stringa.remove(0, (index1 + 1));
  index1 = stringa.indexOf(",");
  ch7 = stringa.substring(0, index1);

  stringa.remove(0, (index1 + 1));
  index1 = stringa.indexOf(",");
  ch8 = stringa.substring(0, index1);

  int c1 = map(constrain(ch1.toInt(), 0, 2048), 0, 2048, -1023, 1023);
  int c2 = map(constrain(ch2.toInt(), 0, 2048), 0, 2048, -1023, 1023);
  int c3 = map(constrain(ch3.toInt(), 0, 2048), 0, 2048, -1023, 1023);
  int c4 = map(constrain(ch4.toInt(), 0, 2048), 0, 2048, -1023, 1023);
  // Read pin values
  Joystick.setXAxis(c1);
  Joystick.setYAxis(c2);
  Joystick.setRxAxis(c3);
  Joystick.setRyAxis(c4);
  stringa = "";

//delay(10);
}
