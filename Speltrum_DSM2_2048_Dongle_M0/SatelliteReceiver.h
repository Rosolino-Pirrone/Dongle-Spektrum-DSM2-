

#ifndef SPECTRUMRECEIVER_H_
#define SPECTRUMRECEIVER_H_
#include "Arduino.h"

class SatelliteReceiver {
  public:

    void getFrame(void);
    int getThro();
    int getAile();
    int getElev();
    int getRudd();
    int getGear();
    int getAux1();
    int getAux2();
    int getAux3();
    

  private:
    int channels[8];
    static constexpr uint16_t MASK_2048_SXPOS = 0x07FF;
    uint8_t chan;
    uint16_t servo_position;
    uint16_t raw;
    int inData[16];
    int index;
    int inByte;
};


#endif /* SPECTRUMRECEIVER_H_ */
