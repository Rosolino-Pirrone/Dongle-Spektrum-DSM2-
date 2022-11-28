// Confirmed working on Arduino Adafruit Feather Blufruit M0
#include <Arduino.h>   // required before wiring_private.h
#include "wiring_private.h" // pinPeripheral() function

#include <Wire.h>
#include <STRING.h>

#include "SatelliteReceiver.h"

SatelliteReceiver Rx;
int i = 0;
String stringa;
int c = 0;
char dati[25];
char dati2[25];
int n;
void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);

  Wire.begin(8);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  Rx.getFrame();

  
  stringa = "$," + String(Rx.getThro()) + "," + String(Rx.getAile()) + "," + String(Rx.getElev()) + "," + String(Rx.getRudd()) + "," + String(Rx.getGear()) + "," + String(Rx.getAux1()) + "," + String(Rx.getAux2()) + "," + String(Rx.getAux3()) + ",*";
  int n_stringa = stringa.length();
  String stringa_1 = stringa.substring(0, 24);
  String stringa_2 = stringa.substring(24, n_stringa);
  stringa_1.toCharArray(dati, 25);
  stringa_2.toCharArray(dati2, (n_stringa - 23));
  n = stringa_2.length();
  Serial.print(dati);
  Serial.println(dati2);

}


void receiveEvent(int howMany)
{
  c = 0;
  c = Wire.read();
  //Serial.print("c =");
  //Serial.println(c);
}


void requestEvent() {

  //Wire.write(dati);

  if (c == 1)
  {
    Wire.write(dati);
  }

  if (c == 2)
  {
    Wire.write(n);
  }

  if (c == 3)
  {
    Wire.write(dati2);
  }


}
