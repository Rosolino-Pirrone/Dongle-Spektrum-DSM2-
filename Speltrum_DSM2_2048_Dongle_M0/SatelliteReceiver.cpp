
#include "SatelliteReceiver.h"
void SatelliteReceiver::getFrame(void) {
  
  while (Serial1.available() > 16) {
    for (index = 0; index <= 15; index++) {
      inByte = Serial1.read();
      inData[index] = inByte;
    }
  }

  for (int i = 1; i <= 7; i++) {

    raw = (((uint16_t)inData[i * 2] << 8) | inData[i * 2 + 1]);
    //Phase = (raw >> 15) & 0x01;
    chan = (raw >> 11) & 0x0F;
    servo_position = (raw & MASK_2048_SXPOS);
    if (chan < 12) {
      channels[chan] = servo_position;

    }


  }
  /*for (int i = 0; i <= 7; i++) {
    Serial.print("ch" + String(i) + "= ");
    Serial.print(String(channels[i]));
    Serial.print(" ");
    if (i == 7) Serial.print("\n");
    }*/
}



int SatelliteReceiver::getThro() {

  return channels[0];
}

int SatelliteReceiver::getAile() {

  return channels[1];
}

int SatelliteReceiver::getElev() {

  return channels[2];
}

int SatelliteReceiver::getRudd() {

  return channels[3];
}

int SatelliteReceiver::getGear() {

  return channels[4];
}

int SatelliteReceiver::getAux1() {

  return channels[5];
}

int SatelliteReceiver::getAux2() {

  return channels[6];
}

int SatelliteReceiver::getAux3() {

  return channels[7];
}
